#pragma once
#include "afxwin.h"
#include "xSkinButton.h"
#include "GdipButton.h"
#include "GdipButtonPic.h"
#include <afxpriv.h>


// CPic 对话框
#define PngShow			1
#define SetFocusPoint	2
#define FocusRun		3

#define REGSTR_PATH_SERVICES    TEXT("Software\\Lenovo\\OSD")
#define REGSUBKEY_MIC			TEXT("Mic")
#define REGSUBKEY_CAMERA		TEXT("Camera")
#define REGSUBKEY_TP			TEXT("TP")
#define REGSUBKEY_NUMBER		TEXT("NumberLock")
#define REGSUBKEY_CAPS			TEXT("Caps")
#define REGSUBKEY_FNLOCK		TEXT("FnLock")
#define REGSUBKEY_ITS			TEXT("ITS")
#define REGSUBKEY_LED			TEXT("KeyBoardLED")


class CPic : public CDialog
{
	DECLARE_DYNAMIC(CPic)

public:
	ULONG_PTR m_gdiplusToken;
	int k = 0;
	CPic(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPic();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
public:
	CToolTipCtrl m_tooltip;
	CxSkinButton m_btnClose;
	CGdipButtonPic m_btnDownload;

	CGdipButtonPic m_btnKeyboardLED;
	CGdipButtonPic m_btnKeyboardLED1;
	CGdipButtonPic m_btnKeyboardLED2;
	CGdipButtonPic m_btnKeyboardLED3;
	CGdipButtonPic m_btnCamera;
	CGdipButtonPic m_btnCamera1;
	CGdipButtonPic m_btnCaps;
	CGdipButtonPic m_btnCaps1;
	CGdipButtonPic m_btnFn;
	CGdipButtonPic m_btnFn1;
	CGdipButtonPic m_btnITS;
	CGdipButtonPic m_btnITS1;
	CGdipButtonPic m_btnITS2;
	CGdipButtonPic m_btnMic;
	CGdipButtonPic m_btnMic1;
	CGdipButtonPic m_btnNumber;
	CGdipButtonPic m_btnNumber1;
	CGdipButtonPic m_btnTP;
	CGdipButtonPic m_btnTP1;

	CGdipButtonPic m_btnCloseOSD;

	CGdipButtonPic m_btnTime1;
	CGdipButtonPic m_btnTime2;
	CGdipButtonPic m_btnTime3;
	CGdipButtonPic m_btnTime4;
	CGdipButtonPic m_btnTime5;
	CGdipButtonPic m_btnTimeAlways;
	CGdipButtonPic m_btnTime1_1;
	CGdipButtonPic m_btnTime2_1;
	CGdipButtonPic m_btnTime3_1;
	CGdipButtonPic m_btnTime4_1;
	CGdipButtonPic m_btnTime5_1;
	CGdipButtonPic m_btnTimeAlways_1;

	CGdipButtonPic m_btnPic;
	BOOL m_bTracked = FALSE;
	BOOL m_OnBtnFocusMsg = FALSE;
	CBitmap m_Pic_Test;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
	
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedAPPIcon1();
	afx_msg void OnBnClickedAPPIcon2();
	afx_msg void OnBnClickedAPPIcon3();
	afx_msg void OnBnClickedAPPIcon4();
	afx_msg void OnBnClickedAPPIcon5();
	afx_msg void OnBnClickedAppIcon6();
	afx_msg void OnBnClickedAppIcon7();
	afx_msg void OnBnClickedAppIcon8();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	/*afx_msg void GetFocusPoint();
	afx_msg void RunFocus();*/
	afx_msg LRESULT OnBtnFocusMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnClickedMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnPressMsg(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowOSD(WPARAM wParam, LPARAM lParam);

	//add utility state
	afx_msg LRESULT OnMicPress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnFnPress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCmeraPress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnKeyBoardLEDPress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnITSPress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCapsPress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnNumberLockPress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTpLockPress(WPARAM wParam, LPARAM lParam);

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);

	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedAppIcon11();
	afx_msg void OnBnClickedAppIcon21();
	afx_msg void OnBnClickedAppIcon31();
	afx_msg void OnBnClickedAppIcon41();
	afx_msg void OnBnClickedAppIcon51();
	afx_msg void OnBnClickedAppIcon61();
	afx_msg void OnBnClickedAppIcon71();
	afx_msg void OnBnClickedAppIcon72();
	afx_msg void OnBnClickedAppIcon81();
	afx_msg void OnBnClickedAppIcon82();
	afx_msg void OnBnClickedAppIcon83();
public:
	void ReadRegValue(DWORD *Val,LPTSTR szValue);
	void SetRegValue(DWORD Value, LPTSTR szValue);
	afx_msg void OnBnClickedBtnTime();
	afx_msg void OnBnClickedBtnTime4();
	afx_msg void OnBnClickedBtnTime2();
	afx_msg void OnBnClickedBtnTime3();
	afx_msg void OnBnClickedBtnTime5();
	afx_msg void OnBnClickedBtnTimealways();
	afx_msg void OnBnClickedBtnTime1();
	afx_msg void OnBnClickedBtnTime21();
	afx_msg void OnBnClickedBtnTime31();
	afx_msg void OnBnClickedBtnTime41();
	afx_msg void OnBnClickedBtnTime51();
	afx_msg void OnBnClickedBtnTimealways1();
};
