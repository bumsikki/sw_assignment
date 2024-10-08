#pragma once
#include "afxdialogex.h"


// img_dlg 대화 상자

class img_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(img_dlg)

public:
	img_dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~img_dlg();

	CWnd* parent;
	CImage img;
	int width = 1280;
	int height = 480;
	int bpp = 8;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_img_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	int x1;
	int x2;
	int y1;
	int y2;
	int r;
	void initImg();
	bool is_valid_radius(int x, int  y, int r);
	int generate_radius(int x, int y);
	bool is_circle(int i, int j, int x, int y, int r);
	void create_circle(int x, int y, int r);
	void move_circle(); 
};
