// Mdonwload.cpp : implementation file
//

#include "stdafx.h"
#include "asdfghjk.h"
#include "Mdonwload.h"
#include <Python.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdonwload dialog


CMdonwload::CMdonwload(CWnd* pParent /*=NULL*/)
	: CDialog(CMdonwload::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMdonwload)
	m_uml = _T("http://blog.sina.com.cn/");
	m_path = _T("");
	//}}AFX_DATA_INIT
}


void CMdonwload::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMdonwload)
	DDX_Text(pDX, IDC_EDIT1, m_uml);
	DDX_Text(pDX, IDC_EDIT2, m_path);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMdonwload, CDialog)
	//{{AFX_MSG_MAP(CMdonwload)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMdonwload message handlers

void CMdonwload::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	char *uml = (LPSTR)(LPCTSTR)(m_uml);
	FILE *f1;
	f1 = fopen("content.txt","w");
	fprintf(f1,"%s",uml);
	fclose(f1);
	char *path = (LPSTR)(LPCTSTR)(m_path);
	FILE *f2;
	f2 = fopen("path.txt","w");
	fprintf(f2,"%s",path);
	fclose(f2);

	Py_Initialize(); 
	PyRun_SimpleString("execfile('test1.pyw')");  
    Py_Finalize( );
	CDialog::OnOK();
    MessageBox("下载成功!","提示",MB_OK);	
}

void CMdonwload::OnCancel() 
{
	// TODO: Add extra cleanup here	
	CDialog::OnCancel();
}

void CMdonwload::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
 BROWSEINFO bInfo;
 ZeroMemory(&bInfo, sizeof(bInfo));
 bInfo.hwndOwner = m_hWnd;
 bInfo.lpszTitle = _T("请选择路径: ");
 bInfo.ulFlags = BIF_RETURNONLYFSDIRS;   
 
 LPITEMIDLIST lpDlist; //用来保存返回信息的IDList
 lpDlist = SHBrowseForFolder(&bInfo) ; //显示选择对话框
 if(lpDlist != NULL)  //用户按了确定按钮
 {
  TCHAR chPath[255]; //用来存储路径的字符串
  SHGetPathFromIDList(lpDlist, chPath);//把项目标识列表转化成字符串
  m_path = chPath; //将TCHAR类型的字符串转换为CString类型的字符串
 }
  UpdateData(false);
}
