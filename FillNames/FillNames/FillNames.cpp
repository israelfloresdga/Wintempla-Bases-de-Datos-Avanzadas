#include "stdafx.h"  //________________________________________ FillNames.cpp
#include "FillNames.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	FillNames app;
	return app.BeginDialog(IDI_FILLNAMES, hInstance);
}

void FillNames::Window_Open(Win::Event& e)
{
	::srand(::GetTickCount());
	const int numInit= 120;
	const int numNames= 10000;

	Sql::SqlConnection conn;
	wstring cmd;
	int employee_id;
	wstring first_name;
	wstring last_name;
	int rows = 0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		//
		//rows = conn.ExecuteNonQuery(L"DELETE FROM emp_skill");
		//rows = conn.ExecuteNonQuery(L"DELETE FROM employee");
		//
		for(employee_id=numInit; employee_id<numInit+numNames; employee_id++)
		{
			first_name= CreateRandomName();
			last_name= CreateRandomName();
			Sys::Format(cmd, L"INSERT INTO employee (employee_id, first_name, last_name, phone, dept_id) VALUES(%d,'%s','%s', 124123, 90)", employee_id, first_name.c_str(), last_name.c_str());
			rows = conn.ExecuteNonQuery(cmd);
			if (rows!=1)
			{
				this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of inserted rows", MB_OK | MB_ICONERROR);
			}
		}
		Sys::Format(cmd, L"INSERT INTO employee (employee_id, first_name, last_name, phone, dept_id) VALUES(119,'Moonlight','Alice', 124123, 90)", employee_id);
		rows = conn.ExecuteNonQuery(cmd);
		if (rows!=1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of inserted rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	wstring randomName= CreateRandomName();
}

wstring FillNames::CreateRandomName()
{
	const int len= 3 + (8*rand())/RAND_MAX;
	const int numChar= 'Z' - 'A' +1;

	wstring randomName;
	randomName.resize(len);
	int randomNumber;

	for(int i=0; i<len; i++)
	{
		randomNumber= (numChar*rand())/RAND_MAX;
		if(i==0)
		{
			randomName[i]= 'A' + randomNumber;
		}
		else
		{
			randomName[i]= 'a' + randomNumber;
		}
	}
	return randomName;
}

