#pragma once   //_____________________________________________ TransactionDentalProcedureDlg.h  
#include "resource.h"

class TransactionDentalProcedureDlg: public Win::Dialog
{
public:
	TransactionDentalProcedureDlg()
	{
		transactionz_id= -1;
		patient_id= -1;
		userz_id= -1;
		dental_procedure_id= -1;
		tooth_id= -1;
		//
		transaction_type_id= 1; //Dental Procedure
	}
	~TransactionDentalProcedureDlg()
	{
	}
	int transactionz_id;
	int patient_id;
	int userz_id;
	int dental_procedure_id;
	int tooth_id;
	wstring tooth_code;
	void updateEstimatedCost();
	//
	int transaction_type_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbPatient;
	Win::DropDownList ddPatient;
	Win::Label lbDental_procedure;
	Win::DropDownList ddDental_procedure;
	Win::Label lbAmount;
	Win::Textbox tbxAmount;
	Win::Label lbComment;
	Win::Textbox tbxComment;
	Win::Button btOK;
	Win::Button btCancel;
	Win::Textbox tbxTransactionTypeID;
	Win::DateTimeBox dtboxTransactionDate;
	Win::Textbox tbxUserzID;
	Win::Textbox tbxToothID;
protected:
	Win::Gdi::Font fontArial014A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx = Sys::Convert::PixelToDlgUnitX(464);
		dlgTemplate.cy = Sys::Convert::PixelToDlgUnitY(166);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbPatient.Create(NULL, L"Patient", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 11, 16, 111, 25, hWnd, 1000);
		ddPatient.Create(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 133, 12, 221, 25, hWnd, 1001);
		lbDental_procedure.Create(NULL, L"Dental procedure", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 11, 51, 111, 25, hWnd, 1002);
		ddDental_procedure.Create(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 133, 47, 221, 25, hWnd, 1003);
		lbAmount.Create(NULL, L"Amount", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 11, 86, 111, 25, hWnd, 1004);
		tbxAmount.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 133, 82, 221, 25, hWnd, 1005);
		lbComment.Create(NULL, L"Comment", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 11, 121, 111, 25, hWnd, 1006);
		tbxComment.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 133, 117, 221, 25, hWnd, 1007);
		btOK.Create(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 364, 11, 80, 28, hWnd, 1008);
		btCancel.Create(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 364, 50, 80, 28, hWnd, 1009);
		tbxTransactionTypeID.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_DISABLED | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 376, 85, 59, 9, hWnd, 1010);
		dtboxTransactionDate.Create(NULL, NULL, WS_CHILD | WS_DISABLED, 376, 97, 59, 11, hWnd, 1011);
		tbxUserzID.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_DISABLED | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 378, 131, 51, 11, hWnd, 1012);
		tbxToothID.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_DISABLED | ES_LEFT | ES_WINNORMALCASE, 375, 110, 62, 12, hWnd, 1013);
		this->SetDefaultButton(btOK);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lbPatient.Font = fontArial014A;
		ddPatient.Font = fontArial014A;
		lbDental_procedure.Font = fontArial014A;
		ddDental_procedure.Font = fontArial014A;
		lbAmount.Font = fontArial014A;
		tbxAmount.Font = fontArial014A;
		lbComment.Font = fontArial014A;
		tbxComment.Font = fontArial014A;
		btOK.Font = fontArial014A;
		btCancel.Font = fontArial014A;
		tbxTransactionTypeID.Font = fontArial014A;
		dtboxTransactionDate.Font = fontArial014A;
		tbxUserzID.Font = fontArial014A;
		tbxToothID.Font = fontArial014A;
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
