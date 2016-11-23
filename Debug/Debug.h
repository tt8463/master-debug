// Debug.h : main header file for the DEBUG application
//

#if !defined(AFX_DEBUG_H__A7E4927D_5B12_4EE7_AE9C_16AA0818EDB1__INCLUDED_)
#define AFX_DEBUG_H__A7E4927D_5B12_4EE7_AE9C_16AA0818EDB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDebugApp:
// See Debug.cpp for the implementation of this class
//

class CDebugApp : public CWinApp
{
public:
	CDebugApp();

//	_ConnectionPtr m_pConnection;
	CString m_strSQL;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDebugApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDebugApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUG_H__A7E4927D_5B12_4EE7_AE9C_16AA0818EDB1__INCLUDED_)
