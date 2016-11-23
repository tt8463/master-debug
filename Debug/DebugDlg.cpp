// DebugDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Debug.h"
#include "DebugDlg.h"
#include "ClientSocket.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern CDebugApp theApp;
CClientSocket m_CClientSocket;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDebugDlg dialog

CDebugDlg::CDebugDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDebugDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDebugDlg)
	m_strAD11 = 0;
	m_strAD12 = 0;
	m_strAD13 = 0;
	m_strAD14 = 0;
	m_strAD21 = 0;
	m_strAD22 = 0;
	m_strAD23 = 0;
	m_strAD24 = 0;
	m_strAD31 = 0;
	m_strAD32 = 0;
	m_strAD33 = 0;
	m_strAD34 = 0;
	m_strBC1X = 0;
	m_strBC1Y = 0;
	m_strBC2X = 0;
	m_strBC2Y = 0;
	m_strDwen = 0;
	m_strFguang = 0;
	m_strFG1 = 0;
	m_strFG2 = 0;
	m_strFG3 = 0;
	m_strFG4 = 0;
	m_strFlapDis = 0;
	m_strTiaoShi = 0;
	m_strXhe = 0;
	m_strXhfgh = 0;
	m_strXheh = 0;
	m_strXheq = 0;
	m_sPort = 8899;
	m_strJH = 0;
	m_strXhfgq = 0;
	m_strFG5 = 0;
	m_strFG6 = 0;
	m_strFG7 = 0;
	m_strFG8 = 0;
	m_strBJ = 0;
	m_strJC1 = 0;
	m_strJC2 = 0;
	m_strJC3 = 0;
	m_strJC4 = 0;
	m_strBaseValue = 0;
	m_strXF = 0;
	m_strBD = 0;
	m_strBD2 = 0;
	m_strBD3 = 0;
	m_strBD4 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDebugDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDebugDlg)
	DDX_Control(pDX, IDC_IPADDRESS1, m_ServerIP);
	DDX_Control(pDX, IDC_COMBO_XM, m_ctrlXM);
	DDX_Text(pDX, IDC_EDIT_AD11, m_strAD11);
	DDX_Text(pDX, IDC_EDIT_AD12, m_strAD12);
	DDX_Text(pDX, IDC_EDIT_AD13, m_strAD13);
	DDX_Text(pDX, IDC_EDIT_AD14, m_strAD14);
	DDX_Text(pDX, IDC_EDIT_AD21, m_strAD21);
	DDX_Text(pDX, IDC_EDIT_AD22, m_strAD22);
	DDX_Text(pDX, IDC_EDIT_AD23, m_strAD23);
	DDX_Text(pDX, IDC_EDIT_AD24, m_strAD24);
	DDX_Text(pDX, IDC_EDIT_AD31, m_strAD31);
	DDX_Text(pDX, IDC_EDIT_AD32, m_strAD32);
	DDX_Text(pDX, IDC_EDIT_AD33, m_strAD33);
	DDX_Text(pDX, IDC_EDIT_AD34, m_strAD34);
	DDX_Text(pDX, IDC_EDIT_BC1X, m_strBC1X);
	DDX_Text(pDX, IDC_EDIT_BC1Y, m_strBC1Y);
	DDX_Text(pDX, IDC_EDIT_BC2X, m_strBC2X);
	DDX_Text(pDX, IDC_EDIT_BC2Y, m_strBC2Y);
	DDX_Text(pDX, IDC_EDIT_DW, m_strDwen);
	DDX_Text(pDX, IDC_EDIT_FG, m_strFguang);
	DDX_Text(pDX, IDC_EDIT_FG1, m_strFG1);
	DDX_Text(pDX, IDC_EDIT_FG2, m_strFG2);
	DDX_Text(pDX, IDC_EDIT_FG3, m_strFG3);
	DDX_Text(pDX, IDC_EDIT_FG4, m_strFG4);
	DDX_Text(pDX, IDC_EDIT_LENGH, m_strFlapDis);
	DDX_Text(pDX, IDC_EDIT_TIAOSHI, m_strTiaoShi);
	DDX_Text(pDX, IDC_EDIT_XH, m_strXhe);
	DDX_Text(pDX, IDC_EDIT_XHFGH, m_strXhfgh);
	DDX_Text(pDX, IDC_EDIT_XHH, m_strXheh);
	DDX_Text(pDX, IDC_EDIT_XHQ, m_strXheq);
	DDX_Text(pDX, IDC_EDIT1, m_sPort);
	DDX_Text(pDX, IDC_JIHAO, m_strJH);
	DDX_Text(pDX, IDC_EDIT_XHFGQ, m_strXhfgq);
	DDX_Text(pDX, IDC_EDIT_FG5, m_strFG5);
	DDX_Text(pDX, IDC_EDIT_FG6, m_strFG6);
	DDX_Text(pDX, IDC_EDIT_FG7, m_strFG7);
	DDX_Text(pDX, IDC_EDIT_FG8, m_strFG8);
	DDX_Text(pDX, IDC_EDIT_BJ, m_strBJ);
	DDX_Text(pDX, IDC_EDIT_JC1, m_strJC1);
	DDX_Text(pDX, IDC_EDIT_JC2, m_strJC2);
	DDX_Text(pDX, IDC_EDIT_JC3, m_strJC3);
	DDX_Text(pDX, IDC_EDIT_JC4, m_strJC4);
	DDX_Text(pDX, IDC_BASE_VALUE, m_strBaseValue);
	DDX_Text(pDX, IDC_EDIT_XF, m_strXF);
	DDX_Text(pDX, IDC_EDIT_BD, m_strBD);
	DDX_Text(pDX, IDC_EDIT_BD2, m_strBD2);
	DDX_Text(pDX, IDC_EDIT_BD3, m_strBD3);
	DDX_Text(pDX, IDC_EDIT_BD4, m_strBD4);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDebugDlg, CDialog)
	//{{AFX_MSG_MAP(CDebugDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonOpenIP)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonCloseIP)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_GET1, OnButtonGetFGStrong)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE1, OnButtonUpdateFGStrong)
	ON_BN_CLICKED(IDC_BUTTON_DEBUG, OnButtonDebug1)
	ON_BN_CLICKED(IDC_BUTTON_DEBUG2, OnButtonDebug2)
	ON_BN_CLICKED(IDC_BUTTON_DEBUG3, OnButtonDebug3)
	ON_BN_CLICKED(IDC_BUTTON_TIAOSHIHUO, OnButtonTiaoShiHuoQu)
	ON_BN_CLICKED(IDC_BUTTON_TIAOSHIUPD, OnButtonTiaoShiUpdate)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonGet)
	ON_BN_CLICKED(IDC_BUTTON_GET_XF, OnButtonGetXf)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_XF, OnButtonUpdateXf)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_DATA, OnButtonSaveData)
	ON_BN_CLICKED(IDC_BUTTON_EXCEL, OnButtonExcel)
	ON_BN_CLICKED(IDC_BUTTON_GET_JC, OnButtonGetJc)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_JC, OnButtonUpdateJc)
	ON_BN_CLICKED(IDC_BUTTON_BASE_VALUE, OnButtonBaseValue)
	ON_BN_CLICKED(IDC_BUTTON_START_STOP, OnButtonStartStop)
	ON_BN_CLICKED(IDC_BUTTON_BUCHANG, OnButtonBuchang)
	ON_BN_CLICKED(IDC_BUTTON_GETBUCHANG, OnButtonGetbuchang)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDebugDlg message handlers

BOOL CDebugDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
//	m_ctrlXM.SetCurSel(0);
	OnIPAddress();

	m_StartC=FALSE;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDebugDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDebugDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDebugDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDebugDlg::OnButtonOpenIP() 
{
	// TODO: Add your control notification handler code here
	if(!m_StartC)
	{
		BYTE nFild[4];
		CString sIP;
		UpdateData();
		m_ServerIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);
		sIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);
		m_CClientSocket.Create();
		m_CClientSocket.Connect(sIP,m_sPort);
		m_StartC=~FALSE;
		GetDlgItem(IDC_BUTTON1)->EnableWindow(!m_StartC);
		GetDlgItem(IDC_EDIT1)->EnableWindow(!m_StartC);
		GetDlgItem(IDC_IPADDRESS1)->EnableWindow(!m_StartC);
		UpdateData(FALSE);
		
		CFile file;
		CFileStatus news;
		if(CFile::GetStatus(_T("2.txt"),news))
		{
			if(file.Open(_T("2.txt"),CFile::modeReadWrite|CFile::modeCreate))
			{	
				CString str_Bk="\t";
				//							file1.SeekToEnd();
				
				file.Write((void*)(LPCSTR)sIP,sIP.GetLength());
				file.Close();
				/*						AfxMessageBox("保存成功!!!");*/
			}
		}
	}
}

void CDebugDlg::OnButtonCloseIP() 
{
	// TODO: Add your control notification handler code here
	m_CClientSocket.Close();
	m_StartC=FALSE;
	GetDlgItem(IDC_BUTTON1)->EnableWindow(!m_StartC);
	GetDlgItem(IDC_EDIT1)->EnableWindow(!m_StartC);
	GetDlgItem(IDC_IPADDRESS1)->EnableWindow(!m_StartC);
	
}

void CDebugDlg::OnIPAddress() 
{
	// 此段代码：独立的获取本机IP地址和计算机名
	CString ip;
	CFile file("2.txt",CFile::modeRead|CFile::modeNoTruncate|CFile::modeCreate);
	char *pBuf;
	int iLen=file.GetLength();
	pBuf=new char[iLen];
	file.Read(pBuf,iLen);
	pBuf[iLen]=0;
	file.Close();
	//				str1[7].Format("%d",pBuf);
	ip.Format("%s",pBuf);
	m_ServerIP.SetWindowText(ip);
}

void CDebugDlg::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x8D;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x6D;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonGetFGStrong() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x1B;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonUpdateFGStrong() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	UpdateData(TRUE);
	
	BYTE strSend[7];
	
	strSend[0]=(char)0xFD;
	strSend[1]=m_strFG1;
	ByteTest=strSend[1];
	strSend[2]=m_strFG2;
	ByteTest=ByteTest^strSend[2];
	strSend[3]=m_strFG3;
	ByteTest=ByteTest^strSend[3];
	strSend[4]=m_strFG4;
	ByteTest=ByteTest^strSend[4];
	strSend[5]=ByteTest;
	strSend[6]=(char)0xDD;
	
	m_CClientSocket.Send(strSend,7);
}

void CDebugDlg::OnButtonDebug1() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	m_strAD11=0;
	m_strAD12=0;
	m_strAD13=0;
	m_strAD14=0;
	UpdateData(FALSE);

	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x2B;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonDebug2() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	m_strAD21=0;
	m_strAD22=0;
	m_strAD23=0;
	m_strAD24=0;
	UpdateData(FALSE);
	
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x3B;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonDebug3() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	m_strAD31=0;
	m_strAD32=0;
	m_strAD33=0;
	m_strAD34=0;
	UpdateData(FALSE);

	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x4B;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonTiaoShiHuoQu() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x7D;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonTiaoShiUpdate() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	UpdateData(TRUE);
	
	BYTE strSend[16];
	
	strSend[0]=(char)0xDF;
	strSend[1]=(m_strFlapDis&0xFF00)>>8;
	ByteTest=strSend[1];
	strSend[2]=m_strFlapDis&0x00FF;
	ByteTest=ByteTest^strSend[2];
	strSend[3]=m_strTiaoShi;
	ByteTest=ByteTest^strSend[3];
	strSend[4]=m_strBJ;
	ByteTest=ByteTest^strSend[4];
	strSend[5]=m_strXF;
	ByteTest=ByteTest^strSend[5];
	strSend[6]=(m_strBD&0xFF00)>>8;
	ByteTest=ByteTest^strSend[6];
	strSend[7]=m_strBD&0x00FF;
	ByteTest=ByteTest^strSend[7];

	strSend[8]=(m_strBD2&0xFF00)>>8;
	ByteTest=ByteTest^strSend[8];
	strSend[9]=m_strBD2&0x00FF;
	ByteTest=ByteTest^strSend[9];
	strSend[10]=(m_strBD3&0xFF00)>>8;
	ByteTest=ByteTest^strSend[10];
	strSend[11]=m_strBD3&0x00FF;
	ByteTest=ByteTest^strSend[11];
	strSend[12]=(m_strBD4&0xFF00)>>8;
	ByteTest=ByteTest^strSend[12];
	strSend[13]=m_strBD4&0x00FF;
	ByteTest=ByteTest^strSend[13];

	strSend[14]=ByteTest;
	strSend[15]=(char)0xDE;
	
	m_CClientSocket.Send(strSend,16);
}

void CDebugDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	UpdateData(TRUE);
	
	BYTE strSend[15];
	
	strSend[0]=0xDD;
	strSend[1]=m_strXhfgq;
	ByteTest=strSend[1];
	strSend[2]=m_strXhfgh;
	ByteTest=ByteTest^strSend[2];
	strSend[3]=m_strXhe;
	ByteTest=ByteTest^strSend[3];
	strSend[4]=m_strXheq;
	ByteTest=ByteTest^strSend[4];
	strSend[5]=m_strXheh;
	ByteTest=ByteTest^strSend[5];
	strSend[6]=m_strFguang;
	ByteTest=ByteTest^strSend[6];
	strSend[7]=(m_strDwen&0xFF00)>>8;
	ByteTest=ByteTest^strSend[7];
	strSend[8]=m_strDwen&0x00FF;
	ByteTest=ByteTest^strSend[8];
	strSend[9]=((m_strJH&0xFF000000)>>24);
	ByteTest=ByteTest^strSend[9];
	strSend[10]=((m_strJH&0x00FF0000)>>16);
	ByteTest=ByteTest^strSend[10];
	strSend[11]=((m_strJH&0x0000FF00)>>8);
	ByteTest=ByteTest^strSend[11];
	strSend[12]=(m_strJH&0x000000FF);
	ByteTest=ByteTest^strSend[12];
	strSend[13]=ByteTest;
	strSend[14]=0xDC;
	
	m_CClientSocket.Send(strSend,15);
	
}

void CDebugDlg::OnButtonGet() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x1A;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
	
}

void CDebugDlg::OnButtonGetXf() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x2A;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonUpdateXf() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	UpdateData(TRUE);
	
	BYTE strSend[11];
	
	strSend[0]=(char)0xDA;
	strSend[1]=(m_strFG5&0xFF00)>>8;
	ByteTest=strSend[1];
	strSend[2]=(m_strFG5&0x00FF);
	ByteTest=ByteTest^strSend[2];
	strSend[3]=(m_strFG6&0xFF00)>>8;
	ByteTest=ByteTest^strSend[3];
	strSend[4]=(m_strFG6&0x00FF);
	ByteTest=ByteTest^strSend[4];
	strSend[5]=(m_strFG7&0xFF00)>>8;
	ByteTest=ByteTest^strSend[5];
	strSend[6]=(m_strFG7&0x00FF);
	ByteTest=ByteTest^strSend[6];
	strSend[7]=(m_strFG8&0xFF00)>>8;
	ByteTest=ByteTest^strSend[7];
	strSend[8]=(m_strFG8&0x00FF);
	ByteTest=ByteTest^strSend[8];
	strSend[9]=ByteTest;
	strSend[10]=(char)0xDB;
	
	m_CClientSocket.Send(strSend,11);
}

void CDebugDlg::OnButtonSaveData() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x2E;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonExcel() 
{
	// TODO: Add your control notification handler code here
	CString sExcelFile,sPath; 
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer ();
	int nPos;
	nPos=sPath.ReverseFind ('\\');
	sPath=sPath.Left (nPos);
	sExcelFile = sPath + "\\Demo.xls"; 			// 要建立的Excel文件
	::ShellExecute(NULL,"open",sExcelFile,NULL,NULL,SW_SHOWNORMAL);
}

void CDebugDlg::OnButtonGetJc() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x1D;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonUpdateJc() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	UpdateData(TRUE);
	
	BYTE strSend[7];
	
	strSend[0]=(char)0xCA;
	strSend[1]=m_strJC1;
	ByteTest=strSend[1];
	strSend[2]=m_strJC2;
	ByteTest=ByteTest^strSend[2];
	strSend[3]=m_strJC3;
	ByteTest=ByteTest^strSend[3];
	strSend[4]=m_strJC4;
	ByteTest=ByteTest^strSend[4];	
	strSend[5]=ByteTest;
	strSend[6]=(char)0xCB;
	
	m_CClientSocket.Send(strSend,7);
}

void CDebugDlg::OnButtonBaseValue() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=0x2D;
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}

void CDebugDlg::OnButtonStartStop() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[2];
	Comd[0]=0xFF;
	Comd[1]=0xFF;
	
	UpdateData();
	m_CClientSocket.Send(Comd,2);
	
}

void CDebugDlg::OnButtonBuchang() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	UpdateData(TRUE);
	
	BYTE strSend[12];
	
	strSend[0]=(char)0xEF;
	strSend[1]=(m_strBC1X&0xFF00)>>8;
	ByteTest=strSend[1];
	strSend[2]=(m_strBC1X&0xFF);
	ByteTest=ByteTest^strSend[2];
	strSend[3]=(m_strBC1Y&0xFF00)>>8;
	ByteTest=ByteTest^strSend[3];
	strSend[4]=(m_strBC1Y&0xFF);
	ByteTest=ByteTest^strSend[4];
	strSend[5]=(m_strBC2X&0xFF00)>>8;
	ByteTest=ByteTest^strSend[5];
	strSend[6]=(m_strBC2X&0xFF);
	ByteTest=ByteTest^strSend[6];
	strSend[7]=(m_strBC2Y&0xFF00)>>8;
	ByteTest=ByteTest^strSend[7];
	strSend[8]=(m_strBC2Y&0xFF);
	ByteTest=ByteTest^strSend[8];
	strSend[9]=m_ctrlXM.GetCurSel();
	ByteTest=ByteTest^strSend[9];
	strSend[10]=ByteTest;
	strSend[11]=(char)0xDB;
	
	m_CClientSocket.Send(strSend,12);
}

void CDebugDlg::OnButtonGetbuchang() 
{
	// TODO: Add your control notification handler code here
	if (!m_StartC)
	{
		AfxMessageBox("未连接！");
		return;
	}
	BYTE Comd[3];
	Comd[0]=0xFE;
	Comd[1]=m_ctrlXM.GetCurSel();
	Comd[2]=0xAA;
	
	UpdateData();
	m_CClientSocket.Send(Comd,3);
}
