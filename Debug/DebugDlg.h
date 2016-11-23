// DebugDlg.h : header file
//

#if !defined(AFX_DEBUGDLG_H__FDE26A9E_C14E_4F54_82A8_E0207A64F861__INCLUDED_)
#define AFX_DEBUGDLG_H__FDE26A9E_C14E_4F54_82A8_E0207A64F861__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDebugDlg dialog

class CDebugDlg : public CDialog
{
// Construction
public:
	CDebugDlg(CWnd* pParent = NULL);	// standard constructor
	
	BOOL m_StartC;
	unsigned char ByteTest;
	
//	_RecordsetPtr m_pRecordset;
	BOOL m_bSuccess;
	void showLists();
	VARIANT	varBLOB;
	void List(CString sql);
	CString currentID;
	
	void OnIPAddress(); 

// Dialog Data
	//{{AFX_DATA(CDebugDlg)
	enum { IDD = IDD_DEBUG_DIALOG };
	CIPAddressCtrl	m_ServerIP;
	CComboBox	m_ctrlXM;
	UINT	m_strAD11;
	UINT	m_strAD12;
	UINT	m_strAD13;
	UINT	m_strAD14;
	UINT	m_strAD21;
	UINT	m_strAD22;
	UINT	m_strAD23;
	UINT	m_strAD24;
	UINT	m_strAD31;
	UINT	m_strAD32;
	UINT	m_strAD33;
	UINT	m_strAD34;
	UINT	m_strBC1X;
	UINT	m_strBC1Y;
	UINT	m_strBC2X;
	UINT	m_strBC2Y;
	UINT	m_strDwen;
	UINT	m_strFguang;
	UINT	m_strFG1;
	UINT	m_strFG2;
	UINT	m_strFG3;
	UINT	m_strFG4;
	UINT	m_strFlapDis;
	UINT	m_strTiaoShi;
	UINT	m_strXhe;
	UINT	m_strXhfgh;
	UINT	m_strXheh;
	UINT	m_strXheq;
	int		m_sPort;
	DWORD	m_strJH;
	UINT	m_strXhfgq;
	UINT	m_strFG5;
	UINT	m_strFG6;
	UINT	m_strFG7;
	UINT	m_strFG8;
	UINT	m_strBJ;
	UINT	m_strJC1;
	UINT	m_strJC2;
	UINT	m_strJC3;
	UINT	m_strJC4;
	UINT	m_strBaseValue;
	UINT	m_strXF;
	UINT	m_strBD;
	UINT	m_strBD2;
	UINT	m_strBD3;
	UINT	m_strBD4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDebugDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDebugDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonOpenIP();
	afx_msg void OnButtonCloseIP();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonGetFGStrong();
	afx_msg void OnButtonUpdateFGStrong();
	afx_msg void OnButtonDebug1();
	afx_msg void OnButtonDebug2();
	afx_msg void OnButtonDebug3();
	afx_msg void OnButtonTiaoShiHuoQu();
	afx_msg void OnButtonTiaoShiUpdate();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonGet();
	afx_msg void OnButtonGetXf();
	afx_msg void OnButtonUpdateXf();
	afx_msg void OnButtonAd();
	afx_msg void OnButtonSaveData();
	afx_msg void OnButtonExcel();
	afx_msg void OnButtonGetJc();
	afx_msg void OnButtonUpdateJc();
	afx_msg void OnButtonBaseValue();
	afx_msg void OnButtonStartStop();
	afx_msg void OnButtonBuchang();
	afx_msg void OnButtonGetbuchang();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUGDLG_H__FDE26A9E_C14E_4F54_82A8_E0207A64F861__INCLUDED_)
