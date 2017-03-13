#if !defined(AFX_PARA3_H__D818E157_E5B3_43B0_8D29_BF8D69ABAA72__INCLUDED_)
#define AFX_PARA3_H__D818E157_E5B3_43B0_8D29_BF8D69ABAA72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Para3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPara3 dialog

class CPara3 : public CDialog
{
// Construction
public:
	CPara3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPara3)
	enum { IDD = IDD_DIALOG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPara3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPara3)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARA3_H__D818E157_E5B3_43B0_8D29_BF8D69ABAA72__INCLUDED_)
