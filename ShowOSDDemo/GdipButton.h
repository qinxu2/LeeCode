/********************************************************************************
模块名       : GdipButton
相关文件     : GdipButton.cpp
文件实现功能 : The Button Class 
作者         : 
版本         : 1.0
--------------------------------------------------------------------------------
备注         : <其它说明>
--------------------------------------------------------------------------------
修改记录 : 
日 期              版本          修改人               修改内容
YYYY/MM/DD         X.Y       <作者或修改者名>        <修改内容>
*******************************************************************************/

#pragma once
class CGdiPlusBitmapResource;
/////////////////////////////////////////////////////////////////////////////
// CGdipButton window

class CGdipButton : public CButton
{
public:
	bool	m_bIsDisabled;
	bool    m_bEnableWords;
	bool    m_BKEnable;
	int     m_BtnPressed;
	int     m_nModeNum;
	int     m_yShift;
	int     m_xShift;
	UINT    m_nFontSize;
	CString m_sTitle;
	HWND    m_PrtHandle;
	CGdipButton();
	virtual ~CGdipButton();
	// image types
	enum	{
		STD_TYPE	= 0,
		ALT_TYPE,
		DIS_TYPE
	};
	// sets the image type
	bool SetImageSize(float x,float y)
	{ 
		m_nImageWidth=x; 
	    m_nImageHeight=y;
		return true;
	};
	BOOL LoadAltImage(UINT id, LPCTSTR pType);
	BOOL LoadStdImage(UINT id, LPCTSTR pType);
	BOOL LoadStdImageHover(UINT id, LPCTSTR pType);
	BOOL LoadStdImageDisabled(UINT id, LPCTSTR pType);
	// if false, disables the press state and uses grayscale image if it exists
	void EnableButton(BOOL bEnable = TRUE) {
		m_bIsDisabled = !bEnable;
	    m_BtnPressed=0;
		if(this->GetSafeHwnd()!=NULL)
			this->Invalidate();
	}
	// in toggle mode each press toggles between std and alt images
	void EnableToggle(BOOL bEnable = TRUE);
	void SetBkGnd(CDC* pDC);
	void SetBK(UINT id,int x=0,int y=0,bool enable=0){m_ID=id; m_yShift=y;m_xShift=x;m_BKEnable=enable;}
	void SetHorizontal(bool ImagesAreLaidOutHorizontally = FALSE);
	void DeleteToolTip();
	void ImageMove(float x,float y)
	{
		m_X=x;
		m_Y=y;
	}
protected:
	BOOL	m_bIsHovering;
	BOOL	m_bHaveAltImage;
	BOOL	m_bIsToggle;
	BOOL	m_bHaveBitmaps;
	bool    m_bDisableEnable;
	bool    m_Disabled;
	bool    m_PressedEnable;	
	BOOL	m_bIsTracking;	
	float   m_X;
	float   m_Y;
	int		m_nCurType;
	UINT    m_ID;

	float   m_nImageWidth;
	float   m_nImageHeight;
	CGdiPlusBitmapResource* m_pAltImage;
	CGdiPlusBitmapResource* m_pStdImage;
	CGdiPlusBitmapResource* m_pStdImageHover;
	CGdiPlusBitmapResource* m_pStdImagePressed;
	CString	m_tooltext;
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	void PaintBk(CDC* pDC);
	void PaintBtn(CDC* pDC);
	//{{AFX_MSG(CGdipButton)
	afx_msg HBRUSH  CtlColor(CDC* pDC, UINT nCtlColor);	
	afx_msg BOOL    OnEraseBkgnd(CDC* pDC);
	afx_msg void    OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnMouseHover(WPARAM wparam, LPARAM lparam) ;
	afx_msg void    OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg	void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDC		m_dcBk;			// button background
	CDC		m_dcStd;		// standard button
	CDC		m_dcStdP;		// standard button pressed
	CDC		m_dcStdH;		// standard button hot
	CDC		m_dcStdON;		// standard button hot
	CDC		m_dcAlt;		// alternate button
	CDC		m_dcAltP;		// alternate button pressed
	CDC		m_dcAltH;		// alternate button hot
	CDC		m_dcGS;			// grayscale button (does not have a hot or pressed state)
	CDC*	m_pCurBtn;		// current pointer to one of the above

};
