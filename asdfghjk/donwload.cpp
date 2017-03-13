// donwload.cpp : implementation file
//

#include "stdafx.h"
#include "asdfghjk.h"
#include "donwload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cdonwload dialog


Cdonwload::Cdonwload(CWnd* pParent /*=NULL*/)
	: CDialog(Cdonwload::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cdonwload)
	m_uml = _T("http://blog.sina.com.cn/");
	m_path = _T("");
	//}}AFX_DATA_INIT
}


void Cdonwload::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cdonwload)
	DDX_Text(pDX, IDC_EDIT1, m_uml);
	DDX_Text(pDX, IDC_EDIT2, m_path);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cdonwload, CDialog)
	//{{AFX_MSG_MAP(Cdonwload)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cdonwload message handlers

void Cdonwload::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	char *uml = (LPSTR)(LPCTSTR)(m_uml);
	FILE *file1 ; 
	file1=fopen("content.txt","w"); 
	fprintf(file1,"%s",uml);
	fclose(file1);
	char *path = (LPSTR)(LPCTSTR)(m_path);
	FILE *file2 ; 
	file2=fopen("path.txt","w"); 
	fprintf(file2,"%s",path);
	fclose(file2);
	CDialog::OnOK();
}

void Cdonwload::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void Cdonwload::OnButton1() 
{
	// TODO: Add your control notification handler code here
    BROWSEINFO bInfo;
 ZeroMemory(&bInfo, sizeof(bInfo));
 bInfo.hwndOwner = m_hWnd;
 bInfo.lpszTitle = _T("��ѡ��·��: ");
 bInfo.ulFlags = BIF_RETURNONLYFSDIRS;   
 
 LPITEMIDLIST lpDlist; //�������淵����Ϣ��IDList
 lpDlist = SHBrowseForFolder(&bInfo) ; //��ʾѡ��Ի���
 if(lpDlist != NULL)  //�û�����ȷ����ť
 {
  TCHAR chPath[255]; //�����洢·�����ַ���
  SHGetPathFromIDList(lpDlist, chPath);//����Ŀ��ʶ�б�ת�����ַ���
  m_path = chPath; //��TCHAR���͵��ַ���ת��ΪCString���͵��ַ���
  UpdateData(false);
 }

}
