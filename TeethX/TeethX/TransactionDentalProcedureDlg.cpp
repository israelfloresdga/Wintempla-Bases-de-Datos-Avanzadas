#include "stdafx.h"  //_____________________________________________ TransactionDentalProcedureDlg.cpp
#include "TransactionDentalProcedureDlg.h"

void TransactionDentalProcedureDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Dental Procedure";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		//___patient_id
		if(transactionz_id<0 || patient_id<0)
		{conn.ExecuteSelect(L"SELECT patient_id, patient_name FROM vw_transaction GROUP BY patient_id, patient_name", 100, ddPatient);}
		else
		{
			Sys::Format(cmd,L"SELECT patient_id, patient_name FROM vw_transaction WHERE patient_id=%d GROUP BY patient_id, patient_name", patient_id);
			conn.ExecuteSelect(cmd, 100, ddPatient);
			//ddPatient.SelectedIndex= 0;
		}

		if(transactionz_id<0)
		{
			Sys::Format(cmd, L"SELECT tooth_id FROM tooth WHERE tooth_code= '%s'", tooth_code.c_str());
		}
		else if(transactionz_id>=0 && !tooth_code.empty())
		{
			Sys::Format(cmd, L"SELECT tooth_id FROM tooth WHERE tooth_code= '%s'", tooth_code.c_str());
		}
		else
		{
			Sys::Format(cmd, L"SELECT tooth_id FROM vw_transaction WHERE transaction_id= %d", transactionz_id);
		}
		tooth_id= conn.GetInt(cmd);
		//
		conn.ExecuteSelect(L"SELECT dental_procedure_id, descr FROM dental_procedure WHERE dental_procedure_id>1", 100, ddDental_procedure);
		ddDental_procedure.SelectedIndex= 0;

		updateEstimatedCost();

		if (transactionz_id < 0) return;
		Sys::Format(cmd, L"SELECT patient_id, dental_procedure_id, amount, comment FROM vw_transaction WHERE transaction_id=%d", transactionz_id);
		conn.ExecuteSelect(cmd);
		conn.BindColumn(1, ddPatient);
		conn.BindColumn(2, ddDental_procedure);
		conn.BindColumn(3, tbxAmount, 128);
		tbxComment.MaxText = 100;
		conn.BindColumn(4, tbxComment, 128);
		if (conn.Fetch() == false)
		{
			this->MessageBox(L"No data was returned", L"Error", MB_OK);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
}

void TransactionDentalProcedureDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	tr1::wregex regexDouble(L"[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?");
	if (tr1::regex_match(tbxAmount.Text, regexDouble) == false)
	{
		tbxAmount.ShowBalloonTip(L"Invalid Amount", L"Please provide a floating point value", TTI_ERROR);
		return;
	}
	
	Sql::StringBuilder sb(L"transactionz", L"transactionz_id", transactionz_id);
	tbxTransactionTypeID.Text= Sys::Convert::ToString(transaction_type_id);
	sb.Bind(L"transaction_type_id", tbxTransactionTypeID);
	dtboxTransactionDate.SetFormat(L"MMM dd, yyyy"); 
	dtboxTransactionDate.SqlGetSysTime();
	sb.BindMicrosoft(L"transaction_date", dtboxTransactionDate);
	sb.Bind(L"patient_id", ddPatient);
	sb.Bind(L"dental_procedure_id", ddDental_procedure);
	tbxToothID.Text= Sys::Convert::ToString(tooth_id);
	sb.Bind(L"tooth_id", tbxToothID);
	sb.Bind(L"amount", tbxAmount);
	tbxUserzID.Text= Sys::Convert::ToString(userz_id);
	sb.Bind(L"userz_id", tbxUserzID);
	sb.Bind(L"comment", tbxComment);
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		rows = conn.ExecuteNonQuery(sb.GetString());
		if (rows!=1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of affected rows", MB_OK | MB_ICONERROR);
			return;
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	this->EndDialog(TRUE);
}

void TransactionDentalProcedureDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

void TransactionDentalProcedureDlg::updateEstimatedCost()
{
	const int selectedIndex= ddDental_procedure.SelectedIndex;
	if(selectedIndex<0) return;
	const int dental_procedure_id= ddDental_procedure.Items[selectedIndex].Data;

	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(cmd, L"SELECT estimated_cost FROM dental_procedure WHERE dental_procedure_id= %d", dental_procedure_id);
		tbxAmount.DoubleValue= conn.GetDouble(cmd);
	}
	catch(Sql::SqlException e)
	{
		this->MessageBoxW(e.GetDescription(), L"Error", MB_OK|MB_ICONERROR);
	}
}
void TransactionDentalProcedureDlg::ddDental_procedure_SelChange(Win::Event& e)
{
	updateEstimatedCost();
}

