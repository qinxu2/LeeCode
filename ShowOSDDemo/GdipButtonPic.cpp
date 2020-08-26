#include "stdafx.h" 
#include "GdipButtonPic.h"
#include "GdipButton.h"

#include "CGdiPlusBitmap.h"
#include "MemDC.h"
#pragma comment(lib,"gdiplus.lib")

CGdipButtonPic::CGdipButtonPic()
{
	m_pStdImage = NULL;
	m_bEnableWords = false;
	m_pAltImage = NULL;
	m_pStdImageHover = NULL;
	m_pStdImagePressed = NULL;
	m_bHaveBitmaps = FALSE;
	m_bHaveAltImage = FALSE;
	m_pCurBtn = NULL;
	m_bIsDisabled = FALSE;
	m_bIsToggle = FALSE;
	m_bIsHovering = FALSE;
	m_bIsTracking = FALSE;
	m_BtnPressed = NULL;
	m_Disabled = 0;
	m_PressedEnable = NULL;
	m_bDisableEnable = false;
	m_nCurType = STD_TYPE;
	m_nImageWidth = 0;
	m_nImageHeight = 0;
	m_nModeNum = 0;
	m_ID = 0;
	m_X = 0;
	m_Y = 0;
	m_nFontSize = 12;
	//m_nFontSize=13;
}


CGdipButtonPic::~CGdipButtonPic()
{
	if (m_pStdImage)        delete m_pStdImage;
	if (m_pStdImageHover)   delete m_pStdImageHover;
	if (m_pStdImagePressed) delete m_pStdImagePressed;
	if (m_pAltImage)        delete m_pAltImage;
}

BEGIN_MESSAGE_MAP(CGdipButtonPic, CButton)
	//{{AFX_MSG_MAP(CGdipButton)
	ON_WM_DRAWITEM()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
	//}}AFX_MSG_MAP
	ON_WM_NCMOUSEMOVE()
END_MESSAGE_MAP()

BOOL CGdipButtonPic::LoadStdImage(UINT id, LPCTSTR pType)
{
	m_bIsHovering = FALSE;
	m_bIsTracking = FALSE;
	if (m_pStdImage) delete m_pStdImage;
	m_pStdImage = new CGdiPlusBitmapResource;
	return m_pStdImage->Load(id, pType);
}

BOOL CGdipButtonPic::LoadStdImageHover(UINT id, LPCTSTR pType)
{
	if (m_pStdImageHover) delete m_pStdImageHover;
	m_pStdImageHover = new CGdiPlusBitmapResource;
	return m_pStdImageHover->Load(id, pType);
}
BOOL CGdipButtonPic::LoadStdImageDisabled(UINT id, LPCTSTR pType)
{
	if (m_pStdImagePressed) delete m_pStdImagePressed;
	m_pStdImagePressed = new CGdiPlusBitmapResource;
	m_bDisableEnable = 1;
	return m_pStdImagePressed->Load(id, pType);
}
BOOL CGdipButtonPic::LoadAltImage(UINT id, LPCTSTR pType)
{
	m_bHaveAltImage = TRUE;
	if (m_pAltImage) delete m_pAltImage;
	m_pAltImage = new CGdiPlusBitmapResource;
	return (m_pAltImage->Load(id, pType));
}
//=============================================================================
//
//	The framework calls this member function when a child control is about to 
//	be drawn.  All the bitmaps are created here on the first call. Every thing
//	is done with a memory DC except the background, which get's it's information 
//	from the parent. The background is needed for transparent portions of PNG 
//	images. An always on top app (such as Task Manager) that is in the way can 
//	cause it to get an incorrect background.  To avoid this, the parent should 
//	call the SetBkGnd function with a memory DC when it creates the background.
//				
//=============================================================================
HBRUSH CGdipButtonPic::CtlColor(CDC* pScreenDC, UINT nCtlColor)
{
	if (!m_bHaveBitmaps)
	{
		if (!m_pStdImage)
		{
			return NULL; // Load the standard image with LoadStdImage()
		}

		CBitmap bmp, *pOldBitmap;
		CRect rect;
		GetClientRect(rect);
		// do everything with mem dc
		CMemDC pDC(pScreenDC, rect);
		Gdiplus::Graphics graphics(pDC->m_hDC);

		CFont font;
		font.CreateFontW(13, // nHeight 
			8, // nWidth 
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
			g_szCurrentLanguageType); // lpszFac _T("Segoe UI")
		pDC->SelectObject(&font);

		if (m_dcBk.m_hDC == NULL)
		{
			CRect rect1;
			CClientDC clDC(GetParent());
			GetWindowRect(rect1);
			GetParent()->ScreenToClient(rect1);
			if (m_dcBk.m_hDC == NULL)
				m_dcBk.CreateCompatibleDC(&clDC);
			bmp.CreateCompatibleBitmap(&clDC, rect.Width(), rect.Height());
			pOldBitmap = m_dcBk.SelectObject(&bmp);
			m_dcBk.BitBlt(0, 0, rect.Width(), rect.Height(), &clDC, rect1.left, rect1.top, SRCCOPY);
			bmp.DeleteObject();
		}

		// standard image
		if (m_dcStd.m_hDC == NULL)
		{
			PaintBk(pDC);
			ColorMatrix HotMat = { 1.05f, 0.00f, 0.00f, 0.00f, 0.00f,
				0.00f, 1.05f, 0.00f, 0.00f, 0.00f,
				0.00f, 0.00f, 1.05f, 0.00f, 0.00f,
				0.00f, 0.00f, 0.00f, 1.00f, 0.00f,
				0.05f, 0.05f, 0.05f, 0.00f, 1.00f };

			ImageAttributes ia;
			ia.SetColorMatrix(&HotMat);

			float width = (float)m_pStdImage->m_pBitmap->GetWidth();
			float height = (float)m_pStdImage->m_pBitmap->GetHeight();
			CRect rect;
			::GetWindowRect(this->GetSafeHwnd(), &rect);
			RectF grect;

			if (!m_nImageWidth)
			{
				grect.X = m_X, grect.Y = m_Y; grect.Width = width; grect.Height = height;
				graphics.DrawImage(*m_pStdImage, grect, 0, 0, width, height, UnitPixel, &ia);
			}
			else
			{
				grect.X = m_X, grect.Y = m_Y; grect.Width = m_nImageWidth; grect.Height = m_nImageHeight;
				graphics.DrawImage(*m_pStdImage, grect, 0, 0, width, height, UnitPixel, &ia);
			}
			if (m_bEnableWords) {
				CRect ClientRect;
				GetClientRect(&ClientRect);
				CSize ClientSize(ClientRect.Width(), ClientRect.Height());
				using namespace Gdiplus;
				Graphics g(pDC->m_hDC);
				RectF ClientRectangle((float)ClientRect.top, (float)ClientRect.left, (float)ClientRect.Width(), (float)ClientRect.Height());
				g.FillRectangle(&SolidBrush(Color::Transparent), ClientRectangle);
				Bitmap bm(ClientSize.cx / 5, ClientSize.cy / 5, &g);
				::SetBkMode(pDC->m_hDC, TRANSPARENT);

				::SetTextColor(pDC->m_hDC, RGB(255, 255, 255));

				GraphicsPath pth;

				//Add the string in the chosen style.  
				int style = FontStyleBold;
				int data = m_sTitle.GetAllocLength();
				CSize   s;
				s = pDC->GetTextExtent(m_sTitle);
				if ((m_nImageWidth - s.cx) > 10)
					pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point((int)((m_nImageWidth - s.cx) / 2), int(m_nImageHeight / 5)), NULL);
				else
					pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point(5, int(m_nImageHeight / 5)), NULL);
				Graphics* bmpg = Graphics::FromImage(&bm);
				Matrix mx(1.0f / 5, 0, 0, 1.0f / 5, -(1.0f) / 5, -(1.0f) / 5);
				bmpg->SetSmoothingMode(SmoothingModeAntiAlias);
				bmpg->SetTransform(&mx);

				//Using a suitable pen...
				Pen p(0xCCEA8000, 1);
				p.SetColor(0xFF000000);
				bmpg->DrawPath(&p, &pth);
				bmpg->FillPath(&SolidBrush(Color::Black), &pth);
				g.SetTransform(&Matrix(1, 0, 0, 1, 0, 0));

				g.SetSmoothingMode(SmoothingModeHighQuality);
				g.SetInterpolationMode(InterpolationModeHighQualityBicubic);

				g.FillPath(&SolidBrush(Color::FloralWhite), &pth);
			}
			if (m_dcStd.m_hDC == NULL)
				m_dcStd.CreateCompatibleDC(pDC);
			bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
			pOldBitmap = m_dcStd.SelectObject(&bmp);
			m_dcStd.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, 0, 0, SRCCOPY);
			bmp.DeleteObject();
			// standard image pressed
			if (m_dcStdP.m_hDC == NULL)
			{
				PaintBk(pDC);
				ColorMatrix HotMat = { 1.05f, 0.00f, 0.00f, 0.00f, 0.00f,
					0.00f, 1.05f, 0.00f, 0.00f, 0.00f,
					0.00f, 0.00f, 1.05f, 0.00f, 0.00f,
					0.00f, 0.00f, 0.00f, 1.00f, 0.00f,
					0.05f, 0.05f, 0.05f, 0.00f, 1.00f };

				ImageAttributes ia;
				ia.SetColorMatrix(&HotMat);

				float width = (float)m_pStdImage->m_pBitmap->GetWidth();
				float height = (float)m_pStdImage->m_pBitmap->GetHeight();

				RectF grect;
				if (!m_nImageWidth)
				{
					grect.X = m_X, grect.Y = m_Y; grect.Width = width; grect.Height = height;
					graphics.DrawImage(*m_pStdImage, grect, 0, 0, width, height, UnitPixel, &ia);
				}
				else
				{
					grect.X = m_X, grect.Y = m_Y; grect.Width = m_nImageWidth; grect.Height = m_nImageHeight;
					graphics.DrawImage(*m_pStdImage, grect, 0, 0, width, height, UnitPixel, &ia);
				}
				if (m_bEnableWords) {
					CRect ClientRect;
					GetClientRect(&ClientRect);
					CSize ClientSize(ClientRect.Width(), ClientRect.Height());
					using namespace Gdiplus;
					Graphics g(pDC->m_hDC);
					RectF ClientRectangle((float)ClientRect.top, (float)ClientRect.left, (float)ClientRect.Width(), (float)ClientRect.Height());
					g.FillRectangle(&SolidBrush(Color::Transparent), ClientRectangle);
					Bitmap bm(ClientSize.cx / 5, ClientSize.cy / 5, &g);
					::SetBkMode(pDC->m_hDC, TRANSPARENT);
					::SetTextColor(pDC->m_hDC, RGB(255, 255, 255));
					GraphicsPath pth;

					//Add the string in the chosen style.  
					int style = FontStyleBold;
					int data = m_sTitle.GetAllocLength();
					CSize   s;
					s = pDC->GetTextExtent(m_sTitle);

					if ((m_nImageWidth - s.cx) > 10)
						pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point((int)((m_nImageWidth - s.cx) / 2), int(m_nImageHeight / 5)), NULL);
					else
						pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point(5, int(m_nImageHeight / 5)), NULL);
					Graphics* bmpg = Graphics::FromImage(&bm);
					Matrix mx(1.0f / 5, 0, 0, 1.0f / 5, -(1.0f) / 5, -(1.0f) / 5);
					bmpg->SetSmoothingMode(SmoothingModeAntiAlias);
					bmpg->SetTransform(&mx);
					Pen p(0xCCEA8000, 1);
					bmpg->DrawPath(&p, &pth);
					bmpg->FillPath(&SolidBrush(Color::Black), &pth);
					g.SetTransform(&Matrix(1, 0, 0, 1, 0, 0));

					g.SetSmoothingMode(SmoothingModeHighQuality);
					g.SetInterpolationMode(InterpolationModeHighQualityBicubic);

					g.FillPath(&SolidBrush(Color::FloralWhite), &pth);

				}
				if (m_dcStdP.m_hDC == NULL)
					m_dcStdP.CreateCompatibleDC(pDC);
				bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
				pOldBitmap = m_dcStdP.SelectObject(&bmp);
				m_dcStdP.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, 0, 0, SRCCOPY);
				bmp.DeleteObject();
			}
			// standard image hot
			if (m_dcStdH.m_hDC == NULL)
			{
				PaintBk(pDC);

				ColorMatrix HotMat = { 1.05f, 0.00f, 0.00f, 0.00f, 0.00f,
					0.00f, 1.05f, 0.00f, 0.00f, 0.00f,
					0.00f, 0.00f, 1.05f, 0.00f, 0.00f,
					0.00f, 0.00f, 0.00f, 1.00f, 0.00f,
					0.05f, 0.05f, 0.05f, 0.00f, 1.00f };

				ImageAttributes ia;
				ia.SetColorMatrix(&HotMat);

				float width = (float)m_pStdImageHover->m_pBitmap->GetWidth();
				float height = (float)m_pStdImageHover->m_pBitmap->GetHeight();
				if (!m_nImageWidth)
				{
					grect.X = m_X, grect.Y = m_Y; grect.Width = width; grect.Height = height;
					graphics.DrawImage(*m_pStdImageHover, grect, 0, 0, width, height, UnitPixel, &ia);
				}
				else
				{
					grect.X = m_X, grect.Y = m_Y; grect.Width = m_nImageWidth; grect.Height = m_nImageHeight;
					graphics.DrawImage(*m_pStdImageHover, grect, 0, 0, width, height, UnitPixel, &ia);
				}
				if (m_bEnableWords) {
					CRect ClientRect;
					GetClientRect(&ClientRect);
					CSize ClientSize(ClientRect.Width(), ClientRect.Height());
					using namespace Gdiplus;
					Graphics g(pDC->m_hDC);
					RectF ClientRectangle((float)ClientRect.top, (float)ClientRect.left, (float)ClientRect.Width(), (float)ClientRect.Height());
					g.FillRectangle(&SolidBrush(Color::Transparent), ClientRectangle);
					Bitmap bm(ClientSize.cx / 5, ClientSize.cy / 5, &g);
					::SetBkMode(pDC->m_hDC, TRANSPARENT);
					::SetTextColor(pDC->m_hDC, RGB(255, 255, 255));
					GraphicsPath pth;

					//Add the string in the chosen style.  
					int style = FontStyleBold;
					int data = m_sTitle.GetAllocLength();
					CSize   s;
					s = pDC->GetTextExtent(m_sTitle);
					if ((m_nImageWidth - s.cx) > 10)
						pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point((int)(m_nImageWidth - s.cx) / 2, int(m_nImageHeight / 5)), NULL);
					else
						pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point(5, int(m_nImageHeight / 5)), NULL);
					Graphics* bmpg = Graphics::FromImage(&bm);
					Matrix mx(1.0f / 5, 0, 0, 1.0f / 5, -(1.0f) / 5, -(1.0f) / 5);
					bmpg->SetSmoothingMode(SmoothingModeAntiAlias);
					bmpg->SetTransform(&mx);
					//Using a suitable pen...
					Pen p(0xAA0092BA, 1);
					bmpg->DrawPath(&p, &pth);
					bmpg->FillPath(&SolidBrush(Color::Black), &pth);
					g.SetTransform(&Matrix(1, 0, 0, 1, 0, 0));

					g.SetSmoothingMode(SmoothingModeHighQuality);
					g.SetInterpolationMode(InterpolationModeHighQualityBicubic);//InterpolationModeHighQuality);

					g.DrawImage(&bm, ClientRectangle, 0, 0, (float)bm.GetWidth(), (float)bm.GetHeight(), UnitPixel);
					g.FillPath(&SolidBrush(Color::FloralWhite), &pth);
				}
				if (m_dcStdH.m_hDC == NULL)
					m_dcStdH.CreateCompatibleDC(pDC);
				bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
				pOldBitmap = m_dcStdH.SelectObject(&bmp);
				m_dcStdH.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, 0, 0, SRCCOPY);
				bmp.DeleteObject();
			}

			// grayscale image
			if (m_dcGS.m_hDC == NULL)
			{
				PaintBk(pDC);

				ColorMatrix GrayMat = { 0.30f, 0.30f, 0.30f, 0.00f, 0.00f,
					0.59f, 0.59f, 0.59f, 0.00f, 0.00f,
					0.11f, 0.11f, 0.11f, 0.00f, 0.00f,
					0.00f, 0.00f, 0.00f, 1.00f, 0.00f,
					0.00f, 0.00f, 0.00f, 0.00f, 1.00f };

				ImageAttributes ia;
				ia.SetColorMatrix(&GrayMat);

				float width = (float)m_pStdImage->m_pBitmap->GetWidth();
				float height = (float)m_pStdImage->m_pBitmap->GetHeight();

				RectF grect; grect.X = 0, grect.Y = 0; grect.Width = width; grect.Height = height;

				graphics.DrawImage(*m_pStdImage, grect, 0, 0, width, height, UnitPixel, &ia);//0331

				if (m_dcGS.m_hDC == NULL)
					m_dcGS.CreateCompatibleDC(pDC);
				bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
				pOldBitmap = m_dcGS.SelectObject(&bmp);
				m_dcGS.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, 0, 0, SRCCOPY);
				bmp.DeleteObject();
			}
		}

		// alternate image
		if ((m_dcAlt.m_hDC == NULL) && m_bHaveAltImage)
		{
			PaintBk(pDC);
			float width = (float)m_pStdImage->m_pBitmap->GetWidth();
			float height = (float)m_pStdImage->m_pBitmap->GetHeight();
			ImageAttributes ia;
			RectF grect; grect.X = 0, grect.Y = 0; grect.Width = width; grect.Height = height;

			if (!m_nImageWidth)
			{
				grect.X = m_X, grect.Y = m_Y; grect.Width = width; grect.Height = height;
				graphics.DrawImage(*m_pAltImage, grect, 0, 0, width, height, UnitPixel, &ia);
			}
			else
			{
				grect.X = m_X, grect.Y = m_Y; grect.Width = m_nImageWidth; grect.Height = m_nImageHeight;
				graphics.DrawImage(*m_pAltImage, grect, 0, 0, width, height, UnitPixel, &ia);
			}
			if (m_bEnableWords) {
				CRect ClientRect;
				GetClientRect(&ClientRect);
				CSize ClientSize(ClientRect.Width(), ClientRect.Height());
				using namespace Gdiplus;
				Graphics g(pDC->m_hDC);
				RectF ClientRectangle((float)ClientRect.top, (float)ClientRect.left, (float)ClientRect.Width(), (float)ClientRect.Height());
				g.FillRectangle(&SolidBrush(Color::Transparent), ClientRectangle);
				Bitmap bm(ClientSize.cx / 5, ClientSize.cy / 5, &g);
				::SetBkMode(pDC->m_hDC, TRANSPARENT);
				::SetTextColor(pDC->m_hDC, RGB(255, 255, 255));
				GraphicsPath pth;
				//Add the string in the chosen style.  
				int style = FontStyleBold;
				int data = m_sTitle.GetAllocLength();
				CSize   s;
				s = pDC->GetTextExtent(m_sTitle);
				if ((m_nImageWidth - s.cx) > 10)
					pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point((int)((m_nImageWidth - s.cx) / 2), int(m_nImageHeight / 5)), NULL);
				else
					pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point(5, int(m_nImageHeight / 5)), NULL);
				Graphics* bmpg = Graphics::FromImage(&bm);
				Matrix mx(1.0f / 5, 0, 0, 1.0f / 5, -(1.0f) / 5, -(1.0f) / 5);
				bmpg->SetSmoothingMode(SmoothingModeAntiAlias);//SmoothingModeHighQuality);
				bmpg->SetTransform(&mx);

				//Using a suitable pen...
				Pen p(0xFFC07000, 1);
				bmpg->DrawPath(&p, &pth);
				bmpg->FillPath(&SolidBrush(Color::Black), &pth);
				g.SetTransform(&Matrix(1, 0, 0, 1, 0, 0));

				g.SetSmoothingMode(SmoothingModeHighQuality);
				g.SetInterpolationMode(InterpolationModeHighQualityBicubic);//InterpolationModeHighQuality);

				if (!m_bDisableEnable)
				{
					g.DrawImage(&bm, ClientRectangle, 0, 0, (float)bm.GetWidth(), (float)bm.GetHeight(), UnitPixel);

					g.FillPath(&SolidBrush(Color::FloralWhite), &pth);
				}
				else
					g.FillPath(&SolidBrush(Color::Gray), &pth);
			}
			if ((m_dcAlt.m_hDC == NULL))
				m_dcAlt.CreateCompatibleDC(pDC);
			bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
			pOldBitmap = m_dcAlt.SelectObject(&bmp);
			m_dcAlt.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, 0, 0, SRCCOPY);

			bmp.DeleteObject();

			// alternate image pressed
			if ((m_dcAltP.m_hDC == NULL) && m_bHaveAltImage)
			{
				PaintBk(pDC);

				graphics.DrawImage(*m_pAltImage, 1, 1);
				if ((m_dcAltP.m_hDC == NULL))
					m_dcAltP.CreateCompatibleDC(pDC);

				bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
				pOldBitmap = m_dcAltP.SelectObject(&bmp);
				m_dcAltP.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, 0, 0, SRCCOPY);
				bmp.DeleteObject();
			}

			// alternate image hot
			if (m_dcAltH.m_hDC == NULL&&m_bDisableEnable == 1)
			{
				PaintBk(pDC);

				ColorMatrix HotMat = { 1.05f, 0.00f, 0.00f, 0.00f, 0.00f,
					0.00f, 1.05f, 0.00f, 0.00f, 0.00f,
					0.00f, 0.00f, 1.05f, 0.00f, 0.00f,
					0.00f, 0.00f, 0.00f, 1.00f, 0.00f,
					0.05f, 0.05f, 0.05f, 0.00f, 1.00f };

				ImageAttributes ia;
				ia.SetColorMatrix(&HotMat);

				float width = (float)m_pStdImagePressed->m_pBitmap->GetWidth();//m_pStdImage
				float height = (float)m_pStdImagePressed->m_pBitmap->GetHeight();

				RectF grect; grect.X = 0, grect.Y = 0; grect.Width = width; grect.Height = height;

				graphics.DrawImage(*m_pStdImagePressed, grect, 0, 0, width, height, UnitPixel, &ia);//0331

				if (m_bEnableWords) {
					CRect ClientRect;
					GetClientRect(&ClientRect);
					CSize ClientSize(ClientRect.Width(), ClientRect.Height());
					using namespace Gdiplus;
					Graphics g(pDC->m_hDC);
					RectF ClientRectangle((float)ClientRect.top, (float)ClientRect.left, (float)ClientRect.Width(), (float)ClientRect.Height());
					g.FillRectangle(&SolidBrush(Color::Transparent), ClientRectangle);
					Bitmap bm(ClientSize.cx / 5, ClientSize.cy / 5, &g);
					::SetBkMode(pDC->m_hDC, TRANSPARENT);
					::SetTextColor(pDC->m_hDC, RGB(255, 255, 255));
					GraphicsPath pth;
					//Add the string in the chosen style.  
					int style = FontStyleBold;
					int data = m_sTitle.GetAllocLength();
					CSize   s;
					s = pDC->GetTextExtent(m_sTitle);
					if ((m_nImageWidth - s.cx) > 10)
						pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point((int)((m_nImageWidth - s.cx) / 2), int(m_nImageHeight / 5)), NULL);
					else
						pth.AddString(m_sTitle, -1, &FontFamily(g_szCurrentLanguageType), 0, m_nFontSize, Point(5, int(m_nImageHeight / 5)), NULL);
					Graphics* bmpg = Graphics::FromImage(&bm);
					Matrix mx(1.0f / 5, 0, 0, 1.0f / 5, -(1.0f) / 5, -(1.0f) / 5);
					bmpg->SetSmoothingMode(SmoothingModeAntiAlias);
					bmpg->SetTransform(&mx);
					//Using a suitable pen...
					Pen p(0xFFC07000, 1);
					bmpg->DrawPath(&p, &pth);
					bmpg->FillPath(&SolidBrush(Color::Black), &pth);
					g.SetTransform(&Matrix(1, 0, 0, 1, 0, 0));

					g.SetSmoothingMode(SmoothingModeHighQuality);
					g.SetInterpolationMode(InterpolationModeHighQualityBicubic);

					if (!m_bDisableEnable)
					{
						g.DrawImage(&bm, ClientRectangle, 0, 0, (float)bm.GetWidth(), (float)bm.GetHeight(), UnitPixel);

						g.FillPath(&SolidBrush(Color::FloralWhite), &pth);
					}
					else
						g.FillPath(&SolidBrush(Color::Gray), &pth);
				}
				if (m_dcAltH.m_hDC == NULL)
					m_dcAltH.CreateCompatibleDC(pDC);
				bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
				pOldBitmap = m_dcAltH.SelectObject(&bmp);
				m_dcAltH.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, 0, 0, SRCCOPY);
				bmp.DeleteObject();

			}

		}

		if (m_pCurBtn == NULL)
		{
			m_pCurBtn = &m_dcStd;
		}

		m_bHaveBitmaps = TRUE;
		::DeleteObject(&font);
	}
	return NULL;
}

//=============================================================================
// paint the background
//=============================================================================
void CGdipButtonPic::PaintBk(CDC *pDC)
{
	CRect rect, rect1;
	CRect rectprt;
	GetClientRect(rect);
	::GetWindowRect(::GetParent(this->GetSafeHwnd()), &rectprt);
	GetWindowRect(&rect1);
	CDC         dcMem;
	CBitmap     bmpBackground;
	dcMem.CreateCompatibleDC(pDC);
	bmpBackground.LoadBitmap(m_ID);
	dcMem.SelectObject(&bmpBackground);
	if (!m_BKEnable)
		pDC->BitBlt(-(rect1.left - rectprt.left) - m_xShift, -(rect1.top - rectprt.top) - m_yShift, 1000, 1000, &dcMem, 0, 0, SRCCOPY);
	else
		pDC->BitBlt(m_xShift, m_yShift, 1000, 1000, &dcMem, 0, 0, SRCCOPY);
}

//=============================================================================
// paint the bitmap currently pointed to with m_pCurBtn
//=============================================================================
void CGdipButtonPic::PaintBtn(CDC *pDC)
{
	CRect rect;
	GetClientRect(rect);
	if (m_BtnPressed&&m_PressedEnable)
	{
		m_pCurBtn = &m_dcAlt;
	}
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), m_pCurBtn, 0, 0, SRCCOPY);
}

//=============================================================================
// enables the toggle mode
// returns if it doesn't have the alternate image
//=============================================================================
void CGdipButtonPic::EnableToggle(BOOL bEnable)
{
	if (!m_bHaveAltImage) return;

	m_bIsToggle = bEnable;

	// this actually makes it start in the std state since toggle is called before paint
	if (bEnable)	m_pCurBtn = &m_dcAlt;
	else		m_pCurBtn = &m_dcStd;

}
//=============================================================================
// set the control to owner draw
//=============================================================================
void CGdipButtonPic::PreSubclassWindow()
{
	// Set control to owner draw
	ModifyStyle(0, BS_OWNERDRAW, SWP_FRAMECHANGED);

	CButton::PreSubclassWindow();
}
//=============================================================================
// overide the erase function
//=============================================================================
BOOL CGdipButtonPic::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

//=============================================================================
// Paint the button depending on the state of the mouse
//=============================================================================
void CGdipButtonPic::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);

	BOOL bIsPressed = (lpDIS->itemState & ODS_SELECTED);

	// handle toggle button
	if (m_bIsToggle && bIsPressed)
	{
		(m_nCurType == STD_TYPE) ? m_nCurType = ALT_TYPE : m_nCurType = STD_TYPE;
	}
	if (bIsPressed)
	{
		if (m_nCurType == STD_TYPE)
			m_pCurBtn = &m_dcStdP;
		else
			m_pCurBtn = &m_dcStdP;
	}
	else if (m_bIsHovering)
	{

		if (m_nCurType == STD_TYPE)
			if (!m_BtnPressed)
				m_pCurBtn = &m_dcStdH;
			else
				if (m_PressedEnable)
					m_pCurBtn = &m_dcStdH;//m_dcStdON;
				else
					m_pCurBtn = &m_dcStdH;
		else
			m_pCurBtn = &m_dcStdH;
	}
	else
	{
		if (m_nCurType == STD_TYPE)
			m_pCurBtn = &m_dcStd;
		else
			m_pCurBtn = &m_dcAlt;
	}
	if (m_BtnPressed)
		m_pCurBtn = &m_dcAlt;// &m_dcStdP;
	if (m_bIsDisabled&&m_bDisableEnable)
		m_pCurBtn = &m_dcAltH;
	// paint the button
	PaintBtn(pDC);
}

//=============================================================================
LRESULT CGdipButtonPic::OnMouseHover(WPARAM wparam, LPARAM lparam)
//=============================================================================
{
	m_bIsHovering = TRUE;
	if (this->GetSafeHwnd() != NULL) {
		g_nIndexHwndBtn = this->GetSafeHwnd();
		if (g_nMainHwnd != NULL)
			::PostMessage(g_nMainHwnd, WM_BTNFOCUS_MSG, NULL, NULL);
		Invalidate(0);
	}
	
	//	::PostMessage(m_PrtHandle,UM_LISTREFRESH,NULL,m_nModeNum);
	//HINSTANCE	hInstance = AfxGetInstanceHandle();
	//HCURSOR cc = AfxGetApp()->LoadCursor(IDC_CURSOR1);
	//::SetCursor(cc);
	return 0;
}


//=============================================================================
LRESULT CGdipButtonPic::OnMouseLeave(WPARAM wparam, LPARAM lparam)
//=============================================================================
{
	if (g_nMainHwnd != NULL)
		::PostMessage(g_nMainHwnd, WM_BTNFOCUS_MSG, NULL, NULL);

	m_bIsTracking = FALSE;
	m_bIsHovering = FALSE;
	//	::PostMessage(m_PrtHandle,UM_LISTREFRESH,NULL,100);
	if (this->GetSafeHwnd() != NULL) {
		Invalidate();
	}
	return 0;
}

//=============================================================================
void CGdipButtonPic::OnMouseMove(UINT nFlags, CPoint point)
//=============================================================================
{
#ifndef GCL_HCURSOR
#define GCL_HCURSOR         (-12)
#else
 
#endif // !UNICODE
	//SetCursor(LoadCursor(NULL, IDC_HAND));
	//MessageBox(_T(""));
	SetClassLong(this->GetSafeHwnd(),GCL_HCURSOR,(LONG)LoadCursor(NULL, IDC_HAND));

	if (!m_bIsTracking)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_bIsTracking = _TrackMouseEvent(&tme);
	}
	CButton::OnMouseMove(nFlags, point);
	HINSTANCE	hInstance = AfxGetInstanceHandle();
	//	HCURSOR cc = AfxGetApp()->LoadCursor(IDC_CURSOR1);
	//	::SetCursor(cc);
}

void CGdipButtonPic::OnLButtonDown(UINT nFlags, CPoint point)
{
	this->m_BtnPressed = TRUE;
	if (this->GetSafeHwnd() != NULL)
		::InvalidateRect(this->GetSafeHwnd(), NULL, NULL);
	CButton::OnLButtonDown(nFlags, point);
}
void CGdipButtonPic::OnLButtonUp(UINT nFlags, CPoint point)
{
	this->m_BtnPressed = FALSE;
	if (this->GetSafeHwnd() != NULL)
		::InvalidateRect(this->GetSafeHwnd(), NULL, NULL);
	CButton::OnLButtonUp(nFlags, point);
}
//=============================================================================
//	
//	Call this member function with a memory DC from the code that paints 
//	the parents background.  Passing the screen DC defeats the purpose of 
//  using this function.
//
//=============================================================================
void CGdipButtonPic::SetBkGnd(CDC* pDC)
{
	CRect rect, rectS;
	CBitmap bmp, *pOldBitmap;

	GetClientRect(rect);
	GetWindowRect(rectS);
	GetParent()->ScreenToClient(rectS);

	m_dcBk.DeleteDC();

	m_dcBk.CreateCompatibleDC(pDC);
	bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBitmap = m_dcBk.SelectObject(&bmp);
	m_dcBk.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, rectS.left, rectS.top, SRCCOPY);
	bmp.DeleteObject();
}

LRESULT CGdipButtonPic::SelectMouseHover()
{
	m_bIsHovering = TRUE;
	if (this->GetSafeHwnd() != NULL)
		Invalidate(0);
	//	::PostMessage(m_PrtHandle,UM_LISTREFRESH,NULL,m_nModeNum);
	//HINSTANCE	hInstance = AfxGetInstanceHandle();
	//HCURSOR cc = AfxGetApp()->LoadCursor(IDC_CURSOR1);
	//::SetCursor(cc);
	return 0;
}

LRESULT CGdipButtonPic::SelectMouseLeave()
{
	m_bIsTracking = FALSE;
	m_bIsHovering = FALSE;
	//	::PostMessage(m_PrtHandle,UM_LISTREFRESH,NULL,100);
	if (this->GetSafeHwnd() != NULL)
		Invalidate();
	return 0;
}

