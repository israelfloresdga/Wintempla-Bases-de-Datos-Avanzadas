#pragma once   //_____________________________________________ SelectPatientDlg.h  
#include "resource.h"

class SelectPatientDlg: public Win::Dialog
{
public:
	SelectPatientDlg()
	{
		patient_id= -1;
		patient_name= L"";
	}
	~SelectPatientDlg()
	{
	}
	int patient_id;
	wstring patient_name;
	void GetPatientName(int patient_id);
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::ListView lvPatient;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(534);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(454);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lvPatient.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_ALIGNLEFT | LVS_SINGLESEL | LVS_REPORT, 21, 22, 493, 412, hWnd, 1000);
		lvPatient.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lvPatient.Font = fontArial014A;
		lvPatient.SetDock(DOCK_BORDER, DOCK_BORDER, DOCK_BORDER, DOCK_BORDER);
	}
	//_________________________________________________
	void lvPatient_ItemActivate(Win::Event& e);
	void lvPatient_KeyDown(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lvPatient.IsEvent(e, LVN_ITEMACTIVATE)) {lvPatient_ItemActivate(e); return true;}
		if (lvPatient.IsEvent(e, LVN_KEYDOWN)) {lvPatient_KeyDown(e); return true;}
		return false;
	}
};
