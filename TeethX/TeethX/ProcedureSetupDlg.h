#pragma once   //_____________________________________________ ProcedureSetupDlg.h  
#include "resource.h"

class ProcedureSetupDlg: public Win::Dialog
{
public:
	ProcedureSetupDlg()
	{
		dental_procedure_id= -1;
	}
	~ProcedureSetupDlg()
	{
	}
	int dental_procedure_id;
	Win::ColorDlg colorDlg;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbDescr;
	Win::Textbox tbxDescr;
	Win::Label lbEstimated_cost;
	Win::Textbox tbxEstimated_cost;
	Win::Button btOK;
	Win::Button btCancel;
	Win::Button btBodyLineColor;
	Win::Button btRootLineColor;
	Win::Button btBodyFillColor;
	Win::Button btRootFillColor;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(430);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(190);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbDescr.Create(NULL, L"Description", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 14, 100, 25, hWnd, 1000);
		tbxDescr.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 10, 200, 25, hWnd, 1001);
		lbEstimated_cost.Create(NULL, L"Estimated cost", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 49, 100, 25, hWnd, 1002);
		tbxEstimated_cost.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 45, 200, 25, hWnd, 1003);
		btOK.Create(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 330, 10, 80, 28, hWnd, 1004);
		btCancel.Create(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 330, 49, 80, 28, hWnd, 1005);
		btBodyLineColor.Create(NULL, L"Body Line Color", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 42, 94, 114, 30, hWnd, 1006);
		btRootLineColor.Create(NULL, L"Root Line Color", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 42, 140, 114, 30, hWnd, 1007);
		btBodyFillColor.Create(NULL, L"Body Fill Color", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 170, 94, 114, 30, hWnd, 1008);
		btRootFillColor.Create(NULL, L"Root Fill Color", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 170, 140, 114, 30, hWnd, 1009);
		this->SetDefaultButton(btOK);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lbDescr.Font = fontArial014A;
		tbxDescr.Font = fontArial014A;
		lbEstimated_cost.Font = fontArial014A;
		tbxEstimated_cost.Font = fontArial014A;
		btOK.Font = fontArial014A;
		btCancel.Font = fontArial014A;
		btBodyLineColor.Font = fontArial014A;
		btRootLineColor.Font = fontArial014A;
		btBodyFillColor.Font = fontArial014A;
		btRootFillColor.Font = fontArial014A;
	}
	//_________________________________________________
	void btOK_Click(Win::Event& e);
	void btCancel_Click(Win::Event& e);
	void btBodyLineColor_Click(Win::Event& e);
	void btBodyLineColor_DrawItem(Win::Event& e);
	void btRootLineColor_Click(Win::Event& e);
	void btRootLineColor_DrawItem(Win::Event& e);
	void btBodyFillColor_Click(Win::Event& e);
	void btBodyFillColor_DrawItem(Win::Event& e);
	void btRootFillColor_Click(Win::Event& e);
	void btRootFillColor_DrawItem(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btOK.IsEvent(e, BN_CLICKED)) {btOK_Click(e); return true;}
		if (btCancel.IsEvent(e, BN_CLICKED)) {btCancel_Click(e); return true;}
		if (btBodyLineColor.IsEvent(e, BN_CLICKED)) {btBodyLineColor_Click(e); return true;}
		if (btBodyLineColor.IsEvent(e, WM_DRAWITEM)) {btBodyLineColor_DrawItem(e); return true;}
		if (btRootLineColor.IsEvent(e, BN_CLICKED)) {btRootLineColor_Click(e); return true;}
		if (btRootLineColor.IsEvent(e, WM_DRAWITEM)) {btRootLineColor_DrawItem(e); return true;}
		if (btBodyFillColor.IsEvent(e, BN_CLICKED)) {btBodyFillColor_Click(e); return true;}
		if (btBodyFillColor.IsEvent(e, WM_DRAWITEM)) {btBodyFillColor_DrawItem(e); return true;}
		if (btRootFillColor.IsEvent(e, BN_CLICKED)) {btRootFillColor_Click(e); return true;}
		if (btRootFillColor.IsEvent(e, WM_DRAWITEM)) {btRootFillColor_DrawItem(e); return true;}
		return false;
	}
};
