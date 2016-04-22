// Tooth.h                                     
#pragma once
#include "resource.h"

class Tooth: public Win::Window
{
public:
	Tooth();
	~Tooth();
	//____________________________________________________Font
	virtual void SetFont(Win::Gdi::Font &font);
	__declspec(property(put= SetFont)) Win::Gdi::Font &Font;
	//____________________________________________________Selected
	bool GetSelected();
	void SetSelected(bool selected);
	__declspec(property(get= GetSelected, put= SetSelected)) bool Selected;
	//____________________________________________________Tooth Code
	wstring GetToothCode();
	void SetToothCode(wstring type);
	__declspec(property(get= GetToothCode, put= SetToothCode)) wstring ToothCode;
	//____________________________________________________Body Line Color
	COLORREF GetBodyLineColor();
	void SetBodyLineColor(COLORREF color);
	__declspec(property(get= GetBodyLineColor, put= SetBodyLineColor)) COLORREF BodyLineColor;
	//____________________________________________________Body Fill Color
	COLORREF GetBodyFillColor();
	void SetBodyFillColor(COLORREF color);
	__declspec(property(get= GetBodyFillColor, put= SetBodyFillColor)) COLORREF BodyFillColor;
	//____________________________________________________Root Line Color
	COLORREF GetRootLineColor();
	void SetRootLineColor(COLORREF color);
	__declspec(property(get= GetRootLineColor, put= SetRootLineColor)) COLORREF RootLineColor;
	//____________________________________________________Root Fill Color
	COLORREF GetRootFillColor();
	void SetRootFillColor(COLORREF color);
	__declspec(property(get= GetRootFillColor, put= SetRootFillColor)) COLORREF RootFillColor;
	//____________________________________________________Is Upper
	bool GetIsUpper();
	void SetIsUpper(bool isUpper);
	__declspec(property(get= GetIsUpper, put= SetIsUpper)) bool IsUpper;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool IsEvent(Win::Event& e, int notification);
private:
	bool _selected;
	bool _has_focus;
	wstring _tooth_code;
	bool _is_upper;
	HFONT _hfont;
	COLORREF _body_line_color;
	COLORREF _body_fill_color;
	COLORREF _root_line_color;
	COLORREF _root_fill_color;
	//
	vector<Sys::Point2D> point_body_upper;
	POINT* _point_body_upper;
	int _point_body_upper_count;
	//
	vector<Sys::Point2D> point_body_lower;
	POINT* _point_body_lower;
	int _point_body_lower_count;
	//
	vector<Sys::Point2D> point_root_upper;
	POINT* _point_root_upper;
	int _point_root_upper_count;
	//
	vector<Sys::Point2D> point_root_lower;
	POINT* _point_root_lower;
	int _point_root_lower_count;
	//
	float _svgWidth;
	float _svgHeight;
	//___________________________________________________Double Buffering
	Win::DDBitmap bitmap;
	void OnPaintControl(Win::Gdi &gdi);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	const wchar_t * GetClassName(void){return L"TOOTH";}
	static bool isRegistered;
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
protected:
	void GetWindowInformation(CREATESTRUCT& createStruct)
	{
		createStruct.style = WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW;
	}
	//_________________________________________________
	void InitializeGui()
	{
	}
	//_________________________________________________
	void Window_KillFocus(Win::Event& e);
	void Window_LButtonDown(Win::Event& e);
	void Window_Open(Win::Event& e);
	void Window_Paint(Win::Event& e);
	void Window_SetFocus(Win::Event& e);
	void Window_Size(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		return false;
	}
};
