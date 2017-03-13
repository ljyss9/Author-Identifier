// Para3.cpp : implementation file
//

#include "stdafx.h"
#include "asdfghjk.h"
#include "Para3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPara3 dialog


CPara3::CPara3(CWnd* pParent /*=NULL*/)
	: CDialog(CPara3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPara3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPara3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPara3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPara3, CDialog)
	//{{AFX_MSG_MAP(CPara3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPara3 message handlers
