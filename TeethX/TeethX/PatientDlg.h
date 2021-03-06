#pragma once   //_____________________________________________ PatientDlg.h  
#include "resource.h"

class PatientDlg: public Win::Dialog
{
public:
	PatientDlg()
	{
		patient_id= -1;
	}
	~PatientDlg()
	{
	}
	int patient_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbFirst_name;
	Win::Textbox tbxFirst_name;
	Win::Label lbLast_name;
	Win::Textbox tbxLast_name;
	Win::Label lbBirth_date;
	Win::DateTimeBox dtboxBirth_date;
	Win::Label lbEmail;
	Win::Textbox tbxEmail;
	Win::Button btOK;
	Win::Button btCancel;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(430);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(164);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbFirst_name.Create(NULL, L"First name", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 14, 100, 25, hWnd, 1000);
		tbxFirst_name.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 10, 200, 25, hWnd, 1001);
		lbLast_name.Create(NULL, L"Last name", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 49, 100, 25, hWnd, 1002);
		tbxLast_name.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 45, 200, 25, hWnd, 1003);
		lbBirth_date.Create(NULL, L"Birth date", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 84, 100, 25, hWnd, 1004);
		dtboxBirth_date.Create(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 120, 80, 200, 25, hWnd, 1005);
		lbEmail.Create(NULL, L"Email", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 119, 100, 25, hWnd, 1006);
		tbxEmail.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 115, 200, 25, hWnd, 1007);
		btOK.Create(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 330, 10, 80, 28, hWnd, 1008);
		btCancel.Create(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 330, 49, 80, 28, hWnd, 1009);
		this->SetDefaultButton(btOK);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lbFirst_name.Font = fontArial014A;
		tbxFirst_name.Font = fontArial014A;
		lbLast_name.Font = fontArial014A;
		tbxLast_name.Font = fontArial014A;
		lbBirth_date.Font = fontArial014A;
		dtboxBirth_date.Font = fontArial014A;
		lbEmail.Font = fontArial014A;
		tbxEmail.Font = fontArial014A;
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
