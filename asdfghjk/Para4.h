#if !defined(AFX_PARA4_H__7513C527_47E6_4FF7_97C8_13309BDC2B0C__INCLUDED_)
#define AFX_PARA4_H__7513C527_47E6_4FF7_97C8_13309BDC2B0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Para4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPara4 dialog

class CPara4 : public CDialog
{
// Construction
public:
	CPara4(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPara4)
	enum { IDD = IDD_DIALOG6 };
	CString	m_len;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPara4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPara4)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARA4_H__7513C527_47E6_4FF7_97C8_13309BDC2B0C__INCLUDED_)
