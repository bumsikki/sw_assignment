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

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_img_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
