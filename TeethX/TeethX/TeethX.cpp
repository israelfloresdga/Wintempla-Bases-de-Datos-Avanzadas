#include "stdafx.h"  //________________________________________ TeethX.cpp
#include "TeethX.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	TeethX app;
	app.CreateMainWindow(L"TeethX", cmdShow, IDI_TEETHX, NULL, (HBRUSH)(COLOR_WINDOW+1), hInstance);
	return app.MessageLoop(IDC_TEETHX);
}

void TeethX::Window_Open(Win::Event& e)
{
	//____________________________________________________Login: Get userz_id
	LoginDlg dlg;
	if(dlg.BeginDialog(hWnd)!=TRUE)
	{
		this->Destroy();
		return;
	}
	userz_id= dlg.userz_id;
	/*this->Width= 820;*/
	//________________________________________________________ toolbMain
	TBBUTTON tbButton[12];//<< EDIT HERE THE NUMBER OF BUTTONS

	toolbMain.imageList.Create(20, 20, 9);//<< EDIT HERE THE NUMBER OF IMAGES
	toolbMain.imageList.AddIcon(this->hInstance, IDI_SAVE);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_COPY);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_ADD);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_EDIT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_DELETE);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_PRINT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_MSEXCEL);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_USERZ);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_FIVE);
	toolbMain.SendMessage(TB_BUTTONSTRUCTSIZE, (WPARAM)(int)sizeof(TBBUTTON), 0); 
	toolbMain.SetImageList(toolbMain.imageList);
	//_____________________________________
	tbButton[0].iBitmap=MAKELONG(0, 0); //<< IMAGE INDEX
	tbButton[0].idCommand=IDM_SAVE;
	tbButton[0].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[0].fsStyle=BTNS_BUTTON;
	tbButton[0].dwData=0L; 
	tbButton[0].iString= (LONG_PTR)L"Unable";
		//_____________________________________
	tbButton[1].iBitmap=MAKELONG(1, 0); //<< IMAGE INDEX
	tbButton[1].idCommand=IDM_COPY;
	tbButton[1].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[1].fsStyle=BTNS_BUTTON;
	tbButton[1].dwData=0L; 
	tbButton[1].iString= (LONG_PTR)L"Copy";
	//________________________ A separator
	tbButton[2].iBitmap=-1;
	tbButton[2].idCommand=0;  
	tbButton[2].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[2].fsStyle=BTNS_SEP;  
	tbButton[2].dwData=0L;  
	tbButton[2].iString=0;  
	//_____________________________________
	tbButton[3].iBitmap=MAKELONG(2, 0); //<< IMAGE INDEX
	tbButton[3].idCommand=IDM_INSERT;
	tbButton[3].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[3].fsStyle=BTNS_BUTTON;
	tbButton[3].dwData=0L; 
	tbButton[3].iString= (LONG_PTR)L"Add";
	//_____________________________________
	tbButton[4].iBitmap=MAKELONG(3, 0); //<< IMAGE INDEX
	tbButton[4].idCommand=IDM_EDIT;
	tbButton[4].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[4].fsStyle=BTNS_BUTTON;
	tbButton[4].dwData=0L; 
	tbButton[4].iString= (LONG_PTR)L"Edit";
	//_____________________________________
	tbButton[5].iBitmap=MAKELONG(4, 0); //<< IMAGE INDEX
	tbButton[5].idCommand=IDM_DELETE;
	tbButton[5].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[5].fsStyle=BTNS_BUTTON;
	tbButton[5].dwData=0L; 
	tbButton[5].iString= (LONG_PTR)L"Delete";
	//________________________ A separator
	tbButton[6].iBitmap=-1;
	tbButton[6].idCommand=0;  
	tbButton[6].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[6].fsStyle=BTNS_SEP;  
	tbButton[6].dwData=0L;  
	tbButton[6].iString=0;  
	//_____________________________________
	tbButton[7].iBitmap=MAKELONG(5, 0); //<< IMAGE INDEX
	tbButton[7].idCommand=IDM_PRINT;
	tbButton[7].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[7].fsStyle=BTNS_BUTTON;
	tbButton[7].dwData=0L; 
	tbButton[7].iString= (LONG_PTR)L"Print";
	//_____________________________________
	tbButton[8].iBitmap=MAKELONG(6, 0); //<< IMAGE INDEX
	tbButton[8].idCommand=IDM_MSEXCEL;
	tbButton[8].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[8].fsStyle=BTNS_BUTTON;
	tbButton[8].dwData=0L; 
	tbButton[8].iString= (LONG_PTR)L"Export to Microsoft Excel";
	//________________________ A separator
	tbButton[9].iBitmap=-1;
	tbButton[9].idCommand=0;  
	tbButton[9].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[9].fsStyle=BTNS_SEP;  
	tbButton[9].dwData=0L;  
	tbButton[9].iString=0;  
	//_____________________________________
	tbButton[10].iBitmap=MAKELONG(7, 0); //<< IMAGE INDEX
	tbButton[10].idCommand=IDM_USERZ;
	tbButton[10].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[10].fsStyle=BTNS_BUTTON;
	tbButton[10].dwData=0L; 
	tbButton[10].iString= (LONG_PTR)L"Select a Patient";
	//_____________________________________
	tbButton[11].iBitmap=MAKELONG(8, 0); //<< IMAGE INDEX
	tbButton[11].idCommand=IDM_FIVE;
	tbButton[11].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[11].fsStyle=BTNS_BUTTON;
	tbButton[11].dwData=0L; 
	tbButton[11].iString= (LONG_PTR)L"Deselect Patient";

	toolbMain.SetBitmapSize(20, 20);
	toolbMain.SetButtonSize(24, 22);
	toolbMain.AddButtons(tbButton, 12);// << EDIT HERE THE NUMBER OF BUTTONS
	toolbMain.SendMessage(TB_AUTOSIZE, 0, 0);
	toolbMain.SetMaxTextRows(0);// EDIT HERE TO DISPLAY THE BUTTON TEXT
	toolbMain.Show(SW_SHOWNORMAL);

	//____________________________________________________Tooth Setup
	wchar_t text[64];
	for(unsigned int i=0; i<TOOTH_COUNT; i++)
	{
		tooth[i]->IsUpper= (i<16);
		_snwprintf_s(text, 64, _TRUNCATE, L"%d", i+1);
		tooth[i]->ToothCode= text;
		tooth[i]->Visible= false;
	}

	enableButtons();
	fillTabSelection();

}

void TeethX::enableButtons()
{
	toolbMain.EnableButton(IDM_INSERT, true);
	toolbMain.EnableButton(IDM_EDIT, false);
	toolbMain.EnableButton(IDM_DELETE, false);
	toolbMain.EnableButton(IDM_PRINT, true);
	toolbMain.EnableButton(IDM_COPY, true);
	toolbMain.EnableButton(IDM_MSEXCEL, true);
	toolbMain.EnableButton(IDM_SAVE, false);
	toolbMain.EnableButton(IDM_USERZ, true);
	toolbMain.EnableButton(IDM_FIVE, false);
}


void TeethX::fillTabSelection()
{
	//____________________________________________________Get Access info from the userz table
	bool is_active= false;
	bool has_acceess_patient_info= false;
	bool has_access_users= false;
	bool has_access_payments= false;
	bool has_access_patient_chart= false;
	bool has_access_dental_procedure_setup= false;
	
	Sql::SqlConnection conn;
	wstring cmd;
	int employee_id=0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(cmd, L"SELECT is_active, has_access_patient_info, has_access_users, has_access_payments, has_access_patient_chart, has_access_dental_procedure_setup FROM userz WHERE userz_id= %d", userz_id);
		conn.ExecuteSelect(cmd);
		conn.BindColumn(1, is_active);
		conn.BindColumn(2, has_acceess_patient_info);
		conn.BindColumn(3, has_access_users);
		conn.BindColumn(4, has_access_payments);
		conn.BindColumn(5, has_access_patient_chart);
		conn.BindColumn(6, has_access_dental_procedure_setup);
		if(conn.Fetch()!=true)
		{
			this->MessageBox(L"Unable to get user access.", L"TeethX", MB_OK|MB_ICONERROR);
			this->Destroy();
			return;
		}
	}
	catch(Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(),L"TeethX", MB_OK|MB_ICONERROR);
	}
	if(is_active==false)
	{
		this->MessageBox(L"This account is not active.", L"TeethX", MB_OK|MB_ICONERROR);
		this->Destroy();
		return;
	}
	//____________________________________________________Tab Selection
	int index= 0;
	if(has_acceess_patient_info==true) tabSelection.Items.Add(index++, L"Patient", TAB_PATIENT);
	if(has_access_payments==true) tabSelection.Items.Add(index++, L"Payment", TAB_PAYMENT);
	if(has_access_patient_chart==true) tabSelection.Items.Add(index++, L"Patient Chart", TAB_PATIENT_CHART);
	if(has_access_dental_procedure_setup==true) tabSelection.Items.Add(index++, L"Procedure Setup", TAB_PROCEDURE_SETUP);
	if(has_access_users==true) tabSelection.Items.Add(index++, L"Users", TAB_USERS);
	tabSelection.SelectedIndex= 0;
	fillListView();
}

void TeethX::fillListView()
{
	/*lvMain.SetRedraw(false);
	lvMain.Cols.DeleteAll();
	lvMain.Items.DeleteAll();*/

	Sql::SqlConnection conn;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if(tabSelection.SelectedData==0)//Patient
		{
			lvMain.SetRedraw(false);
			lvMain.Cols.DeleteAll();
			lvMain.Items.DeleteAll();
			//
			lvMain.Cols.Add(0, LVCFMT_LEFT, 200, L"Last Name");
			lvMain.Cols.Add(1, LVCFMT_LEFT, 200, L"First Name");
			lvMain.Cols.Add(2, LVCFMT_LEFT, 100, L"Birthdate");
			lvMain.Cols.Add(3, LVCFMT_LEFT, 250, L"Email");
			if(patient_id==-1)
			{
				conn.ExecuteSelect(L"SELECT patient_id, last_name, first_name, birth_date, email FROM patient", 100, lvMain);
			}
			else
			{
				wstring cmd_s;
				Sys::Format(cmd_s, L"SELECT patient_id, last_name, first_name, birth_date, email FROM patient WHERE patient_id= %d", patient_id);
				conn.ExecuteSelect(cmd_s, 100, lvMain);
			}
		}
		else if(tabSelection.SelectedData==1)//Payment
		{
			lvMain.SetRedraw(false);
			lvMain.Cols.DeleteAll();
			lvMain.Items.DeleteAll();
			//
			lvMain.Cols.Add(0, LVCFMT_LEFT, 200, L"Patient");
			lvMain.Cols.Add(1, LVCFMT_LEFT, 100, L"Date");
			lvMain.Cols.Add(2, LVCFMT_LEFT, 100, L"Procedure");
			lvMain.Cols.Add(3, LVCFMT_LEFT, 70, L"Tooth");
			lvMain.Cols.Add(4, LVCFMT_LEFT, 100, L"Type");
			lvMain.Cols.Add(5, LVCFMT_LEFT, 100, L"Username");
			lvMain.Cols.Add(6, LVCFMT_LEFT, 100, L"Amount");
			if(patient_id==-1)
			{
				conn.ExecuteSelect(L"SELECT transaction_id, patient_name, transaction_date, dental_procedure, tooth_code, transaction_type, username, amount FROM vw_transaction WHERE transaction_type_id=2", 100, lvMain);
			}
			else
			{
				wstring cmd_s;
				Sys::Format(cmd_s, L"SELECT transaction_id, patient_name, transaction_date, dental_procedure, tooth_code, transaction_type, username, amount FROM vw_transaction WHERE transaction_type_id=2 AND patient_id= %d", patient_id);
				conn.ExecuteSelect(cmd_s, 100, lvMain);
			}
		}
		else if(tabSelection.SelectedData==2)//Dental Procedure
		{
			lvMain.SetRedraw(false);
			lvMain.Cols.DeleteAll();
			lvMain.Items.DeleteAll();
			//
			lvMain.Cols.Add(0, LVCFMT_LEFT, 200, L"Patient");
			lvMain.Cols.Add(1, LVCFMT_LEFT, 100, L"Date");
			lvMain.Cols.Add(2, LVCFMT_LEFT, 100, L"Procedure");
			lvMain.Cols.Add(3, LVCFMT_LEFT, 100, L"Tooth");
			lvMain.Cols.Add(4, LVCFMT_LEFT, 150, L"Type");
			lvMain.Cols.Add(5, LVCFMT_LEFT, 100, L"Username");
			lvMain.Cols.Add(6, LVCFMT_LEFT, 100, L"Amount");
			if(patient_id==-1)
			{
				conn.ExecuteSelect(L"SELECT transaction_id, patient_name, transaction_date, dental_procedure, tooth_code, transaction_type, username, amount FROM vw_transaction WHERE transaction_type_id=1", 100, lvMain);
			}
			else
			{
				wstring cmd_s;
				Sys::Format(cmd_s, L"SELECT transaction_id, patient_name, transaction_date, dental_procedure, tooth_code, transaction_type, username, amount FROM vw_transaction WHERE transaction_type_id=1 AND patient_id= %d", patient_id);
				conn.ExecuteSelect(cmd_s, 100, lvMain);
			}
		}
		else if(tabSelection.SelectedData==3)//Procedure Setup
		{
			lvMain.SetRedraw(false);
			lvMain.Cols.DeleteAll();
			lvMain.Items.DeleteAll();
			//
			lvMain.Cols.Add(0, LVCFMT_LEFT, 100, L"Description");
			lvMain.Cols.Add(1, LVCFMT_RIGHT, 100, L"Est. Cost");
			lvMain.Cols.Add(2, LVCFMT_CENTER, 150, L"Body line color");
			lvMain.Cols.Add(3, LVCFMT_CENTER, 150, L"Body fill color");
			lvMain.Cols.Add(4, LVCFMT_CENTER, 150, L"Root line color");
			lvMain.Cols.Add(5, LVCFMT_CENTER, 150, L"Root fill color");
			conn.ExecuteSelect(L"SELECT dental_procedure_id, descr, ROUND(estimated_cost,2), body_line_color, body_fill_color, root_line_color, root_fill_color FROM vw_dental_procedure", 100, lvMain);
		}
		else if(tabSelection.SelectedData==4)//Users
		{
			lvMain.SetRedraw(false);
			lvMain.Cols.DeleteAll();
			lvMain.Items.DeleteAll();
			//
			lvMain.Cols.Add(0, LVCFMT_LEFT, 150, L"Username");
			lvMain.Cols.Add(1, LVCFMT_LEFT, 150, L"Password");
			lvMain.Cols.Add(2, LVCFMT_LEFT, 150, L"Last name");
			lvMain.Cols.Add(3, LVCFMT_LEFT, 150, L"First name");
			lvMain.Cols.Add(4, LVCFMT_LEFT, 100, L"Active");
			lvMain.Cols.Add(5, LVCFMT_LEFT, 100, L"Patient info");
			lvMain.Cols.Add(6, LVCFMT_LEFT, 100, L"Users");
			lvMain.Cols.Add(7, LVCFMT_LEFT, 100, L"Transactions");
			lvMain.Cols.Add(8, LVCFMT_LEFT, 100, L"Pacient Chart");
			lvMain.Cols.Add(9, LVCFMT_LEFT, 100, L"Proc. Setup");
			conn.ExecuteSelect(L"SELECT userz_id, username, passwordz, last_name, first_name, dbo.f_to_yesno(is_active) AS is_active, dbo.f_to_access(has_access_patient_info) AS has_access_patient_info, dbo.f_to_access(has_access_users) AS has_access_users, dbo.f_to_access(has_access_payments) AS has_access_payments, dbo.f_to_access(has_access_patient_chart) AS has_access_patient_chart, dbo.f_to_access(has_access_dental_procedure_setup) AS has_access_dental_procedure_setup FROM userz", 100, lvMain);
		}
		else return;
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	lvMain.SetRedraw(true);
	if(tabSelection.SelectedData== TAB_PATIENT_CHART) {updatePatientChart();};
}

void TeethX::deleteItem()
{
	toolbMain.EnableButton(IDM_DELETE,false);
	Win::HourGlassCursor hgc(true);
	const int selectedIndex= lvMain.GetSelectedIndex();
	if(selectedIndex<0) return; //_____________________________Nothing is selected
	//_________________________________________________________Ask the user
	if(this->MessageBox(L"Are you sure you want to delete the selected item?", L"Delete item",
		MB_YESNO|MB_ICONQUESTION)!=IDYES) return;
	//________________________________________________________Delete;
	Sql::SqlConnection conn;
	wstring cmd;
	const int item_id= lvMain.Items[selectedIndex].Data; //Get the Primary Key; 
	int rows = 0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if(tabSelection.SelectedData==0)
			{Sys::Format(cmd, L"DELETE FROM patient WHERE patient_id= %d", item_id);}
		else if(tabSelection.SelectedData==1)
			{Sys::Format(cmd, L"DELETE FROM transactionz WHERE transactionz_id= %d", item_id);}
		else if(tabSelection.SelectedData==2)
			Sys::Format(cmd, L"DELETE FROM transactionz WHERE transactionz_id= %d", item_id);
		else if(tabSelection.SelectedData==3)
			{Sys::Format(cmd, L"DELETE FROM dental_procedure WHERE dental_procedure_id= %d", item_id);}
		else if(tabSelection.SelectedData==4)
			{Sys::Format(cmd, L"DELETE FROM userz WHERE userz_id= %d", item_id);}
		rows = conn.ExecuteNonQuery(cmd);
		if (rows!=1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"ERROR: number of deleted rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException ex)
	{
		this->MessageBox(ex.GetDescription(), L"ERROR", MB_OK | MB_ICONERROR);
	}
	fillListView();
}

void TeethX::insertItem()
{
	toolbMain.EnableButton(IDM_INSERT,false);
	if(tabSelection.SelectedData==0)//Patient
	{
		PatientDlg dlg;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			fillListView();
		}
	}
	else if(tabSelection.SelectedData==1)//Payment
	{
		PaymentDlg dlg;
		dlg.userz_id= userz_id;
		dlg.patient_id= patient_id;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			fillListView();
		}
	}
	else if(tabSelection.SelectedData==2)//Patient Chart
	{
		wstring tooth_code;
		for(int i= 0; i<TOOTH_COUNT; i++)
		{
			if(tooth[i]->Selected==true)
			{
				tooth_code= tooth[i]->ToothCode;
				break;
			}
		}
		if(tooth_code.empty()==true)
		{
			this->MessageBoxW(L"Please select a tooth", L"TeethX", MB_OK|MB_ICONINFORMATION);
			return;
		}
		//
		TransactionDentalProcedureDlg dlg;
		dlg.patient_id= patient_id;
		dlg.userz_id= userz_id;
		dlg.tooth_code= tooth_code;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			//____________________________________________Unselect Tooth
			for(int i=0; i<TOOTH_COUNT; i++)
			{
				tooth[i]->Selected= false;
			}
			fillListView();
		}
	}
	else if(tabSelection.SelectedData==3)//Proc Setup
	{
		ProcedureSetupDlg dlg;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			fillListView();
		}
	}
	else if(tabSelection.SelectedData==4)//Users
	{
		UserDlg dlg;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			fillListView();
		}
	}

	//fillListView();
	toolbMain.EnableButton(IDM_INSERT,true);
}

void TeethX::editItem()
{
	toolbMain.EnableButton(IDM_EDIT,false);
	const int selectedIndex= lvMain.GetSelectedIndex();
	if(selectedIndex<0) return;
	//____________________________________________________Ask the user
	if(this->MessageBox(L"Are you sure you want to modify the selected item?", L"Edit item", 
		MB_YESNO|MB_ICONQUESTION)!=IDYES) return;
	//___________________________________________________Edit
	const int item_id= lvMain.Items[selectedIndex].Data;

	if(tabSelection.SelectedData==TAB_PATIENT)
	{
		PatientDlg dlg;
		dlg.patient_id= item_id;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			fillListView();
		}
	}
	else if(tabSelection.SelectedData==TAB_PAYMENT)
	{
		PaymentDlg dlg;
		dlg.transactionz_id= item_id;
		dlg.userz_id= userz_id;
		dlg.patient_id= patient_id;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			fillListView();
		}
	}
	else if(tabSelection.SelectedData==TAB_PATIENT_CHART)
	{
		wstring tooth_code;
		TransactionDentalProcedureDlg dlg;
		for(int i= 0; i<TOOTH_COUNT; i++)
		{
			if(tooth[i]->Selected==true)
			{
				tooth_code= tooth[i]->ToothCode;
				dlg.tooth_code= tooth_code;
				break;
			}
		}
		//
		/*TransactionDentalProcedureDlg dlg;*/
		dlg.transactionz_id= item_id;
		dlg.userz_id= userz_id;
		dlg.patient_id= patient_id;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			//____________________________________________Unselect Tooth
			for(int i=0; i<TOOTH_COUNT; i++)
			{
				tooth[i]->Selected= false;
			}
			fillListView();
		}
	}
	else if(tabSelection.SelectedData==TAB_PROCEDURE_SETUP)
	{
		ProcedureSetupDlg dlg;
		dlg.dental_procedure_id= item_id;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			fillListView();
		}
	}
	else if(tabSelection.SelectedData==TAB_USERS)
	{
		UserDlg dlg;
		dlg.userz_id= item_id;
		if(dlg.BeginDialog(hWnd)==TRUE)
		{
			fillListView();
		}
	}
	toolbMain.EnableButton(IDM_EDIT,true);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TeethX::tabSelection_SelChange(Win::Event& e)
{
	const int view= tabSelection.SelectedData;
	for(int i=0; i<TOOTH_COUNT; i++)
	{
		tooth[i]->Visible= (view==TAB_PATIENT_CHART);
	}
	//____________________________________________________Adjust Size
	Win::Event event;
	Window_Size(event);
	fillListView();
}

void TeethX::Cmd_Print(Win::Event& e)
{
	toolbMain.EnableButton(IDM_PRINT, false);
	//___________________________________________________Build document
	Win::PrintDoc doc;
	doc.Create(L"Dental");
	doc.Add(500,lvMain.Items.Count+1,lvMain);//0.5cm
	//___________________________________________________Print doc
	Win::PrintPreviewDlg dlg;
	dlg.BeginDialog_(hWnd, &doc);
	toolbMain.EnableButton(IDM_PRINT, true);
}

void TeethX::Cmd_Copy(Win::Event& e)
{
	toolbMain.EnableButton(IDM_COPY, false);
	lvMain.CopyToClipboard();
	toolbMain.EnableButton(IDM_COPY, true);
}

void TeethX::Cmd_Msexcel(Win::Event& e)
{
	toolbMain.EnableButton(IDM_MSEXCEL, false);
	Win::FileDlg filedlg;
	filedlg.Clear();
	filedlg.SetFilter(L"Excel Files(*.xlsx)\0*.xlsx\0All Files(*.*)\0*.*\0\0",0,L"xlsx");
	if(filedlg.BeginDialog(hWnd,L"Save a Ms Excel File", true))
	{
		lvMain.ExportToMsExcel(filedlg.GetFileNameFullPath());	
	}
	toolbMain.EnableButton(IDM_MSEXCEL, true);
	//______________________Line Before: ActiveSheet.Method(L"SaveAs", filename, result);
	//______________________ActiveSheet.Method(L"Paste");
	//Not nedeed in this project. ¿?
}

void TeethX::Cmd_Insert(Win::Event& e)
{
	insertItem();
	toolbMain.EnableButton(IDM_INSERT,true);
}

void TeethX::Cmd_Delete(Win::Event& e)
{
	deleteItem();
}

void TeethX::Cmd_Edit(Win::Event& e)
{
	editItem();
}

void TeethX::lvMain_ItemChanged(Win::Event& e)
{
	if(lvMain.GetSelectedIndex() >=0)
	{
		this->toolbMain.EnableButton(IDM_DELETE,true);
		this->toolbMain.EnableButton(IDM_EDIT,true);
	}
	else
	{
		this->toolbMain.EnableButton(IDM_DELETE,false);
		this->toolbMain.EnableButton(IDM_EDIT,false);
	}
}

void TeethX::lvMain_KeyDown(Win::Event& e)
{
	LPNMLVKEYDOWN p = (LPNMLVKEYDOWN) e.lParam;
	if (p->wVKey == VK_DELETE)
	{
		deleteItem();
	}
}

void TeethX::lvMain_DblClk(Win::Event& e)
{
	editItem();
}

void TeethX::Cmd_Save(Win::Event& e)
{
	this->MessageBoxW(L"Save", L"Save", MB_OK);
}

void TeethX::Cmd_Userz(Win::Event& e)
{
	toolbMain.EnableButton(IDM_USERZ, false);
	SelectPatientDlg dlg;
	if(dlg.BeginDialog(hWnd)==TRUE)
	{
		patient_id= dlg.patient_id;
		patient_name= dlg.patient_name;

		fillListView();
		this->Text= L"TeethX     Patient: ";
		this->Text+= patient_name;
	}
	toolbMain.EnableButton(IDM_USERZ, true);
	toolbMain.EnableButton(IDM_FIVE, true);
}

void TeethX::Cmd_Five(Win::Event& e)
{
	toolbMain.EnableButton(IDM_FIVE, false);
	//Clear Patient
	patient_id= -1;
	patient_name= L"";
	//
	fillListView();
	this->Text= L"TeethX";
}
void TeethX::Window_Size(Win::Event& e)
{
	const int view= tabSelection.SelectedData;
	const int offset= 4;
	const int half_height= height/2;
	const int toolbar_height= 24;
	const int tab_height= 24;
	const int lv_height= (view==TAB_PATIENT_CHART) ? half_height-toolbar_height-tab_height-offset : height-toolbar_height-tab_height-offset;
	const int tooth_width= (width-17*offset)/16;
	const int tooth_height= (half_height-2*offset)/2;
	int x= offset;
	int y= 0;

	toolbMain.Move(x,y,300,toolbar_height, true);
	y+= toolbar_height;
	//
	tabSelection.Move(x,y,width-2*offset,tab_height, true);
	y+= tab_height;
	//
	lvMain.Move(x,y,width-2*offset,lv_height,true);
	y+= lv_height+offset;
	//

	if(view==TAB_PATIENT_CHART)
	{
		//________________________________________________Place Teeth
		for(int i=0; i<TOOTH_COUNT; i++)
		{
			tooth[i]->Move(x,y,tooth_width,tooth_height,true);
			x+= tooth_width+offset;
			if(i==TOOTH_COUNT/2 -1)
			{
				x= offset;
				y+= tooth_height+offset;
			}
		}
	}
}

void TeethX::updatePatientChart()
{
	int i;
	//____________________________________________________Clear Patient Chart
	for(i=0; i<TOOTH_COUNT; i++)
	{
		tooth[i]->BodyFillColor= RGB(245,245,245);
		tooth[i]->BodyLineColor= RGB(70,70,70);
		tooth[i]->RootFillColor= RGB(245,245,245);
		tooth[i]->RootLineColor= RGB(70,70,70);
	}
	if(patient_id==-1) {return;}

	int body_line_color_red= 0;
	int body_line_color_green= 0;
	int body_line_color_blue= 0;
	int body_fill_color_red= 0;
	int body_fill_color_green= 0;
	int body_fill_color_blue= 0;
	//
	int root_line_color_red= 0;
	int root_line_color_green= 0;
	int root_line_color_blue= 0;
	int root_fill_color_red= 0;
	int root_fill_color_green= 0;
	int root_fill_color_blue= 0;

	Sql::SqlConnection conn;
	wstring tooth_code;
	wstring cmd;
	int count;
	try
	{
		//conn.OpenSession(DSN,USERNAME,PASSWORD);//Control Panel>Administrative Tools>Data Sources (ODBC)> Create dsn_myDB
		conn.OpenSession(hWnd,CONNECTION_STRING);
		for(i=0; i<TOOTH_COUNT;i++)
		{
			tooth_code= tooth[i]->ToothCode;
			//____________________________________________Check if the tooth has a procedure
			Sys::Format(cmd,L"SELECT count(*) FROM vw_transaction WHERE patient_id= %d AND tooth_code= '%s' AND transaction_type_id= 1", patient_id, tooth_code.c_str());
			count= conn.GetInt(cmd);
			if(count<=0) {continue;}
			//____________________________________________Get Colors (This SQL command must be modified to extract the maximum date that is less or equal than today)
			Sys::Format(cmd, L"SELECT root_line_color_red, root_line_color_green, root_line_color_blue, root_fill_color_red, root_fill_color_green, root_fill_color_blue, body_line_color_red, body_line_color_green, body_line_color_blue, body_fill_color_red, body_fill_color_green, body_fill_color_blue FROM vw_transaction WHERE patient_id= %d AND transaction_type_id=1 AND tooth_code= '%s'", patient_id, tooth_code.c_str());
			conn.ExecuteSelect(cmd);
			conn.BindColumn(1, root_line_color_red);
			conn.BindColumn(2, root_line_color_green);
			conn.BindColumn(3, root_line_color_blue);
			conn.BindColumn(4, root_fill_color_red);
			conn.BindColumn(5, root_fill_color_green);
			conn.BindColumn(6, root_fill_color_blue);
			conn.BindColumn(7, body_line_color_red);
			conn.BindColumn(8, body_line_color_green);
			conn.BindColumn(9, body_line_color_blue);
			conn.BindColumn(10, body_fill_color_red);
			conn.BindColumn(11, body_fill_color_green);
			conn.BindColumn(12, body_fill_color_blue);
			if(conn.Fetch()==true)
			{
				tooth[i]->BodyFillColor= RGB(body_fill_color_red,body_fill_color_green,body_fill_color_blue);
				tooth[i]->BodyLineColor= RGB(body_line_color_red,body_line_color_green,body_line_color_blue);
				tooth[i]->RootFillColor= RGB(root_fill_color_red,root_fill_color_green,root_fill_color_blue);
				tooth[i]->RootLineColor= RGB(root_line_color_red,root_line_color_green,root_line_color_blue);
			}
		}
	}
	catch(Sql::SqlException e)
	{
		this->MessageBoxW(e.GetDescription(), L"Error", MB_OK|MB_ICONERROR);
	}
}

void TeethX::customControl1_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl1.Selected==true)
	{
		customControl1.Selected= false;
	}
	else
	{
		customControl1.Selected= true;
	}
}

void TeethX::customControl2_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl2.Selected==true)
	{
		customControl2.Selected= false;
	}
	else
	{
		customControl2.Selected= true;
	}
}

void TeethX::customControl3_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl3.Selected==true)
	{
		customControl3.Selected= false;
	}
	else
	{
		customControl3.Selected= true;
	}
}

void TeethX::customControl4_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl4.Selected==true)
	{
		customControl4.Selected= false;
	}
	else
	{
		customControl4.Selected= true;
	}
}

void TeethX::customControl5_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl5.Selected==true)
	{
		customControl5.Selected= false;
	}
	else
	{
		customControl5.Selected= true;
	}
}

void TeethX::customControl6_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl6.Selected==true)
	{
		customControl6.Selected= false;
	}
	else
	{
		customControl6.Selected= true;
	}
}

void TeethX::customControl7_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl7.Selected==true)
	{
		customControl7.Selected= false;
	}
	else
	{
		customControl7.Selected= true;
	}
}

void TeethX::customControl8_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl8.Selected==true)
	{
		customControl8.Selected= false;
	}
	else
	{
		customControl8.Selected= true;
	}
}

void TeethX::customControl9_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl9.Selected==true)
	{
		customControl9.Selected= false;
	}
	else
	{
		customControl9.Selected= true;
	}
}

void TeethX::customControl10_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl10.Selected==true)
	{
		customControl10.Selected= false;
	}
	else
	{
		customControl10.Selected= true;
	}
}

void TeethX::customControl11_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl11.Selected==true)
	{
		customControl11.Selected= false;
	}
	else
	{
		customControl11.Selected= true;
	}
}

void TeethX::customControl12_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl12.Selected==true)
	{
		customControl12.Selected= false;
	}
	else
	{
		customControl12.Selected= true;
	}
}

void TeethX::customControl13_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl13.Selected==true)
	{
		customControl13.Selected= false;
	}
	else
	{
		customControl13.Selected= true;
	}
}

void TeethX::customControl14_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl14.Selected==true)
	{
		customControl14.Selected= false;
	}
	else
	{
		customControl14.Selected= true;
	}
}

void TeethX::customControl15_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl15.Selected==true)
	{
		customControl15.Selected= false;
	}
	else
	{
		customControl15.Selected= true;
	}
}

void TeethX::customControl16_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl16.Selected==true)
	{
		customControl16.Selected= false;
	}
	else
	{
		customControl16.Selected= true;
	}
}

void TeethX::customControl17_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl17.Selected==true)
	{
		customControl17.Selected= false;
	}
	else
	{
		customControl17.Selected= true;
	}
}

void TeethX::customControl18_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl18.Selected==true)
	{
		customControl18.Selected= false;
	}
	else
	{
		customControl18.Selected= true;
	}
}

void TeethX::customControl19_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl19.Selected==true)
	{
		customControl19.Selected= false;
	}
	else
	{
		customControl19.Selected= true;
	}
}

void TeethX::customControl20_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl20.Selected==true)
	{
		customControl20.Selected= false;
	}
	else
	{
		customControl20.Selected= true;
	}
}

void TeethX::customControl21_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl21.Selected==true)
	{
		customControl21.Selected= false;
	}
	else
	{
		customControl21.Selected= true;
	}
}

void TeethX::customControl22_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl22.Selected==true)
	{
		customControl22.Selected= false;
	}
	else
	{
		customControl22.Selected= true;
	}
}

void TeethX::customControl23_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl23.Selected==true)
	{
		customControl23.Selected= false;
	}
	else
	{
		customControl23.Selected= true;
	}
}

void TeethX::customControl24_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl24.Selected==true)
	{
		customControl24.Selected= false;
	}
	else
	{
		customControl24.Selected= true;
	}
}

void TeethX::customControl25_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl25.Selected==true)
	{
		customControl25.Selected= false;
	}
	else
	{
		customControl25.Selected= true;
	}
}

void TeethX::customControl26_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl26.Selected==true)
	{
		customControl26.Selected= false;
	}
	else
	{
		customControl26.Selected= true;
	}
}

void TeethX::customControl27_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl27.Selected==true)
	{
		customControl27.Selected= false;
	}
	else
	{
		customControl27.Selected= true;
	}
}

void TeethX::customControl28_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl28.Selected==true)
	{
		customControl28.Selected= false;
	}
	else
	{
		customControl28.Selected= true;
	}
}

void TeethX::customControl29_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl29.Selected==true)
	{
		customControl29.Selected= false;
	}
	else
	{
		customControl29.Selected= true;
	}
}

void TeethX::customControl30_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl30.Selected==true)
	{
		customControl30.Selected= false;
	}
	else
	{
		customControl30.Selected= true;
	}
}

void TeethX::customControl31_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl31.Selected==true)
	{
		customControl31.Selected= false;
	}
	else
	{
		customControl31.Selected= true;
	}
}

void TeethX::customControl32_Click(Win::Event& e)
{
	oneToothSelected();
	if(customControl32.Selected==true)
	{
		customControl32.Selected= false;
	}
	else
	{
		customControl32.Selected= true;
	}
}

void TeethX::oneToothSelected()
{
	customControl1.Selected= false;
	customControl2.Selected= false;
	customControl3.Selected= false;
	customControl4.Selected= false;
	customControl5.Selected= false;
	customControl6.Selected= false;
	customControl7.Selected= false;
	customControl8.Selected= false;
	customControl9.Selected= false;
	customControl10.Selected= false;
	customControl11.Selected= false;
	customControl12.Selected= false;
	customControl13.Selected= false;
	customControl14.Selected= false;
	customControl15.Selected= false;
	customControl16.Selected= false;
	customControl17.Selected= false;
	customControl18.Selected= false;
	customControl19.Selected= false;
	customControl20.Selected= false;
	customControl21.Selected= false;
	customControl22.Selected= false;
	customControl23.Selected= false;
	customControl24.Selected= false;
	customControl25.Selected= false;
	customControl26.Selected= false;
	customControl27.Selected= false;
	customControl28.Selected= false;
	customControl29.Selected= false;
	customControl30.Selected= false;
	customControl31.Selected= false;
	customControl32.Selected= false;
}
