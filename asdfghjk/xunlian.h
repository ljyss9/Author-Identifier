#if !defined(AFX_XUNLIAN_H__6BEC7622_AA82_4F74_9808_034238F63050__INCLUDED_)
#define AFX_XUNLIAN_H__6BEC7622_AA82_4F74_9808_034238F63050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// xunlian.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cxunlian dialog

class Cxunlian : public CDialog
{
// Construction
public:
	Cxunlian(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cxunlian)
	enum { IDD = IDD_DIALOG7 };
	CProgressCtrl	m_xpro;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cxunlian)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cxunlian)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XUNLIAN_H__6BEC7622_AA82_4F74_9808_034238F63050__INCLUDED_)
