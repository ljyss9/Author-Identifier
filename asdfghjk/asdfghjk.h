// asdfghjk.h : main header file for the ASDFGHJK application
//

#if !defined(AFX_ASDFGHJK_H__180A48C1_BE36_482F_998F_E07FFBEE1C6D__INCLUDED_)
#define AFX_ASDFGHJK_H__180A48C1_BE36_482F_998F_E07FFBEE1C6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAsdfghjkApp:
// See asdfghjk.cpp for the implementation of this class
//

class CAsdfghjkApp : public CWinApp
{
public:
	CAsdfghjkApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAsdfghjkApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAsdfghjkApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASDFGHJK_H__180A48C1_BE36_482F_998F_E07FFBEE1C6D__INCLUDED_)
