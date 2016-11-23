// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E1F74196_BACA_42FD_828A_38D503F3CC01__INCLUDED_)
#define AFX_STDAFX_H__E1F74196_BACA_42FD_828A_38D503F3CC01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#import "c:\program files\common files\system\ado\msado15.dll" no_namespace rename ("EOF", "adoEOF")

#include <afxsock.h>		// MFC socket extensions

#if !defined CATCH_ERROR
#define CATCH_ERROR											\
		{													\
		CString strComError;							\
		strComError.Format("¥ÌŒÛ±‡∫≈: %08lx\n¥ÌŒÛ–≈œ¢: %s\n¥ÌŒÛ‘¥: %s\n¥ÌŒÛ√Ë ˆ: %s", \
								e.Error(),                  \
								e.ErrorMessage(),           \
								(LPCSTR) e.Source(),        \
								(LPCSTR) e.Description());  \
								::MessageBox(NULL,strComError,"¥ÌŒÛ",MB_ICONEXCLAMATION);	\
		}
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E1F74196_BACA_42FD_828A_38D503F3CC01__INCLUDED_)
