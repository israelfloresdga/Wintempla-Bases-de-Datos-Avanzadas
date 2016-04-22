#include "stdafx.h"  //_____________________________________________ ProcedureSetupDlg.cpp
#include "ProcedureSetupDlg.h"

void ProcedureSetupDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Dental procedure";

	int root_line_color_red= 0;
	int root_line_color_green= 0;
	int root_line_color_blue= 0;
	int root_fill_color_red= 0;
	int root_fill_color_green= 0;
	int root_fill_color_blue= 0;
	int body_line_color_red= 0;
	int body_line_color_green= 0;
	int body_line_color_blue= 0;
	int body_fill_color_red= 0;
	int body_fill_color_green= 0;
	int body_fill_color_blue= 0;

	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (dental_procedure_id < 0) return;
		Sys::Format(cmd, L"SELECT descr, estimated_cost, root_line_color_red, root_line_color_green, root_line_color_blue, root_fill_color_red, root_fill_color_green, root_fill_color_blue, body_line_color_red, body_line_color_green, body_line_color_blue, body_fill_color_red, body_fill_color_green, body_fill_color_blue FROM dental_procedure WHERE dental_procedure_id=%d", dental_procedure_id);
		conn.ExecuteSelect(cmd);
		tbxDescr.MaxText = 32;
		conn.BindColumn(1, tbxDescr, 128);
		conn.BindColumn(2, tbxEstimated_cost, 128);
		conn.BindColumn(3, root_line_color_red);
		conn.BindColumn(4, root_line_color_green);
		conn.BindColumn(5, root_line_color_blue);
		conn.BindColumn(6, root_fill_color_red);
		conn.BindColumn(7, root_fill_color_green);
		conn.BindColumn(8, root_fill_color_blue);
		conn.BindColumn(9, body_line_color_red);
		conn.BindColumn(10, body_line_color_green);
		conn.BindColumn(11, body_line_color_blue);
		conn.BindColumn(12, body_fill_color_red);
		conn.BindColumn(13, body_fill_color_green);
		conn.BindColumn(14, body_fill_color_blue);
		if (conn.Fetch() == false)
		{
			this->MessageBox(L"No data was returned", L"Error", MB_OK);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	btRootLineColor.BackColor= RGB(root_line_color_red, root_line_color_green, root_line_color_blue);
	btRootFillColor.BackColor= RGB(root_fill_color_red, root_fill_color_green, root_fill_color_blue);
	btBodyLineColor.BackColor= RGB(body_line_color_red, body_line_color_green, body_line_color_blue);
	btBodyFillColor.BackColor= RGB(body_fill_color_red, body_fill_color_green, body_fill_color_blue);
}

void ProcedureSetupDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	tr1::wregex regexDouble(L"[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?");
	tr1::wregex regextbxDescr(L"[A-Za-z0-9]+");
	if (tr1::regex_match(tbxDescr.Text, regextbxDescr) == false)
	{
		tbxDescr.ShowBalloonTip(L"Invalid Descr", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	if (tr1::regex_match(tbxEstimated_cost.Text, regexDouble) == false)
	{
		tbxEstimated_cost.ShowBalloonTip(L"Invalid Estimated cost", L"Please provide a floating point value", TTI_ERROR);
		return;
	}
	//
	const int root_line_color_red= GetRValue(btRootLineColor.BackColor);
	const int root_line_color_green= GetGValue(btRootLineColor.BackColor);
	const int root_line_color_blue= GetBValue(btRootLineColor.BackColor);
	const int root_fill_color_red= GetRValue(btRootFillColor.BackColor);
	const int root_fill_color_green= GetGValue(btRootFillColor.BackColor);
	const int root_fill_color_blue= GetBValue(btRootFillColor.BackColor);

	const int body_line_color_red= GetRValue(btBodyLineColor.BackColor);
	const int body_line_color_green= GetGValue(btBodyLineColor.BackColor);
	const int body_line_color_blue= GetBValue(btBodyLineColor.BackColor);
	const int body_fill_color_red= GetRValue(btBodyFillColor.BackColor);
	const int body_fill_color_green= GetGValue(btBodyFillColor.BackColor);
	const int body_fill_color_blue= GetBValue(btBodyFillColor.BackColor);

	Sql::StringBuilder sb(L"dental_procedure", L"dental_procedure_id", dental_procedure_id);
	sb.Bind(L"descr", tbxDescr);
	sb.Bind(L"estimated_cost", tbxEstimated_cost);
	sb.BindInt(L"root_line_color_red", root_line_color_red);
	sb.BindInt(L"root_line_color_green", root_line_color_green);
	sb.BindInt(L"root_line_color_blue", root_line_color_blue);
	sb.BindInt(L"root_fill_color_red", root_fill_color_red);
	sb.BindInt(L"root_fill_color_green", root_fill_color_green);
	sb.BindInt(L"root_fill_color_blue", root_fill_color_blue);
	sb.BindInt(L"body_line_color_red", body_line_color_red);
	sb.BindInt(L"body_line_color_green", body_line_color_green);
	sb.BindInt(L"body_line_color_blue", body_line_color_blue);
	sb.BindInt(L"body_fill_color_red", body_fill_color_red);
	sb.BindInt(L"body_fill_color_green", body_fill_color_green);
	sb.BindInt(L"body_fill_color_blue", body_fill_color_blue);
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		rows = conn.ExecuteNonQuery(sb.GetString());
		if (rows!=1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of affected rows", MB_OK | MB_ICONERROR);
			return;
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	this->EndDialog(TRUE);
}

void ProcedureSetupDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

void ProcedureSetupDlg::btBodyLineColor_Click(Win::Event& e)
{
	colorDlg.SelectedColor= btBodyLineColor.BackColor;
	if(colorDlg.BeginDialog(hWnd)==TRUE)
	{
		btBodyLineColor.BackColor= colorDlg.SelectedColor;
	}
}

void ProcedureSetupDlg::btBodyLineColor_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	btBodyLineColor.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void ProcedureSetupDlg::btRootLineColor_Click(Win::Event& e)
{
	colorDlg.SelectedColor= btRootLineColor.BackColor;
	if(colorDlg.BeginDialog(hWnd)==TRUE)
	{
		btRootLineColor.BackColor= colorDlg.SelectedColor;
	}
}

void ProcedureSetupDlg::btRootLineColor_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	btRootLineColor.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void ProcedureSetupDlg::btBodyFillColor_Click(Win::Event& e)
{
	colorDlg.SelectedColor= btBodyFillColor.BackColor;
	if(colorDlg.BeginDialog(hWnd)==TRUE)
	{
		btBodyFillColor.BackColor= colorDlg.SelectedColor;
	}
}

void ProcedureSetupDlg::btBodyFillColor_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	btBodyFillColor.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void ProcedureSetupDlg::btRootFillColor_Click(Win::Event& e)
{
	colorDlg.SelectedColor= btRootFillColor.BackColor;
	if(colorDlg.BeginDialog(hWnd)==TRUE)
	{
		btRootFillColor.BackColor= colorDlg.SelectedColor;
	}
}

void ProcedureSetupDlg::btRootFillColor_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	btRootFillColor.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

