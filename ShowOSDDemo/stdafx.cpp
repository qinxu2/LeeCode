// stdafx.cpp : source file that includes just the standard includes
// NcInterface.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#define  INI_FILE_NAME TEXT("config.dll")

BOOL g_nPreSenceOrInterface = FALSE;
BOOL g_nNoInterface = FALSE;
HWND g_nIndexHwndBtn = NULL;
HWND g_nMainHwnd = NULL;
CFont *g_pTempContextFont=NULL;
CFont *g_pTempBtnFont=NULL;
TCHAR  g_strTempContext[MAXTIPCOUNT] ={0};

BOOL g_NotSupportLanguage = FALSE;
BOOL g_IsLanguageRightAlign  = FALSE;
BOOL g_IsJapaneseLanguage  = FALSE;
BOOL g_IsbulgarianLanguage  = FALSE;


DWORD g_dwCurrentLanSmBackground = 0; 
DWORD g_dwCurrentLanguageBigBackground = 0; 
DWORD g_dwCurrentLanguage = 0;
TCHAR g_szCurrentLanguageType[64] = {0};
 
DWORD g_dwBigContext_X_Lift_Margins = 60;
DWORD g_dwBigContext_Y_top_Margins = 40;
DWORD g_dwBigContext_RX_Right_Margins = 50;
DWORD g_dwBigContext_BY_bottom_Margins = 60;

DWORD g_dwBigContext_Width = 12;

DWORD g_dwBigBtn_X1_pos = 0;
DWORD g_dwBigBtn_X2_pos = 0;
DWORD g_dwBigBtn_Y_pos = 0;
DWORD g_dwBigBtn_W_len = 0;
DWORD g_dwBigBtn_H_len = 0;

DWORD g_dwSmBtn_X1_pos = 0;
DWORD g_dwSmBtn_X2_pos = 0;
DWORD g_dwSmBtn_Y_pos = 0;
DWORD g_dwSmBtn_W_len = 0;
DWORD g_dwSmBtn_H_len = 0;

DWORD g_dwSkypeBackground = 0;
DWORD g_dwSkypeCloseNor = 0;
DWORD g_dwSkypeCloseOn = 0;
DWORD g_dwSkypeDownloadNor = 0;
DWORD g_dwSkypeDownloadOn = 0;


DWORD g_close_1 = 0;
DWORD g_close_2 = 0;

DWORD g_time_1s = 0;
DWORD g_time_2s = 0;
DWORD g_time_3s = 0;
DWORD g_time_4s = 0;
DWORD g_time_5s = 0;
DWORD g_time_always = 0;
DWORD g_time_frame = 0;
DWORD g_time_1s_1 = 0;
DWORD g_time_2s_1 = 0;
DWORD g_time_3s_1 = 0;
DWORD g_time_4s_1 = 0;
DWORD g_time_5s_1 = 0;
DWORD g_time_always_1 = 0;



DWORD g_keyboardMin = 0;
DWORD g_keyboardMax = 0;
DWORD g_keyboardClose = 0;
DWORD g_keyboardAuto = 0;
DWORD g_cameraUnlock = 0;
DWORD g_cameraLock = 0;
DWORD g_capsUnlock = 0;
DWORD g_capsLock = 0;
DWORD g_fnUnlock = 0;
DWORD g_fnLock = 0;
DWORD g_ITSFATachometer = 0;
DWORD g_ITSLEBattery = 0;
DWORD g_ITSLEIntelligentColl = 0;
DWORD g_micLock = 0;
DWORD g_micUnlock = 0;
DWORD g_numberUnlock = 0;
DWORD g_numberLock = 0;
DWORD g_tpLock = 0;
DWORD g_tpUnlock = 0;



DWORD g_Pic_Chose = 0;



DWORD g_dwDownloadX = 0;
DWORD g_dwDownloadY = 0;
DWORD g_dwDownload_W_len = 0;
DWORD g_dwDownload_H_len = 0;


void initInterfaceValue(DWORD _dwBigBKParam,DWORD _dwSmBKParam)
{
	g_dwSmBtn_X1_pos = 160;
	g_dwSmBtn_X2_pos = 250;
	g_dwSmBtn_Y_pos = 180;
	g_dwSmBtn_W_len = 80;
	g_dwSmBtn_H_len = 30;


	g_dwCurrentLanguageBigBackground = _dwBigBKParam; // IDB_BIG_BG1;
	g_dwCurrentLanSmBackground = _dwSmBKParam;        // IDB_BMP_SM_BG;
 
	g_dwBigBtn_X1_pos = 140;
	g_dwBigBtn_X2_pos = 270;		
	g_dwBigBtn_W_len = 120;
	g_dwBigBtn_H_len = 30;
	if (_dwBigBKParam == IDB_BIG_BG)
	{
		g_dwBigBtn_Y_pos = 240;
		g_dwBigContext_X_Lift_Margins = 60;
		g_dwBigContext_Y_top_Margins = 40;
		g_dwBigContext_RX_Right_Margins = 50;
		g_dwBigContext_BY_bottom_Margins = 60;
	}
	else if (_dwBigBKParam == IDB_BIG_BG1)
	{
		g_dwBigBtn_Y_pos = 215;
		g_dwBigContext_X_Lift_Margins = 60;
		g_dwBigContext_Y_top_Margins = 40;
		g_dwBigContext_RX_Right_Margins = 50;
		g_dwBigContext_BY_bottom_Margins = 60;
	} 
	else if (_dwBigBKParam == IDB_BIG_BG2)
	{
		g_dwBigBtn_Y_pos = 245;
		g_dwBigBtn_X1_pos = 150+50;
		g_dwBigBtn_X2_pos = 270+50;
		g_dwBigContext_X_Lift_Margins = 50;
		g_dwBigContext_Y_top_Margins = 40;
		g_dwBigContext_RX_Right_Margins = 50;
		g_dwBigContext_BY_bottom_Margins = 60;
	}
	else if (_dwBigBKParam == IDB_BIG_BG3)
	{
		g_dwBigBtn_Y_pos = 255;
		g_dwBigBtn_X1_pos = 150+60;
		g_dwBigBtn_X2_pos = 270+60;
		g_dwBigContext_X_Lift_Margins = 50;
		g_dwBigContext_Y_top_Margins = 40;
		g_dwBigContext_RX_Right_Margins = 50;
		g_dwBigContext_BY_bottom_Margins = 60;
	}
}


void g_InitValueFromLanguage()
{
	CString cmd2 = __wargv[0] ;
	CString cmd =  __wargv[0];
	BOOL  bIsOOBEInterface = FALSE;


	g_dwCurrentLanguage = GetUserDefaultLCID();
	OutputDebugStringWEx(L"Interface ~~~~~~~~~~~ GetUserDefaultLCID  %d  ",g_dwCurrentLanguage);	
 	g_dwCurrentLanguage = GetSystemDefaultLCID();
	OutputDebugStringWEx(L"Interface~~~~~~~~~~~  GetSystemDefaultLCID %d   ", g_dwCurrentLanguage);		

  	memset(g_strTempContext,0,MAXTIPCOUNT);
	if (::LoadString(NULL, IDS_HELPFILE, g_strTempContext, MAXTIPCOUNT) )
	{
	 	if(0 == _tcscmp(g_strTempContext, L"hebrew") )
		{
			g_dwCurrentLanguage = 0x040d;
		}
 	    if(0 == _tcscmp(g_strTempContext, L"JP.chm") )
		{
			g_IsJapaneseLanguage = TRUE;
		}
 	    if(0 == _tcscmp(g_strTempContext, L"BG.chm") )
		{
			g_IsbulgarianLanguage = TRUE; 
		}
	}
 
	g_dwBigContext_Width = 8;
	_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
	initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

	if (bIsOOBEInterface) //调OOBE界面 
	{		 
		initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
	} 
	return ;

	if (__wargv[1] != NULL)
	{
		cmd2 = __wargv[1];
	}
	if (cmd == "Obe" || cmd == "O" || cmd == "o"||  cmd == "installend"||cmd == "-IE"||cmd == "/IE" ||cmd == "/IENTIP"||
		cmd2 == "Obe" || cmd2 == "O" || cmd2 == "o"||  cmd2 == "installend"||cmd2 == "-IE"||cmd2 == "/IE" || cmd2 == "/IENTIP")
	{
         bIsOOBEInterface = TRUE;
	}
	switch( g_dwCurrentLanguage ) 
	{ 			
	case   0x404:  	  //   0x0404   Chinese   (Taiwan   Region)   // 繁体中文 CHT zh-tw Traditional chinese 中文(繁体)
	case   0x804:     //   0x0804   Chinese   (PRC)  // 简体中文 CHS zh-cn Simplified Chinese 中文(简体)
	case   0x0c04:    //   0x0c04   Chinese   (Hong   Kong   SAR,   PRC)    
	case   0x1004: 	  //   0x1004   Chinese   (Singapore)  	 "微软雅黑"
		{ 
			g_dwBigContext_Width = 12;
 
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));//_T("Arial Unicode MS")
 
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			}
		}
		break; 

	case   0x0405://   0x0405   Czech   CSY cs-cz czech 捷克语
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0406://   0x0406   Danish   DAN da-dk danish 丹麦语
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0407://   0x0407   German   (Standard)    
	case   0x0807://   0x0807   German   (Swiss)    
	case   0x0c07://   0x0c07   German   (Austrian)    
	case   0x1007://   0x1007   German   (Luxembourg)    
	case   0x1407://   0x1407   German   (Liechtenstein)   DEU de-de German 德语(德国)
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0408:	 //   0x0408   Greek   ELL el-gr greek 希腊语
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;
	
	case   0x040a:	//   0x040a   Spanish   (Traditional   Sort)    
	case   0x080a:	//   0x080a   Spanish   (Mexican)    
	case   0x0c0a:	//   0x0c0a   Spanish   (Modern   Sort)    
	case   0x100a:	//   0x100a   Spanish   (Guatemala)    
	case   0x140a:	//   0x140a   Spanish   (Costa   Rica)    
	case   0x180a:	//   0x180a   Spanish   (Panama)    
	case   0x1c0a:	//   0x1c0a   Spanish   (Dominican   Republic)    
	case   0x200a:	//   0x200a   Spanish   (Venezuela)    
	case   0x240a:	//   0x240a   Spanish   (Colombia)    
	case   0x280a:	//   0x280a   Spanish   (Peru)    
	case   0x2c0a:	//   0x2c0a   Spanish   (Argentina)    
	case   0x300a:  //   0x300a   Spanish   (Ecuador)    
	case   0x340a:  //   0x340a   Spanish   (Chile)    
	case   0x380a:	//   0x380a   Spanish   (Uruguay)    
	case   0x3c0a:	//   0x3c0a   Spanish   (Paraguay)    
	case   0x400a:  //   0x400a   Spanish   (Bolivia)    
	case   0x440a:	//   0x440a   Spanish   (El   Salvador)    
	case   0x480a:	//   0x480a   Spanish   (Honduras)    
	case   0x4c0a:	//   0x4c0a   Spanish   (Nicaragua)    
	case   0x500a:	//   0x500a   Spanish   (Puerto   Rico)  ESP es-es spanish 西班牙语(传统) 
		{		
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x040b:	//   0x040b   Finnish   FIN fi-fi finnish 芬兰语
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x040c:  //   0x040c   French   (Standard)    
	case   0x080c:  //   0x080c   French   (Belgian)    
	case   0x0c0c:  //   0x0c0c   French   (Canadian)    
	case   0x100c:	//   0x100c   French   (Swiss)    
	case   0x140c:	//   0x140c   French   (Luxembourg)    FRA fr-fr Frensh 法语(法国) 
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x040e:	//   0x040e   Hungarian    	HUN hu-hu hungarian 匈牙利语
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0411:	// LANG_JAPANESE  0x0411   Japanese    	JPN ja-jp Japanese 日语
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0412:	//   0x0412   Korean    
	case   0x0812:	//   0x0812   Korean   (Johab)  KOR ko-kr korean 韩语 
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0413:	//   0x0413   Dutch   (Standard)    
	case   0x0813:	//   0x0813   Dutch   (Belgian)   	NLD nl-nl dutch 荷兰语(荷兰)
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0414:	//   0x0414   Norwegian   (Bokmal)    
	case   0x0814:	//   0x0814   Norwegian   (Nynorsk)   NOR nb-no norwegian 挪威语(伯克梅尔)
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;


	case   0x0415:	//   0x0415   Polish    	PLK pl-pl polish 波兰语
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0410:  //   0x0410   Italian   (Standard)    
	case   0x0810:	//   0x0810   Italian   (Swiss)  ITA it-it italian 意大利语(意大利)
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0416:	//   0x0416   Portuguese   (Brazilian)   	PTB pt-br brazilian protuguese 葡萄牙语(巴西) 
	case   0x0816:	//   0x0816   Portuguese   (Standard)  	PTG pt-pt european portuguese 葡萄牙语(葡萄牙)
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0419:	//   0x0419   Russian   	RUS ru-ru Russian 俄语 
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x041d:	//   0x041d   Swedish    
	case   0x081d:	//   0x081d   Swedish   (Finland)   SVE sv-se swedish 瑞典语 
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x041f:	//   0x041f   Turkish   		TRK tr-tr Turkish 土耳其语
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;

	case   0x0409:  //   0x0409   English   (United   States)     英文	  ENU en-US English 英语(美国)
	case   0x0809:  //   0x0809   English   (United   Kingdom)    
	case   0x0c09: 	//   0x0c09   English   (Australian)    
	case   0x1009: 	//   0x1009   English   (Canadian)    
	case   0x1409: 	//   0x1409   English   (New   Zealand)    
	case   0x1809: 	//   0x1809   English   (Ireland)    
	case   0x1c09: 	//   0x1c09   English   (South   Africa)    
	case   0x2009: 	//   0x2009   English   (Jamaica)    
	case   0x2409: 	//   0x2409   English   (Caribbean)    
	case   0x2809: 	//   0x2809   English   (Belize)    
	case   0x2c09: 	//   0x2c09   English   (Trinidad)  
		{

			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
 
			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break; 

	case   0x0401: //   0x0401   Arabic   (Saudi   Arabia)    
	case   0x0801: //   0x0801   Arabic   (Iraq)    
	case   0x0c01: //   0x0c01   Arabic   (Egypt)    
	case   0x1001: //   0x1001   Arabic   (Libya)    
	case   0x1401: //   0x1401   Arabic   (Algeria)    
	case   0x1801: //   0x1801   Arabic   (Morocco)    
	case   0x1c01: //   0x1c01   Arabic   (Tunisia)    
	case   0x2001: //   0x2001   Arabic   (Oman)    
	case   0x2401: //   0x2401   Arabic   (Yemen)    
	case   0x2801: //   0x2801   Arabic   (Syria)    
	case   0x2c01: //   0x2c01   Arabic   (Jordan)    
	case   0x3001: //   0x3001   Arabic   (Lebanon)    
	case   0x3401: //   0x3401   Arabic   (Kuwait)    
	case   0x3801: //   0x3801   Arabic   (U.A.E.)    
	case   0x3c01: //   0x3c01   Arabic   (Bahrain)    
	case   0x4001: //   0x4001   Arabic   (Qatar) 
		{
		    //g_IsLanguageRightAlign = TRUE;
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI")); 
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
 
			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break; 

	case   0x040d: //   0x040d   Hebrew    
		{
		    //g_IsLanguageRightAlign = TRUE;
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI")); 
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
 
			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break; 
 
	case   0x0402:  //   0x0402   Bulgarian      
	case   0x041a:  //   0x041a   Croatian   
	case   0x0418:	//   0x0418   Romanian  
	case   0x041b:	//   0x041b   Slovak    
	case   0x0424:	//   0x0424   Slovenian  
		{
			g_dwBigContext_Width = 8;
			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
		}
		break;  


	default: // 未知语言，统一用英文件语言
		{
			g_dwBigContext_Width = 8;

			_tcscpy(g_szCurrentLanguageType,_T("Segoe UI"));
		 
			initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);

			if (bIsOOBEInterface) //调OOBE界面 
			{		 
				initInterfaceValue(IDB_BIG_BG1,IDB_BMP_SM_BG);
			} 
            g_NotSupportLanguage = TRUE;
		}
		break;
	};
}

//////////////////////////////////////////////////////////////////////////









BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize)
{
	// Get the required size of the buffer that receives the Unicode 
	// string. 
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, NULL, 0);

	if(dwSize < dwMinSize)
	{
		return FALSE;
	}
 
	// Convert headers from ASCII to Unicode.
	MultiByteToWideChar (CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize);  
	return TRUE;
}


BOOL WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_OEMCP,NULL,lpcwszStr,-1,NULL,0,NULL,FALSE);
	if(dwSize < dwMinSize)
	{
		return FALSE;
	}
	WideCharToMultiByte(CP_OEMCP,NULL,lpcwszStr,-1,lpszStr,dwSize,NULL,FALSE);
	return TRUE;
}


void WriteLogFile(TCHAR * DebugString)
{  
	HANDLE hFile;
	static DWORD dwCount = 0;
	DWORD nBytes; 
	TCHAR szBuff[MAX_PATH*3] = {0};
	hFile=CreateFile(_T("D:\\TestInstantResetLongRun\\Log\\IR_NcInterface.Log"),GENERIC_WRITE,FILE_SHARE_WRITE,NULL,/*CREATE_ALWAYS*/ OPEN_ALWAYS,0,NULL);

	if(hFile==INVALID_HANDLE_VALUE)
	{
		hFile=CreateFile(_T("D:\\TestInstantResetLongRun\\Log\\IR_NcInterface.Log"),GENERIC_WRITE,FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,0,NULL);
	}

	if(hFile!=INVALID_HANDLE_VALUE)
	{
		SetFilePointer(hFile, NULL  ,   NULL,   FILE_END); 
		static CHAR str_time[100];  
		struct tm *local_time = NULL;  
		time_t utc_time;   

		utc_time = time (NULL);  
		local_time = localtime(&utc_time);  
		strftime(str_time, sizeof(str_time),  ("%Y-%m-%d,%H:%M:%S"), local_time); 

		WCHAR _CurrentOldDirName[MAX_PATH];
		BOOL bRet = FALSE;
		MByteToWChar(str_time,_CurrentOldDirName,256);
		_stprintf(szBuff,TEXT("[%s %d] %s "),_CurrentOldDirName,dwCount++,DebugString);
		//_stprintf(szBuff,TEXT("[%d] %s \r\n"),dwCount++,DebugString);
		//_stprintf(szBuff,TEXT("[%d] %s "),dwCount++,DebugString);
		WriteFile(hFile,szBuff, _tcslen(szBuff)*sizeof(TCHAR)  ,&nBytes,NULL);//第三个参数可以直接sizeof(msg)

		CloseHandle(hFile);
	}
}


void OutputDebugStringWEx(TCHAR *lpszFormat,...)
{
	if (! PathIsDirectory( TEXT("D:\\TestInstantResetLongRun\\Log")  ))
	{
		return  ;
	}

	static TCHAR szMsg[512];
	va_list argList;
	va_start(argList, lpszFormat);
	try
	{
		_vstprintf(szMsg,lpszFormat, argList);
	}
	catch(...)
	{
		lstrcpy(szMsg ,_T("DebugHelper:Invalid string format!"));
	}
	va_end(argList);	

	static TCHAR DebugString[576] = {0};
	wsprintf(DebugString ,_T("<<<=NcInterface=>>>: %s\r\n"),szMsg);
	OutputDebugString(DebugString);


	WriteLogFile( DebugString);
}


CString GetIniString(CString strDefault , CString strKey)
{
	CString   strReturn = strDefault;
	TCHAR    strPath[MAX_PATH] = {0};
	int driverLocLen = GetCurrentDirectory(MAX_PATH,
		strPath	);
 
	_tcscat(strPath,_T("\\"));
	_tcscat(strPath,INI_FILE_NAME);

	::GetPrivateProfileString(TEXT("SimpleChinise"),strKey,(LPTSTR)(LPCTSTR)strDefault,(LPTSTR)(LPCTSTR)strReturn,512,strPath );

	return strReturn;
}



BOOL GetRegStr(LPCWSTR lpValueName,LPWSTR lpValueData)
{
	int RetVal = 0;
	DWORD	IsRuned = 0;
	DWORD	ValLen = MAX_PATH;
	LSTATUS	lstatus = ERROR_SUCCESS;
	HKEY    hKey = NULL;
	HKEY    hCompanyKey = NULL;
	HKEY    hAppKey = NULL;
	DWORD dw;

	if ( ERROR_SUCCESS != RegOpenKeyExW( HKEY_LOCAL_MACHINE,
		SUBKEY_GET_VALUES,
		0,
		( KEY_READ),
		&hKey ) )
	{
		if (ERROR_SUCCESS  !=  RegCreateKeyExW(HKEY_LOCAL_MACHINE, SUBKEY_GET_VALUES, 0, REG_NONE,
			REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL,
			&hKey, &dw))
		{
			//			OutputDebugStringWEx(L"     RegOpenKeyExW %s  ERROR " , lpValueName);
			return FALSE;
		}
	}
	if (hKey == NULL)
	{
		//OutputDebugStringWEx(L"     RegOpenKeyExW %s  ERROR " , lpValueName);
		return FALSE;
	}

	lstatus = RegQueryValueExW ( hKey,
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


BOOL SetRegStr( LPCWSTR lpValueName,  LPCWSTR strData )
{
	int RetVal = 0;
	DWORD	ValLen = MAX_PATH;
	LSTATUS	lstatus = ERROR_SUCCESS;
	HKEY    hKey = NULL;

	// ensure whether the service runned or not
	if ( ERROR_SUCCESS != RegOpenKeyExW( HKEY_LOCAL_MACHINE,
		SUBKEY_GET_VALUES,
		0,
		(KEY_WRITE | KEY_READ),
		&hKey ) )
	{
		//		OutputDebugStringWEx(L"     RegOpenKeyExW %s  ERROR %d",lpValueName,GetLastError());
		return FALSE;
	}

	if ( RegSetValueExW( hKey,
		lpValueName ,
		0,
		REG_EXPAND_SZ,             // value type
		(LPBYTE)strData,          // pointer to value data
		(wcslen(strData)+1)*sizeof(WCHAR) ) != ERROR_SUCCESS )
	{
		//		OutputDebugStringWEx(L"     RegSetValueExW %s  ERROR %d",lpValueName,GetLastError());
		if (hKey)
		{
			RegCloseKey(hKey);
		}
		return FALSE;
	}

	if (hKey)
	{
		RegCloseKey(hKey);
	}
	RegFlushKey(HKEY_LOCAL_MACHINE);

	return TRUE;
}


BOOL SetFindFileRegFlag( TCHAR * _szCurrentOldDirName)
{
	//WCHAR _CurrentOldDirName[MAX_PATH];
	BOOL bRet = FALSE;
	//MByteToWChar(_szCurrentOldDirName,_CurrentOldDirName,256);
	//bRet = SetRegStr(SVC_NEED_CLEAR_CUR_DIR_STR ,_CurrentOldDirName );
	bRet = SetRegStr(SVC_NEED_CLEAR_CUR_DIR_STR ,_szCurrentOldDirName );
	return bRet;
} 


BOOL ClearFindFileRegFlag()
{
	return  SetRegStr(SVC_NEED_CLEAR_CUR_DIR_STR,L"" );
}


// 从注册表得到找回文件的路径，
BOOL GetFindFileRegFlag( TCHAR * _szCurrentOldDirName)
{
	//WCHAR _CurrentOldDirName[MAX_PATH];
	BOOL bRet = FALSE;

	//bRet = GetRegStr(SVC_NEED_CLEAR_CUR_DIR_STR, _CurrentOldDirName );
	//WCharToMByte(_CurrentOldDirName, _szCurrentOldDirName, MAX_PATH);
	bRet = GetRegStr(SVC_NEED_CLEAR_CUR_DIR_STR, _szCurrentOldDirName );
	return bRet;
}


//////////////////////////////////////////////////////////////////////////
// 文件夹是否 不存在
BOOL IsFolderNotExist(TCHAR *_szFolderPath )
{
	if (_szFolderPath == NULL)
	{
		return FALSE;
	}
	// Returns TRUE if pszPath is an empty directory. Returns FALSE if pszPath is not a directory
	BOOL bRet =  PathIsDirectory(_szFolderPath);//,目录不存在或目录中有文件,返回假
	if (!bRet )
	{
		DWORD dwRet = GetLastError();//
		if ( 3 == dwRet ||  2 == dwRet ) // 指定目录不存在.
		{
			return TRUE; // 这里情况也视为空文件夹.
		}
	}
	return FALSE;
}
