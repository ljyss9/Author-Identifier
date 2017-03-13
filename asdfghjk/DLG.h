#if !defined(AFX_DLG_H__A00E7138_5FFC_4A9A_B46D_9045D54AD15B__INCLUDED_)
#define AFX_DLG_H__A00E7138_5FFC_4A9A_B46D_9045D54AD15B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DLG dialog

class DLG : public CDialog
{
// Construction
public:
	DLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DLG)
	enum { IDD = IDD_DIALOG2 };
	CString	m_adress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLG)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__A00E7138_5FFC_4A9A_B46D_9045D54AD15B__INCLUDED_)
