// img_dlg.cpp: 구현 파일
//

#include "pch.h"
#include "main.h"
#include "afxdialogex.h"
#include "img_dlg.h"

#include <iostream>
#include "mainDlg.h"
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
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
	std::cout << fs::current_path() << std::endl;
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

bool img_dlg::is_valid_radius(int x, int  y, int r) {
	if (x + r > width)
		return false;
	if (x - r < 0)
		return false;
	if (y - r < 0)
		return false;
	if (y + r > height) {
		return false;
	}
	return true;
}

int img_dlg::generate_radius(int x, int y) {
	r = rand() % 100 + 30;
	while (!is_valid_radius(x, y, r)) {
		r = rand() % 100 + 30;
	}
	return r;
}

bool img_dlg::is_circle(int i, int j, int x, int y, int r) {
	double dx = i - x;
	double dy = j - y;
	double dist = dx * dx + dy * dy;
	if (dist  <= r * r) {
		return true;
	}
	return false;
}

void img_dlg::create_circle(int x, int y, int r) {
	int pitch = img.GetPitch();
	unsigned char* fm = (unsigned char*)img.GetBits();
	memset(fm, 0xff, width * height);

	for (int j = y-r; j < y+r; j++) {
		for (int i = x-r; i < x+r; i++) {
			if(is_circle(i,j,x,y,r))
				fm[j * pitch + i] = 0;
		}
	}
	CClientDC dc(this);
	img.Draw(dc,0,0);
	//Invalidate(); // somehow, invalidate doesn't work when using this function. it only shows the circle at the end
}

void img_dlg::move_circle() {
	int x_step = (x2 - x1) / r;
	int y_step = (y2 - y1) / r;
	for (int i = 0; i < r; i++) {
			create_circle(x1+x_step*i, y1+y_step*i, r);
			//after each move, save image in bmp format		
			/*img.Save(_T("../img/step1.bmp"));*/
			// auto curr_path = fs::current_path();
			//std::string img_num = std::to_string(i + 1);
			//std::string img_path = "/res/img/img" + img_num + ".bmp";
			//
			//std::string image_path = curr_path + img_path;
			///*fs::path image_path = temp;*/
			//
			//std::cout << image_path << std::endl;
			////curr_path.insert(curr_path.end(), img_path);
			//img.Save((LPCTSTR)curr_path.c_str());
			/*std::string temp = "C:\\Users\\kbss7\\OneDrive\\Desktop\\glim\\sw_assignment\\main\\main\\res\\img\\";
			auto path = temp + std::to_string(i) + ".bmp";
			img.Save((LPCTSTR)path.c_str());*/

			// how to make the path to relative?
			std::string temp = "C:\\Users\\kbss7\\OneDrive\\Desktop\\glim\\sw_assignment\\main\\main\\res\\img\\";
			std::string img_path = "img" + std::to_string(i) + ".bmp";
			std::string path = temp + img_path;
			CString final_path(path.c_str());
			img.Save(final_path);
			Sleep(10);
	}
}
