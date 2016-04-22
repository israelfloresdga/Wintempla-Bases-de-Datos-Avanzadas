#include "stdafx.h"  //_____________________________________________ SelectPatientDlg.cpp
#include "SelectPatientDlg.h"

void SelectPatientDlg::Window_Open(Win::Event& e)
{
	this->Text= L"Select a Patient";
	//________________________________________________________ lvPatient
	lvPatient.Cols.Add(0, LVCFMT_LEFT, 200, L"Last Name");
	lvPatient.Cols.Add(1, LVCFMT_LEFT, 200, L"First Name");

	Sql::SqlConnection conn;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
				
		conn.ExecuteSelect(L"SELECT patient_id, last_name, first_name FROM patient ORDER BY last_name ASC", 100, lvPatient);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
}

void SelectPatientDlg::lvPatient_ItemActivate(Win::Event& e)
{
	const int selectedIndex= lvPatient.GetSelectedIndex();
	if(selectedIndex<0) return;
	patient_id= lvPatient.Items[selectedIndex].Data;

	patient_name= lvPatient.Items[selectedIndex].Text;
	patient_name+= L", ";
	patient_name+= lvPatient.Items[selectedIndex][1].Text;
	//GetPatientName(patient_id); //Inefficient
	/*wstring text;
	Sys::Format(text, L"Selecting: %s \nAre you sure?", patient_name.c_str());
	if(this->MessageBoxW(text, L"Selecting Patient.",MB_YESNO|MB_ICONQUESTION)!=IDYES) return;*/

	this->EndDialog(TRUE);
}

void SelectPatientDlg::lvPatient_KeyDown(Win::Event& e)
{
	LPNMLVKEYDOWN p = (LPNMLVKEYDOWN) e.lParam;
	if (p->wVKey == VK_RETURN)
	{
		lvPatient_ItemActivate(e);
	}
}

void SelectPatientDlg::GetPatientName(int patient_id)
{
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		
		Sys::Format(cmd, L"SELECT last_name+', '+first_name AS patient_name FROM patient WHERE patient_id= %i", patient_id);
		conn.GetString(cmd, patient_name,68);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
}
