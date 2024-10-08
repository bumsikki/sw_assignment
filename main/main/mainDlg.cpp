﻿
// mainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "main.h"
#include "mainDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnDestroy();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CmainDlg 대화 상자



CmainDlg::CmainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
	, x1(0)
	, y1(0)
	, x2(0)
	, y2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_x1, x1);
	DDX_Text(pDX, IDC_EDIT_y1, y1);
	DDX_Text(pDX, IDC_EDIT_x2, x2);
	DDX_Text(pDX, IDC_EDIT_y2, y2);
}

BEGIN_MESSAGE_MAP(CmainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CRT_DLG, &CmainDlg::OnBnClickedCrtDlg)
	ON_BN_CLICKED(IDC_BTN_Draw, &CmainDlg::OnBnClickedBtnDraw)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_Action, &CmainDlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CmainDlg::OnBnClickedBtnOpen)
	ON_STN_CLICKED(IDC_STATIC_cy, &CmainDlg::OnStnClickedStaticcy)
END_MESSAGE_MAP()


// CmainDlg 메시지 처리기

BOOL CmainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 1280, 600);
	
	dlg = new img_dlg;
	dlg->Create(IDD_img_dlg, this);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmainDlg::OnBnClickedCrtDlg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	dlg->ShowWindow(SW_SHOW);
	
}



//bool CmainDlg::is_valid_radius(int x, int  y, int r) {
//	if (x + r > dlg->width)
//		return false;
//	if (x - r < 0)
//		return false;
//	if (y - r < 0)
//		return false;
//	if (y + r > dlg->height) {
//		return false;
//	}
//	return true;
//}
//
//int CmainDlg::generate_radius(int x, int y) {
//	r = rand() % 100 + 10;
//	while (!is_valid_radius(x, y, r)) {
//		r = rand() % 100 + 10;
//	}
//	return r;
//}
void CmainDlg::update_variables(int x1, int y1, int x2, int y2) {
	dlg->x1 = x1;
	dlg->y1 = y1;
	dlg->x2 = x2;
	dlg->y2 = y2;
	dlg->r = dlg->generate_radius(x1, y1);
}

void CmainDlg::OnBnClickedBtnDraw()
{
	UpdateData(); // to update x1,y1,x2,y2 
	// STEP3: draw a random-sized circle with center coordinate of (x1,y1)
	std::cout << x1 << y1 << x2 << y2 << std::endl;
	update_variables(x1, y1, x2, y2);
	int pitch = dlg->img.GetPitch();
	unsigned char* fm = (unsigned char*)dlg->img.GetBits();
	dlg->create_circle(x1, y1, dlg->r);
	//dlg->move_circle(x1, y1, r);
	//dlg->Invalidate(); //update dlg img
}



void CmainDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	delete dlg;
}

void CmainDlg::OnBnClickedBtnAction()
{
	// STEP4: move a circle from (x1,y1) to (x2,y2)
	UpdateData(); // to update x1,y1,x2,y2 
	std::cout << x1 << y1 << x2 << y2 << std::endl;
	dlg->move_circle();
}


void CmainDlg::OnBnClickedBtnOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	dlg->load_image();
	CString x(std::to_string(dlg->dCenterX).c_str());
	CString y(std::to_string(dlg->dCenterY).c_str());
	SetDlgItemText(IDC_STATIC_cx, x);
	SetDlgItemText(IDC_STATIC_cy, y);
}


void CmainDlg::OnStnClickedStaticcy()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
