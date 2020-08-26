// NcInterface.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CNcInterfaceApp:
// See NcInterface.cpp for the implementation of this class
//

class CNcInterfaceApp : public CWinApp
{
public:
	CNcInterfaceApp();

	//BOOL  IsAdminUserPrivilege(const   CString   &   strUserName,BOOL   &   bAdminPrivilege) ;  
// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CNcInterfaceApp theApp;