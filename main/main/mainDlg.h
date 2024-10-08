﻿
// mainDlg.h: 헤더 파일
//

#pragma once

#include <iostream>
#include <filesystem>
#include "img_dlg.h"

namespace fs = std::filesystem;
//using namespace std;

// CmainDlg 대화 상자
class CmainDlg : public CDialogEx
{
// 생성입니다.
public:
	CmainDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	img_dlg* dlg;


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCrtDlg();
	afx_msg void OnBnClickedBtnDraw();
	int x1;
	int y1;
	int x2;
	int y2;
	void update_variables(int x1, int y1, int x2, int y2);
	/*bool is_valid_radius(int x, int  y, int r);
	int generate_radius(int x, int y);*/
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnStnClickedStaticcy();
};
