#pragma once  //______________________________________ TeethX.h  
#include "Resource.h"
#include "LoginDlg.h"
#include "PatientDlg.h"
#include "ProcedureSetupDlg.h"
#include "PaymentDlg.h"
#include "UserDlg.h"
#include "SelectPatientDlg.h"
#include "TransactionDentalProcedureDlg.h"
#include "Tooth.h"

#define TAB_PATIENT 0
#define	TAB_PAYMENT 1
#define TAB_PATIENT_CHART 2
#define TAB_PROCEDURE_SETUP 3
#define TAB_USERS 4
//
#define TOOTH_COUNT 32

class TeethX: public Win::Window
{
public:
	TeethX()
	{
		userz_id= -1;
		patient_id=-1;
		patient_name= L"";
		//
		tooth[0]= &customControl1;
		tooth[1]= &customControl2;
		tooth[2]= &customControl3;
		tooth[3]= &customControl4;
		tooth[4]= &customControl5;
		tooth[5]= &customControl6;
		tooth[6]= &customControl7;
		tooth[7]= &customControl8;
		tooth[8]= &customControl9;
		tooth[9]= &customControl10;
		tooth[10]= &customControl11;
		tooth[11]= &customControl12;
		tooth[12]= &customControl13;
		tooth[13]= &customControl14;
		tooth[14]= &customControl15;
		tooth[15]= &customControl16;
		tooth[16]= &customControl17;
		tooth[17]= &customControl18;
		tooth[18]= &customControl19;
		tooth[19]= &customControl20;
		tooth[20]= &customControl21;
		tooth[21]= &customControl22;
		tooth[22]= &customControl23;
		tooth[23]= &customControl24;
		tooth[24]= &customControl25;
		tooth[25]= &customControl26;
		tooth[26]= &customControl27;
		tooth[27]= &customControl28;
		tooth[28]= &customControl29;
		tooth[29]= &customControl30;
		tooth[30]= &customControl31;
		tooth[31]= &customControl32;
	}
	~TeethX()
	{
	}
	int userz_id;
	int patient_id;
	wstring patient_name;
	Tooth* tooth[TOOTH_COUNT];
	void fillTabSelection();
	void fillListView();
	void enableButtons();
	void deleteItem();
	void insertItem();
	void editItem();
	void refreshTooth();
	void updatePatientChart();
	void oneToothSelected();
	const wchar_t * GetClassName(){return L"TEETHX";}
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::ListView lvMain;
	Win::Toolbar toolbMain;
	Win::Tab tabSelection;
	Tooth customControl1;
	Tooth customControl2;
	Tooth customControl3;
	Tooth customControl4;
	Tooth customControl5;
	Tooth customControl6;
	Tooth customControl7;
	Tooth customControl8;
	Tooth customControl9;
	Tooth customControl10;
	Tooth customControl11;
	Tooth customControl12;
	Tooth customControl13;
	Tooth customControl14;
	Tooth customControl15;
	Tooth customControl16;
	Tooth customControl17;
	Tooth customControl18;
	Tooth customControl19;
	Tooth customControl20;
	Tooth customControl21;
	Tooth customControl22;
	Tooth customControl23;
	Tooth customControl24;
	Tooth customControl25;
	Tooth customControl26;
	Tooth customControl27;
	Tooth customControl28;
	Tooth customControl29;
	Tooth customControl30;
	Tooth customControl31;
	Tooth customControl32;
protected:
	Win::Gdi::Font fontArial014A;
	void GetWindowInformation(CREATESTRUCT& createStruct)
	{
		createStruct.style = WS_CLIPCHILDREN | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_OVERLAPPEDWINDOW | WS_THICKFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"TeethX";
		lvMain.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_ALIGNLEFT | LVS_SINGLESEL | LVS_REPORT, 12, 80, 782, 222, hWnd, 1000);
		toolbMain.Create(NULL, NULL, WS_CHILD | WS_VISIBLE | CCS_NORESIZE | CCS_NOPARENTALIGN | CCS_ADJUSTABLE | CCS_NODIVIDER | TBSTYLE_FLAT | TBSTYLE_TOOLTIPS, 12, 8, 782, 25, hWnd, 1001);
		tabSelection.Create(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT, 12, 42, 782, 25, hWnd, 1002);
		customControl1.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 12, 312, 46, 77, hWnd, 1003);
		customControl2.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 61, 312, 46, 77, hWnd, 1004);
		customControl3.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 110, 312, 46, 77, hWnd, 1005);
		customControl4.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 158, 312, 46, 77, hWnd, 1006);
		customControl5.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 208, 312, 46, 77, hWnd, 1007);
		customControl6.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 258, 312, 46, 77, hWnd, 1008);
		customControl7.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 306, 312, 46, 77, hWnd, 1009);
		customControl8.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 355, 312, 46, 77, hWnd, 1010);
		customControl9.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 404, 312, 46, 77, hWnd, 1011);
		customControl10.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 453, 312, 46, 77, hWnd, 1012);
		customControl11.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 502, 312, 46, 77, hWnd, 1013);
		customControl12.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 551, 312, 46, 77, hWnd, 1014);
		customControl13.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 601, 312, 46, 77, hWnd, 1015);
		customControl14.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 650, 312, 46, 77, hWnd, 1016);
		customControl15.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 699, 312, 46, 77, hWnd, 1017);
		customControl16.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 748, 312, 46, 77, hWnd, 1018);
		customControl17.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 12, 391, 46, 77, hWnd, 1019);
		customControl18.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 61, 391, 46, 77, hWnd, 1020);
		customControl19.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 110, 391, 46, 77, hWnd, 1021);
		customControl20.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 158, 391, 46, 77, hWnd, 1022);
		customControl21.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 208, 391, 46, 77, hWnd, 1023);
		customControl22.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 258, 391, 46, 77, hWnd, 1024);
		customControl23.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 306, 391, 46, 77, hWnd, 1025);
		customControl24.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 355, 391, 46, 77, hWnd, 1026);
		customControl25.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 404, 391, 46, 77, hWnd, 1027);
		customControl26.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 453, 391, 46, 77, hWnd, 1028);
		customControl27.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 502, 391, 46, 77, hWnd, 1029);
		customControl28.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 551, 391, 46, 77, hWnd, 1030);
		customControl29.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 601, 391, 46, 77, hWnd, 1031);
		customControl30.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 650, 391, 46, 77, hWnd, 1032);
		customControl31.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 699, 391, 46, 77, hWnd, 1033);
		customControl32.Create(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE, 748, 391, 46, 77, hWnd, 1034);
		lvMain.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial014A.Create(L"Arial", 14, false, false, false, false);
		lvMain.Font = fontArial014A;
		tabSelection.Font = fontArial014A;
		customControl1.Font = fontArial014A;
		customControl2.Font = fontArial014A;
		customControl3.Font = fontArial014A;
		customControl4.Font = fontArial014A;
		customControl5.Font = fontArial014A;
		customControl6.Font = fontArial014A;
		customControl7.Font = fontArial014A;
		customControl8.Font = fontArial014A;
		customControl9.Font = fontArial014A;
		customControl10.Font = fontArial014A;
		customControl11.Font = fontArial014A;
		customControl12.Font = fontArial014A;
		customControl13.Font = fontArial014A;
		customControl14.Font = fontArial014A;
		customControl15.Font = fontArial014A;
		customControl16.Font = fontArial014A;
		customControl17.Font = fontArial014A;
		customControl18.Font = fontArial014A;
		customControl19.Font = fontArial014A;
		customControl20.Font = fontArial014A;
		customControl21.Font = fontArial014A;
		customControl22.Font = fontArial014A;
		customControl23.Font = fontArial014A;
		customControl24.Font = fontArial014A;
		customControl25.Font = fontArial014A;
		customControl26.Font = fontArial014A;
		customControl27.Font = fontArial014A;
		customControl28.Font = fontArial014A;
		customControl29.Font = fontArial014A;
		customControl30.Font = fontArial014A;
		customControl31.Font = fontArial014A;
		customControl32.Font = fontArial014A;
		lvMain.SetDock(DOCK_BORDER, DOCK_BORDER, DOCK_BORDER, DOCK_BORDER);
		toolbMain.SetDock(DOCK_BORDER, DOCK_BORDER, DOCK_BORDER, DOCK_NONE);
		tabSelection.SetDock(DOCK_BORDER, DOCK_BORDER, DOCK_BORDER, DOCK_NONE);
		customControl1.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl2.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl3.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl4.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl5.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl6.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl7.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl8.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl9.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl10.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl11.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl12.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl13.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl14.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl15.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl16.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl17.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl18.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl19.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl20.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl21.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl22.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl23.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl24.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl25.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl26.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl27.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl28.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl29.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl30.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl31.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
		customControl32.SetDock(DOCK_CENTER, DOCK_CENTER, DOCK_CENTER, DOCK_BORDER);
	}
	//_________________________________________________
	void lvMain_ItemChanged(Win::Event& e);
	void lvMain_KeyDown(Win::Event& e);
	void lvMain_DblClk(Win::Event& e);
	void tabSelection_SelChange(Win::Event& e);
	void customControl1_Click(Win::Event& e);
	void customControl2_Click(Win::Event& e);
	void customControl3_Click(Win::Event& e);
	void customControl4_Click(Win::Event& e);
	void customControl5_Click(Win::Event& e);
	void customControl6_Click(Win::Event& e);
	void customControl7_Click(Win::Event& e);
	void customControl8_Click(Win::Event& e);
	void customControl9_Click(Win::Event& e);
	void customControl10_Click(Win::Event& e);
	void customControl11_Click(Win::Event& e);
	void customControl12_Click(Win::Event& e);
	void customControl13_Click(Win::Event& e);
	void customControl14_Click(Win::Event& e);
	void customControl15_Click(Win::Event& e);
	void customControl16_Click(Win::Event& e);
	void customControl17_Click(Win::Event& e);
	void customControl18_Click(Win::Event& e);
	void customControl19_Click(Win::Event& e);
	void customControl20_Click(Win::Event& e);
	void customControl21_Click(Win::Event& e);
	void customControl22_Click(Win::Event& e);
	void customControl23_Click(Win::Event& e);
	void customControl24_Click(Win::Event& e);
	void customControl25_Click(Win::Event& e);
	void customControl26_Click(Win::Event& e);
	void customControl27_Click(Win::Event& e);
	void customControl28_Click(Win::Event& e);
	void customControl29_Click(Win::Event& e);
	void customControl30_Click(Win::Event& e);
	void customControl31_Click(Win::Event& e);
	void customControl32_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	void Window_Size(Win::Event& e);
	void Cmd_Print(Win::Event& e);
	void Cmd_Save(Win::Event& e);
	void Cmd_Insert(Win::Event& e);
	void Cmd_Delete(Win::Event& e);
	void Cmd_Edit(Win::Event& e);
	void Cmd_Copy(Win::Event& e);
	void Cmd_Msexcel(Win::Event& e);
	void Cmd_Userz(Win::Event& e);
	void Cmd_Five(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lvMain.IsEvent(e, LVN_ITEMCHANGED)) {lvMain_ItemChanged(e); return true;}
		if (lvMain.IsEvent(e, LVN_KEYDOWN)) {lvMain_KeyDown(e); return true;}
		if (lvMain.IsEvent(e, NM_DBLCLK)) {lvMain_DblClk(e); return true;}
		if (tabSelection.IsEvent(e, TCN_SELCHANGE)) {tabSelection_SelChange(e); return true;}
		if (customControl1.IsEvent(e, WIN_CLICK)) {customControl1_Click(e); return true;}
		if (customControl2.IsEvent(e, WIN_CLICK)) {customControl2_Click(e); return true;}
		if (customControl3.IsEvent(e, WIN_CLICK)) {customControl3_Click(e); return true;}
		if (customControl4.IsEvent(e, WIN_CLICK)) {customControl4_Click(e); return true;}
		if (customControl5.IsEvent(e, WIN_CLICK)) {customControl5_Click(e); return true;}
		if (customControl6.IsEvent(e, WIN_CLICK)) {customControl6_Click(e); return true;}
		if (customControl7.IsEvent(e, WIN_CLICK)) {customControl7_Click(e); return true;}
		if (customControl8.IsEvent(e, WIN_CLICK)) {customControl8_Click(e); return true;}
		if (customControl9.IsEvent(e, WIN_CLICK)) {customControl9_Click(e); return true;}
		if (customControl10.IsEvent(e, WIN_CLICK)) {customControl10_Click(e); return true;}
		if (customControl11.IsEvent(e, WIN_CLICK)) {customControl11_Click(e); return true;}
		if (customControl12.IsEvent(e, WIN_CLICK)) {customControl12_Click(e); return true;}
		if (customControl13.IsEvent(e, WIN_CLICK)) {customControl13_Click(e); return true;}
		if (customControl14.IsEvent(e, WIN_CLICK)) {customControl14_Click(e); return true;}
		if (customControl15.IsEvent(e, WIN_CLICK)) {customControl15_Click(e); return true;}
		if (customControl16.IsEvent(e, WIN_CLICK)) {customControl16_Click(e); return true;}
		if (customControl17.IsEvent(e, WIN_CLICK)) {customControl17_Click(e); return true;}
		if (customControl18.IsEvent(e, WIN_CLICK)) {customControl18_Click(e); return true;}
		if (customControl19.IsEvent(e, WIN_CLICK)) {customControl19_Click(e); return true;}
		if (customControl20.IsEvent(e, WIN_CLICK)) {customControl20_Click(e); return true;}
		if (customControl21.IsEvent(e, WIN_CLICK)) {customControl21_Click(e); return true;}
		if (customControl22.IsEvent(e, WIN_CLICK)) {customControl22_Click(e); return true;}
		if (customControl23.IsEvent(e, WIN_CLICK)) {customControl23_Click(e); return true;}
		if (customControl24.IsEvent(e, WIN_CLICK)) {customControl24_Click(e); return true;}
		if (customControl25.IsEvent(e, WIN_CLICK)) {customControl25_Click(e); return true;}
		if (customControl26.IsEvent(e, WIN_CLICK)) {customControl26_Click(e); return true;}
		if (customControl27.IsEvent(e, WIN_CLICK)) {customControl27_Click(e); return true;}
		if (customControl28.IsEvent(e, WIN_CLICK)) {customControl28_Click(e); return true;}
		if (customControl29.IsEvent(e, WIN_CLICK)) {customControl29_Click(e); return true;}
		if (customControl30.IsEvent(e, WIN_CLICK)) {customControl30_Click(e); return true;}
		if (customControl31.IsEvent(e, WIN_CLICK)) {customControl31_Click(e); return true;}
		if (customControl32.IsEvent(e, WIN_CLICK)) {customControl32_Click(e); return true;}
		if (this->IsEvent(e, IDM_PRINT)) {Cmd_Print(e); return true;}
		if (this->IsEvent(e, IDM_SAVE)) {Cmd_Save(e); return true;}
		if (this->IsEvent(e, IDM_INSERT)) {Cmd_Insert(e); return true;}
		if (this->IsEvent(e, IDM_DELETE)) {Cmd_Delete(e); return true;}
		if (this->IsEvent(e, IDM_EDIT)) {Cmd_Edit(e); return true;}
		if (this->IsEvent(e, IDM_COPY)) {Cmd_Copy(e); return true;}
		if (this->IsEvent(e, IDM_MSEXCEL)) {Cmd_Msexcel(e); return true;}
		if (this->IsEvent(e, IDM_USERZ)) {Cmd_Userz(e); return true;}
		if (this->IsEvent(e, IDM_FIVE)) {Cmd_Five(e); return true;}
		return false;
	}
};
