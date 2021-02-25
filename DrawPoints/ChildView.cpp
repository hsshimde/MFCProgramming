
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "DrawPoints.h"
#include "ChildView.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

	CRect rect;
	GetClientRect(&rect);
	
	size_t width = rect.Width();
	size_t height = rect.Height();
	std::cout << width << std::endl;
	std::cout << height << std::endl;

	/*CString str;
	str.Format(_T("widht = %d, height = %d"), width, height);
	
	dc.TextOutW(width / 2, height / 2, str);*/

	for (size_t i = 0; i < 500; i++)
	{
		for (size_t j = 0; j < 500; j++)
		{
			dc.SetPixel(i, j, RGB(i%256, j%256, (i*j)%256));
		}
	}
	
	// Do not call CWnd::OnPaint() for painting messages
}

