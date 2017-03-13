// xunlian.cpp : implementation file
//

#include "stdafx.h"
#include "asdfghjk.h"
#include "xunlian.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cxunlian dialog


Cxunlian::Cxunlian(CWnd* pParent /*=NULL*/)
	: CDialog(Cxunlian::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cxunlian)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Cxunlian::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cxunlian)
	DDX_Control(pDX, IDC_PROGRESS1, m_xpro);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cxunlian, CDialog)
	//{{AFX_MSG_MAP(Cxunlian)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cxunlian message handlers

void Cxunlian::OnOK() 
{
	// TODO: Add extra validation here	
	CDialog::OnOK();
	DestroyWindow();
}
