// Para2.cpp : implementation file
//

#include "stdafx.h"
#include "asdfghjk.h"
#include "Para2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPara2 dialog


CPara2::CPara2(CWnd* pParent /*=NULL*/)
	: CDialog(CPara2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPara2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPara2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPara2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPara2, CDialog)
	//{{AFX_MSG_MAP(CPara2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPara2 message handlers
