// MessageBoxEx.cpp : implementation file
//

#include "stdafx.h"
#include "NcInterface.h"
#include "MessageBoxEx.h"
 #include "cgdiplusbitmap.h"


CMessageBoxEx::CMessageBoxEx(CWnd* pParent /*=NULL*/)
: CDialog(CMessageBoxEx::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	noShutUpBtn = FALSE;
	OnlyOKBtn = FALSE;
	IsOKChgOObeBtn = FALSE;

}
DWORD CMessageBoxEx::iQuitStatus = 0;
void CMessageBoxEx::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btn_ok);
	DDX_Control(pDX, IDC_QUIT, m_btn_cancel);
}

BEGIN_MESSAGE_MAP(CMessageBoxEx, CDialog)
	ON_WM_SYSCOMMAND()

	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CMessageBoxEx::OnBnClickedButton1)

	ON_BN_CLICKED(IDC_QUIT, &CMessageBoxEx::OnBnClickedQuit)
	ON_BN_CLICKED(IDOK, &CMessageBoxEx::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMessageBoxEx::OnBnClickedCancel)

	ON_WM_PAINT()
	ON_WM_NCHITTEST()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &CMessageBoxEx::OnBnClickedButton2)
	ON_WM_HELPINFO()
END_MESSAGE_MAP()


// obedlg message handlers

BOOL CMessageBoxEx::OnInitDialog()
{
	CDialog::OnInitDialog();
	ULONG_PTR uToken;
	GdiplusStartupInput gsi;
	GdiplusStartup(&uToken, &gsi, NULL );
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
    ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW);

	CRect rect;
	CBitmap  bmpBackground;
	GetClientRect(&rect); 
	bmpBackground.LoadBitmap(g_dwCurrentLanSmBackground);// 
	BITMAP bmInfo;
	bmpBackground.GetObject(sizeof(bmInfo),&bmInfo);
	MoveWindow(0,0,bmInfo.bmWidth,bmInfo.bmHeight,TRUE);

#ifndef RECT_IMAGE 
	GetClientRect(&rect); // 对话框矩形  
	HRGN hRgn = CreateRoundRectRgn(rect.left,rect.top,rect.right,rect.bottom,20,20); // 圆角矩形
	SetWindowRgn(hRgn,TRUE);
#endif
  
	CenterWindow(   CWnd::GetDesktopWindow()   ); 
  
	if(g_pTempBtnFont!=NULL)
	{
		g_pTempBtnFont->DeleteObject();
		g_pTempBtnFont = NULL;
	}
	if(g_pTempBtnFont==NULL)
	{
		g_pTempBtnFont = new CFont; 
		g_pTempBtnFont->CreateFont(22, // nHeight 
			8, // nWidth 
			0, // nEscapement 
			0, // nOrientation 
			800, // nWeight 
			false, // bItalic 
			FALSE, // bUnderline 
			0, // cStrikeOut 
			ANSI_CHARSET, // nCharSet 
			OUT_DEFAULT_PRECIS, // nOutPrecision 
			CLIP_DEFAULT_PRECIS, // nClipPrecision 
			DEFAULT_QUALITY, // nQuality 
			DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
			g_szCurrentLanguageType); // lpszFac 
	}
 
	m_btn_ok.m_bEnableWords=true;

	m_btn_ok.SetBK(g_dwCurrentLanSmBackground);
	m_btn_ok.SetFont(g_pTempBtnFont); 
	/*m_btn_ok.LoadStdImage(IDB_PNG3, _T("PNG"));
	m_btn_ok.LoadStdImageHover(IDB_PNG3, _T("PNG"));
	m_btn_ok.LoadAltImage(IDB_PNG3, _T("PNG"));*/
	memset(g_strTempContext,0,MAXTIPCOUNT);
	if (IsOKChgOObeBtn) // oobe 
	{
		if (g_NotSupportLanguage)
		{ 
			_tcscpy(g_strTempContext,TEXT( DEF_IDS_OBE_DLG_ENABLE_BTN2 ) );
		}
		else
		{
			if(0 == ::LoadString(NULL, IDS_OBE_DLG_ENABLE_BTN, g_strTempContext, MAXTIPCOUNT))
			{
				_tcscpy(g_strTempContext,TEXT( DEF_IDS_OBE_DLG_ENABLE_BTN2 ) );
			}
		}
		m_btn_ok.SetImageSize(g_dwBigBtn_W_len/*g_dwSmBtn_W_len*/,g_dwSmBtn_H_len);
		m_btn_ok.MoveWindow( g_dwSmBtn_X1_pos-70,g_dwSmBtn_Y_pos,g_dwBigBtn_W_len,g_dwSmBtn_H_len , TRUE);
	} 
	else
	{
		if (g_NotSupportLanguage)
		{ 
			_tcscpy(g_strTempContext,TEXT( DEF_IDS_MESSAGEBOXEX_OK ) );
		}
		else
		{
			if (0 == ::LoadString(NULL, IDS_MESSAGEBOXEX_OK, g_strTempContext, MAXTIPCOUNT))
			{
				_tcscpy(g_strTempContext,TEXT( DEF_IDS_MESSAGEBOXEX_OK ) );
			}
		}
		m_btn_ok.SetImageSize(g_dwSmBtn_W_len,g_dwSmBtn_H_len);
		m_btn_ok.MoveWindow( g_dwSmBtn_X1_pos,g_dwSmBtn_Y_pos,g_dwSmBtn_W_len,g_dwSmBtn_H_len , TRUE);
	}
	m_btn_ok.m_sTitle.Format(_T("%s"),g_strTempContext);


	m_btn_cancel.m_bEnableWords=true;
	m_btn_cancel.SetBK(g_dwCurrentLanSmBackground);
	m_btn_cancel.SetFont(g_pTempBtnFont); 
	/*m_btn_cancel.LoadStdImage(IDB_PNG3, _T("PNG"));
	m_btn_cancel.LoadStdImageHover(IDB_PNG3, _T("PNG"));
	m_btn_cancel.LoadAltImage(IDB_PNG3, _T("PNG"));*/
	memset(g_strTempContext,0,MAXTIPCOUNT);
 
	if (IsOKChgOObeBtn) // oobe
	{
		if (g_NotSupportLanguage)
		{ 
			_tcscpy(g_strTempContext,TEXT( DEF_IDS_OBE_DLG_DISABLE_BTN2 ) );
		}
		else
		{
			if (::LoadString(NULL, IDS_OBE_DLG_DISABLE_BTN, g_strTempContext, MAXTIPCOUNT) == 0)
			{
				_tcscpy(g_strTempContext,TEXT( DEF_IDS_OBE_DLG_DISABLE_BTN2 ) );
			}
		}
		m_btn_cancel.SetImageSize(g_dwBigBtn_W_len/*g_dwSmBtn_W_len+30*/,g_dwSmBtn_H_len);
		m_btn_cancel.MoveWindow( g_dwSmBtn_X2_pos-30,g_dwSmBtn_Y_pos,g_dwBigBtn_W_len,g_dwSmBtn_H_len , TRUE);
	} 
	else
	{
		if (g_NotSupportLanguage)
		{	 
			_tcscpy(g_strTempContext,TEXT( DEF_IDS_MESSAGEBOXEX_CANCEL ) );
		}
		else
		{
			if (0 == ::LoadString(NULL, IDS_MESSAGEBOXEX_CANCEL, g_strTempContext, MAXTIPCOUNT))
			{
				_tcscpy(g_strTempContext,TEXT( DEF_IDS_MESSAGEBOXEX_CANCEL ) );
			}
		}
		m_btn_cancel.SetImageSize(g_dwSmBtn_W_len,g_dwSmBtn_H_len);
		m_btn_cancel.MoveWindow( g_dwSmBtn_X2_pos,g_dwSmBtn_Y_pos,g_dwSmBtn_W_len,g_dwSmBtn_H_len , TRUE);
	}

	m_btn_cancel.m_sTitle.Format(_T("%s"),g_strTempContext);

 
	iQuitStatus = 0;
	//if (noShutUpBtn)//全部改成成无X状态
	{
		((CButton*)GetDlgItem(IDC_BUTTON2))->ShowWindow(SW_HIDE);
	}


	if (OnlyOKBtn) // 只有一个按钮
	{
		((CButton*)GetDlgItem(IDC_BUTTON2))->ShowWindow(SW_HIDE);
		((CButton*)GetDlgItem(IDC_BUTTON1))->ShowWindow(SW_HIDE);
		//  ((CButton*)GetDlgItem(IDC_QUIT))->SetFocus();
		memset(g_strTempContext,0,MAXTIPCOUNT);
 
		if (g_NotSupportLanguage)
		{ 
			 _tcscpy(g_strTempContext,TEXT( DEF_IDS_MESSAGEBOXEX_OK ) );
		}
		else
		{
			if (::LoadString(NULL, IDS_MESSAGEBOXEX_OK, g_strTempContext, MAXTIPCOUNT) == 0)
			{
				_tcscpy(g_strTempContext,TEXT( DEF_IDS_MESSAGEBOXEX_OK ) );
			}
		}
		//	m_btn_cancel.SetWindowText(g_strTempContext);
		m_btn_cancel.m_sTitle.Format(_T("%s"),g_strTempContext);
		m_btn_cancel.SetFocus();
		//m_btn_cancelm_btn_cancel.SetSkin(IDB_OK_NOR, IDB_OK_DOWN,IDB_OK_OVER,IDB_OK_OVER,0 ,IDB_OK_MASK1 ,0 ,0 ,0 ); 
	}

	if(g_pTempContextFont!=NULL)
	{
		g_pTempContextFont->DeleteObject();
		g_pTempContextFont = NULL;
	}

	if(g_pTempContextFont==NULL)
	{
		g_pTempContextFont = new CFont; 
		g_pTempContextFont->CreateFont(18, // nHeight 
			6, // nWidth 
			0, // nEscapement 
			0, // nOrientation 
			500, // nWeight 
			false, // bItalic 
			FALSE, // bUnderline 
			0, // cStrikeOut 
			ANSI_CHARSET, // nCharSet 
			OUT_DEFAULT_PRECIS, // nOutPrecision 
			CLIP_DEFAULT_PRECIS, // nClipPrecision 
			DEFAULT_QUALITY, // nQuality 
			DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
			g_szCurrentLanguageType); // lpszFac 

		if (USE_DEFAULT_LANGAGE_TYPE)
		{
			g_pTempContextFont = this->GetFont();
		}
	}

	((CStatic*)GetDlgItem(IDC_STATIC))->SetFont(g_pTempContextFont);
	((CStatic*)GetDlgItem(IDC_STATIC))->SetWindowText(m_szContext);

	//DWORD dwWide = ( (DWORD)(rect.right-g_dwBigContext_X_Lift_Margins-g_dwBigContext_RX_Right_Margins)/g_dwBigContext_Width )*g_dwBigContext_Width;
	//DWORD dwhight = rect.bottom-g_dwBigContext_RX_Right_Margins-g_dwBigContext_BY_bottom_Margins; 
	//((CStatic*)GetDlgItem(IDC_STATIC))->MoveWindow( g_dwBigContext_X_Lift_Margins,g_dwBigContext_RX_Right_Margins,dwWide,dwhight,TRUE); 
	if(g_IsLanguageRightAlign)
	{
		CStatic* pStatic = ((CStatic*)GetDlgItem(IDC_STATIC));
		LONG style = GetWindowLong(pStatic->GetSafeHwnd(),GWL_STYLE);
		style |= SS_RIGHT;
		SetWindowLong(pStatic->GetSafeHwnd(),GWL_STYLE,style);
	}
	if(g_IsJapaneseLanguage)
	{
	 ((CStatic*)GetDlgItem(IDC_STATIC))->MoveWindow(33,41,298 ,300 ,TRUE);
  
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMessageBoxEx::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

#ifdef PRINT_TITAIL_ON_BG
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
		bmpBackground.LoadBitmap(g_dwCurrentLanSmBackground);//
		CBitmap *pbmpOld=dcMem.SelectObject(&bmpBackground);
		BITMAP bmInfo;
		bmpBackground.GetObject(sizeof(bmInfo),&bmInfo);
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bmInfo.bmWidth-1,  bmInfo.bmHeight-1,SRCCOPY);//
		HFONT hFONT=::CreateFont(27,8,0,0,700,0,0,0,0,0,0,0,0,g_szCurrentLanguageType);
		::SelectObject (dc.m_hDC,hFONT);
		::SetBkMode (dc.m_hDC,TRANSPARENT);
		::SetTextColor(dc.m_hDC,RGB(241,155,43));
		::TextOut(dc.m_hDC,130,6,_T("Instant Reset"),13);
		if(g_pTempContextFont!=NULL)
		{
			((CStatic*)GetDlgItem(IDC_STATIC))->SetFont(g_pTempContextFont);
		}
		image.Load(IDB_PNG_LOGO, _T("PNG"));
		graphics.DrawImage(image,10,12,70,12);
		graphics.ReleaseHDC(dc.m_hDC);
		::DeleteObject(pbmpOld);
		::DeleteObject(&image);
		::DeleteDC(dcMem);
		DeleteObject(bmpBackground); 
#else
		CPaintDC dc(this);  
		CBitmap   bitmap;         
		bitmap.LoadBitmap(g_dwCurrentLanSmBackground);     

		CDC   dcMem;                    
		dcMem.CreateCompatibleDC(&dc);  

		CBitmap*   pOldBitmap   =   dcMem.SelectObject(&bitmap); 

		BITMAP bmInfo;
		bitmap.GetObject(sizeof(bmInfo),&bmInfo);
		CRect   rect(0   ,0,   0,   0); 
		GetClientRect( &rect );

		dc.StretchBlt(0,   0,  rect.Width(),rect.Height(),   &dcMem,   
			0,   0,  bmInfo.bmWidth-1,  bmInfo.bmHeight-1,   SRCCOPY);// 
#endif

	}
}
LRESULT CMessageBoxEx::OnNcHitTest(CPoint point)
{
	// TODO: Add your message handler code here and/or call defaultCWnd::OnNcHitTest(point)  
	if   (CDialog::OnNcHitTest(point) ==   HTCLIENT) 
		return   HTCAPTION; 

	return CDialog::OnNcHitTest(point);
}


HBRUSH CMessageBoxEx::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//if(nCtlColor   ==   CTLCOLOR_STATIC)   
	//{ 
	//	pDC->SetTextColor(RGB(255, 255, 255));
	//	pDC-> SetBkMode(TRANSPARENT);   
	//} 
	//return   HBRUSH(GetStockObject(HOLLOW_BRUSH)); 
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	pDC->SetTextColor(RGB(255,255,255));
	pDC->SetBkMode(TRANSPARENT);   
	return  (HBRUSH)::GetStockObject(NULL_BRUSH);  
}



void CMessageBoxEx::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{

	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMessageBoxEx::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 确定
void CMessageBoxEx::OnBnClickedButton1()
{
	iQuitStatus = 1;
	OnOK();// TODO: Add your control notification handler code here
}

// 取消
void CMessageBoxEx::OnBnClickedQuit()
{
	// TODO: Add your control notification handler code here
iQuitStatus = 0;	
OnCancel();
}

void CMessageBoxEx::OnBnClickedOk()
{
 // TODO: Add your control notification handler code here
	iQuitStatus = 1;
	OnOK();
}

void CMessageBoxEx::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
OnCancel();
iQuitStatus = 0;	
}

// 关闭
void CMessageBoxEx::OnBnClickedButton2()
{
	iQuitStatus = 0;
	OnCancel();// TODO: Add your control notification handler code here
}

BOOL CMessageBoxEx::OnHelpInfo(HELPINFO* pHelpInfo)
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;

	//return CDialog::OnHelpInfo(pHelpInfo);
}
