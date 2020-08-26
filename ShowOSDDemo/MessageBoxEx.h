#pragma once

 
#include "xSkinButton.h"
#include "afxwin.h"
#include "GdipButton.h"

 

// CNcInterfaceDlg dialog
class CMessageBoxEx : public CDialog
{
	// Construction
public:
	CMessageBoxEx(CWnd* pParent = NULL);	// standard constructor
	BOOL noShutUpBtn ;
	BOOL OnlyOKBtn ;
	BOOL IsOKChgOObeBtn ;
	static DWORD iQuitStatus ;
	CString m_szContext ;

	// Dialog Data
	enum { IDD = IDD_MESSAGEBOXEX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);

	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg void OnBnClickedQuit();

	/*CxSkinButton m_btn_ok;
	CxSkinButton m_btn_cancel;*/
	CGdipButton m_btn_ok;
	CGdipButton m_btn_cancel;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg void OnBnClickedButton2();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
};