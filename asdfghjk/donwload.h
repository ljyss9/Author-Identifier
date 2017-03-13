#if !defined(AFX_DONWLOAD_H__CB2206CF_03DE_46AD_9785_0479385DBE2F__INCLUDED_)
#define AFX_DONWLOAD_H__CB2206CF_03DE_46AD_9785_0479385DBE2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// donwload.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cdonwload dialog

class Cdonwload : public CDialog
{
// Construction
public:
	Cdonwload(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cdonwload)
	enum { IDD = IDD_DIALOG8 };
	CString	m_uml;
	CString	m_path;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cdonwload)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cdonwload)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DONWLOAD_H__CB2206CF_03DE_46AD_9785_0479385DBE2F__INCLUDED_)
