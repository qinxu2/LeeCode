// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once
#pragma   warning(disable:4995)
#pragma   warning(disable:4996)
#pragma   warning(disable:4005)
#pragma   warning(disable:4244)
#pragma   warning(disable:4312)
#pragma   warning(disable:4267)
#if  defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else if defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#else if defined _M_IA64
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df'language='*'\"")
#endif
 
//
//#ifdef _UNICODE
//#if defined _M_IX86
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#elif defined _M_IA64
//#pragma comment(linker,"/manifestdependency:\"type='win64' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#elif defined _M_X64
//#pragma comment(linker,"/manifestdependency:\"type='win64' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x64' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#else
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#endif
//#endif
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define WINVER 0x0600   

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions


#include <afxdisp.h>        // MFC Automation classes

#include <windows.h>
#include <tchar.h>

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <winioctl.h>
#include <shlobj.h>
#include <strsafe.h>
#include <tlhelp32.h>
#include <Winsvc.h>
#include <shlwapi.h>
#include <ntsecapi.h>

#pragma comment(lib, "shlwapi.lib")
 




#include "resource.h"
#include "commonfactory.h"


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


//#define  RECT_IMAGE 




#define FSCTL_SOLID_DISK_BASE    0xBCDE

#define FSCTL_SOLID_GET_UICOMMU_FILE_CONTAIN  CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E03, METHOD_BUFFERED, FILE_READ_ACCESS)
//#define FSCTL_SOLID_SET_UICOMMU_FILE_CONTAIN  CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E04, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FSCTL_SOLID_UNINSTALL_DAMAGEGUARD   CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E05, METHOD_BUFFERED, FILE_READ_ACCESS)
#define FSCTL_SOLID_UPDATA_DAMAGEGUARD    CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E06, METHOD_BUFFERED, FILE_READ_ACCESS)

//#define FSCTL_SOLID_GET_STATUS                   (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E07, METHOD_NEITHER, FILE_ANY_ACCESS)  // Get Status
#define FSCTL_SOLID_SET_STATUS                   (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E08, METHOD_NEITHER, FILE_ANY_ACCESS)  // Set Status
//#define FSCTL_SOLID_GET_DIRTY_HIVE               (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E09, METHOD_NEITHER, FILE_ANY_ACCESS)  // Get DirtyHiveFileName
#define FSCTL_SOLID_SET_DIRTY_HIVE               (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E0A, METHOD_NEITHER, FILE_ANY_ACCESS)  // Set DirtyHiveFileName
//#define FSCTL_SOLID_GET_LAST_OLDDIR              (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E0B, METHOD_NEITHER, FILE_ANY_ACCESS)  // Get LastOldDirName
#define FSCTL_SOLID_SET_LAST_OLDDIR              (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E0C, METHOD_NEITHER, FILE_ANY_ACCESS)  // Set LastOldDirName
//#define FSCTL_SOLID_GET_CURT_OLDDIR              (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E0D, METHOD_NEITHER, FILE_ANY_ACCESS)  // Get CurrentOldDirName
#define FSCTL_SOLID_SET_CURT_OLDDIR              (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E0E, METHOD_NEITHER, FILE_ANY_ACCESS)  // Set CurrentOldDirName
//#define FSCTL_SOLID_GET_RENAMETODIR            (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E0F, METHOD_NEITHER, FILE_ANY_ACCESS)  // Get RenameToDirName
#define FSCTL_SOLID_SET_RENAMETODIR              (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E10, METHOD_NEITHER, FILE_ANY_ACCESS)  // Set RenameToDirName
//#define FSCTL_SOLID_GET_NEED_CREATEDIR           (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E11, METHOD_NEITHER, FILE_ANY_ACCESS)  // Get NeedCreateDirName
#define FSCTL_SOLID_SET_NEED_CREATEDIR           (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E12, METHOD_NEITHER, FILE_ANY_ACCESS)  // Set NeedCreateDirName
#define FSCTL_SOLID_SET_EXCHANG_SECTOR		(ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E13, METHOD_NEITHER, FILE_ANY_ACCESS)     // 设置交换扇区
#define FSCTL_SOLID_SET_BIOS_INFORMATION		(ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E14, METHOD_NEITHER, FILE_ANY_ACCESS) // 设置BIOS信息 to go home
#define FSCTL_SOLID_SET_BIOS_INFORMATION		(ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E14, METHOD_NEITHER, FILE_ANY_ACCESS) // 设置BIOS信息 to go home
#define FSCTL_SOLID_GOHOME_OK_REBOOT		    (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E15, METHOD_NEITHER, FILE_ANY_ACCESS) // 所有操作都以成功,需要重启PC
#define FSCTL_SOLID_GET_HADDDISKVOLUME		    (ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E16, METHOD_NEITHER, FILE_ANY_ACCESS) // 获得HarddiakVolume
#define FSCTL_SOLID_SEND_EXPLORER_NOTIFY_EVENT	(ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E17, METHOD_NEITHER, FILE_ANY_ACCESS) // APP send the envent handle to driver
#define FSCTL_SOLID_CLEAR_EXPLORER_NOTIFY_EVENT	(ULONG) CTL_CODE(FSCTL_SOLID_DISK_BASE, 0x0E18, METHOD_NEITHER, FILE_ANY_ACCESS) // APP clear the envent object to driver

 
//#define STAGE_NOT_SURE						0x0FFFF
#define STAGE_SPECAIL						0x04
#define STAGE_ERROR_TO_DISABLE				0x05
#define DAMAGEGUARD_ALL_STAGE_FLAG				(0x0003L)
#define DAMAGEGUARD_RUNNING_NORMAL				(0x0001L)// GOHOME时要清
#define DAMAGEGUARD_RUNNING_GOHOME				(0x0002L)// GOHOME时要设
#define DAMAGEGUARD_RUNNING_FIRST				(0x0003L)// GOHOME时要清

#define DAMAGEGUARD_ALL_POPUP_FLAG				(0x0078L)
#define DAMAGEGUARD_NEED_POPUP_NORMAL_UI		(0x0008L)
#define DAMAGEGUARD_RUNNING_GOHOME_ERROR_BIOS	(0x0010L) // 报ERROR
#define DAMAGEGUARD_RUNNING_GOHOME_FAILED_FSDR	(0x0020L) // 报ERROR 写交互扇区失败;写UICommu.bin失败;Set CMOS失败;Bios没有找到交互扇区;无法处理HIVE文件
#define DAMAGEGUARD_RUNNING_FUNC_DISABLE_FSDR	(0x0040L) // 报FAILED

#define DAMAGEGUARD_RUNNING_MAYBE_ABNORMAL		(0x0080L)   //using when go-home and first-run // GOHOME时要设
#define DAMAGEGUARD_RUNNING_UNINSTALL			(0x0100L)   // 卸载程序状态
#define DAMAGEGUARD_NEED_CHECK_COPY_PRECREATE	(0x0200L)	//need check the file whether copy or not when precreate.
#define DAMAGEGUARD_NEED_POP_SCROLL				(0x0400L)   // 弹出等待界面


#define DAMAGEGUARD_RUNNING_EXPLORER_INIT		(0x4000L)   //using when go-home and first-run
#define DAMAGEGUARD_UNINSTALL_NOPOP_UI		    (0x8000L)   //using when Uninstall and Second-run  no pop ui add by wh

#define STATUS_FUNCTION_DISABLE					((NTSTATUS)0xF90000CCL)
#define STATUS_FILE_DO_EXIST					((NTSTATUS)0xF90000CDL)

#define WM_CLICKED_MSG						WM_USER+3001
#define WM_SUPER_MSG						WM_USER+3000
#define WM_LVAMAKE_MSG						WM_USER+3002
#define WM_BTNFOCUS_MSG						WM_USER+3003
#define WM_SHOWOSD_MSG						WM_USER+3004

#define WM_MIC_MSG							WM_USER+3005
#define WM_FN_MSG							WM_USER+3006
#define WM_CAMERA_MSG						WM_USER+3007
#define WM_LED_MSG							WM_USER+3008
#define WM_ITS_MSG							WM_USER+3009
#define WM_CAPS_MSG							WM_USER+3010
#define WM_NUMBER_MSG						WM_USER+3011
#define WM_TP_MSG							WM_USER+3012

#define WM_TIME_1S_MSG						WM_USER+3020
#define WM_TIME_2S_MSG						WM_USER+3021
#define WM_TIME_3S_MSG						WM_USER+3022
#define WM_TIME_4S_MSG						WM_USER+3023
#define WM_TIME_5S_MSG						WM_USER+3024
#define WM_TIME_ALWAYS_MSG					WM_USER+3025

#define WM_MIC_STATUS						WM_USER+3030
#define WM_TP_STATUS						WM_USER+3031
#define WM_NUMLOCK_STATUS					WM_USER+3032
#define WM_FN_ON							WM_USER+3033
#define WM_FN_OFF							WM_USER+3034
#define WM_CAPS_STATUS						WM_USER+3035




#ifndef FlagOn
#define FlagOn(_F,_SF)        ((_F) & (_SF))
#endif

#ifndef BooleanFlagOn
#define BooleanFlagOn(F,SF)   ((BOOLEAN)(((F) & (SF)) != 0))
#endif

#ifndef SetFlag
#define SetFlag(_F,_SF)       ((_F) |= (_SF))
#endif

#ifndef ClearFlag
#define ClearFlag(_F,_SF)     ((_F) &= ~(_SF))
#endif

#define FILENAME_CHAR_LIMIT 16

#pragma  pack(push, 1)   //保存对齐状态.
#pragma  pack(1) //设定为字节对齐/


typedef struct _FS_COMMUNICATION_WITH_UI_INFO {
	ULONG	Size;  // whole block's size, not only this struct.
	ULONG	CheckSum1;  // whole block's sum is 0
	USHORT	Status;					// 1 - normal; 2 - go-home; 8 - popup message; 10 - go home error 1(bios,so continue normal OP); 20 - go home error 2(MiniFlter,).
	union {
		struct {
			USHORT RegCpBitmap;
			UCHAR  OtherFileCpBitmap;
			UCHAR  RunToStage;
		} u;
		ULONG	CpPreCreateBitmap;
	} BitMap;
	ULONG	GoHomeCount;            //go-home count from first running.
	USHORT	CommuSecLBA;      // 第一个逻辑分区的前2个分区位置,now the upest sector's 65535(about 31MB)
	LARGE_INTEGER	BackFileSecLBA;  // backup sectors file's location.
	WCHAR	NeedCreateDirName[FILENAME_CHAR_LIMIT];   // 该Name include NULL-char; go home or first call using
	WCHAR	RealMapDirName[FILENAME_CHAR_LIMIT];   // 该Name include NULL-char; normal using, get from NeedCreateDirName;
	WCHAR	RenameToDirName[FILENAME_CHAR_LIMIT];   // 该Name include NULL-char; go home using.
	WCHAR	CurrentOldDirName[FILENAME_CHAR_LIMIT];   // go home success. get from RenameToDirName; 当前需要打开和删除的上次的mapping dir
	WCHAR	LastOldDirName[FILENAME_CHAR_LIMIT];   // UI all check it.没有删除的上上次的mapping dir，马上需要删除;
	WCHAR	DirtyHiveFileName[FILENAME_CHAR_LIMIT];   // UI all check it.没有删除的dirty system hive file，马上需要删除;
	ULONG	Reserve1;  //Reserve1必须紧靠CheckSum2，Reserve2等放到1的前面
	ULONG	CheckSum2;
} FS_COMMUNICATION_WITH_UI_INFO, *PFS_COMMUNICATION_WITH_UI_INFO;
#pragma  pack()
#pragma  pack(pop) //恢复对齐状态T

#define PROGRAM_PROGRAM_PATH            L"Instant Reset"  //Lenovo 


#define	SUBKEY_GET_VALUES	L"SYSTEM\\CurrentControlSet\\services\\DeleteFileSys"  
#define SVC_NEED_CLEAR_CUR_DIR_STR   	L"LvClearCurDirPath"   // 清空本次的文件夹的路径
#define PROGRAM_NAME_UNINSTALL L"IRFuncMgr.exe"

// 280,200,115,30 
 
 
#define PRINT_TITAIL_ON_BG  1  //是否开启单一中文语言

#define USE_CHINA_LANGAGE  0  //是否开启单一中文语言

#define USE_DEFAULT_LANGAGE_TYPE  0 

#define CMemDC XCMemDC//  [7/3/2019 wh-y50]

void g_InitValueFromLanguage();
extern BOOL g_IsJapaneseLanguage ;
extern BOOL g_IsbulgarianLanguage  ;
extern BOOL g_IsLanguageRightAlign ; 

extern DWORD g_dwCurrentLanSmBackground ; 
extern DWORD g_dwCurrentLanguageBigBackground ; 

extern DWORD g_dwCurrentLanguage  ;
extern TCHAR g_szCurrentLanguageType[64] ;
  
extern DWORD g_dwBigBtn_X1_pos  ;
extern DWORD g_dwBigBtn_X2_pos  ;
extern DWORD g_dwBigBtn_Y_pos  ;
extern DWORD g_dwBigBtn_W_len  ;
extern DWORD g_dwBigBtn_H_len  ;

extern DWORD g_dwSmBtn_X1_pos  ;
extern DWORD g_dwSmBtn_X2_pos  ;
extern DWORD g_dwSmBtn_Y_pos  ;
extern DWORD g_dwSmBtn_W_len ;
extern DWORD g_dwSmBtn_H_len ;

extern DWORD g_dwBigContext_X_Lift_Margins  ;
extern DWORD g_dwBigContext_Y_top_Margins ;
extern DWORD g_dwBigContext_RX_Right_Margins  ;
extern DWORD g_dwBigContext_BY_bottom_Margins  ;

extern DWORD g_dwBigContext_Width ;

extern DWORD g_dwSkypeBackground;
extern DWORD g_dwSkypeCloseNor;
extern DWORD g_dwSkypeCloseOn;
extern DWORD g_dwSkypeDownloadNor;
extern DWORD g_dwSkypeDownloadOn;

extern DWORD g_dwDownloadX;
extern DWORD g_dwDownloadY;
extern DWORD g_dwDownload_W_len;
extern DWORD g_dwDownload_H_len;


extern DWORD g_close_1;
extern DWORD g_close_2;

extern DWORD g_time_1s;
extern DWORD g_time_2s;
extern DWORD g_time_3s;
extern DWORD g_time_4s;
extern DWORD g_time_5s;
extern DWORD g_time_always;
extern DWORD g_time_1s_1;
extern DWORD g_time_2s_1;
extern DWORD g_time_3s_1;
extern DWORD g_time_4s_1;
extern DWORD g_time_5s_1;
extern DWORD g_time_always_1;


extern DWORD g_keyboardMin;
extern DWORD g_keyboardMax;
extern DWORD g_keyboardClose;
extern DWORD g_keyboardAuto;
extern DWORD g_cameraUnlock;
extern DWORD g_cameraLock;
extern DWORD g_capsUnlock;
extern DWORD g_capsLock ;
extern DWORD g_fnUnlock ;
extern DWORD g_fnLock ;
extern DWORD g_ITSFATachometer ;
extern DWORD g_ITSLEBattery ;
extern DWORD g_ITSLEIntelligentColl ;
extern DWORD g_micLock ;
extern DWORD g_micUnlock ;
extern DWORD g_numberUnlock ;
extern DWORD g_numberLock ;
extern DWORD g_tpLock ;
extern DWORD g_tpUnlock;

extern DWORD g_Pic_Chose;



// 新OOBE 逻辑
/*
在安装包运行后，各个驱动和服务，都设为为不运行（start=4）。不执行重定向功能 安装包会在开始菜单增加开启功能选项。安装包装PUSHTOOL工具保留
在工厂初始化后， 将RUN 。设为最后调出OOBE界面，直到不为工厂模式的第一次重新启动，也就是OOBE， 
会提示用户选取择是否要开启 NC，或不开启。
不开启就退出，等待下次调出开启界面.
开启要去掉:安装包会在开始菜单增加开启功能选项。
检测文件是否丢失。
设置全部服务启动。
在下次重启全部程序开始工作，执行重定向操作。
*/
 


// 旧OOBE 逻辑
/*
在安装包运行后，各个驱动和服务，都开始运行(start=1)。但不执行重定向功能
检测（NC_JUDGE_OOBE_VOL）是否工厂模式，如果是工厂模式不去执行任何动作。
直到不为工厂模式的第一次重新启动，也就是OOBE，会提示用户重新启动。
在下次重启全部程序开始工作，执行重定向操作。
*/
 
#define NOT_WRITE_LOG 1

#define  MAXTIPCOUNT 1024
extern TCHAR  g_strTempContext[MAXTIPCOUNT] ;
extern CFont *g_pTempContextFont;
extern CFont *g_pTempBtnFont;

// 用于找回文件的目录 不显示的情况.
// 用于找回文件的目录 不显示的情况.
#define FIND_FILE_REDIRECT_NAME      TEXT("Retrieve Documents")   //   // add by wh 2011-10-18
#define GOHOME_FIND_FILE_FALG       TEXT("gohomefindfileflag")

// 用于找回文件的目录 设置 不显示真实目录 的情况.FIND_FILE_REDIRECT_NAME   // add by wh 2011-10-18
BOOL CreateFindFileRedirect(TCHAR *szpath);
BOOL GetChgGohomePathFlag(OUT TCHAR *_RanameFileName);


// 从配制表中获得语言
CString GetIniString(CString strDefault , CString strKey);

// 从注册表得到找回文件的路径，
BOOL GetFindFileRegFlag( TCHAR * _SyspathDefaultPath);
BOOL SetFindFileRegFlag( TCHAR * _CurrentOldDirName);
BOOL CallClearFolderProcess( LPCTSTR lpFileName);

BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);
BOOL WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize);

// 文件夹是否 不存在
BOOL IsFolderNotExist(TCHAR *_szFolderPath );


BOOL g_EnableDebugPriv();
void OutputDebugStringWEx(TCHAR *lpszFormat,...);

// 删除文件夹
BOOL  DeleteFolder(LPCTSTR szPath);
 
// 文件夹重命名
BOOL ReNameFolder(LPTSTR lpszFromPath,LPTSTR lpszToPath);



extern HWND g_nIndexHwndBtn;
extern HWND g_nMainHwnd;
extern BOOL g_NotSupportLanguage;
extern BOOL g_nPreSenceOrInterface;
extern BOOL g_nNoInterface;
//////////////////////////////////////////////////////////////////////////
// 当调用语言失败的情况调用这个地方。
#define  DEF_IDS_GOHOME_DLG          "\nThe system has already been reset to the state when you enabled Instant Reset for the first time. Click \"Retrieve Files\", the users' files on the original system disk (c:\\) will be displayed in the prompted resource manager window. It is expected for you to promptly copy the files to another disk path! If you have completed the backup, please click \"Clear Files\" to use your disk space more efficiently!"
#define  DEF_IDS_GOHOME_DLG_FILDFILE_BTN  "     Retrieve Files"
#define  DEF_IDS_GOHOME_DLG_CLEARFILE_BTN "    Clear Files"
#define  DEF_IDS_GOHOME_DLG_CHECK_BTN "Don't show this next time."
#define  DEF_IDS_GOHOMECLEARFILE_MSGDLG "Have you already retrieved your files?  \nClicking \"OK\" empty the \"Retrieve Files\",including My Documents,Desktop,Program Files,User-created folders etc.  \nPlease check these files are needless before you continue!"
#define  DEF_IDS_GOHOMEPATHNOTEXIST_MSGDLG  "\n\n   The file path you are retrieving does not exist. "
#define  DEF_IDS_GOHOMEERROR_DLG     "\n\nSorry! Instant Reset failed in operation. Please restart the operating system to correct it or uninstall this software on the Start menu. "
#define  DEF_IDS_GOHOMEERROR_DLG_QUIT_BTN " Quit"
#define  DEF_IDS_OBE_DLG_PAGE2              "\nPlease click \"Enable Now\" to restart the operating system for enabling this software. \nYou can also click \"Quit\" and start this software later.\nBefore using this software, please read carefully chapter 4 of UserGuide."
#define  DEF_IDS_GOHOMEFAILED_DLG    "\n\nSorry! Instant Reset failed in operation. Please restart the operating system to correct it or uninstall this software on the Start menu. "
#define  DEF_IDS_GOHOMEFAILED_DLG_REPAIR_BTN "    Repair"
#define  DEF_IDS_GOHOMEFAILED_DLG_QUIT_BTN " Quit"
#define  DEF_IDS_IMPORTREG_DLG       "\n\nPlease wait a moment. Instant Reset is refreshing. "
#define  DEF_IDS_ISGOHOME_DLG        "\n\nInstant Reset will reset your system partition settings to the initial state when you enabled Instant Reset. Please back up your important data.  \nDo you want to continue? " 
#define  DEF_IDS_ISGOHOME_DLG_CONTIUNE_BTN "   Continue"
#define  DEF_IDS_ISGOHOME_DLG_QUIT_BTN     " Quit"
#define  DEF_IDS_ISGOHOME_CONTIUNE_MSGDLG  "\nYour system partitions will be reset to the initial state when they were the first time you enabled Instant Reset. The system will restart if you continue. Please back up your important data."
#define  DEF_IDS_REPAIROK_MSGDLG     "\n      Software repair successful."
#define  DEF_IDS_REPAIRFAILED_MSGDLG "\nSoftware repair unsuccessful. Please uninstall this program."
#define  DEF_IDS_UNINSTALL_DLG       "\n\nDo you wish to uninstall this program? Your computer will be forced to restore to the state it was the first time this software was used. Users' data will be lost. Please back up users' data from your computer."
#define  DEF_IDS_UNINSTALL_CONTIUNE_MSGDLG "\nClicking \"OK\" will restart your operating system and restore it to the state when Instant Reset was used for the first time. Users' files will be lost. Please back up the important data stored on the system disk."
#define  DEF_IDS_UNINSTALL_DLG_CONTIUNE_BTN "     Continue"
#define  DEF_IDS_UNINSTALL_DLG_QUIT_BTN     " Quit"
#define  DEF_IDS_MESSAGEBOXEX_OK     "  Ok"
#define  DEF_IDS_MESSAGEBOXEX_CANCEL "  Cancel"
#define  DEF_IDS_PROGRAM_FILE_NOT_EXIST  "\n\nThere are important files missing from this program. Please reinstall this program to ensure it runs correctly."
#define  DEF_IDS_REBOOTSYS_DLG       "The system will power down immediately. Please save all unsaved files. "
#define  DEF_IDS_REBOOTSYS_DLG_BTN   "Restart Now"
#define  DEF_IDS_REBOOTSYS_DLG_COUNT_TIME "Shutdown after: %02d seconds"
#define  DEF_IDS_OBE_DLG_ENABLE_BTN2  "     Enable Now" 
#define  DEF_IDS_OBE_DLG_DISABLE_BTN2 "  Quit"
#define  DEF_IDS_ADDMENU_GOHOME_TIP2 "Reboot the system, the system will be restored to its initial state."
#define  DEF_IDS_STOPCREATERECOVER_MSGDLG2 "\n\nLenovo Instant Reset system software has been enabled. The Windows System Restore function is disabled."
#define  DEF_IDS_MENU_HELP           "Help.lnk"
#define  DEF_IDS_MENU_UNINSTALL      "Uninstall.lnk"
#define  DEF_IDS_MENU_FINDFILE       "Retrieve Files.lnk"
#define  DEF_IDS_MENU_INITINSTANT    "Initialize Instant Reset.lnk"
#define  DEF_IDS_IS_UNINSTALL        "\n\n\nDo you wish to uninstall this program? "
#define  DEF_IDS_UNINSATLL_END       "\n\n\n     Uninstall Complete."
#define  DEF_IDS_INSTALL_SUCCESS     "\n\n\n    Installation completed successfully."
#define  DEF_IDS_START_NC_NO_RIGHTS   "\n\nYou need to run the software in the administrator user. "
#define  DEF_IDS_OBE_DLG      "\n\nThank you for using Lenovo Instant Reset system software. It can quickly reset your system to the state when this software was initially enabled. \n Hint: When you start this software, the system restore function of Windows will be automatically disabled. "
#define  DEF_IDS_START_NC_NO_FREE_SPACE  "\n\n  Insufficient disk space." 


