#pragma once   //_____________________________________________ PaymentDlg.h  
#include "resource.h"

class PaymentDlg: public Win::Dialog
{
public:
	PaymentDlg()
	{
		transactionz_id= -1;
		patient_id= -1;
		userz_id= -1;
		//
		transaction_type_id= 2; //Payment
		dental_procedure_id= 1; //None
		tooth_id= 1; //0
	}
	~PaymentDlg()
	{
	}
	int transactionz_id;
	int patient_id;
	int userz_id;
	//
	int transaction_type_id;
	int dental_procedure_id;
	int tooth_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbPatient;
	Win::DropDownList ddPatient;
	Win::Label lbAmount;
	Win::Textbox tbxAmount;
	Win::Label lbComment;
	Win::Textbox tbxComment;
	Win::Button btOK;
	Win::Button btCancel;
	Win::Textbox tbxTransactionTypeID;
	Win::DateTimeBox dtboxTransactionDate;
	Win::Textbox tbxDentalProcedureID;
	Win::Textbox tbxToothID;
	Win::Textbox tbxUserzID;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(430);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(219);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbPatient.Create(NULL, L"Patient", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 18, 100, 25, hWnd, 1000);
		ddPatient.Create(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 120, 14, 200, 25, hWnd, 1001);
		lbAmount.Create(NULL, L"Amount", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 53, 100, 25, hWnd, 1002);
		tbxAmount.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 120, 49, 200, 25, hWnd, 1003);
		lbComment.Create(NULL, L"Comment", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10, 88, 100, 25, hWnd, 1004);
		tbxComment.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 120, 84, 200, 115, hWnd, 1005);
		btOK.Create(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 330, 10, 80, 28, hWnd, 1006);
		btCancel.Create(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 330, 49, 80, 28, hWnd, 1007);
		tbxTransactionTypeID.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_DISABLED | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 27, 119, 62, 25, hWnd, 1008);
		dtboxTransactionDate.Create(NULL, NULL, WS_CHILD | WS_DISABLED, 27, 133, 62, 16, hWnd, 1009);
		tbxDentalProcedureID.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_DISABLED | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 29, 151, 58, 25, hWnd, 1010);
		tbxToothID.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_DISABLED | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 30, 164, 58, 11, hWnd, 1011);
		tbxUserzID.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_DISABLED | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 29, 174, 62, 15, hWnd, 1012);
		this->SetDefaultButton(btOK);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lbPatient.Font = fontArial014A;
		ddPatient.Font = fontArial014A;
		lbAmount.Font = fontArial014A;
		tbxAmount.Font = fontArial014A;
		lbComment.Font = fontArial014A;
		tbxComment.Font = fontArial014A;
		btOK.Font = fontArial014A;
		btCancel.Font = fontArial014A;
		tbxTransactionTypeID.Font = fontArial014A;
		dtboxTransactionDate.Font = fontArial014A;
		tbxDentalProcedureID.Font = fontArial014A;
		tbxToothID.Font = fontArial014A;
		tbxUserzID.Font = fontArial014A;
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
