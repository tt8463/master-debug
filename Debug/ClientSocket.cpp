// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Debug.h"
#include "ClientSocket.h"
#include "DebugDlg.h"
#include "afxdb.h"
#include "odbcinst.h"
#include <afxdb.h>
#include "CSpreadSheet.h"
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDebugApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
	for (int i=0;i<200;i++)
	{
		DataArray[i]=0;
	}	
	count=0;
	ByteTest=0;
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode)
	{		
		AfxMessageBox("连接失败，请你重试！");	
		return ;
	}
	else
		AfxMessageBox("连接成功！");
	CAsyncSocket::OnConnect(nErrorCode);
}

void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString str,str1[84];
	unsigned char buf[200];
	int n=Receive(buf,200);
	buf[n]='\0';
	
	for (int i=0;i<n;i++)
	{
		DataArray[i]=buf[i];
	}
	//温度值实时显示	
	if (DataArray[0]==0xFA&&DataArray[10]==0xEB)
	{
	//	((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strWD=DataArray[1]*256+DataArray[2];
		ByteTest=DataArray[1];
		for (int i=2;i<9;i++)
		{
			ByteTest=ByteTest^DataArray[i];
			if (ByteTest==DataArray[9])
			{
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD11=DataArray[1]*256+DataArray[2];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD12=DataArray[3]*256+DataArray[4];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD13=DataArray[5]*256+DataArray[6];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD14=DataArray[7]*256+DataArray[8];
			}
		}
	}
	if (DataArray[0]==0xCA&&DataArray[6]==0xCB)
	{
		//	((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strWD=DataArray[1]*256+DataArray[2];
		ByteTest=DataArray[1];
		for (int i=2;i<5;i++)
		{
			ByteTest=ByteTest^DataArray[i];
			if (ByteTest==DataArray[5])
			{
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strJC1=DataArray[1];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strJC2=DataArray[2];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strJC3=DataArray[3];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strJC4 =DataArray[4];
			}
		}
	}

	if (DataArray[0]==0xBF&&DataArray[3]==0xBE)
	{
		((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBaseValue=DataArray[1]*256+DataArray[2];
	}

	if (DataArray[0]==0xFB&&DataArray[10]==0xEA)
	{
		//	((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strWD=DataArray[1]*256+DataArray[2];
		ByteTest=DataArray[1];
		for (int i=2;i<9;i++)
		{
			ByteTest=ByteTest^DataArray[i];
			if (ByteTest==DataArray[9])
			{
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD21=DataArray[1]*256+DataArray[2];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD22=DataArray[3]*256+DataArray[4];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD23=DataArray[5]*256+DataArray[6];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD24=DataArray[7]*256+DataArray[8];
			}
		}
	}
	if (DataArray[0]==0xFC&&DataArray[10]==0xEC)
	{
		//	((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strWD=DataArray[1]*256+DataArray[2];
		ByteTest=DataArray[1];
		for (int i=2;i<9;i++)
		{
			ByteTest=ByteTest^DataArray[i];
			if (ByteTest==DataArray[9])
			{
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD31=DataArray[1]*256+DataArray[2];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD32=DataArray[3]*256+DataArray[4];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD33=DataArray[5]*256+DataArray[6];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strAD34=DataArray[7]*256+DataArray[8];
			}
		}
	}
	if (DataArray[0]==0xED&&DataArray[6]==0xEF)
	{
		//	((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strWD=DataArray[1]*256+DataArray[2];
		ByteTest=DataArray[1];
		for (int i=2;i<5;i++)
		{
			ByteTest=ByteTest^DataArray[i];
			if (ByteTest==DataArray[5])
			{
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFG1=DataArray[1];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFG2=DataArray[2];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFG3=DataArray[3];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFG4=DataArray[4];
			}
		}
	}
	if (DataArray[0]==0xDA&&DataArray[10]==0xDB)
	{
		ByteTest=DataArray[1];
		for (int i=2;i<9;i++)
		{
			ByteTest=ByteTest^DataArray[i];
			if (ByteTest==DataArray[9])
			{
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFG5=DataArray[1]*256+DataArray[2];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFG6=DataArray[3]*256+DataArray[4];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFG7=DataArray[5]*256+DataArray[6];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFG8=DataArray[7]*256+DataArray[8];
			}
		}
	}
	if (DataArray[0]==0xDF&&DataArray[15]==0xDE)
	{
		//	((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strWD=DataArray[1]*256+DataArray[2];
		ByteTest=DataArray[1];
		for (int i=2;i<14;i++)
		{
			ByteTest=ByteTest^DataArray[i];
			if (ByteTest==DataArray[14])
			{
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFlapDis=DataArray[1]*256+DataArray[2];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strTiaoShi=DataArray[3];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBJ=DataArray[4];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strXF=DataArray[5];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBD=DataArray[6]*256+DataArray[7];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBD2=DataArray[8]*256+DataArray[9];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBD3=DataArray[10]*256+DataArray[11];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBD4=DataArray[12]*256+DataArray[13];
			}
		}
	}
	//仪器参数
	if (DataArray[0]==0xDD&&DataArray[14]==0xDC)
	{
		ByteTest=DataArray[1];
		for (int i=2;i<13;i++)
		{
			ByteTest=ByteTest^DataArray[i];
		}
		if (ByteTest==DataArray[13])
		{
			((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strXhfgq=DataArray[1];
			((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strXhfgh=DataArray[2];
			((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strXhe=DataArray[3];
			((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strXheq=DataArray[4];
			((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strXheh=DataArray[5];
			((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strFguang=DataArray[6];
			((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strDwen=DataArray[7]*256+DataArray[8];
			((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strJH=DataArray[9]*16777216+DataArray[10]*65536+DataArray[11]*256+DataArray[12];
		}
		
	}

	if (DataArray[0]==0xCD&&DataArray[170]==0xCC)
	{
		//	((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strWD=DataArray[1]*256+DataArray[2];
		ByteTest=DataArray[1];
		for (int i=2;i<169;i++)
		{
			ByteTest=ByteTest^DataArray[i];			
		}
		if (ByteTest==DataArray[169])
		{
			CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel安装驱动
			CString sExcelFile,sPath; 
			//获取主程序所在路径,存在sPath中
			GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
			sPath.ReleaseBuffer ();
			int nPos;
			nPos=sPath.ReverseFind ('\\');
			sPath=sPath.Left (nPos);
			sExcelFile = sPath + "\\Demo.xls"; 			// 要建立的Excel文件
			
			TRY
			{
				sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, sExcelFile, sExcelFile);
				
				for(int i=0;i<84;i++)
				{
					str1[i].Format("%d",DataArray[2*i+1]*256+DataArray[2*i+2]);
				}	
				if(database.OpenEx(sSql,CDatabase::noOdbcDialog) )
				{
// 					sSql ="CREATE TABLE AAA (10 NUMBER, 11 NUMBER ,12 NUMBER)";
// 					database.ExecuteSQL(sSql);

// 					sSql="INSERT INTO AAA (10,11,12) VALUES ('"+str1[0]+"', '"+str1[1]+"','"+str1[2]+"')";
// 					database.ExecuteSQL(sSql);
// 					sSql = "CREATE TABLE RESULT1 (X NUMBER,10 NUMBER,11 NUMBER,12 NUMBER,13 NUMBER,14 NUMBER,15 NUMBER,16 NUMBER,17 NUMBER,18 NUMBER,19 NUMBER,20 NUMBER,21 NUMBER,22 NUMBER,23 NUMBER,24 NUMBER,25 NUMBER,26 NUMBER,27 NUMBER,28 NUMBER,29 NUMBER,30 NUMBER)";
// 					database.ExecuteSQL(sSql);
					
					sSql = "INSERT INTO RESULT1 (X,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30) VALUES (1,'"+str1[0]+"', '"+str1[1]+"','"+str1[2]+"', '"+str1[3]+"','"+str1[4]+"', '"+str1[5]+"' ,'"+str1[6]+"', '"+str1[7]+"' ,'"+str1[8]+"', '"+str1[9]+"' ,'"+str1[10]+"', '"+str1[11]+"' ,'"+str1[12]+"', '"+str1[13]+"' ,'"+str1[14]+"', '"+str1[15]+"' ,'"+str1[16]+"', '"+str1[17]+"' ,'"+str1[18]+"', '"+str1[19]+"', '"+str1[20]+"' )";
					database.ExecuteSQL(sSql);
					sSql = "INSERT INTO RESULT1 (X,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30) VALUES (2,'"+str1[21]+"', '"+str1[22]+"','"+str1[23]+"', '"+str1[24]+"','"+str1[25]+"', '"+str1[26]+"' ,'"+str1[27]+"', '"+str1[28]+"' ,'"+str1[29]+"', '"+str1[30]+"' ,'"+str1[31]+"', '"+str1[32]+"' ,'"+str1[33]+"', '"+str1[34]+"' ,'"+str1[35]+"', '"+str1[36]+"' ,'"+str1[37]+"', '"+str1[38]+"' ,'"+str1[39]+"', '"+str1[40]+"', '"+str1[41]+"' )";
					database.ExecuteSQL(sSql);
					sSql = "INSERT INTO RESULT1 (X,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30) VALUES (3,'"+str1[42]+"', '"+str1[43]+"','"+str1[44]+"', '"+str1[45]+"','"+str1[46]+"', '"+str1[47]+"' ,'"+str1[48]+"', '"+str1[49]+"' ,'"+str1[50]+"', '"+str1[51]+"' ,'"+str1[52]+"', '"+str1[53]+"' ,'"+str1[54]+"', '"+str1[55]+"' ,'"+str1[56]+"', '"+str1[57]+"' ,'"+str1[58]+"', '"+str1[59]+"' ,'"+str1[60]+"', '"+str1[61]+"', '"+str1[62]+"' )";
					database.ExecuteSQL(sSql);
					sSql = "INSERT INTO RESULT1 (X,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30) VALUES (4,'"+str1[63]+"', '"+str1[64]+"','"+str1[65]+"', '"+str1[66]+"','"+str1[67]+"', '"+str1[68]+"' ,'"+str1[69]+"', '"+str1[70]+"' ,'"+str1[71]+"', '"+str1[72]+"' ,'"+str1[73]+"', '"+str1[74]+"' ,'"+str1[75]+"', '"+str1[76]+"' ,'"+str1[77]+"', '"+str1[78]+"' ,'"+str1[79]+"', '"+str1[80]+"' ,'"+str1[81]+"', '"+str1[82]+"', '"+str1[83]+"' )";
					database.ExecuteSQL(sSql);
					
					
					
// 					sSql ="UPDATE RESULT set X=1, A='"+str1[0]+"', B='"+str1[1]+"',C='"+str1[2]+"', D='"+str1[3]+"',E='"+str1[4]+"', F='"+str1[5]+"' ,G='"+str1[6]+"', H='"+str1[7]+"' ,I='"+str1[8]+"', J='"+str1[9]+"' ,K='"+str1[10]+"', L='"+str1[11]+"' ,M='"+str1[12]+"', N='"+str1[13]+"' ,O='"+str1[14]+"', P='"+str1[15]+"' ,Q='"+str1[16]+"', R='"+str1[17]+"' ,S='"+str1[18]+"', T='"+str1[19]+"', U='"+str1[20]+"'  where X=1 ";
// 					database.ExecuteSQL(sSql);
                    
					// 					sSql ="UPDATE RESULT set X=2, A='"+str1[21]+"', B='"+str1[22]+"',C='"+str1[23]+"', D='"+str1[24]+"',E='"+str1[25]+"', F='"+str1[26]+"' ,G='"+str1[27]+"', H='"+str1[28]+"' ,I='"+str1[29]+"', J='"+str1[30]+"' ,K='"+str1[31]+"', L='"+str1[32]+"' ,M='"+str1[33]+"', N='"+str1[34]+"' ,O='"+str1[35]+"', P='"+str1[36]+"' ,Q='"+str1[37]+"', R='"+str1[38]+"' ,S='"+str1[39]+"', T='"+str1[40]+"', U='"+str1[41]+"' ";
					// 					database.ExecuteSQL(sSql);
					// 					
					// 					sSql ="INSERT INTO RESULT (A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U) VALUES (X=1, '"+str1[21]+"', '"+str1[22]+"','"+str1[23]+"', '"+str1[24]+"','"+str1[25]+"', '"+str1[26]+"' ,'"+str1[27]+"', '"+str1[28]+"' ,'"+str1[29]+"', '"+str1[30]+"' ,'"+str1[31]+"', '"+str1[32]+"' ,'"+str1[33]+"', '"+str1[34]+"' ,'"+str1[35]+"', '"+str1[36]+"' ,'"+str1[37]+"', '"+str1[38]+"' ,'"+str1[39]+"', '"+str1[40]+"', '"+str1[41]+"' )";
					// 					database.ExecuteSQL(sSql);
					// 
					// 					sSql ="UPDATE RESULT set  A=10, B=20  where X=3";
					//   					database.ExecuteSQL(sSql);
					//  					sSql ="UPDATE RESULT set X=3, A='"+str1[42]+"', B='"+str1[43]+"',C='"+str1[44]+"', D='"+str1[45]+"',E='"+str1[46]+"', F='"+str1[47]+"' ,G='"+str1[48]+"', H='"+str1[49]+"' ,I='"+str1[50]+"', J='"+str1[51]+"' ,K='"+str1[52]+"', L='"+str1[53]+"' ,M='"+str1[54]+"', N='"+str1[55]+"' ,O='"+str1[56]+"', P='"+str1[57]+"' ,Q='"+str1[58]+"', R='"+str1[59]+"' ,S='"+str1[60]+"', T='"+str1[61]+"', U='"+str1[62]+"'   where A=3";
					//  					database.ExecuteSQL(sSql);
					//  
					//  					sSql ="UPDATE RESULT set X=4, A='"+str1[63]+"', B='"+str1[64]+"',C='"+str1[65]+"', D='"+str1[66]+"',E='"+str1[67]+"', F='"+str1[68]+"' ,G='"+str1[69]+"', H='"+str1[70]+"' ,I='"+str1[71]+"', J='"+str1[72]+"' ,K='"+str1[73]+"', L='"+str1[74]+"' ,M='"+str1[75]+"', N='"+str1[76]+"' ,O='"+str1[77]+"', P='"+str1[78]+"' ,Q='"+str1[79]+"', R='"+str1[80]+"' ,S='"+str1[81]+"', T='"+str1[82]+"', U='"+str1[83]+"'   where A=4";
					//  					database.ExecuteSQL(sSql);
					
				}
				database.Close();
				//AfxMessageBox("Excel文件写入成功！");
				CString sExcelFile,sPath; 
				GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
				sPath.ReleaseBuffer ();
				int nPos;
				nPos=sPath.ReverseFind ('\\');
				sPath=sPath.Left (nPos);
				sExcelFile = sPath + "\\Demo.xls"; 			// 要建立的Excel文件
				::ShellExecute(NULL,"open",sExcelFile,NULL,NULL,SW_SHOWNORMAL);
			}
			CATCH_ALL(e)
			{
				database.Close();
				AfxMessageBox("Excel文件写入失败！");
				TRACE1("Excel驱动没有安装: %s",sDriver);
			}
			END_CATCH_ALL;
		}
	}

	if (DataArray[0]==0xEF&&DataArray[10]==0xEC)
	{
		ByteTest=DataArray[1];
		for (int i=2;i<9;i++)
		{
			ByteTest=ByteTest^DataArray[i];
			if (ByteTest==DataArray[9])
			{
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBC1X=DataArray[1]*256+DataArray[2];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBC1Y=DataArray[3]*256+DataArray[4];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBC2X=DataArray[5]*256+DataArray[6];
				((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->m_strBC2Y=DataArray[7]*256+DataArray[8];
			}
		}
	}

	((CDebugDlg*)(AfxGetApp()->m_pMainWnd))->UpdateData(FALSE);

	CAsyncSocket::OnReceive(nErrorCode);
}
