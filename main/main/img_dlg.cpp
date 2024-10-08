// img_dlg.cpp: 구현 파일
//

#include "pch.h"
#include "main.h"
#include "afxdialogex.h"
#include "img_dlg.h"

#include <iostream>
#include "mainDlg.h"

// img_dlg 대화 상자

IMPLEMENT_DYNAMIC(img_dlg, CDialogEx)

img_dlg::img_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_img_dlg, pParent)
{
	parent = pParent;
	/*CmainDlg* mainDlg = (CmainDlg*)parent;*/

}

img_dlg::~img_dlg()
{
}

void img_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(img_dlg, CDialogEx)
	ON_WM_PAINT()
	//ON_BN_CLICKED(IDC_BTN_DRAW, &img_dlg::OnBnClickedBtnDraw)
END_MESSAGE_MAP()


// img_dlg 메시지 처리기


BOOL img_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, width, height);
	initImg();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void img_dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (img)
		img.Draw(dc, 0, 0);
}




void img_dlg::initImg() {
	img.Create(width, -height, bpp);
	if (bpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		img.SetColorTable(0, 256, rgb);
	}
	int pitch = img.GetPitch();
	unsigned char* fm = (unsigned char*)img.GetBits();
	memset(fm, 0xff, width * height);
}



void img_dlg::create_circle(int x, int y, int r) {
	int pitch = img.GetPitch();
	unsigned char* fm = (unsigned char*)img.GetBits();
	memset(fm, 0xff, width * height);

	for (int j = y; j < y+r; j++) {
		for (int i = x; i < x+r; i++) {
			fm[j * pitch + i] = 0;
		}
	}
	CClientDC dc(this);
	img.Draw(dc,0,0);
	//Invalidate(); // somehow, invalidate doesn't work when using this function. it only shows the circle at the end
}

void img_dlg::move_circle(int x, int y, int r) {
	for (int i = 0; i < 100; i++) {
		create_circle(x+i, y, r);
		Sleep(10);
		//Invalidate();
	}
}

//void img_dlg::OnBnClickedBtnDraw()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	int pitch = img.GetPitch();
//	unsigned char* fm = (unsigned char*)img.GetBits();
//	memset(fm, 0, width * height);
//	Invalidate();
//	//drawImg();
//}
