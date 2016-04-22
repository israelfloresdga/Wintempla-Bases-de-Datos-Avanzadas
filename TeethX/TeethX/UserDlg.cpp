#include "stdafx.h"  //_____________________________________________ UserDlg.cpp
#include "UserDlg.h"

void UserDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Userz";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (userz_id < 0) return;
		Sys::Format(cmd, L"SELECT username, first_name, last_name, passwordz, email, is_active, has_access_patient_info, has_access_users, has_access_payments, has_access_patient_chart, has_access_dental_procedure_setup FROM userz WHERE userz_id=%d", userz_id);
		conn.ExecuteSelect(cmd);
		tbxUsername.MaxText = 16;
		conn.BindColumn(1, tbxUsername, 128);
		tbxFirst_name.MaxText = 32;
		conn.BindColumn(2, tbxFirst_name, 128);
		tbxLast_name.MaxText = 32;
		conn.BindColumn(3, tbxLast_name, 128);
		tbxPasswordz.MaxText = 16;
		conn.BindColumn(4, tbxPasswordz, 128);
		tbxEmail.MaxText = 32;
		conn.BindColumn(5, tbxEmail, 128);
		conn.BindColumn(6, ckIs_active);
		conn.BindColumn(7, ckHas_access_patient_info);
		conn.BindColumn(8, ckHas_access_users);
		conn.BindColumn(9, ckHas_access_payments);
		conn.BindColumn(10, ckHas_access_patient_chart);
		conn.BindColumn(11, ckHas_access_dental_procedure_setup);
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

void UserDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	tr1::wregex regextbxUsername(L"[A-Za-z0-9]+");
	if (tr1::regex_match(tbxUsername.Text, regextbxUsername) == false)
	{
		tbxUsername.ShowBalloonTip(L"Invalid Username", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
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
	tr1::wregex regextbxPasswordz(L"[A-Za-z0-9]+");
	if (tr1::regex_match(tbxPasswordz.Text, regextbxPasswordz) == false)
	{
		tbxPasswordz.ShowBalloonTip(L"Invalid Passwordz", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	tr1::wregex regextbxEmail(L".+@.+");
	if (tr1::regex_match(tbxEmail.Text, regextbxEmail) == false)
	{
		tbxEmail.ShowBalloonTip(L"Invalid Email", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"userz", L"userz_id", userz_id);
	sb.Bind(L"username", tbxUsername);
	sb.Bind(L"first_name", tbxFirst_name);
	sb.Bind(L"last_name", tbxLast_name);
	sb.Bind(L"passwordz", tbxPasswordz);
	sb.Bind(L"email", tbxEmail);
	sb.Bind(L"is_active", ckIs_active);
	sb.Bind(L"has_access_patient_info", ckHas_access_patient_info);
	sb.Bind(L"has_access_users", ckHas_access_users);
	sb.Bind(L"has_access_payments", ckHas_access_payments);
	sb.Bind(L"has_access_patient_chart", ckHas_access_patient_chart);
	sb.Bind(L"has_access_dental_procedure_setup", ckHas_access_dental_procedure_setup);
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

void UserDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

