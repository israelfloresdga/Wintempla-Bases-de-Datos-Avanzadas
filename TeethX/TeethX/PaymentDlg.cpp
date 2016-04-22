#include "stdafx.h"  //_____________________________________________ PaymentDlg.cpp
#include "PaymentDlg.h"

void PaymentDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Payment";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if(patient_id<0)
		{conn.ExecuteSelect(L"SELECT patient_id, patient_name FROM vw_transaction GROUP BY patient_id, patient_name", 100, ddPatient);}
		else
		{
			Sys::Format(cmd,L"SELECT patient_id, patient_name FROM vw_transaction WHERE patient_id=%d GROUP BY patient_id, patient_name", patient_id);
			conn.ExecuteSelect(cmd, 100, ddPatient);
			ddPatient.SelectedIndex= 0;
		}

		if (transactionz_id < 0) return;
		Sys::Format(cmd, L"SELECT patient_id, amount, comment FROM transactionz WHERE transactionz_id=%d", transactionz_id);
		conn.ExecuteSelect(cmd);
		conn.BindColumn(1, ddPatient);
		conn.BindColumn(2, tbxAmount, 128);
		tbxComment.MaxText = 100;
		conn.BindColumn(3, tbxComment, 128);
		if (conn.Fetch() == false)
		{
			this->MessageBox(L"No data was returned", L"Error", MB_OK);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	//________________________________________________________ dtbox1
	//dtbox1.SelectedDate = Sys::Time::Now().AddDays(2);
	//dtbox1.SetFormat(L"hh:mm:ss dddd MMM dd, yyyy"); 
	//________________________________________________________ dtboxTransaction_date
	//dtboxTransaction_date.SelectedDate = Sys::Time::Now().AddDays(2);
	//dtboxTransaction_date.SetFormat(L"hh:mm:ss dddd MMM dd, yyyy"); 
	//________________________________________________________ dtboxTransactionDate
	//dtboxTransactionDate.SelectedDate = Sys::Time::Now().AddDays(2);
	//dtboxTransactionDate.SetFormat(L"hh:mm:ss dddd MMM dd, yyyy"); 
}

void PaymentDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	tr1::wregex regexDouble(L"[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?");
	if (tr1::regex_match(tbxAmount.Text, regexDouble) == false)
	{
		tbxAmount.ShowBalloonTip(L"Invalid Amount", L"Please provide a floating point value", TTI_ERROR);
		return;
	}
	
	Sql::StringBuilder sb(L"transactionz", L"transactionz_id", transactionz_id);
	tbxTransactionTypeID.Text= L"2";
	sb.Bind(L"transaction_type_id", tbxTransactionTypeID);
	dtboxTransactionDate.SetFormat(L"MMM dd, yyyy"); 
	dtboxTransactionDate.SqlGetSysTime();
	sb.BindMicrosoft(L"transaction_date", dtboxTransactionDate);
	sb.Bind(L"patient_id", ddPatient);
	tbxDentalProcedureID.Text= L"1";
	sb.Bind(L"dental_procedure_id", tbxDentalProcedureID);
	tbxToothID.Text= L"1";
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

void PaymentDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

