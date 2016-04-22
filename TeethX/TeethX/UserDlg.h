#pragma once   //_____________________________________________ UserDlg.h  
#include "resource.h"

class UserDlg: public Win::Dialog
{
public:
	UserDlg()
	{
		userz_id= -1;
	}
	~UserDlg()
	{
	}
	int userz_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbUsername;
	Win::Textbox tbxUsername;
	Win::Label lbFirst_name;
	Win::Textbox tbxFirst_name;
	Win::Label lbLast_name;
	Win::Textbox tbxLast_name;
	Win::Label lbPasswordz;
	Win::Textbox tbxPasswordz;
	Win::Label lbEmail;
	Win::Textbox tbxEmail;
	Win::Button ckIs_active;
	Win::Button ckHas_access_patient_info;
	Win::Button ckHas_access_users;
	Win::Button ckHas_access_payments;
	Win::Button ckHas_access_patient_chart;
	Win::Button ckHas_access_dental_procedure_setup;
	Win::Button btOK;
	Win::Button btCancel;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(430);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(411);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbUsername.Create(NULL, L"Username", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 14, 100, 25, hWnd, 1000);
		tbxUsername.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 10, 200, 25, hWnd, 1001);
		lbFirst_name.Create(NULL, L"First name", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 49, 100, 25, hWnd, 1002);
		tbxFirst_name.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 45, 200, 25, hWnd, 1003);
		lbLast_name.Create(NULL, L"Last name", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 84, 100, 25, hWnd, 1004);
		tbxLast_name.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 80, 200, 25, hWnd, 1005);
		lbPasswordz.Create(NULL, L"Password", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 119, 100, 25, hWnd, 1006);
		tbxPasswordz.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 115, 200, 25, hWnd, 1007);
		lbEmail.Create(NULL, L"Email", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 154, 100, 25, hWnd, 1008);
		tbxEmail.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 150, 200, 25, hWnd, 1009);
		ckIs_active.Create(NULL, L"Is active", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 120, 185, 200, 26, hWnd, 1010);
		ckHas_access_patient_info.Create(NULL, L"Has access patient info", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 120, 221, 200, 26, hWnd, 1011);
		ckHas_access_users.Create(NULL, L"Has access users", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 120, 257, 200, 26, hWnd, 1012);
		ckHas_access_payments.Create(NULL, L"Has access payments", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 120, 293, 200, 26, hWnd, 1013);
		ckHas_access_patient_chart.Create(NULL, L"Has access patient chart", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 120, 329, 200, 26, hWnd, 1014);
		ckHas_access_dental_procedure_setup.Create(NULL, L"Has access dental procedure setup", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_AUTOCHECKBOX | BS_LEFT | BS_VCENTER, 120, 365, 200, 26, hWnd, 1015);
		btOK.Create(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 330, 10, 80, 28, hWnd, 1016);
		btCancel.Create(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 330, 49, 80, 28, hWnd, 1017);
		this->SetDefaultButton(btOK);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lbUsername.Font = fontArial014A;
		tbxUsername.Font = fontArial014A;
		lbFirst_name.Font = fontArial014A;
		tbxFirst_name.Font = fontArial014A;
		lbLast_name.Font = fontArial014A;
		tbxLast_name.Font = fontArial014A;
		lbPasswordz.Font = fontArial014A;
		tbxPasswordz.Font = fontArial014A;
		lbEmail.Font = fontArial014A;
		tbxEmail.Font = fontArial014A;
		ckIs_active.Font = fontArial014A;
		ckHas_access_patient_info.Font = fontArial014A;
		ckHas_access_users.Font = fontArial014A;
		ckHas_access_payments.Font = fontArial014A;
		ckHas_access_patient_chart.Font = fontArial014A;
		ckHas_access_dental_procedure_setup.Font = fontArial014A;
		btOK.Font = fontArial014A;
		btCancel.Font = fontArial014A;
	}
	//_________________________________________________
	void btOK_Click(Win::Event& e);
	void btCancel_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btOK.IsEvent(e, BN_CLICKED)) {btOK_Click(e); return true;}
		if (btCancel.IsEvent(e, BN_CLICKED)) {btCancel_Click(e); return true;}
		return false;
	}
};
