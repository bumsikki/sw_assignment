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
END_MESSAGE_MAP()


// img_dlg 메시지 처리기
