// DLG.cpp : implementation file
//

#include "stdafx.h"
#include "asdfghjk.h"
#include "DLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DLG dialog



DLG::DLG(CWnd* pParent /*=NULL*/)
	: CDialog(DLG::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(DLG)
	m_adress = _T("");
	//}}AFX_DATA_INIT
}


void DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLG)
	DDX_Text(pDX, IDC_EDIT1, m_adress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLG, CDialog)
	//{{AFX_MSG_MAP(DLG)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLG message handlers
