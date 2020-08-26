// NcInterface.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "NcInterface.h"


#include "MessageBoxEx.h"

#include <time.h>
#include <lm.h>
#pragma hdrstop
#include <Psapi.h>
#pragma comment( lib, "Psapi.lib" )
#pragma comment( lib, "netapi32.lib" )
#include "WtsApi32.h"
#pragma comment(lib,"WtsApi32.lib")

#include "Pic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNcInterfaceApp

BEGIN_MESSAGE_MAP(CNcInterfaceApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CNcInterfaceApp construction

CNcInterfaceApp::CNcInterfaceApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CNcInterfaceApp object

CNcInterfaceApp theApp;

BOOL IsShowWindowNextStart = FALSE;
CString SyspathDefaultPath = L"";
BOOL IsTipCheck = FALSE;

// CNcInterfaceApp initialization
BOOL g_EnableDebugPriv()
{
	HANDLE hToken;
	LUID sedebugnameValue;
	TOKEN_PRIVILEGES tkp;

	if (!OpenProcessToken(GetCurrentProcess(), 
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
			return FALSE;
	}

	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &sedebugnameValue)) {
		CloseHandle(hToken);
		return FALSE;
	}

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = sedebugnameValue;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL)) {
		CloseHandle(hToken);
		return FALSE;
	}

	return TRUE;
}

//设定强制关机
void AdjustToken()
{
	HANDLE hToken;   
	TOKEN_PRIVILEGES tkp;   
	if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&hToken))   
		return;   
	LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&tkp.Privileges[0].Luid);   
	tkp.PrivilegeCount=1;   
	tkp.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;   
	AdjustTokenPrivileges(hToken,FALSE,&tkp,0,(PTOKEN_PRIVILEGES)NULL,0);   
}


#define UNIQE_NAME L"{1AB7L2D6-EAF2-3267-9A84-9135681127A4}"
#define GIS_MSG "{D48CAL93-4925-41cb-8F59-ABAAAFCEF797}"
const UINT ID_GIS_INSTANCE = ::RegisterWindowMessage(_T(GIS_MSG)); 
BOOL IsOnlyOneUninstallRun() 
{
 
	HANDLE m_hOneInstance = ::CreateMutex(NULL, FALSE, UNIQE_NAME);
	if ( (GetLastError() == ERROR_ALREADY_EXISTS) || (m_hOneInstance == NULL) ) 
	{
	 	DWORD dwRecipients = BSM_APPLICATIONS; 
		::BroadcastSystemMessage(BSF_NOHANG, &dwRecipients,
			ID_GIS_INSTANCE, // registered window message
			0, 0 );    //user defined parameters 
 
		return FALSE;
	}

	return TRUE;
}

//#define UNIQE_NAME0 L"{1AB7L2D6-EAA2-3268-9A84-9135611127A4}"
//#define GIS_MSG0 "{D48CAS93-4925-41cb-8F57-ABAAAFCEF717}"
//const UINT ID_GIS_INSTANCE0 = ::RegisterWindowMessage(_T(GIS_MSG0)); 
//BOOL IsOnlyOneGohomeRun() 
//{
// 
//	HANDLE m_hOneInstance = ::CreateMutex(NULL, FALSE, UNIQE_NAME0);
//	if ( (GetLastError() == ERROR_ALREADY_EXISTS) || (m_hOneInstance == NULL) ) 
//	{
//	 	DWORD dwRecipients = BSM_APPLICATIONS; 
//		::BroadcastSystemMessage(BSF_NOHANG, &dwRecipients,
//			ID_GIS_INSTANCE0, // registered window message
//			0, 0 );    //user defined parameters 
// 
//		return FALSE;
//	}
//
//	return TRUE;
//}

#define UNIQE_NAME1 L"{1AB7L2D6-EAF2-3268-9A84-9135681127A4}"
#define GIS_MSG1 "{D48CAL93-4925-41cb-8F57-ABAAAFCEF797}"
const UINT ID_GIS_INSTANCE1 = ::RegisterWindowMessage(_T(GIS_MSG1)); 
BOOL IsOnlyOneIsGohomeRun() 
{
 
	HANDLE m_hOneInstance = ::CreateMutex(NULL, FALSE, UNIQE_NAME1);
	if ( (GetLastError() == ERROR_ALREADY_EXISTS) || (m_hOneInstance == NULL) ) 
	{
	 	DWORD dwRecipients = BSM_APPLICATIONS; 
		::BroadcastSystemMessage(BSF_NOHANG, &dwRecipients,
			ID_GIS_INSTANCE1, // registered window message
			0, 0 );    //user defined parameters 
 
		return FALSE;
	}

	return TRUE;
}

#define UNIQE_NAME2 L"{1AB7L2D6-EAF2-3269-9A84-9135681127A4}"
#define GIS_MSG2 "{D48CAL93-4925-41cb-8F56-ABAAAFCEF797}"
const UINT ID_GIS_INSTANCE2 = ::RegisterWindowMessage(_T(GIS_MSG2)); 
BOOL IsOnlyOneFindFileRun() 
{
 
	HANDLE m_hOneInstance = ::CreateMutex(NULL, FALSE, UNIQE_NAME2);
	if ( (GetLastError() == ERROR_ALREADY_EXISTS) || (m_hOneInstance == NULL) ) 
	{
	 	DWORD dwRecipients = BSM_APPLICATIONS; 
		::BroadcastSystemMessage(BSF_NOHANG, &dwRecipients,
			ID_GIS_INSTANCE2, // registered window message
			0, 0 );    //user defined parameters 
 
		return FALSE;
	}

	return TRUE;
}

#define UNIQE_NAME3 L"{1AB7L2D6-EAF2-3269-9A85-9135681127A4}"
#define GIS_MSG3 "{D48CAL93-4925-41cb-8F52-ABAAAFCEF797}"
const UINT ID_GIS_INSTANCE3 = ::RegisterWindowMessage(_T(GIS_MSG3)); 
BOOL IsOnlyOneInitRun() 
{
 
	HANDLE m_hOneInstance = ::CreateMutex(NULL, FALSE, UNIQE_NAME3);
	if ( (GetLastError() == ERROR_ALREADY_EXISTS) || (m_hOneInstance == NULL) ) 
	{
	 	DWORD dwRecipients = BSM_APPLICATIONS; 
		::BroadcastSystemMessage(BSF_NOHANG, &dwRecipients,
			ID_GIS_INSTANCE3, // registered window message
			0, 0 );    //user defined parameters 
 
		return FALSE;
	}

	return TRUE;
}


BOOL   IsAdminUserPrivilege(const WCHAR * _strUserName,BOOL   &_bAdminPrivilege)   
{     
	_bAdminPrivilege   =   FALSE;   

/*	PSID pSid   =   NULL;   
	DWORD cbSid   =   0;   
	LPTSTR bufDomain   =   NULL;   
	DWORD cbDomain   =   0;   
	SID_NAME_USE type;   
	LookupAccountName(NULL,strUserName,pSid,&cbSid,bufDomain,&cbDomain,&type);   
	if(cbSid)   
	{   
		pSid   =   new   byte[cbSid];   
		bufDomain   =   new   TCHAR[cbDomain];   
		if(LookupAccountName(NULL,strUserName,pSid,&cbSid,bufDomain,&cbDomain,&type))   
		{   
			PSID_IDENTIFIER_AUTHORITY   pAutho   =   GetSidIdentifierAuthority(pSid);   
			DWORD   dwErr   =   GetLastError();   
			if(!dwErr)   
			{   
				SID_IDENTIFIER_AUTHORITY   AdminAuth   =   SECURITY_NT_AUTHORITY;   
				bAdminPrivilege   =   !memcmp(pAutho,&AdminAuth,sizeof(SID_IDENTIFIER_AUTHORITY));   
			}   
		}   
		delete []pSid;   
		delete []bufDomain;   
	}   
	if(bAdminPrivilege)   
		return TRUE;  */ 

	DWORD   rc;   
	USER_INFO_1   *info = NULL;   
	rc   =   NetUserGetInfo(NULL,  LPCWSTR(_strUserName),1,(byte**)&info);   
	if(rc == NERR_Success)   
	{   
		_bAdminPrivilege  =  info->usri1_priv  == USER_PRIV_ADMIN;   
		NetApiBufferFree(info);   
	}   
	else
	{
		if (rc ==  5)
		{
			OutputDebugStringWEx( L"IsAdminUserPrivilege return rc ==  5"); 
			return TRUE;
		}
		OutputDebugStringWEx( L"IsAdminUserPrivilege %d failed",GetLastError()); 
	}

	return rc  ==  NERR_Success;   
}


BOOL  GetLogonUser(TCHAR * _strName)
{
	BOOL bRet = FALSE;
	TCHAR *szLogName = NULL;	//for xp or above
	DWORD dwSize = 0;
	if (_strName == NULL)
	{
		OutputDebugStringWEx( L"GetLogonUser failed _strName == NULL " ); 
		return bRet;
	}

	__try
	{
		if (WTSQuerySessionInformation(WTS_CURRENT_SERVER_HANDLE,
			WTS_CURRENT_SESSION,
			WTSUserName,
			&szLogName,
			&dwSize))
		{		
			if (szLogName[0] == NULL)
			{
				OutputDebugStringWEx( L"GetLogonUser WTSQuerySessionInformation failed %d ", GetLastError()); 
				return bRet;
			}
			wcscpy(_strName,szLogName);
			WTSFreeMemory(szLogName);
			bRet = TRUE;
		}
	}
 	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		OutputDebugStringWEx( L"GetLogonUser WTSQuerySessionInformation !!! __except failed %d ", GetLastError()); 
		return FALSE;
	}

	return bRet;
} 


BOOL GetRegStr2(HKEY hKey2,LPCWSTR lpKeyName,LPCWSTR lpValueName,LPWSTR lpValueData)
{
	int RetVal = 0;
	DWORD	IsRuned = 0;
	DWORD	ValLen = MAX_PATH;
	LSTATUS	lstatus = ERROR_SUCCESS;
	HKEY    hKey = NULL;
	HKEY    hCompanyKey = NULL;
	HKEY    hAppKey = NULL;
	DWORD dw;

	if ( ERROR_SUCCESS != RegOpenKeyEx( hKey2 ,
		lpKeyName,
		0,
		(KEY_WRITE | KEY_READ),
		&hKey ) )
	{
		if (ERROR_SUCCESS  !=  RegCreateKeyEx(HKEY_LOCAL_MACHINE, SUBKEY_GET_VALUES, 0, REG_NONE,
			REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL,
			&hKey, &dw))
		{
			OutputDebugStringWEx(L" DamageGuardSvc   RegOpenKeyExW %s  ERROR " , lpValueName);
			return FALSE;
		}
	}
	if (hKey == NULL)
	{
		OutputDebugStringWEx(L" DamageGuardSvc   RegOpenKeyExW %s  ERROR " , lpValueName);
		return FALSE;
	}
	ValLen=MAX_PATH; 

	lstatus = RegQueryValueEx ( hKey,
		lpValueName,  
		NULL,
		NULL,
		(LPBYTE)lpValueData,
		&ValLen);
	if (lstatus == ERROR_FILE_NOT_FOUND)
	{
		RetVal = FALSE;
		goto Clean_Exit;
	}
	else if (lstatus == ERROR_SUCCESS)
	{
		RetVal = TRUE;
	}
	else
	{
		RetVal = FALSE;
	}

Clean_Exit:
	if (hKey)
	{
		RegCloseKey(hKey);
	}

	return RetVal;
}



BOOL CNcInterfaceApp::InitInstance()
{
  //   g_EnableDebugPriv();
	 //AdjustToken();
  
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
 
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
 

	int iCount = __argc;
	CString cmd = __wargv[0];

	CPic dlg;//  [7/4/2019 wh-y50]
	dlg.DoModal();


	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
