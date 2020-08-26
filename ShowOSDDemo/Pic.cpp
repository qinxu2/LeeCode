// Pic.cpp : 实现文件
//

#include "stdafx.h"
#include "Pic.h"
#include "afxdialogex.h"
#include "cgdiplusbitmap.h"
#include "Resource.h"
#include <../atlmfc/include/atlimage.h>
// CPic 对话框

IMPLEMENT_DYNAMIC(CPic, CDialog)
int g_nIndexSelIcon = 0;
int i = 0;
int g_nWidthpic = 0;
int g_nHeightpic = 0;
BOOL g_bHideWin = TRUE;
BOOL g_micState = FALSE;
BOOL g_cameraState = FALSE;
BOOL g_TPState = FALSE;
BOOL g_numberState = FALSE;
BOOL g_capsState = FALSE;
BOOL g_fnState = FALSE;
DWORD g_ITSState = 0;
DWORD g_LEDState = 0;
bool FirstRun = TRUE;
BOOL g_BtnRun = FALSE;
int g_bFlageDlgShowOrHide = 0;

CPic::CPic(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PIC, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CPic::~CPic()
{
}

void CPic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_APP_ICON_1, m_btnMic);
	DDX_Control(pDX, IDC_APP_ICON_1_1, m_btnMic1);
	DDX_Control(pDX, IDC_APP_ICON_2, m_btnCamera);
	DDX_Control(pDX, IDC_APP_ICON_2_1, m_btnCamera1);
	DDX_Control(pDX, IDC_APP_ICON_3, m_btnTP);
	DDX_Control(pDX, IDC_APP_ICON_3_1, m_btnTP1);
	DDX_Control(pDX, IDC_APP_ICON_4, m_btnNumber);
	DDX_Control(pDX, IDC_APP_ICON_4_1, m_btnNumber1);
	DDX_Control(pDX, IDC_APP_ICON_5, m_btnCaps);
	DDX_Control(pDX, IDC_APP_ICON_5_1, m_btnCaps1);
	DDX_Control(pDX, IDC_APP_ICON_6, m_btnFn);
	DDX_Control(pDX, IDC_APP_ICON_6_1, m_btnFn1);
	DDX_Control(pDX, IDC_APP_ICON_7, m_btnITS);
	DDX_Control(pDX, IDC_APP_ICON_7_1, m_btnITS1);
	DDX_Control(pDX, IDC_APP_ICON_7_2, m_btnITS2);
	DDX_Control(pDX, IDC_APP_ICON_8, m_btnKeyboardLED);
	DDX_Control(pDX, IDC_APP_ICON_8_1, m_btnKeyboardLED1);
	DDX_Control(pDX, IDC_APP_ICON_8_2, m_btnKeyboardLED2);
	DDX_Control(pDX, IDC_APP_ICON_8_3, m_btnKeyboardLED3);
	DDX_Control(pDX, IDC_BUTTON1, m_btnCloseOSD);

	DDX_Control(pDX, IDC_BTN_TIME, m_btnTime1);
	DDX_Control(pDX, IDC_BTN_TIME2, m_btnTime2);
	DDX_Control(pDX, IDC_BTN_TIME3, m_btnTime3);
	DDX_Control(pDX, IDC_BTN_TIME4, m_btnTime4);
	DDX_Control(pDX, IDC_BTN_TIME5, m_btnTime5);
	DDX_Control(pDX, IDC_BTN_TIMEALWAYS, m_btnTimeAlways);
	DDX_Control(pDX, IDC_BTN_TIME_1, m_btnTime1_1);
	DDX_Control(pDX, IDC_BTN_TIME2_1, m_btnTime2_1);
	DDX_Control(pDX, IDC_BTN_TIME3_1, m_btnTime3_1);
	DDX_Control(pDX, IDC_BTN_TIME4_1, m_btnTime4_1);
	DDX_Control(pDX, IDC_BTN_TIME5_1, m_btnTime5_1);
	DDX_Control(pDX, IDC_BTN_TIMEALWAYS_1, m_btnTimeAlways_1);
}


BEGIN_MESSAGE_MAP(CPic, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CPic::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(WM_BTNFOCUS_MSG, &CPic::OnBtnFocusMsg)
	ON_MESSAGE(WM_CLICKED_MSG, &CPic::OnClickedMsg)
	ON_MESSAGE(WM_SUPER_MSG, &CPic::OnPressMsg)

	ON_MESSAGE(WM_SHOWOSD_MSG, &CPic::OnShowOSD)

	ON_MESSAGE(WM_MIC_MSG, &CPic::OnMicPress)
	ON_MESSAGE(WM_FN_MSG, &CPic::OnFnPress)
	ON_MESSAGE(WM_CAMERA_MSG, &CPic::OnCmeraPress)
	ON_MESSAGE(WM_LED_MSG, &CPic::OnKeyBoardLEDPress)
	ON_MESSAGE(WM_ITS_MSG, &CPic::OnITSPress)
	ON_MESSAGE(WM_CAPS_MSG, &CPic::OnCapsPress)
	ON_MESSAGE(WM_NUMBER_MSG, &CPic::OnNumberLockPress)
	ON_MESSAGE(WM_TP_MSG, &CPic::OnTpLockPress)

	ON_BN_CLICKED(IDC_BUTTON2, &CPic::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_APP_ICON_1, &CPic::OnBnClickedAPPIcon1)
	ON_BN_CLICKED(IDC_APP_ICON_1_1, &CPic::OnBnClickedAppIcon11)
	ON_BN_CLICKED(IDC_APP_ICON_2, &CPic::OnBnClickedAPPIcon2)
	ON_BN_CLICKED(IDC_APP_ICON_2_1, &CPic::OnBnClickedAppIcon21)
	ON_BN_CLICKED(IDC_APP_ICON_3, &CPic::OnBnClickedAPPIcon3)
	ON_BN_CLICKED(IDC_APP_ICON_3_1, &CPic::OnBnClickedAppIcon31)
	ON_BN_CLICKED(IDC_APP_ICON_4, &CPic::OnBnClickedAPPIcon4)
	ON_BN_CLICKED(IDC_APP_ICON_4_1, &CPic::OnBnClickedAppIcon41)
	ON_BN_CLICKED(IDC_APP_ICON_5, &CPic::OnBnClickedAPPIcon5)
	ON_BN_CLICKED(IDC_APP_ICON_5_1, &CPic::OnBnClickedAppIcon51)
	ON_BN_CLICKED(IDC_APP_ICON_6, &CPic::OnBnClickedAppIcon6)
	ON_BN_CLICKED(IDC_APP_ICON_6_1, &CPic::OnBnClickedAppIcon61)
	ON_BN_CLICKED(IDC_APP_ICON_7, &CPic::OnBnClickedAppIcon7)
	ON_BN_CLICKED(IDC_APP_ICON_7_1, &CPic::OnBnClickedAppIcon71)
	ON_BN_CLICKED(IDC_APP_ICON_7_2, &CPic::OnBnClickedAppIcon72)
	ON_BN_CLICKED(IDC_APP_ICON_8, &CPic::OnBnClickedAppIcon8)
	ON_BN_CLICKED(IDC_APP_ICON_8_1, &CPic::OnBnClickedAppIcon81)
	ON_BN_CLICKED(IDC_APP_ICON_8_2, &CPic::OnBnClickedAppIcon82)
	ON_BN_CLICKED(IDC_APP_ICON_8_3, &CPic::OnBnClickedAppIcon83)
	ON_WM_NCHITTEST()
	ON_WM_NCMOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_ACTIVATE()
	ON_WM_ERASEBKGND()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BTN_TIME, &CPic::OnBnClickedBtnTime)
	ON_BN_CLICKED(IDC_BTN_TIME4, &CPic::OnBnClickedBtnTime4)
	ON_BN_CLICKED(IDC_BTN_TIME2, &CPic::OnBnClickedBtnTime2)
	ON_BN_CLICKED(IDC_BTN_TIME3, &CPic::OnBnClickedBtnTime3)
	ON_BN_CLICKED(IDC_BTN_TIME5, &CPic::OnBnClickedBtnTime5)
	ON_BN_CLICKED(IDC_BTN_TIMEALWAYS, &CPic::OnBnClickedBtnTimealways)
	ON_BN_CLICKED(IDC_BTN_TIME_1, &CPic::OnBnClickedBtnTime1)
	ON_BN_CLICKED(IDC_BTN_TIME2_1, &CPic::OnBnClickedBtnTime21)
	ON_BN_CLICKED(IDC_BTN_TIME3_1, &CPic::OnBnClickedBtnTime31)
	ON_BN_CLICKED(IDC_BTN_TIME4_1, &CPic::OnBnClickedBtnTime41)
	ON_BN_CLICKED(IDC_BTN_TIME5_1, &CPic::OnBnClickedBtnTime51)
	ON_BN_CLICKED(IDC_BTN_TIMEALWAYS_1, &CPic::OnBnClickedBtnTimealways1)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CPic 消息处理程序


BOOL CPic::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetWindowText(L"LSK_ShowOSD_Window");
	g_nMainHwnd = this->GetSafeHwnd();

	

	ULONG_PTR uToken;
	GdiplusStartupInput gsi;
	GdiplusStartup(&uToken, &gsi, NULL);

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
	ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);


	int nWidthBtnClose = 0;
	int nHeightBtnClose = 0;

	int nWidthBtnDownload = 0;
	int nHeightBtnDownload = 0;

	int nWidthpic = 0;
	int nHeightpic = 0;

	int cxIcon = GetSystemMetrics(SM_CXSCREEN);
	int cyIcon = GetSystemMetrics(SM_CYSCREEN);
	if (cxIcon==3840 && cyIcon==2160&&0)
	{
		
	} 
	else if (cxIcon==2560 && cyIcon == 1440&&0)
	{
		
	}
	else if ((cxIcon == 1920 && cyIcon == 1080)|| (cxIcon == 2560 && cyIcon == 1440)|| (cxIcon == 3840 && cyIcon == 2160))
	{
		g_dwSkypeBackground = IDB_SKYPE_BG1;
		g_micLock = IDB_MIC_MUTE;
		g_micUnlock = IDB_MIC_UNMUTE;
		g_cameraLock = IDB_CAMERA_LOCK;
		g_cameraUnlock = IDB_CAMERA_UNLOCK;
		g_tpLock = IDB_TP_LOCK;
		g_tpUnlock = IDB_TP_UNLOCK;
		g_numberLock = IDB_NUMBER_LOCK;
		g_numberUnlock = IDB_NUMBER_UNLOCK;
		g_capsLock = IDB_CAPS_LOCK;
		g_capsUnlock = IDB_CAPS_UNLOCK;
		g_fnLock = IDB_FN_LOCK;
		g_fnUnlock = IDB_FN_UNLOCK;
		g_ITSFATachometer = IDB_ITS4_FA_TACHOMETER;
		g_ITSLEBattery = IDB_ITS4_LE_BATTERY;
		g_ITSLEIntelligentColl = IDB_ITS4_LE_INTERLLIGENTCOOL;
		g_keyboardAuto = IDB_KEYBOARDLED_AUTO;
		g_keyboardClose = IDB_KEYBOARDLED_CLOSE;
		g_keyboardMax = IDB_KEYBOARDLED_MAX;
		g_keyboardMin = IDB_KEYBOARDLED_MIN;

		g_close_1 = IDB_CLOSE_1;
		g_close_2 = IDB_CLOSE_2;

		g_time_1s = IDB_TIME_1S;
		g_time_2s = IDB_TIME_2S;
		g_time_3s = IDB_TIME_3S;
		g_time_4s = IDB_TIME_4S;
		g_time_5s = IDB_TIME_5S;
		g_time_always= IDB_TIME_ALWAYS;
		g_time_1s_1 = IDB_TIME_1S_1;
		g_time_2s_1 = IDB_TIME_2S_1;
		g_time_3s_1 = IDB_TIME_3S_1;
		g_time_4s_1 = IDB_TIME_4S_1;
		g_time_5s_1 = IDB_TIME_5S_1;
		g_time_always_1 = IDB_TIME_ALWAYS_1;
	
		g_nWidthpic = nWidthpic = 50;
		g_nHeightpic = nHeightpic = 50;

	}
	else
	{
		
	}

	CRect rect;
	CBitmap  bmpBackground;
	//GetClientRect(&rect);
	bmpBackground.LoadBitmap(g_dwSkypeBackground);
	BITMAP bmInfo;
	bmpBackground.GetObject(sizeof(bmInfo), &bmInfo);
	MoveWindow(0, 0, bmInfo.bmWidth, bmInfo.bmHeight, TRUE);	
	GetClientRect(&rect);
	float fWidth = rect.right - rect.left;
	float fHeight = rect.bottom - rect.top;
	CRect WinSite;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &WinSite, 0);//工作区大小
	MoveWindow(WinSite.Width() / 2 - 1010 / 2, WinSite.Height() - bmInfo.bmHeight, bmInfo.bmWidth, bmInfo.bmHeight);
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	//read RegValue


	//1
	DWORD val;
	ReadRegValue(&val, REGSUBKEY_MIC);

	if (val == 0) {
		g_micState = FALSE;
		m_btnMic.m_bEnableWords = TRUE;
		m_btnMic.SetBK(g_micLock);
		m_btnMic.SetFont(g_pTempBtnFont);
		m_btnMic.LoadStdImage(g_micLock, _T("PNG"));
		m_btnMic.LoadStdImageHover(g_micLock, _T("PNG"));
		m_btnMic.LoadAltImage(g_micLock, _T("PNG"));
		m_btnMic.EnableToggle(TRUE);

		m_btnMic.SetImageSize(nWidthpic, nHeightpic);
		m_btnMic.MoveWindow(41, 53, nWidthpic, nHeightpic, FALSE);

		m_btnMic1.m_bEnableWords = true;
		m_btnMic1.SetBK(g_micUnlock);
		m_btnMic1.SetFont(g_pTempBtnFont);
		m_btnMic1.LoadStdImage(g_micUnlock, _T("PNG"));
		m_btnMic1.LoadStdImageHover(g_micUnlock, _T("PNG"));
		m_btnMic1.LoadAltImage(g_micUnlock, _T("PNG"));
		m_btnMic1.SetImageSize(nWidthpic, nHeightpic);
		m_btnMic1.MoveWindow(41, 400, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 1) {
		g_micState = TRUE;
		m_btnMic.m_bEnableWords = true;
		m_btnMic.SetBK(g_micLock);
		m_btnMic.SetFont(g_pTempBtnFont);
		m_btnMic.LoadStdImage(g_micLock, _T("PNG"));
		m_btnMic.LoadStdImageHover(g_micLock, _T("PNG"));
		m_btnMic.LoadAltImage(g_micLock, _T("PNG"));
		m_btnMic.SetImageSize(nWidthpic, nHeightpic);
		m_btnMic.MoveWindow(41, 400, nWidthpic, nHeightpic, TRUE);
		m_btnMic1.m_bEnableWords = true;
		m_btnMic1.SetBK(g_micUnlock);
		m_btnMic1.SetFont(g_pTempBtnFont);
		m_btnMic1.LoadStdImage(g_micUnlock, _T("PNG"));
		m_btnMic1.LoadStdImageHover(g_micUnlock, _T("PNG"));
		m_btnMic1.LoadAltImage(g_micUnlock, _T("PNG"));
		m_btnMic1.SetImageSize(nWidthpic, nHeightpic);
		m_btnMic1.MoveWindow(41, 53, nWidthpic, nHeightpic, TRUE);
	}
	
	//2
	ReadRegValue(&val, REGSUBKEY_CAMERA);
	if (val == 0) {
		g_cameraState = FALSE;
		m_btnCamera.m_bEnableWords = true;
		m_btnCamera.SetBK(g_cameraLock);
		m_btnCamera.SetFont(g_pTempBtnFont);
		m_btnCamera.LoadStdImage(g_cameraLock, _T("PNG"));
		m_btnCamera.LoadStdImageHover(g_cameraLock, _T("PNG"));
		m_btnCamera.LoadAltImage(g_cameraLock, _T("PNG"));
		m_btnCamera.SetImageSize(nWidthpic, nHeightpic);
		m_btnCamera.MoveWindow(132, 53, nWidthpic, nHeightpic, TRUE);
		m_btnCamera1.m_bEnableWords = true;
		m_btnCamera1.SetBK(g_cameraUnlock);
		m_btnCamera1.SetFont(g_pTempBtnFont);
		m_btnCamera1.LoadStdImage(g_cameraUnlock, _T("PNG"));
		m_btnCamera1.LoadStdImageHover(g_cameraUnlock, _T("PNG"));
		m_btnCamera1.LoadAltImage(g_cameraUnlock, _T("PNG"));
		m_btnCamera1.SetImageSize(nWidthpic, nHeightpic);
		m_btnCamera1.MoveWindow(132, 400, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 1) {
		g_cameraState = TRUE;
		m_btnCamera.m_bEnableWords = true;
		m_btnCamera.SetBK(g_cameraLock);
		m_btnCamera.SetFont(g_pTempBtnFont);
		m_btnCamera.LoadStdImage(g_cameraLock, _T("PNG"));
		m_btnCamera.LoadStdImageHover(g_cameraLock, _T("PNG"));
		m_btnCamera.LoadAltImage(g_cameraLock, _T("PNG"));
		m_btnCamera.SetImageSize(nWidthpic, nHeightpic);
		m_btnCamera.MoveWindow(132, 400, nWidthpic, nHeightpic, TRUE);
		m_btnCamera1.m_bEnableWords = true;
		m_btnCamera1.SetBK(g_cameraUnlock);
		m_btnCamera1.SetFont(g_pTempBtnFont);
		m_btnCamera1.LoadStdImage(g_cameraUnlock, _T("PNG"));
		m_btnCamera1.LoadStdImageHover(g_cameraUnlock, _T("PNG"));
		m_btnCamera1.LoadAltImage(g_cameraUnlock, _T("PNG"));
		m_btnCamera1.SetImageSize(nWidthpic, nHeightpic);
		m_btnCamera1.MoveWindow(132, 53, nWidthpic, nHeightpic, TRUE);
	}

	//3
	ReadRegValue(&val, REGSUBKEY_TP);
	if (val == 0) {
		g_TPState = FALSE;
		m_btnTP.m_bEnableWords = true;
		m_btnTP.SetBK(g_tpLock);
		m_btnTP.SetFont(g_pTempBtnFont);
		m_btnTP.LoadStdImage(g_tpLock, _T("PNG"));
		m_btnTP.LoadStdImageHover(g_tpLock, _T("PNG"));
		m_btnTP.LoadAltImage(g_tpLock, _T("PNG"));
		m_btnTP.SetImageSize(nWidthpic, nHeightpic);
		m_btnTP.MoveWindow(223, 53, nWidthpic, nHeightpic, TRUE);
		m_btnTP1.m_bEnableWords = true;
		m_btnTP1.SetBK(g_tpUnlock);
		m_btnTP1.SetFont(g_pTempBtnFont);
		m_btnTP1.LoadStdImage(g_tpUnlock, _T("PNG"));
		m_btnTP1.LoadStdImageHover(g_tpUnlock, _T("PNG"));
		m_btnTP1.LoadAltImage(g_tpUnlock, _T("PNG"));
		m_btnTP1.SetImageSize(nWidthpic, nHeightpic);
		m_btnTP1.MoveWindow(223, 400, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 1) {
		g_TPState = TRUE;
		m_btnTP.m_bEnableWords = true;
		m_btnTP.SetBK(g_tpLock);
		m_btnTP.SetFont(g_pTempBtnFont);
		m_btnTP.LoadStdImage(g_tpLock, _T("PNG"));
		m_btnTP.LoadStdImageHover(g_tpLock, _T("PNG"));
		m_btnTP.LoadAltImage(g_tpLock, _T("PNG"));
		m_btnTP.SetImageSize(nWidthpic, nHeightpic);
		m_btnTP.MoveWindow(223, 400, nWidthpic, nHeightpic, TRUE);
		m_btnTP1.m_bEnableWords = true;
		m_btnTP1.SetBK(g_tpUnlock);
		m_btnTP1.SetFont(g_pTempBtnFont);
		m_btnTP1.LoadStdImage(g_tpUnlock, _T("PNG"));
		m_btnTP1.LoadStdImageHover(g_tpUnlock, _T("PNG"));
		m_btnTP1.LoadAltImage(g_tpUnlock, _T("PNG"));
		m_btnTP1.SetImageSize(nWidthpic, nHeightpic);
		m_btnTP1.MoveWindow(223, 53, nWidthpic, nHeightpic, TRUE);
	}
	
	//4
	ReadRegValue(&val, REGSUBKEY_NUMBER);
	if (val == 0) {
		g_numberState = FALSE;
		m_btnNumber.m_bEnableWords = true;
		m_btnNumber.SetBK(g_numberLock);
		m_btnNumber.SetFont(g_pTempBtnFont);
		m_btnNumber.LoadStdImage(g_numberLock, _T("PNG"));
		m_btnNumber.LoadStdImageHover(g_numberLock, _T("PNG"));
		m_btnNumber.LoadAltImage(g_numberLock, _T("PNG"));
		m_btnNumber.SetImageSize(nWidthpic, nHeightpic);
		m_btnNumber.MoveWindow(315, 53, nWidthpic, nHeightpic, TRUE);
		m_btnNumber1.m_bEnableWords = true;
		m_btnNumber1.SetBK(g_numberUnlock);
		m_btnNumber1.SetFont(g_pTempBtnFont);
		m_btnNumber1.LoadStdImage(g_numberUnlock, _T("PNG"));
		m_btnNumber1.LoadStdImageHover(g_numberUnlock, _T("PNG"));
		m_btnNumber1.LoadAltImage(g_numberUnlock, _T("PNG"));
		m_btnNumber1.SetImageSize(nWidthpic, nHeightpic);
		m_btnNumber1.MoveWindow(315, 400, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 1) {
		g_numberState = TRUE;
		m_btnNumber.m_bEnableWords = true;
		m_btnNumber.SetBK(g_numberLock);
		m_btnNumber.SetFont(g_pTempBtnFont);
		m_btnNumber.LoadStdImage(g_numberLock, _T("PNG"));
		m_btnNumber.LoadStdImageHover(g_numberLock, _T("PNG"));
		m_btnNumber.LoadAltImage(g_numberLock, _T("PNG"));
		m_btnNumber.SetImageSize(nWidthpic, nHeightpic);
		m_btnNumber.MoveWindow(315, 400, nWidthpic, nHeightpic, TRUE);
		m_btnNumber1.m_bEnableWords = true;
		m_btnNumber1.SetBK(g_numberUnlock);
		m_btnNumber1.SetFont(g_pTempBtnFont);
		m_btnNumber1.LoadStdImage(g_numberUnlock, _T("PNG"));
		m_btnNumber1.LoadStdImageHover(g_numberUnlock, _T("PNG"));
		m_btnNumber1.LoadAltImage(g_numberUnlock, _T("PNG"));
		m_btnNumber1.SetImageSize(nWidthpic, nHeightpic);
		m_btnNumber1.MoveWindow(315, 53, nWidthpic, nHeightpic, TRUE);
	}
	
	//5
	ReadRegValue(&val, REGSUBKEY_CAPS);
	if (val == 0) {
		g_capsState = FALSE;
		m_btnCaps.m_bEnableWords = true;
		m_btnCaps.SetBK(g_capsLock);
		m_btnCaps.SetFont(g_pTempBtnFont);
		m_btnCaps.LoadStdImage(g_capsLock, _T("PNG"));
		m_btnCaps.LoadStdImageHover(g_capsLock, _T("PNG"));
		m_btnCaps.LoadAltImage(g_capsLock, _T("PNG"));
		m_btnCaps.SetImageSize(nWidthpic, nHeightpic);
		m_btnCaps.MoveWindow(406, 53, nWidthpic, nHeightpic, TRUE);

		m_btnCaps1.m_bEnableWords = true;
		m_btnCaps1.SetBK(g_capsUnlock);
		m_btnCaps1.SetFont(g_pTempBtnFont);
		m_btnCaps1.LoadStdImage(g_capsUnlock, _T("PNG"));
		m_btnCaps1.LoadStdImageHover(g_capsUnlock, _T("PNG"));
		m_btnCaps1.LoadAltImage(g_capsUnlock, _T("PNG"));
		m_btnCaps1.SetImageSize(nWidthpic, nHeightpic);
		m_btnCaps1.MoveWindow(406, 400, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 1) {
		g_capsState = TRUE;
		m_btnCaps.m_bEnableWords = true;
		m_btnCaps.SetBK(g_capsLock);
		m_btnCaps.SetFont(g_pTempBtnFont);
		m_btnCaps.LoadStdImage(g_capsLock, _T("PNG"));
		m_btnCaps.LoadStdImageHover(g_capsLock, _T("PNG"));
		m_btnCaps.LoadAltImage(g_capsLock, _T("PNG"));
		m_btnCaps.SetImageSize(nWidthpic, nHeightpic);
		m_btnCaps.MoveWindow(406, 400, nWidthpic, nHeightpic, TRUE);

		m_btnCaps1.m_bEnableWords = true;
		m_btnCaps1.SetBK(g_capsUnlock);
		m_btnCaps1.SetFont(g_pTempBtnFont);
		m_btnCaps1.LoadStdImage(g_capsUnlock, _T("PNG"));
		m_btnCaps1.LoadStdImageHover(g_capsUnlock, _T("PNG"));
		m_btnCaps1.LoadAltImage(g_capsUnlock, _T("PNG"));
		m_btnCaps1.SetImageSize(nWidthpic, nHeightpic);
		m_btnCaps1.MoveWindow(406, 53, nWidthpic, nHeightpic, TRUE);
	}

	//6
	ReadRegValue(&val, REGSUBKEY_FNLOCK);
	if (val == 0) {
		g_fnState = FALSE;
		m_btnFn.m_bEnableWords = true;
		m_btnFn.SetBK(g_fnLock);
		m_btnMic.SetFont(g_pTempBtnFont);
		m_btnFn.LoadStdImage(g_fnLock, _T("PNG"));
		m_btnFn.LoadStdImageHover(g_fnLock, _T("PNG"));
		m_btnFn.LoadAltImage(g_fnLock, _T("PNG"));
		m_btnFn.SetImageSize(nWidthpic, nHeightpic);
		m_btnFn.MoveWindow(497, 53, nWidthpic, nHeightpic, TRUE);

		m_btnFn1.m_bEnableWords = true;
		m_btnFn1.SetBK(g_fnUnlock);
		m_btnFn1.SetFont(g_pTempBtnFont);
		m_btnFn1.LoadStdImage(g_fnUnlock, _T("PNG"));
		m_btnFn1.LoadStdImageHover(g_fnUnlock, _T("PNG"));
		m_btnFn1.LoadAltImage(g_fnUnlock, _T("PNG"));
		m_btnFn1.SetImageSize(nWidthpic, nHeightpic);
		m_btnFn1.MoveWindow(497, 400, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 1) {
		g_fnState = TRUE;
		m_btnFn.m_bEnableWords = true;
		m_btnFn.SetBK(g_fnLock);
		m_btnMic.SetFont(g_pTempBtnFont);
		m_btnFn.LoadStdImage(g_fnLock, _T("PNG"));
		m_btnFn.LoadStdImageHover(g_fnLock, _T("PNG"));
		m_btnFn.LoadAltImage(g_fnLock, _T("PNG"));
		m_btnFn.SetImageSize(nWidthpic, nHeightpic);
		m_btnFn.MoveWindow(497, 400, nWidthpic, nHeightpic, TRUE);

		m_btnFn1.m_bEnableWords = true;
		m_btnFn1.SetBK(g_fnUnlock);
		m_btnFn1.SetFont(g_pTempBtnFont);
		m_btnFn1.LoadStdImage(g_fnUnlock, _T("PNG"));
		m_btnFn1.LoadStdImageHover(g_fnUnlock, _T("PNG"));
		m_btnFn1.LoadAltImage(g_fnUnlock, _T("PNG"));
		m_btnFn1.SetImageSize(nWidthpic, nHeightpic);
		m_btnFn1.MoveWindow(497, 53, nWidthpic, nHeightpic, TRUE);
	}
	
	//7
	ReadRegValue(&val, REGSUBKEY_ITS);
	if (val == 0) {
		g_ITSState = 0;
		m_btnITS.m_bEnableWords = true;
		m_btnITS.SetBK(g_ITSFATachometer);
		m_btnITS.SetFont(g_pTempBtnFont);
		m_btnITS.LoadStdImage(g_ITSFATachometer, _T("PNG"));
		m_btnITS.LoadStdImageHover(g_ITSFATachometer, _T("PNG"));
		m_btnITS.LoadAltImage(g_ITSFATachometer, _T("PNG"));
		m_btnITS.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS.MoveWindow(588, 53, nWidthpic, nHeightpic, TRUE);

		m_btnITS1.m_bEnableWords = true;
		m_btnITS1.SetBK(g_ITSLEIntelligentColl);
		m_btnITS1.SetFont(g_pTempBtnFont);
		m_btnITS1.LoadStdImage(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.LoadStdImageHover(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.LoadAltImage(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS1.MoveWindow(588, 400, nWidthpic, nHeightpic, TRUE);

		m_btnITS2.m_bEnableWords = true;
		m_btnITS2.SetBK(g_ITSLEBattery);
		m_btnITS2.SetFont(g_pTempBtnFont);
		m_btnITS2.LoadStdImage(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.LoadStdImageHover(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.LoadAltImage(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS2.MoveWindow(588, 800, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 1) {
		g_ITSState = 1;
		m_btnITS.m_bEnableWords = true;
		m_btnITS.SetBK(g_ITSFATachometer);
		m_btnITS.SetFont(g_pTempBtnFont);
		m_btnITS.LoadStdImage(g_ITSFATachometer, _T("PNG"));
		m_btnITS.LoadStdImageHover(g_ITSFATachometer, _T("PNG"));
		m_btnITS.LoadAltImage(g_ITSFATachometer, _T("PNG"));
		m_btnITS.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS.MoveWindow(588, 800, nWidthpic, nHeightpic, TRUE);

		m_btnITS1.m_bEnableWords = true;
		m_btnITS1.SetBK(g_ITSLEIntelligentColl);
		m_btnITS1.SetFont(g_pTempBtnFont);
		m_btnITS1.LoadStdImage(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.LoadStdImageHover(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.LoadAltImage(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS1.MoveWindow(588, 53, nWidthpic, nHeightpic, TRUE);

		m_btnITS2.m_bEnableWords = true;
		m_btnITS2.SetBK(g_ITSLEBattery);
		m_btnITS2.SetFont(g_pTempBtnFont);
		m_btnITS2.LoadStdImage(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.LoadStdImageHover(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.LoadAltImage(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS2.MoveWindow(588, 400, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 2) {
		g_ITSState = 2;
		m_btnITS.m_bEnableWords = true;
		m_btnITS.SetBK(g_ITSFATachometer);
		m_btnITS.SetFont(g_pTempBtnFont);
		m_btnITS.LoadStdImage(g_ITSFATachometer, _T("PNG"));
		m_btnITS.LoadStdImageHover(g_ITSFATachometer, _T("PNG"));
		m_btnITS.LoadAltImage(g_ITSFATachometer, _T("PNG"));
		m_btnITS.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS.MoveWindow(588, 400, nWidthpic, nHeightpic, TRUE);

		m_btnITS1.m_bEnableWords = true;
		m_btnITS1.SetBK(g_ITSLEIntelligentColl);
		m_btnITS1.SetFont(g_pTempBtnFont);
		m_btnITS1.LoadStdImage(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.LoadStdImageHover(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.LoadAltImage(g_ITSLEIntelligentColl, _T("PNG"));
		m_btnITS1.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS1.MoveWindow(588, 800, nWidthpic, nHeightpic, TRUE);

		m_btnITS2.m_bEnableWords = true;
		m_btnITS2.SetBK(g_ITSLEBattery);
		m_btnITS2.SetFont(g_pTempBtnFont);
		m_btnITS2.LoadStdImage(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.LoadStdImageHover(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.LoadAltImage(g_ITSLEBattery, _T("PNG"));
		m_btnITS2.SetImageSize(nWidthpic, nHeightpic);
		m_btnITS2.MoveWindow(588, 53, nWidthpic, nHeightpic, TRUE);
	}

	//8
	ReadRegValue(&val, REGSUBKEY_LED);
	if (val == 0) {
		g_LEDState = 0;
		m_btnKeyboardLED.m_bEnableWords = true;
		m_btnKeyboardLED.SetBK(g_keyboardAuto);
		m_btnKeyboardLED.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED.LoadStdImage(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.LoadStdImageHover(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.LoadAltImage(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED.MoveWindow(679, 53, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED1.m_bEnableWords = true;
		m_btnKeyboardLED1.SetBK(g_keyboardMin);
		m_btnKeyboardLED1.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED1.LoadStdImage(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.LoadStdImageHover(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.LoadAltImage(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED1.MoveWindow(679, 400, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED2.m_bEnableWords = true;
		m_btnKeyboardLED2.SetBK(g_keyboardMax);
		m_btnKeyboardLED2.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED2.LoadStdImage(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.LoadStdImageHover(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.LoadAltImage(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED2.MoveWindow(679, 800, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED3.m_bEnableWords = true;
		m_btnKeyboardLED3.SetBK(g_keyboardClose);
		m_btnKeyboardLED3.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED3.LoadStdImage(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.LoadStdImageHover(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.LoadAltImage(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED3.MoveWindow(679, 1200, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 1) {
		g_LEDState = 1;
		m_btnKeyboardLED.m_bEnableWords = true;
		m_btnKeyboardLED.SetBK(g_keyboardAuto);
		m_btnKeyboardLED.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED.LoadStdImage(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.LoadStdImageHover(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.LoadAltImage(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED.MoveWindow(679, 1200, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED1.m_bEnableWords = true;
		m_btnKeyboardLED1.SetBK(g_keyboardMin);
		m_btnKeyboardLED1.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED1.LoadStdImage(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.LoadStdImageHover(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.LoadAltImage(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED1.MoveWindow(679, 53, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED2.m_bEnableWords = true;
		m_btnKeyboardLED2.SetBK(g_keyboardMax);
		m_btnKeyboardLED2.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED2.LoadStdImage(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.LoadStdImageHover(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.LoadAltImage(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED2.MoveWindow(679, 400, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED3.m_bEnableWords = true;
		m_btnKeyboardLED3.SetBK(g_keyboardClose);
		m_btnKeyboardLED3.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED3.LoadStdImage(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.LoadStdImageHover(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.LoadAltImage(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED3.MoveWindow(679, 800, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 2) {
		g_LEDState = 2;
		m_btnKeyboardLED.m_bEnableWords = true;
		m_btnKeyboardLED.SetBK(g_keyboardAuto);
		m_btnKeyboardLED.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED.LoadStdImage(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.LoadStdImageHover(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.LoadAltImage(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED.MoveWindow(679, 800, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED1.m_bEnableWords = true;
		m_btnKeyboardLED1.SetBK(g_keyboardMin);
		m_btnKeyboardLED1.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED1.LoadStdImage(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.LoadStdImageHover(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.LoadAltImage(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED1.MoveWindow(679, 1200, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED2.m_bEnableWords = true;
		m_btnKeyboardLED2.SetBK(g_keyboardMax);
		m_btnKeyboardLED2.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED2.LoadStdImage(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.LoadStdImageHover(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.LoadAltImage(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED2.MoveWindow(679, 53, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED3.m_bEnableWords = true;
		m_btnKeyboardLED3.SetBK(g_keyboardClose);
		m_btnKeyboardLED3.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED3.LoadStdImage(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.LoadStdImageHover(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.LoadAltImage(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED3.MoveWindow(679, 400, nWidthpic, nHeightpic, TRUE);
	}
	if (val == 3) {
		g_LEDState = 3;
		m_btnKeyboardLED.m_bEnableWords = true;
		m_btnKeyboardLED.SetBK(g_keyboardAuto);
		m_btnKeyboardLED.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED.LoadStdImage(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.LoadStdImageHover(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.LoadAltImage(g_keyboardAuto, _T("PNG"));
		m_btnKeyboardLED.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED.MoveWindow(679, 400, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED1.m_bEnableWords = true;
		m_btnKeyboardLED1.SetBK(g_keyboardMin);
		m_btnKeyboardLED1.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED1.LoadStdImage(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.LoadStdImageHover(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.LoadAltImage(g_keyboardMin, _T("PNG"));
		m_btnKeyboardLED1.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED1.MoveWindow(679, 800, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED2.m_bEnableWords = true;
		m_btnKeyboardLED2.SetBK(g_keyboardMax);
		m_btnKeyboardLED2.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED2.LoadStdImage(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.LoadStdImageHover(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.LoadAltImage(g_keyboardMax, _T("PNG"));
		m_btnKeyboardLED2.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED2.MoveWindow(679, 1200, nWidthpic, nHeightpic, TRUE);

		m_btnKeyboardLED3.m_bEnableWords = true;
		m_btnKeyboardLED3.SetBK(g_keyboardClose);
		m_btnKeyboardLED3.SetFont(g_pTempBtnFont);
		m_btnKeyboardLED3.LoadStdImage(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.LoadStdImageHover(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.LoadAltImage(g_keyboardClose, _T("PNG"));
		m_btnKeyboardLED3.SetImageSize(nWidthpic, nHeightpic);
		m_btnKeyboardLED3.MoveWindow(679, 53, nWidthpic, nHeightpic, TRUE);
	}
	
	//time
	{
		//time 1s
		m_btnTime1.m_bEnableWords = true;
		m_btnTime1.SetBK(g_time_1s);
		m_btnTime1.SetFont(g_pTempBtnFont);
		m_btnTime1.LoadStdImage(g_time_1s, _T("PNG"));
		m_btnTime1.LoadStdImageHover(g_time_1s, _T("PNG"));
		m_btnTime1.LoadAltImage(g_time_1s, _T("PNG"));
		m_btnTime1.SetImageSize(57, 25);
		m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
		m_btnTime1_1.m_bEnableWords = true;
		m_btnTime1_1.SetBK(g_time_1s_1);
		m_btnTime1_1.SetFont(g_pTempBtnFont);
		m_btnTime1_1.LoadStdImage(g_time_1s_1, _T("PNG"));
		m_btnTime1_1.LoadStdImageHover(g_time_1s_1, _T("PNG"));
		m_btnTime1_1.LoadAltImage(g_time_1s_1, _T("PNG"));
		m_btnTime1_1.SetImageSize(57, 25);
		m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
		//time 2s
		m_btnTime2.m_bEnableWords = true;
		m_btnTime2.SetBK(g_time_2s);
		m_btnTime2.SetFont(g_pTempBtnFont);
		m_btnTime2.LoadStdImage(g_time_2s, _T("PNG"));
		m_btnTime2.LoadStdImageHover(g_time_2s, _T("PNG"));
		m_btnTime2.LoadAltImage(g_time_2s, _T("PNG"));
		m_btnTime2.SetImageSize(57, 25);
		m_btnTime2.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTime2_1.m_bEnableWords = true;
		m_btnTime2_1.SetBK(g_time_2s_1);
		m_btnTime2_1.SetFont(g_pTempBtnFont);
		m_btnTime2_1.LoadStdImage(g_time_2s_1, _T("PNG"));
		m_btnTime2_1.LoadStdImageHover(g_time_2s_1, _T("PNG"));
		m_btnTime2_1.LoadAltImage(g_time_2s_1, _T("PNG"));
		m_btnTime2_1.SetImageSize(57, 25);
		m_btnTime2_1.MoveWindow(845, 70, 57, 25, TRUE);
		//time 3s
		m_btnTime3.m_bEnableWords = true;
		m_btnTime3.SetBK(g_time_3s);
		m_btnTime3.SetFont(g_pTempBtnFont);
		m_btnTime3.LoadStdImage(g_time_3s, _T("PNG"));
		m_btnTime3.LoadStdImageHover(g_time_3s, _T("PNG"));
		m_btnTime3.LoadAltImage(g_time_3s, _T("PNG"));
		m_btnTime3.SetImageSize(57, 25);
		m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
		m_btnTime3_1.m_bEnableWords = true;
		m_btnTime3_1.SetBK(g_time_3s_1);
		m_btnTime3_1.SetFont(g_pTempBtnFont);
		m_btnTime3_1.LoadStdImage(g_time_3s_1, _T("PNG"));
		m_btnTime3_1.LoadStdImageHover(g_time_3s_1, _T("PNG"));
		m_btnTime3_1.LoadAltImage(g_time_3s_1, _T("PNG"));
		m_btnTime3_1.SetImageSize(57, 25);
		m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
		//time 4s
		m_btnTime4.m_bEnableWords = true;
		m_btnTime4.SetBK(g_time_4s);
		m_btnTime4.SetFont(g_pTempBtnFont);
		m_btnTime4.LoadStdImage(g_time_4s, _T("PNG"));
		m_btnTime4.LoadStdImageHover(g_time_4s, _T("PNG"));
		m_btnTime4.LoadAltImage(g_time_4s, _T("PNG"));
		m_btnTime4.SetImageSize(57, 25);
		m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
		m_btnTime4_1.m_bEnableWords = true;
		m_btnTime4_1.SetBK(g_time_4s_1);
		m_btnTime4_1.SetFont(g_pTempBtnFont);
		m_btnTime4_1.LoadStdImage(g_time_4s_1, _T("PNG"));
		m_btnTime4_1.LoadStdImageHover(g_time_4s_1, _T("PNG"));
		m_btnTime4_1.LoadAltImage(g_time_4s_1, _T("PNG"));
		m_btnTime4_1.SetImageSize(57, 25);
		m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
		//time 5s
		m_btnTime5.m_bEnableWords = true;
		m_btnTime5.SetBK(g_time_5s);
		m_btnTime5.SetFont(g_pTempBtnFont);
		m_btnTime5.LoadStdImage(g_time_5s, _T("PNG"));
		m_btnTime5.LoadStdImageHover(g_time_5s, _T("PNG"));
		m_btnTime5.LoadAltImage(g_time_5s, _T("PNG"));
		m_btnTime5.SetImageSize(57, 25);
		m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
		m_btnTime5_1.m_bEnableWords = true;
		m_btnTime5_1.SetBK(g_time_5s_1);
		m_btnTime5_1.SetFont(g_pTempBtnFont);
		m_btnTime5_1.LoadStdImage(g_time_5s_1, _T("PNG"));
		m_btnTime5_1.LoadStdImageHover(g_time_5s_1, _T("PNG"));
		m_btnTime5_1.LoadAltImage(g_time_5s_1, _T("PNG"));
		m_btnTime5_1.SetImageSize(57, 25);
		m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
		//time always
		m_btnTimeAlways.m_bEnableWords = true;
		m_btnTimeAlways.SetBK(g_time_always);
		m_btnTimeAlways.SetFont(g_pTempBtnFont);
		m_btnTimeAlways.LoadStdImage(g_time_always, _T("PNG"));
		m_btnTimeAlways.LoadStdImageHover(g_time_always, _T("PNG"));
		m_btnTimeAlways.LoadAltImage(g_time_always, _T("PNG"));
		m_btnTimeAlways.SetImageSize(57, 25);
		m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
		m_btnTimeAlways_1.m_bEnableWords = true;
		m_btnTimeAlways_1.SetBK(g_time_always_1);
		m_btnTimeAlways_1.SetFont(g_pTempBtnFont);
		m_btnTimeAlways_1.LoadStdImage(g_time_always_1, _T("PNG"));
		m_btnTimeAlways_1.LoadStdImageHover(g_time_always_1, _T("PNG"));
		m_btnTimeAlways_1.LoadAltImage(g_time_always_1, _T("PNG"));
		m_btnTimeAlways_1.SetImageSize(57, 25);
		m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
	}

	LONG para = GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE);
	para |= WS_EX_LAYERED;
	SetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE, para);
	SetLayeredWindowAttributes(RGB(255, 0, 0), 255, LWA_ALPHA);

	return FALSE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE

}


void CPic::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
}


void CPic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc.m_hDC);
	CRect    rect;
	CSize    s;
	CDC      dcMem;
	CString  temp;
	CBitmap  bmpBackground;
	CGdiPlusBitmapResource  image;
	GetClientRect(&rect);
	dcMem.CreateCompatibleDC(&dc);
	bmpBackground.LoadBitmap(g_dwSkypeBackground);//
	CBitmap *pbmpOld = dcMem.SelectObject(&bmpBackground);
	BITMAP bmInfo;
	bmpBackground.GetObject(sizeof(bmInfo), &bmInfo);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bmInfo.bmWidth - 1, bmInfo.bmHeight - 1, SRCCOPY);//
	//
	// TODO: add draw code for native data here  
	
	if (g_bHideWin) {
		ShowWindow(SW_HIDE);
	}
}


HBRUSH CPic::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	pDC->SetTextColor(RGB(255, 255, 0));
	pDC->SetBkMode(TRANSPARENT);
	return  (HBRUSH)::GetStockObject(NULL_BRUSH);
}


void CPic::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, _T("open"), _T("https://www.microsoft.com/en-us/download/details.aspx?id=49440"), NULL, NULL, SW_SHOWNORMAL);
}

//open mic
void CPic::OnBnClickedAPPIcon1()
{
	
	m_btnMic.MoveWindow(41, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnMic1.MoveWindow(41, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_micState) {
		SetRegValue(0, REGSUBKEY_MIC);
		g_micState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_MIC);
		g_micState = TRUE;
	}
	
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_MIC_STATUS, NULL, NULL);
}
//close mic
void CPic::OnBnClickedAppIcon11()
{
	m_btnMic1.MoveWindow(41, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnMic.MoveWindow(41, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_micState) {
		SetRegValue(0, REGSUBKEY_MIC);
		g_micState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_MIC);
		g_micState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_MIC_STATUS, NULL, NULL);
}
//open camera
void CPic::OnBnClickedAPPIcon2()
{
	m_btnCamera.MoveWindow(132, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnCamera1.MoveWindow(132, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_cameraState) {
		SetRegValue(0, REGSUBKEY_CAMERA);
		g_cameraState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_CAMERA);
		g_cameraState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_CAMERA_MSG, NULL, NULL);
}
//close camera
void CPic::OnBnClickedAppIcon21()
{
	m_btnCamera1.MoveWindow(132, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnCamera.MoveWindow(132, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_cameraState) {
		SetRegValue(0, REGSUBKEY_CAMERA);
		g_cameraState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_CAMERA);
		g_cameraState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_CAMERA_MSG, NULL, NULL);
}
//open Tp
void CPic::OnBnClickedAPPIcon3()
{
	m_btnTP.MoveWindow(223, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnTP1.MoveWindow(223, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_TPState) {
		SetRegValue(0, REGSUBKEY_TP);
		g_TPState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_TP);
		g_TPState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_TP_STATUS, 1, NULL);
}
//close TP
void CPic::OnBnClickedAppIcon31()
{
	m_btnTP1.MoveWindow(223, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnTP.MoveWindow(223, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_TPState) {
		SetRegValue(0, REGSUBKEY_TP);
		g_TPState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_TP);
		g_TPState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_TP_STATUS, 0, NULL);
}
//open number
void CPic::OnBnClickedAPPIcon4()
{
	m_btnNumber.MoveWindow(315, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnNumber1.MoveWindow(315, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_LEDState) {
		SetRegValue(0, REGSUBKEY_NUMBER);
		g_LEDState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_NUMBER);
		g_LEDState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_NUMLOCK_STATUS, 1, NULL);
}
//close number
void CPic::OnBnClickedAppIcon41()
{
	m_btnNumber1.MoveWindow(315, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnNumber.MoveWindow(315, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_LEDState) {
		SetRegValue(0, REGSUBKEY_NUMBER);
		g_LEDState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_NUMBER);
		g_LEDState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_NUMLOCK_STATUS, 0, NULL);
}
//open caps
void CPic::OnBnClickedAPPIcon5()
{
	m_btnCaps.MoveWindow(406, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnCaps1.MoveWindow(406, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_capsState) {
		SetRegValue(0, REGSUBKEY_CAPS);
		g_capsState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_CAPS);
		g_capsState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_CAPS_STATUS, NULL, NULL);
}
//close caps
void CPic::OnBnClickedAppIcon51()
{
	m_btnCaps1.MoveWindow(406, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnCaps.MoveWindow(406, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_capsState) {
		SetRegValue(0, REGSUBKEY_CAPS);
		g_capsState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_CAPS);
		g_capsState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_CAPS_STATUS, NULL, NULL);
}
//open fn
void CPic::OnBnClickedAppIcon6()
{
	m_btnFn.MoveWindow(497, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnFn1.MoveWindow(497, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_fnState) {
		SetRegValue(0, REGSUBKEY_FNLOCK);
		g_capsState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_FNLOCK);
		g_capsState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_FN_ON, NULL, NULL);
}
//close fn
void CPic::OnBnClickedAppIcon61()
{
	m_btnFn1.MoveWindow(497, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnFn.MoveWindow(497, 53, g_nWidthpic, g_nHeightpic, TRUE);
	if (g_fnState) {
		SetRegValue(0, REGSUBKEY_FNLOCK);
		g_capsState = FALSE;
	}
	else {
		SetRegValue(1, REGSUBKEY_FNLOCK);
		g_capsState = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_FN_OFF, NULL, NULL);
}
//open xuehua
void CPic::OnBnClickedAppIcon7()
{
	m_btnITS.MoveWindow(588, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnITS1.MoveWindow(588, 53, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnITS2.MoveWindow(588, 800, g_nWidthpic, g_nHeightpic, TRUE);
	SetRegValue(0, REGSUBKEY_ITS);
}
//open battery
void CPic::OnBnClickedAppIcon71()
{
	m_btnITS1.MoveWindow(588, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnITS2.MoveWindow(588, 53, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnITS.MoveWindow(588, 800, g_nWidthpic, g_nHeightpic, TRUE);
	SetRegValue(1, REGSUBKEY_ITS);
}
//open biao
void CPic::OnBnClickedAppIcon72()
{
	m_btnITS2.MoveWindow(588, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnITS.MoveWindow(588, 53, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnITS1.MoveWindow(588, 800, g_nWidthpic, g_nHeightpic, TRUE);
	SetRegValue(2, REGSUBKEY_ITS);
}
//open min
void CPic::OnBnClickedAppIcon8()
{
	m_btnKeyboardLED.MoveWindow(679, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED1.MoveWindow(679, 53, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED2.MoveWindow(679, 800, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED3.MoveWindow(679, 1200, g_nWidthpic, g_nHeightpic, TRUE);
	SetRegValue(0, REGSUBKEY_LED);
}
//open max
void CPic::OnBnClickedAppIcon81()
{
	m_btnKeyboardLED1.MoveWindow(679, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED2.MoveWindow(679, 53, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED3.MoveWindow(679, 800, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED.MoveWindow(679, 1200, g_nWidthpic, g_nHeightpic, TRUE);
	SetRegValue(1, REGSUBKEY_LED);
}
//backlight close
void CPic::OnBnClickedAppIcon82()
{
	m_btnKeyboardLED2.MoveWindow(679, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED3.MoveWindow(679, 53, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED.MoveWindow(679, 800, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED1.MoveWindow(679, 1200, g_nWidthpic, g_nHeightpic, TRUE);
	SetRegValue(2, REGSUBKEY_LED);
}
//open auto
void CPic::OnBnClickedAppIcon83()
{
	m_btnKeyboardLED3.MoveWindow(679, 400, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED.MoveWindow(679, 53, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED2.MoveWindow(679, 800, g_nWidthpic, g_nHeightpic, TRUE);
	m_btnKeyboardLED1.MoveWindow(679, 1200, g_nWidthpic, g_nHeightpic, TRUE);
	SetRegValue(3, REGSUBKEY_LED);
}
void CPic::ReadRegValue(DWORD* Val, LPTSTR szValue)
{
	BOOL	bSuccess = FALSE;
	HKEY		hKey = NULL;
	LPDWORD		dwData = new DWORD;
	DWORD		cbData = sizeof(DWORD);
	DWORD dwTpye = 0;
	TCHAR* pBuf = new TCHAR[sizeof(DWORD)];
	LONG ret = RegOpenKeyEx(HKEY_CURRENT_USER, REGSTR_PATH_SERVICES, 0, KEY_WOW64_64KEY | KEY_ALL_ACCESS, &hKey);
	if (ret != ERROR_SUCCESS)
	{
		//MessageBox(L"Open Reg failed");
		RegCloseKey(hKey);
	}
	bSuccess = (ERROR_SUCCESS == RegQueryValueEx(hKey, szValue, 0, (LPDWORD)(LPCTSTR)pBuf, (LPBYTE)dwData, &cbData));
	if (!bSuccess) {
		//MessageBox(L"Read Val Error");
		return;
	}
	*Val = *dwData;
	RegCloseKey(hKey);
	delete dwData;
}

void CPic::SetRegValue(DWORD Value, LPTSTR szValue) {
	BOOL	bSuccess = FALSE;
	HKEY	hKey = NULL;
	DWORD type_1 = REG_DWORD;
	DWORD dwData = 0;
	DWORD cbData = sizeof(dwData);

	bSuccess = (ERROR_SUCCESS == RegOpenKeyEx(HKEY_CURRENT_USER, REGSTR_PATH_SERVICES, 0, KEY_ALL_ACCESS, &hKey));
	if (!bSuccess) {
		//MessageBox(L"Open Reg Error");
		return;
	}
	bSuccess = bSuccess && (ERROR_SUCCESS == RegSetValueEx(hKey, szValue, NULL, type_1, (LPBYTE)&Value, cbData));
	if (!bSuccess) {
		//MessageBox(L"Write Val Error");
		return;
	}
}

LRESULT CPic::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (CDialog::OnNcHitTest(point) == HTCLIENT)
		return   HTCAPTION;

	return CDialog::OnNcHitTest(point);
}

void CPic::OnTimer(UINT_PTR _nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (_nIDEvent == 1) 
	{
		CRect rect;
		CClientDC *pDC = new CClientDC(GetDlgItem(IDC_STATIC));
		GetDlgItem(IDC_STATIC)->GetWindowRect(&rect);
		Graphics graphics(pDC->m_hDC); // Create a GDI+ graphics object

		//GetDlgItem(IDC_STATIC)->MoveWindow(15 + coordinate * 80, 10, 130, 130);

		CString str;
		str.Format(_T("Images\\App_Chose1_%d.png"), ++k);
		Image image(str); // Construct an image
		graphics.DrawImage(&image, 0, 0, 130, 130);

		if (k == 10) {

			CString temp;
			temp.Format(_T("Images\\pic%d_H.png"), g_nIndexSelIcon + 1);
			Image png(temp);
			graphics.DrawImage(&png, 0, 0, 70, 70);

			KillTimer(1);
			k = 0;
		}
	}
	CDialog::OnTimer(_nIDEvent);
}

void CPic::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (nID == SC_MOVE || nID == 0xF012)//禁止移动控件
		return;
	else
		CDialog::OnSysCommand(nID, lParam);
}

void CPic::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	//ShowWindow(SW_HIDE);
}

LRESULT CPic::OnBtnFocusMsg(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CPic::OnMicPress(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 0) {
		m_btnMic.MoveWindow(41, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnMic1.MoveWindow(41, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(0, REGSUBKEY_MIC);
	}
	if (wParam == 1) {
		m_btnMic1.MoveWindow(41, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnMic.MoveWindow(41, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(1, REGSUBKEY_MIC);

	}
	return LRESULT();
}

LRESULT CPic::OnFnPress(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 1) {
		m_btnFn.MoveWindow(497, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnFn1.MoveWindow(497, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(0, REGSUBKEY_FNLOCK);	
	}
	if (wParam == 0) {
		m_btnFn1.MoveWindow(497, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnFn.MoveWindow(497, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(1, REGSUBKEY_FNLOCK);
	}
	return LRESULT();
}

LRESULT CPic::OnCmeraPress(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 1) {
		m_btnCamera.MoveWindow(132, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnCamera1.MoveWindow(132, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(0, REGSUBKEY_CAMERA);
	}
	if (wParam == 0) {
		m_btnCamera1.MoveWindow(132, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnCamera.MoveWindow(132, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(1, REGSUBKEY_CAMERA);
	}

	return LRESULT();
}

LRESULT CPic::OnKeyBoardLEDPress(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 0) {
		m_btnKeyboardLED2.MoveWindow(679, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnKeyboardLED3.MoveWindow(679, 53, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnKeyboardLED.MoveWindow(679, 800, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnKeyboardLED1.MoveWindow(679, 1200, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(2, REGSUBKEY_LED);
	}
	if (wParam == 1) {
		m_btnKeyboardLED1.MoveWindow(679, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnKeyboardLED2.MoveWindow(679, 53, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnKeyboardLED3.MoveWindow(679, 800, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnKeyboardLED.MoveWindow(679, 1200, g_nWidthpic, g_nHeightpic, TRUE);
	}
	return LRESULT();
}

LRESULT CPic::OnITSPress(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 1) {
		m_btnITS.MoveWindow(588, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnITS1.MoveWindow(588, 53, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnITS2.MoveWindow(588, 800, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(0, REGSUBKEY_ITS);
	}
	if (wParam == 3) {
		m_btnITS1.MoveWindow(588, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnITS2.MoveWindow(588, 53, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnITS.MoveWindow(588, 800, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(1, REGSUBKEY_ITS);
	}
	if (wParam == 2) {
		m_btnITS2.MoveWindow(588, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnITS.MoveWindow(588, 53, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnITS1.MoveWindow(588, 800, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(2, REGSUBKEY_ITS);
	}
	return LRESULT();
}

LRESULT CPic::OnCapsPress(WPARAM wParam, LPARAM lParam)
{

	return LRESULT();
}

LRESULT CPic::OnNumberLockPress(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 1) {
		m_btnNumber.MoveWindow(315, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnNumber1.MoveWindow(315, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(0, REGSUBKEY_FNLOCK);
	}
	if (wParam == 0) {
		m_btnNumber1.MoveWindow(315, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnNumber.MoveWindow(315, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(1, REGSUBKEY_FNLOCK);
	}
	return LRESULT();
}

LRESULT CPic::OnTpLockPress(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 1) {
		m_btnTP.MoveWindow(223, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnTP1.MoveWindow(223, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(0, REGSUBKEY_FNLOCK);
	}
	if (wParam == 0) {
		m_btnTP1.MoveWindow(223, 400, g_nWidthpic, g_nHeightpic, TRUE);
		m_btnTP.MoveWindow(223, 53, g_nWidthpic, g_nHeightpic, TRUE);
		SetRegValue(1, REGSUBKEY_FNLOCK);
	}
	return LRESULT();
}

BOOL g_time1 = TRUE;
BOOL g_time1_1 = TRUE;
BOOL g_time2 = TRUE;
BOOL g_time2_1 = FALSE;
BOOL g_time3 = TRUE;
BOOL g_time3_1 = TRUE;
BOOL g_time4 = TRUE;
BOOL g_time4_1 = TRUE;
BOOL g_time5 = TRUE;
BOOL g_time5_1 = TRUE;
BOOL g_time6 = TRUE;
BOOL g_time6_1 = TRUE;

BOOL CPic::PreTranslateMessage(MSG* pMsg)
{
	//KeyBoard Enter & ESC
	if ((WM_KEYFIRST <= pMsg->message) && (pMsg->message <= WM_KEYLAST) || pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_ESCAPE)
		{
			ShowWindow(SW_HIDE);
			return TRUE;
		}
		if (pMsg->message != WM_KEYDOWN) {
			if (pMsg->wParam == 0x31) {
				if (g_time1) {
					m_btnTime1_1.MoveWindow(784, 70, 57, 25, TRUE);
					m_btnTime1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
					m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
					m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
					m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
					m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
					m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
					m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
					g_time1_1 = FALSE;
					g_time2 = TRUE;
					g_time2_1 = FALSE;
					g_time3 = TRUE;
					g_time3_1 = TRUE;
					g_time4 = TRUE;
					g_time4_1 = TRUE;
					g_time5 = TRUE;
					g_time5_1 = TRUE;
					g_time6 = TRUE;
					g_time6_1 = TRUE;
				}

				HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
				if (hWnd == NULL) {
					return 0;
				}
				::SendMessage(hWnd, WM_TIME_1S_MSG, NULL, NULL);
			}
			if (pMsg->wParam == 0x32) {
				if (g_time2) {
					m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
					m_btnTime2.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTime2_1.MoveWindow(845, 70, 57, 25, TRUE);
					m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
					m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
					m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
					m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
					m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
					m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);

					g_time1 = TRUE;
					g_time1_1 = TRUE;
					g_time2 = FALSE;
					g_time3 = TRUE;
					g_time3_1 = TRUE;
					g_time4 = TRUE;
					g_time4_1 = TRUE;
					g_time5 = TRUE;
					g_time5_1 = TRUE;
					g_time6 = TRUE;
					g_time6_1 = TRUE;
				}
				HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
				if (hWnd == NULL) {
					return 0;
				}
				::SendMessage(hWnd, WM_TIME_2S_MSG, NULL, NULL);
			}
			if (pMsg->wParam == 0x33) {
				if (g_time3) {
					m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
					m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
					m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTime3.MoveWindow(906, 400, 57, 25, TRUE);
					m_btnTime3_1.MoveWindow(906, 70, 57, 25, TRUE);
					m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
					m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
					m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
					m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
					g_time3_1 = FALSE;
					g_time5 = TRUE;
					g_time5_1 = TRUE;
					g_time4 = TRUE;
					g_time4_1 = TRUE;
					g_time6 = TRUE;
					g_time6_1 = TRUE;
					g_time2 = TRUE;
				}
				HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
				if (hWnd == NULL) {
					return 0;
				}
				::SendMessage(hWnd, WM_TIME_3S_MSG, NULL, NULL);
			}
			if (pMsg->wParam == 0x34) {
				if (g_time4) {
					m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
					m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
					m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
					m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
					m_btnTime4.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime4_1.MoveWindow(784, 99, 57, 25, TRUE);
					m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
					m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
					m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
					g_time4_1 = FALSE;
					g_time5 = TRUE;
					g_time5_1 = TRUE;
					g_time6 = TRUE;
					g_time6_1 = TRUE;
					g_time2 = TRUE;
				}
				HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
				if (hWnd == NULL) {
					return 0;
				}
				::SendMessage(hWnd, WM_TIME_4S_MSG, NULL, NULL);
			}
			if (pMsg->wParam == 0x35) {
				if (g_time5) {
					m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
					m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
					m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
					m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
					m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
					m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime5.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTime5_1.MoveWindow(845, 99, 57, 25, TRUE);
					m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
					m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
					g_time5_1 = FALSE;
					g_time6 = TRUE;
					g_time6_1 = TRUE;
					g_time2 = TRUE;
				}
				HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
				if (hWnd == NULL) {
					return 0;
				}
				::SendMessage(hWnd, WM_TIME_5S_MSG, NULL, NULL);
			}
			if (pMsg->wParam == 0x41) {
				if (g_time6) {
					m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
					m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
					m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
					m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
					m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
					m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
					m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
					m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
					m_btnTimeAlways.MoveWindow(906, 400, 57, 25, TRUE);
					m_btnTimeAlways_1.MoveWindow(906, 99, 57, 25, TRUE);
					g_time6_1 = FALSE;
					g_time2 = TRUE;
				}
				HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
				if (hWnd == NULL) {
					return 0;
				}
				::SendMessage(hWnd, WM_TIME_ALWAYS_MSG, NULL, NULL);
			}
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

LRESULT CPic::OnClickedMsg(WPARAM wParam, LPARAM lParam)
{
	ShowWindow(SW_SHOW);
	g_bHideWin = FALSE;
	return LRESULT();
}

LRESULT CPic::OnPressMsg(WPARAM wParam, LPARAM lParam)
{
	ShowWindow(SW_SHOW);
	g_bHideWin = FALSE;
	
	return LRESULT();
}

LRESULT CPic::OnShowOSD(WPARAM wParam, LPARAM lParam)
{
	ShowWindow(SW_SHOW);
	g_bHideWin = FALSE;
	return LRESULT();
}

HCURSOR CPic::OnQueryDragIcon()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CDialog::OnQueryDragIcon();
}




void CPic::OnBnClickedBtnTime()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time1) {
		m_btnTime1_1.MoveWindow(784, 70, 57, 25, TRUE);
		m_btnTime1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
		m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
		m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
		m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
		m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
		m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
		m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
		g_time1_1 = FALSE;
		g_time2 = TRUE;
		g_time2_1 = FALSE;
		g_time3 = TRUE;
		g_time3_1 = TRUE;
		g_time4 = TRUE;
		g_time4_1 = TRUE;
		g_time5 = TRUE;
		g_time5_1 = TRUE;
		g_time6 = TRUE;
		g_time6_1 = TRUE;
	}

	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_TIME_1S_MSG, NULL, NULL);
}

void CPic::OnBnClickedBtnTime1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time1_1) {
		m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
		g_time1 = FALSE;
		g_time2 = TRUE;
		g_time2_1 = FALSE;
		g_time3 = TRUE;
		g_time3_1 = TRUE;
		g_time4 = TRUE;
		g_time4_1 = TRUE;
	}
}

void CPic::OnBnClickedBtnTime2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time2) {
		m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
		m_btnTime2.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTime2_1.MoveWindow(845, 70, 57, 25, TRUE);
		m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
		m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
		m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
		m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
		m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
		m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);

		g_time1 = TRUE;
		g_time1_1 = TRUE;
		g_time2 = FALSE;
		g_time3 = TRUE;
		g_time3_1 = TRUE;
		g_time4 = TRUE;
		g_time4_1 = TRUE;
		g_time5 = TRUE;
		g_time5_1 = TRUE;
		g_time6 = TRUE;
		g_time6_1 = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_TIME_2S_MSG, NULL, NULL);
}

void CPic::OnBnClickedBtnTime21()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time2_1) {
		m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
		m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
		g_time1 = TRUE;
		g_time1_1 = TRUE;
		g_time2_1 = FALSE;
		g_time3 = TRUE;
		g_time3_1 = TRUE;
		g_time4 = TRUE;
		g_time4_1 = TRUE;
		g_time5 = TRUE;
		g_time5_1 = TRUE;
		g_time6 = TRUE;
		g_time6_1 = TRUE;
	}
}

void CPic::OnBnClickedBtnTime3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time3) {
		m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
		m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
		m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTime3.MoveWindow(906, 400, 57, 25, TRUE);
		m_btnTime3_1.MoveWindow(906, 70, 57, 25, TRUE);
		m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
		m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
		m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
		m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
		g_time3_1 = FALSE;
		g_time5 = TRUE;
		g_time5_1 = TRUE;
		g_time4 = TRUE;
		g_time4_1 = TRUE;
		g_time6 = TRUE;
		g_time6_1 = TRUE;
		g_time2 = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_TIME_3S_MSG, NULL, NULL);
}

void CPic::OnBnClickedBtnTime31()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time3_1) {
		m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
		m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
		g_time3 = FALSE;
		g_time4 = TRUE;
		g_time4_1 = TRUE;
	}
}

void CPic::OnBnClickedBtnTime4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time4) {
		m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
		m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
		m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
		m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
		m_btnTime4.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime4_1.MoveWindow(784, 99, 57, 25, TRUE);
		m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
		m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
		m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
		g_time4_1 = FALSE;
		g_time5 = TRUE;
		g_time5_1 = TRUE;
		g_time6 = TRUE;
		g_time6_1 = TRUE;
		g_time2 = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_TIME_4S_MSG, NULL, NULL);
}

void CPic::OnBnClickedBtnTime41()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time4_1) {
		m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
		m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
		g_time4 = FALSE;
	}
}

void CPic::OnBnClickedBtnTime5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time5) {
		m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
		m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
		m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
		m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
		m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
		m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime5.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTime5_1.MoveWindow(845, 99, 57, 25, TRUE);
		m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
		m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
		g_time5_1 = FALSE;
		g_time6 = TRUE;
		g_time6_1 = TRUE;
		g_time2 = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_TIME_5S_MSG, NULL, NULL);
}

void CPic::OnBnClickedBtnTime51()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time5_1) {
		m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
		m_btnTime5_1.MoveWindow(860, 400, 57, 25, TRUE);
		g_time5 = FALSE;
	}
}

void CPic::OnBnClickedBtnTimealways()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time6) {
		//m_btnTimeAlways_1.MoveWindow(920, 179, 57, 25, TRUE);
		//m_btnTimeAlways.MoveWindow(920, 400, 57, 25, TRUE);
		//m_btnTime5.MoveWindow(860, 179, 57, 25, TRUE);
		//m_btnTime5_1.MoveWindow(860, 400, 57, 25, TRUE);
		//m_btnTime4.MoveWindow(810, 179, 57, 25, TRUE);
		//m_btnTime4_1.MoveWindow(810, 400, 57, 25, TRUE);
		//m_btnTime3.MoveWindow(760, 179, 57, 25, TRUE);
		//m_btnTime3_1.MoveWindow(760, 400, 57, 25, TRUE);
		//m_btnTime2.MoveWindow(710, 179, 57, 25, TRUE);
		//m_btnTime2_1.MoveWindow(710, 400, 57, 25, TRUE);
		//m_btnTime1.MoveWindow(660, 179, 57, 25, TRUE);
		//m_btnTime1_1.MoveWindow(660, 400, 57, 25, TRUE);

		m_btnTime1.MoveWindow(784, 70, 57, 25, TRUE);
		m_btnTime1_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime2.MoveWindow(845, 70, 57, 25, TRUE);
		m_btnTime2_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTime3.MoveWindow(906, 70, 57, 25, TRUE);
		m_btnTime3_1.MoveWindow(906, 400, 57, 25, TRUE);
		m_btnTime4.MoveWindow(784, 99, 57, 25, TRUE);
		m_btnTime4_1.MoveWindow(784, 400, 57, 25, TRUE);
		m_btnTime5.MoveWindow(845, 99, 57, 25, TRUE);
		m_btnTime5_1.MoveWindow(845, 400, 57, 25, TRUE);
		m_btnTimeAlways.MoveWindow(906, 400, 57, 25, TRUE);
		m_btnTimeAlways_1.MoveWindow(906, 99, 57, 25, TRUE);
		g_time6_1 = FALSE;
		g_time2 = TRUE;
	}
	HWND hWnd = ::FindWindow(L"Lenovo_Utility_Window", NULL);
	if (hWnd == NULL) {
		return;
	}
	::SendMessage(hWnd, WM_TIME_ALWAYS_MSG, NULL, NULL);
}

void CPic::OnBnClickedBtnTimealways1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_time6_1) {
		m_btnTimeAlways.MoveWindow(906, 99, 57, 25, TRUE);
		m_btnTimeAlways_1.MoveWindow(906, 400, 57, 25, TRUE);
		g_time6 = FALSE;
		g_time2 = TRUE;
	}
}
