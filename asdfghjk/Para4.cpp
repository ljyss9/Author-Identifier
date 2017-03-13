// Para4.cpp : implementation file
//

#include "stdafx.h"
#include "asdfghjk.h"
#include "Para4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPara4 dialog


CPara4::CPara4(CWnd* pParent /*=NULL*/)
	: CDialog(CPara4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPara4)
	m_len = _T("");
	//}}AFX_DATA_INIT
}


void CPara4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPara4)
	DDX_Text(pDX, IDC_EDIT1, m_len);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPara4, CDialog)
	//{{AFX_MSG_MAP(CPara4)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPara4 message handlers
