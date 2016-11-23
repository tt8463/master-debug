#if !defined(AFX_CLIENTSOCKET_H__B49C4A46_965B_452D_B35E_FA589C990BDC__INCLUDED_)
#define AFX_CLIENTSOCKET_H__B49C4A46_965B_452D_B35E_FA589C990BDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//
#include "DebugDlg.h"
#include <afxdb.h>

/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CAsyncSocket
{
// Attributes
public:
	unsigned char DataArray[200];
	unsigned char count;
	unsigned char ByteTest;
	CDatabase database;
	CString sSql;
	CFile file1;
	_RecordsetPtr m_pRecordset;
// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__B49C4A46_965B_452D_B35E_FA589C990BDC__INCLUDED_)
