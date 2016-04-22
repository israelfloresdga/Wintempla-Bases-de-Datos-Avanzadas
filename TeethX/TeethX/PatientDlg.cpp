#include "stdafx.h"  //_____________________________________________ PatientDlg.cpp
#include "PatientDlg.h"

void PatientDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Patient";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (patient_id < 0) return;
		Sys::Format(cmd, L"SELECT first_name, last_name, birth_date, email FROM patient WHERE patient_id=%d", patient_id);
		conn.ExecuteSelect(cmd);
		tbxFirst_name.MaxText = 32;
		conn.BindColumn(1, tbxFirst_name, 128);
		tbxLast_name.MaxText = 32;
		conn.BindColumn(2, tbxLast_name, 128);
		dtboxBirth_date.SetFormat(L"MMM dd, yyyy"); 
		conn.BindColumn(3, dtboxBirth_date);
		tbxEmail.MaxText = 64;
		conn.BindColumn(4, tbxEmail, 128);
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

void PatientDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	tr1::wregex regextbxFirst_name(L"[A-Za-z0-9]+");
	if (tr1::regex_match(tbxFirst_name.Text, regextbxFirst_name) == false)
	{
		tbxFirst_name.ShowBalloonTip(L"Invalid First name", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxLast_name(L"[A-Za-z0-9]+");
	if (tr1::regex_match(tbxLast_name.Text, regextbxLast_name) == false)
	{
		tbxLast_name.ShowBalloonTip(L"Invalid Last name", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxEmail(L".+@.+");
	if (tr1::regex_match(tbxEmail.Text, regextbxEmail) == false)
	{
		tbxEmail.ShowBalloonTip(L"Invalid Email", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"patient", L"patient_id", patient_id);
	sb.Bind(L"first_name", tbxFirst_name);
	sb.Bind(L"last_name", tbxLast_name);
	sb.BindMicrosoft(L"birth_date", dtboxBirth_date);
	sb.Bind(L"email", tbxEmail);
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

void PatientDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

