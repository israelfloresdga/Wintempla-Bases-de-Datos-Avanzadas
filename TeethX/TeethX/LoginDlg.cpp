#include "stdafx.h"  //_____________________________________________ LoginDlg.cpp
#include "LoginDlg.h"

void LoginDlg::Window_Open(Win::Event& e)
{
	this->Text= L"Login";
}

void LoginDlg::btOk_Click(Win::Event& e)
{
	if(tbxUsername.Text.length()<3) return;
	if(tbxPassword.Text.length()<3) return;

	Sql::SqlConnection conn;
	int count =0;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		wstring username= tbxUsername.Text;
		wstring password= tbxPassword.Text;
		Sys::Format(cmd, L"SELECT count(*) FROM userz WHERE username='%s' AND passwordz='%s'", username.c_str(), password.c_str());
		count = conn.GetInt(cmd);
		count =1;
		if(count==1)
		{
			Sys::Format(cmd, L"SELECT userz_id FROM userz WHERE username='%s' AND passwordz='%s'", username.c_str(), password.c_str());
			userz_id= conn.GetInt(cmd);
			this->EndDialog(TRUE);
			return;
		}
		else
		{
			tryCount++;
			this->MessageBoxW(L"Usuario o Contraseña Incorrecta", L"Error", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		tryCount++;
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	if(tryCount>2)
	{
		this->EndDialog(FALSE);
		return;
	}
}

void LoginDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}
