#if !defined(AFX_PARA1_H__36C4F346_2283_481C_85A2_61070F621B57__INCLUDED_)
#define AFX_PARA1_H__36C4F346_2283_481C_85A2_61070F621B57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Para1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPara1 dialog

class CPara1 : public CDialog
{
// Construction
public:
	CPara1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPara1)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPara1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPara1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARA1_H__36C4F346_2283_481C_85A2_61070F621B57__INCLUDED_)
