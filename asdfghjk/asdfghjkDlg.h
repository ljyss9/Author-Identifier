// asdfghjkDlg.h : header file
//

#if !defined(AFX_ASDFGHJKDLG_H__B26587B5_3FF7_437F_8CEA_A30685DB1BAD__INCLUDED_)
#define AFX_ASDFGHJKDLG_H__B26587B5_3FF7_437F_8CEA_A30685DB1BAD__INCLUDED_
#include "Para1.h"
#include "Para2.h"
#include "Para3.h"
#include "Para4.h"
#include "xunlian.h"
#include "Mdonwload.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAsdfghjkDlg dialog

class CAsdfghjkDlg : public CDialog
{
// Construction
public:
	CAsdfghjkDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAsdfghjkDlg)
	enum { IDD = IDD_ASDFGHJK_DIALOG };
	CButton	m_radio13;
	CButton	m_radio12;
	CButton	m_radio11;
	CTabCtrl	m_tab;
	CButton	m_radio3;
	CButton	m_radio2;
	CButton	m_radio1;
	CProgressCtrl	m_pro8;
	CProgressCtrl	m_pro7;
	CProgressCtrl	m_pro6;
	CProgressCtrl	m_pro1;
	CProgressCtrl	m_pro5;
	CProgressCtrl	m_pro4;
	CProgressCtrl	m_pro3;
	CProgressCtrl	m_pro2;
	CString	m_R;
	CString	m_len;
	double	m_w1;
	double	m_w2;
	double	m_w3;
	double	m_w4;
	CString	m_rate;
	Cxunlian dlg;
	CPara1 para1;
	CPara2 para2;
	CPara3 para3;
	CPara4 para4;
	CMdonwload ddlg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAsdfghjkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAsdfghjkDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCresource();
	afx_msg void OnResult();
	afx_msg void OnPart();
	afx_msg void OnAl();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnButton5();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton6();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASDFGHJKDLG_H__B26587B5_3FF7_437F_8CEA_A30685DB1BAD__INCLUDED_)
