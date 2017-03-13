#if !defined(AFX_MDONWLOAD_H__FAB8C5E3_D5DF_47CE_8BEF_93A2A59BA7BF__INCLUDED_)
#define AFX_MDONWLOAD_H__FAB8C5E3_D5DF_47CE_8BEF_93A2A59BA7BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mdonwload.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMdonwload dialog

class CMdonwload : public CDialog
{
// Construction
public:
	CMdonwload(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMdonwload)
	enum { IDD = IDD_DIALOG8 };
	CString	m_uml;
	CString	m_path;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMdonwload)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMdonwload)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDONWLOAD_H__FAB8C5E3_D5DF_47CE_8BEF_93A2A59BA7BF__INCLUDED_)
