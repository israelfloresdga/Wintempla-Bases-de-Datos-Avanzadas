// Tooth.cpp
#include "stdafx.h"
#include "Tooth.h"

bool Tooth::isRegistered= false;

Tooth::Tooth()
{	
	if (!this->isRegistered)
	{
		 
		this->RegisterClassEx(
			LoadCursor(NULL, IDC_ARROW), // Cursor: IDC_IBEAM, IDC_WAIT, IDC_CROSS, ...
			//(HBRUSH)(COLOR_BTNFACE+1)); //Background:  (HBRUSH)(COLOR_WINDOW+1)), ::GetStockObject(BLACK_BRUSH)...
			(HBRUSH)::GetStockObject(NULL_BRUSH));
		this->isRegistered = true;
	}
	_selected= false;
	_has_focus= false;
	_tooth_code= L"01";
	_is_upper= true;
	_hfont= NULL;
	//
	_body_line_color= RGB(70,70,70);
	_body_fill_color= RGB(245,245,245);
	_root_line_color= RGB(70,70,70);
	_root_line_color= RGB(245,245,245);
	//
	_point_body_upper= NULL;
	_point_body_upper_count= 0;
	_point_body_lower= NULL;
	_point_body_lower_count= 0;
	_point_root_upper= NULL;
	_point_root_upper_count= 0;
	_point_root_lower= NULL;
	_point_root_lower_count= 0;
	//
	_svgWidth= 0.0;
	_svgHeight= 0.0;
}

Tooth::~Tooth()
{
	if(_point_body_upper!=NULL) {delete [] _point_body_upper;}
	if(_point_body_lower!=NULL) {delete [] _point_body_lower;}
	if(_point_body_upper!=NULL) {delete [] _point_root_upper;}
	if(_point_body_lower!=NULL) {delete [] _point_root_lower;}
	//... ?
}

void Tooth::Window_Open(Win::Event& e)
{
	//____________________________________________________Upper
	Sys::SvgReader svgUpper;
	if(svgUpper.CreateFromResource(this->hInstance,IDR_TOOTH_UPPER)== false)
	{
		this->MessageBoxW(L"The Tooth_Upper resource could not be open.", L"Tooth", MB_OK|MB_ICONERROR);
		return;
	}
	//____________________________________________________Box
	Sys::Point2D position;
	Sys::Point2D size;
	if(svgUpper.GetRectangle(L"box", position, size)== false)
	{
		this->MessageBoxW(L"The 'box' rectangle resource could not be found.", L"Tooth", MB_OK|MB_ICONERROR);
		return;
	}
	//Use the position and size from the SVG to create the rect variable
	_svgWidth= size.x;
	_svgHeight= size.y;

	//____________________________________________________Bezier Body Upper
	if(svgUpper.GetBezierPoints(L"body", point_body_upper)== false)
	{
		this->MessageBoxW(L"The 'body' bezier resource could not be found.", L"Tooth", MB_OK|MB_ICONERROR);
		return;
	}
	_point_body_upper_count= point_body_upper.size();
	_point_body_upper= new POINT[_point_body_upper_count];
	for(int i=0; i<_point_body_upper_count; i++)
	{
		_point_body_upper[i].x= (int)(point_body_upper[i].x);
		_point_body_upper[i].y= (int)(point_body_upper[i].y);
	}
	//____________________________________________________Bezier Root Upper
	if(svgUpper.GetBezierPoints(L"root", point_root_upper)== false)
	{
		this->MessageBoxW(L"The 'root' bezier resource could not be found.", L"Tooth", MB_OK|MB_ICONERROR);
		return;
	}
	_point_root_upper_count= point_root_upper.size();
	_point_root_upper= new POINT[_point_root_upper_count];
	for(int i=0; i<_point_root_upper_count; i++)
	{
		_point_root_upper[i].x= (int)(point_root_upper[i].x);
		_point_root_upper[i].y= (int)(point_root_upper[i].y);
	}

	//____________________________________________________Lower
	Sys::SvgReader svgLower;
	if(svgLower.CreateFromResource(this->hInstance,IDR_TOOTH_LOWER)== false)
	{
		this->MessageBoxW(L"The Tooth_Lower resource could not be open.", L"Tooth", MB_OK|MB_ICONERROR);
		return;
	}
	//____________________________________________________Bezier Body Lower
	if(svgLower.GetBezierPoints(L"body", point_body_lower)== false)
	{
		this->MessageBoxW(L"The 'body' bezier resource could not be found.", L"Tooth", MB_OK|MB_ICONERROR);
		return;
	}
	_point_body_lower_count= point_body_lower.size();
	_point_body_lower= new POINT[_point_body_lower_count];
	for(int i=0; i<_point_body_lower_count; i++)
	{
		_point_body_lower[i].x= (int)(point_body_lower[i].x);
		_point_body_lower[i].y= (int)(point_body_lower[i].y);
	}
	//____________________________________________________Bezier Root Lower
	if(svgLower.GetBezierPoints(L"root", point_root_lower)== false)
	{
		this->MessageBoxW(L"The 'root' bezier resource could not be found.", L"Tooth", MB_OK|MB_ICONERROR);
		return;
	}
	_point_root_lower_count= point_root_lower.size();
	_point_root_lower= new POINT[_point_root_lower_count];
	for(int i=0; i<_point_root_lower_count; i++)
	{
		_point_root_lower[i].x= (int)(point_root_lower[i].x);
		_point_root_lower[i].y= (int)(point_root_lower[i].y);
	}
}

void Tooth::Window_Paint(Win::Event& e)
{
	Win::Gdi gdi(e.hWnd, true, false);
	
	Win::Gdi gdiBitmap(bitmap, gdi.GetRcPaint(),false);
	OnPaintControl(gdiBitmap);
	gdi.DrawDoubleBuffer(bitmap);
}

void Tooth::OnPaintControl(Win::Gdi& gdi)
{
	RECT rect;

	Win::Gdi::Pen pen_selected(PS_SOLID,1,RGB(0,0,255));
	Win::Gdi::Brush brush_selected(RGB(220,220,255));
	Win::Gdi::Pen pen_normal(PS_SOLID,1,RGB(220,220,220));
	Win::Gdi::Brush brush_normal(RGB(220,220,220));
	
	Win::Gdi::Pen pen_body(PS_SOLID,1,_body_line_color);
	Win::Gdi::Brush brush_body(_body_fill_color);
	Win::Gdi::Pen pen_root(PS_SOLID,1,_root_line_color);
	Win::Gdi::Brush brush_root(_root_fill_color);

	rect.left= 0;
	rect.top= 0;
	rect.right= width;
	rect.bottom= height;

	//____________________________________________________Paint Background
	if(Selected==true)
	{
		gdi.SelectPen_(pen_selected);
		gdi.SelectBrush_(brush_selected);
	}
	else
	{
		gdi.SelectPen_(pen_normal);
		gdi.SelectBrush_(brush_normal);
	}
	gdi.Rectangle(rect);

	//____________________________________________________Paint Body
	gdi.SelectPen_(pen_body);
	if(_is_upper)
	{
		gdi.FillPolyBezier(_point_body_upper,_point_body_upper_count,brush_body);
		gdi.PolyBezier(_point_body_upper,_point_body_upper_count);
	}
	else
	{
		gdi.FillPolyBezier(_point_body_lower,_point_body_lower_count,brush_body);
		gdi.PolyBezier(_point_body_lower,_point_body_lower_count);
	}
	//____________________________________________________Paint Root
	gdi.SelectPen_(pen_root);
	if(_is_upper)
	{
		gdi.FillPolyBezier(_point_root_upper,_point_root_upper_count,brush_root);
		gdi.PolyBezier(_point_root_upper,_point_root_upper_count);
	}
	else
	{
		gdi.FillPolyBezier(_point_root_lower,_point_root_lower_count,brush_root);
		gdi.PolyBezier(_point_root_lower,_point_root_lower_count);
	}

	//____________________________________________________Paint Tooth Type
	if(_tooth_code.empty()==false)
	{
		gdi.SelectFont__(_hfont);
		gdi.SetBkMode(true);
		gdi.SetTextColor(RGB(0,0,0));
		if(Selected==true) {gdi.SetTextColor(RGB(0,0,255));}
		if(Enabled==true) {gdi.SetTextColor(RGB(180,180,180));}
		gdi.TextOutW(0,0,_tooth_code.c_str());
	}
	//____________________________________________________Paint Focus
	if(_has_focus==true)
	{
		Win::Gdi::Pen pen;
		pen.Create(PS_DOT,1,RGB(50,50,50));
		gdi.SelectPen_(pen);
		gdi.SelectBrush__((HBRUSH)GetStockObject(NULL_BRUSH)); //No filling

		rect.left= 0;
		rect.top= 0;
		rect.right= width;
		rect.bottom= height;
		gdi.Rectangle(rect);
	}
}

void Tooth::SetFont(Win::Gdi::Font& font)
{
	_hfont= font.GetHFONT();
	if(hWnd==NULL) {return;};
	::InvalidateRect(hWnd,NULL,FALSE);
}

void Tooth::Window_Size(Win::Event& e)
{
	int i;
	bitmap.CreateCompatible(hWnd,width,height);
	//___________________________________________________Find Scale
	const float scaleX= width/_svgWidth;
	const float scaleY= height/_svgHeight;
	const float scale= MINIMUM(scaleX,scaleY);
	const float actual_width= _svgWidth*scale;
	const float actual_height= _svgHeight*scale;
	const float offsetX= (width-actual_width)/(float)2.0;
	const float offsetY= (height-actual_height)/(float)2.0;
	//___________________________________________________Scale Body
	for(i=0; i<_point_body_upper_count; i++)
	{
		_point_body_upper[i].x= (int)(point_body_upper[i].x*scale + offsetX);
		_point_body_upper[i].y= (int)(point_body_upper[i].y*scale + offsetY);
	}
	for(i=0; i<_point_body_lower_count; i++)
	{
		_point_body_lower[i].x= (int)(point_body_lower[i].x*scale + offsetX);
		_point_body_lower[i].y= (int)(point_body_lower[i].y*scale + offsetY);
	}
	//___________________________________________________Scale Root
	for(i=0; i<_point_root_upper_count; i++)
	{
		_point_root_upper[i].x= (int)(point_root_upper[i].x*scale + offsetX);
		_point_root_upper[i].y= (int)(point_root_upper[i].y*scale + offsetY);
	}
	for(i=0; i<_point_root_lower_count; i++)
	{
		_point_root_lower[i].x= (int)(point_root_lower[i].x*scale + offsetX);
		_point_root_lower[i].y= (int)(point_root_lower[i].y*scale + offsetY);
	}
}

bool Tooth::IsEvent(Win::Event& e, int notification)
{
	if (e.uMsg!=WM_COMMAND) return false;
	const int id = LOWORD(e.wParam);
	const int notificationd = HIWORD(e.wParam);
	if (id != this->id) return false;
	if (notificationd!=notification) return false;
	return true;
}

void Tooth::Window_LButtonDown(Win::Event& e)
{
	/*const int x = LOWORD(e.lParam);
	const int y = HIWORD(e.lParam);*/
	if(Enabled==false) return;
	HWND hWndParent= ::GetParent(hWnd);
	::SendMessage(hWndParent,WM_COMMAND,MAKEWPARAM(this->id,WIN_CLICK),e.lParam);
	::SetFocus(hWnd);
}

void Tooth::Window_KillFocus(Win::Event& e)
{
	this->_has_focus= false;
	this->Repaint(NULL, true);
}

void Tooth::Window_SetFocus(Win::Event& e)
{
	this->_has_focus= true;
	this->Repaint(NULL, true);
}

bool Tooth::GetSelected()
{
	return _selected;
}

void Tooth::SetSelected(bool selected)
{
	if(_selected==selected) return;
	_selected= selected;
	this->Repaint(NULL, true);
}

COLORREF Tooth::GetRootFillColor()
{
	return _root_fill_color;
}

void Tooth::SetRootFillColor(COLORREF color)
{
	if(_root_fill_color==color) {return;}
	_root_fill_color= color;
	Repaint(NULL,true);
}

COLORREF Tooth::GetRootLineColor()
{
	return _root_line_color;
}

void Tooth::SetRootLineColor(COLORREF color)
{
	if(_root_line_color==color) {return;}
	_root_line_color= color;
	Repaint(NULL,true);
}

COLORREF Tooth::GetBodyFillColor()
{
	return _body_fill_color;
}

void Tooth::SetBodyFillColor(COLORREF color)
{
	if(_body_fill_color==color) {return;}
	_body_fill_color= color;
	Repaint(NULL,true);
}

COLORREF Tooth::GetBodyLineColor()
{
	return _body_fill_color;
}

void Tooth::SetBodyLineColor(COLORREF color)
{
	if(_body_fill_color==color) {return;}
	_body_fill_color= color;
	Repaint(NULL,true);
}

wstring Tooth::GetToothCode()
{
	return _tooth_code;
}

void Tooth::SetToothCode(wstring type)
{
	if(_tooth_code==type) return;
	_tooth_code= type;
	this->Repaint(NULL, true);
}

bool Tooth::GetIsUpper()
{
	return _is_upper;
}

void Tooth::SetIsUpper(bool isUpper)
{
	if(_is_upper==isUpper) return;
	_is_upper= isUpper;
	this->Repaint(NULL, true);
}