// PDFWriter.h : Declaration of the CPDFWriter

#pragma once

#ifndef _ONLY_PDF_WRITER_INTERFACE

#include "resource.h"       // main symbols

#include "../ASCImageStudio3/ASCGraphics/Interfaces/ASCRenderer.h"
#include "../ASCImageStudio3/ASCGraphics/Objects/Structures.h"

#include "../ASCImageStudio3/ASCGraphics/Interfaces/FileDownloader.h"
#include "../Common/GdiplusEx.h"
#include "../Common/ASCUtils.h"
#include "Base64.h"

#ifdef BUILD_CONFIG_FULL_VERSION
#include "../../../../../../Common/Registration.h"
#endif

#include "Document.h"
#include "Image.h"
#include "Font.h"
#include "Streams.h"
#include "Utils.h"
#include "Errors.h"
#include "MemoryManager.h"
#include "List.h"
#include "Streams.h"
#include "Objects.h"
#include "Annotation.h"
#include "Destination.h"
#include "GraphicState.h"
#include "MetaData.h"
#include "Outline.h"
#include "PageOperations.h"
#include "Pages.h"
#include "Catalog.h"
#include "PDF.h"
#include "Encoder.h"
#include "EncryptDictionary.h"
#include "LZWEncoder.h"
#include "ImageExt.h"

#include "Common.h"

//#ifdef _DEBUG
//
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//
//#define new DEBUG_NEW
//
//#endif

#endif

#include "OnlineOfficeBinToPdf.h"

// IPDFWriter
[
	object,
	uuid("BDA96253-29C4-4C62-98DC-D9718695883C"),
	dual,	helpstring("IPDFWriter Interface"),
	pointer_default(unique)
]
__interface IPDFWriter : IDispatch
{
	//----- Основные функции для работы с документом ---------------------------------------------------

	[id(11)]HRESULT CreatePDF();
	[id(12)]HRESULT DeletePDF();
	[id(13)]HRESULT SaveToFile([in] BSTR bsPath);

	[id(21)]HRESULT SetPDFPageMode([in]long nMode);
	[id(22)]HRESULT GetPDFPageMode([out, retval]long *pnMode);
	[id(23)]HRESULT SetPDFPageLayout([in]long nLayout);
	[id(24)]HRESULT GetPDFPageLayout([out, retval]long *pnLayout);
	[id(25)]HRESULT SetPDFViewerPreference([in]long nValue );
	[id(26)]HRESULT GetPDFViewerPreference([out, retval]long *pnValue);

	[id(30)]HRESULT SetPDFCompressionMode([in]long nMode);
	[id(31)]HRESULT SetPDFOpenAction([in]long nAction);

	[id(50)]HRESULT GetLastErrorCode([out, retval]long *pnErrorCode);
	[id(51)]HRESULT GetLastErrorString([out, retval]BSTR *pbsErrorString);


	//----- Функции для работы со страницами -----------------------------------------------------------

	[id(101)]HRESULT AddNewPage();
	[id(102)]HRESULT GetPagesCount([out, retval] long *pnCount);
	[id(103)]HRESULT SetCurrentPage([in] long nIndex);
	[id(104)]HRESULT GetCurrentPageIndex([out, retval] long *pnIndex);

	[id(105)]HRESULT SetPageWidth([in]float fValue);
	[id(106)]HRESULT SetPageHeight([in]float fValue);
	[id(107)]HRESULT GetWidth([out, retval]float *pfValue);
	[id(108)]HRESULT GetHeight([out, retval]float *pfValue);
	[id(109)]HRESULT SetSize([in]long nSize, [in]long nDirection);
	[id(110)]HRESULT SetRotate([in]long nAngle);

	[id(120)]HRESULT AddLabel([in]long nPageNum, [in]long nNumStyle, [in]long nFirstPage, [in]BSTR bsPrefix );



	//----- Функции рисования и вывода текста ----------------------------------------------------------

	[id(201)]HRESULT SetLineWidth([in] float fLineWidth );
	[id(202)]HRESULT GetLineWidth([out, retval] float *pfLineWidth);

	[id(203)]HRESULT SetLineCap([in] long nLineCap);
	[id(204)]HRESULT GetLineCap([out, retval] long *pnLineCap);

	[id(205)]HRESULT SetLineJoin([in]long nLineJoin);
	[id(206)]HRESULT GetLineJoin([out, retval]long *pnLineJoin);

	[id(207)]HRESULT SetMiterLimit([in]float fMiterLimit);
	[id(208)]HRESULT GetMiterLimit([out, retval]float *pfMiterLimit);

	[id(209)]HRESULT SetDash([in,  satype("float")] SAFEARRAY** ppnDashPtn, [in] long  nNumParam,  [in] float   fPhase);
	[id(210)]HRESULT GetDash([out, satype("float")] SAFEARRAY** ppnDashPtn, [out]long *pnNumParam, [out]float *pfPhase);

	[id(211)]HRESULT SetFlat([in]         float   fFlatness);
	[id(212)]HRESULT GetFlat([out, retval]float *pfFlatness);

	[id(213)]HRESULT NewExtGraphicsState();
	[id(214)]HRESULT ExtGraphicsStateSetAlphaStroke([in]float fValue);
	[id(215)]HRESULT ExtGraphicsStateSetAlphaFill([in]float fValue);
	[id(216)]HRESULT ExtGraphicsStateSetBlendMode([in]long nBlendMode);
	[id(217)]HRESULT ExtGraphicsStateSetStrokeAdjustment([in]int nFlag);
	[id(218)]HRESULT SetExtGraphicsState();
	[id(219)]HRESULT GSave();
	[id(220)]HRESULT GRestore();

	[id(221)]HRESULT GetGStateDepth([out, retval]long *pnDepth);
	[id(222)]HRESULT GetGMode([out, retval]long *pnGMode);

	[id(223)]HRESULT Concat([in]float fA, [in]float fB, [in]float fC, [in]float fD, [in]float fX, [in]float fY);

	[id(224)]HRESULT MoveTo([in]float fX, [in]float fY);
	[id(225)]HRESULT GetCurrentPosition([out] float *pfX, [out] float *pfY);

	[id(226)]HRESULT LineTo([in]float fX, [in]float fY);
	[id(227)]HRESULT CurveTo ([in]float fX1, [in]float fY1, [in]float fX2, [in]float fY2, [in]float fX3, [in]float fY3);
	[id(228)]HRESULT CurveTo2([in]float fX2, [in]float fY2, [in]float fX3, [in]float fY3);
	[id(229)]HRESULT CurveTo3([in]float fX1, [in]float fY1, [in]float fX3, [in]float fY3);
	[id(230)]HRESULT ClosePath();
	[id(231)]HRESULT AppendRectangle([in]float fX, [in]float fY, [in]float fWidth, [in]float fHeight);

	[id(232)]HRESULT Stroke();
	[id(233)]HRESULT GetStrokingColorSpace([out, retval]long *pnColorSpace);

	[id(234)]HRESULT ClosePathStroke();

	[id(235)]HRESULT Fill();
	[id(236)]HRESULT GetFillingColorSpace([out, retval]long *pnColorSpace);
	[id(237)]HRESULT EoFill();
	[id(238)]HRESULT FillStroke();
	[id(239)]HRESULT EoFillStroke();
	[id(240)]HRESULT ClosePathFillStroke();
	[id(241)]HRESULT ClosePathEoFillStroke();
	[id(242)]HRESULT EndPath();
	[id(243)]HRESULT Clip();
	[id(244)]HRESULT EoClip();
	[id(245)]HRESULT BeginText();
	[id(246)]HRESULT EndText();

	[id(247)]HRESULT SetCharSpace([in]         float   fValue);
	[id(248)]HRESULT GetCharSpace([out, retval]float *pfValue);

	[id(249)]HRESULT SetWordSpace([in]float fValue);
	[id(250)]HRESULT GetWordSpace([out, retval]float *pfValue);

	[id(251)]HRESULT SetHorizontalScalling([in]float fValue);
	[id(252)]HRESULT GetHorizontalScalling([out, retval]float *pfValue);

	[id(253)]HRESULT SetTextLeading([in]float fValue);
	[id(254)]HRESULT GetTextLeading([out, retval]float *pfValue);

	[id(255)]HRESULT SetFontAndSizeToGState([in]float fSize);
	[id(256)]HRESULT GetCurrentFontFromGState([out]BSTR *pbsFontName, [out]BSTR *pbsEncodingName);
	[id(257)]HRESULT GetCurrentFontSizeFromGState([out, retval]float *pfSize);

	[id(258)]HRESULT SetTextRenderingMode([in]long nMode);
	[id(259)]HRESULT GetTextRenderingMode([out, retval]long *pnMode);

	[id(260)]HRESULT SetTextRise([in]float fValue);
	[id(261)]HRESULT GetTextRise([out, retval]float *pfValue);

	[id(262)]HRESULT MoveTextPos([in]float fX, [in]float fY);
	[id(263)]HRESULT MoveTextPos2([in]float fX, [in]float fY);
	[id(264)]HRESULT GetCurrentTextPosition([out] float *pfX, [out] float *pfY);

	[id(265)]HRESULT SetTextMatrix([in] float   fA, [in] float   fB, [in] float   fC, [in] float   fD, [in]  float   fX, [in] float   fY);
	[id(266)]HRESULT GetTextMatrix([out]float* pfA, [out]float* pfB, [out]float* pfC, [out]float* pfD, [out] float* pfX, [out]float* pfY);

	[id(267)]HRESULT MoveToNextLine();

	[id(268)]HRESULT ShowText([in] BSTR bsText);
	[id(269)]HRESULT ShowTextNextLine([in] BSTR bsText);
	[id(270)]HRESULT ShowTextNextLineEx([in]float fWordSpace, [in]float fCharSpace, [in]BSTR bsText);

	[id(271)]HRESULT SetGrayStroke([in]         float   fGray);
	[id(272)]HRESULT GetGrayStroke([out, retval]float *pfGray);

	[id(273)]HRESULT SetGrayFill([in]         float   fGray);
	[id(274)]HRESULT GetGrayFill([out, retval]float *pfGray);

	[id(275)]HRESULT SetRGBStroke([in ]float   fR, [in] float   fG, [in] float   fB);
	[id(276)]HRESULT GetRGBStroke([out]float *pfR, [out]float *pfG, [out]float *pfB);

	[id(277)]HRESULT SetRGBFill([in] float   fR, [in] float   fG, [in] float   fB);
	[id(278)]HRESULT GetRGBFill([out]float *pfR, [out]float *pfG, [out]float *pfB);

	[id(279)]HRESULT SetCMYKStroke([in] float   fC, [in] float   fM, [in] float   fY, [in] float   fK);
	[id(280)]HRESULT GetCMYKStroke([out]float *pfC, [out]float *pfM, [out]float *pfY, [out]float *pfK);

	[id(281)]HRESULT SetCMYKFill([in] float   fC, [in] float   fM, [in] float   fY, [in] float   fK);
	[id(282)]HRESULT GetCMYKFill([out]float *pfC, [out]float *pfM, [out]float *pfY, [out]float *pfK);

	[id(283)]HRESULT ExecuteXObject();

	[id(284)]HRESULT AppendCircle    ([in]float fX, [in]float fY, [in]float fRay);
	[id(285)]HRESULT AppendEllipse   ([in]float fX, [in]float fY, [in]float fXRad, [in]float fYRad);
	[id(286)]HRESULT AppendArc       ([in]float fX, [in]float fY, [in]float fRad,  [in]float fAngle1, [in]float fAngle2);
	[id(287)]HRESULT AppendEllipseArc([in]float fX, [in]float fY, [in]float fXRad, [in]float fYRad, [in]float fAngle1, [in]float fAngle2, [in]BOOL bClockDirection = FALSE);
	[id(288)]HRESULT TextOut([in]float fXPos, [in]float fYPos, [in] BSTR bsText);
	[id(289)]HRESULT TextRect([in]float fLeft, [in]float fTop, [in]float fRight, [in]float fBottom, [in] BSTR bsText, [in]long nAlign, [in, out]unsigned int *pnLen);
	[id(290)]HRESULT SetSlideShow(long nType, float fDispTime, float fTransTime);
	[id(291)]HRESULT GetTextWidth([in]BSTR bsText, [out, retval] float *pfResult);
	[id(292)]HRESULT MeasureText([in]BSTR bsText, [in]float fWidth, [in]BOOL bWordWrap, [in, out]float *pfRealWidth, [out, retval]long *pnLength);

	[id(293)]HRESULT SetExtGraphicsState2(BSTR bsXmlOptions);

	//----- Функции для работы с фонтами ---------------------------------------------------------------

	[id(301)]HRESULT LoadT1FFromFile([in]BSTR bsAFMFileName, [in]BSTR bsDataFileName, [out, retval]BSTR *bsFontName);
	[id(302)]HRESULT LoadTTFFromFile([in]BSTR bsFileName, [in]BOOL bEmbedding, [in] BSTR bsEncodingName, [out, retval] BSTR *bsFontName);
	[id(303)]HRESULT LoadTTCFromFile([in]BSTR bsFileName, [in]long nIndex, [in] BOOL bEmbedding, [out, retval] BSTR *bsFontName);
	[id(304)]HRESULT SetCurrentFont([in] BSTR bsFontName, [in] BSTR bsEncodingName, [in]BOOL bNameIsUnicodeArray, [in]BSTR bsToUnicodeName);
	[id(305)]HRESULT GetCurrentFont([out]BSTR *pbsFontName, [out]BSTR *pbsEncodingName);
	[id(306)]HRESULT GetFontUnicodeWidth ([in]long nCode, [out, retval]long *pnUnicode);
	[id(307)]HRESULT GetFontBBox         ([out]float *pfLeft, [out]float *pfBottom, [out]float *pfRight, [out]float *pfTop);
	[id(308)]HRESULT GetFontAscent       ([out, retval]long *pnAscent);
	[id(309)]HRESULT GetFontDescent      ([out, retval]long *pnDescent);
	[id(310)]HRESULT GetFontXHeight      ([out, retval]long *pnXHeight);
	[id(311)]HRESULT GetFontCapHeight    ([out, retval]long *pnCapHeight);

	//----- Функции для работы с кодировкой -----------------------------------------------------------

	[id(401)]HRESULT SetCurrentEncoder([in]BSTR bsEncodingName);
	[id(402)]HRESULT GetCurrentEncoder([out, retval]BSTR *pbsEncodingName);
	[id(403)]HRESULT GetEncoderUnicode([in]long nCode, [out, retval]long *pnUnicode);
	[id(404)]HRESULT GetEncoderByteType([in]BSTR bsText, [in]long nIndex, [out, retval]long *pnByteType);
	[id(405)]HRESULT GetEncoderType([out, retval]long *pnEncoderType);
	[id(406)]HRESULT GetEncoderWritingMode([out, retval]long *pnWritingMode);

	//----- Функции для работы с Annotation ------------------------------------------------------------

	[id(501)]HRESULT CreateTextAnnot      ([in]float fLeft, [in]float fBottom, [in]float fRight, [in]float fTop, [in]BSTR bsText, [in]BSTR bsEncoder);
	[id(502)]HRESULT CreateLinkAnnot      ([in]float fLeft, [in]float fBottom, [in]float fRight, [in]float fTop);
	[id(503)]HRESULT CreateUriLinkAnnot   ([in]float fLeft, [in]float fBottom, [in]float fRight, [in]float fTop, [in]BSTR bsUrl);
	[id(504)]HRESULT ArbAnnotationSetBorderStyle   ([in]long nSubtype, [in]float fWidth, [in]long nDashOn, [in]long nDashOff, [in]long nDashPhase);
	[id(505)]HRESULT LinkAnnotationSetBorderStyle  ([in]float fWidth, [in]long nDashOn, [in]long nDashOff );
	[id(506)]HRESULT LinkAnnotationSetHighlightMode([in]long nMode);
	[id(507)]HRESULT TextAnnotationSetIcon         ([in]long nIcon);
	[id(508)]HRESULT TextAnnotationSetOpened       ([in]BOOL bOpened);
	[id(509)]HRESULT SetCurrentAnnot([in]long nIndex);
	[id(510)]HRESULT GetCurrentAnnotIndex([out, retval]long *pnIndex);
	[id(511)]HRESULT MakeAnnotationFromXml([in]BSTR bsXML);

	//----- Функции для работы с Destination -----------------------------------------------------------

	[id(601)]HRESULT CreateNewDestination();
	[id(602)]HRESULT DestSetXYZ  ([in]float fLeft, [in]float fTop, [in]float fZoom);
	[id(603)]HRESULT DestSetFit  ();
	[id(604)]HRESULT DestSetFitH ([in]float fTop);
	[id(605)]HRESULT DestSetFitV ([in]float fLeft);
	[id(606)]HRESULT DestSetFitR ([in]float fLeft, [in]float fBottom, [in]float fRight, [in]float fTop);
	[id(607)]HRESULT DestSetFitB ();
	[id(608)]HRESULT DestSetFitBH([in]float fTop);
	[id(609)]HRESULT DestSetFitBV([in]float fLeft);
	[id(610)]HRESULT SetCurrentDest([in]long nIndex);
	[id(611)]HRESULT GetCurrentDestIndex([out, retval]long *pnIndex);

	//----- Функции для работы с Outline ---------------------------------------------------------------

	[id(701)]HRESULT CreateNewOutline( [in]long nParentIndex, [in]BSTR bsTitle, [in]BSTR bsEncoder);
	[id(702)]HRESULT OutlineSetCurrentDestination();
	[id(703)]HRESULT SetOutlineOpened([in]BOOL bOpened);
	[id(704)]HRESULT SetCurrentOutline([in]long nIndex);
	[id(705)]HRESULT GetCurrentOutlineIndex([out, retval]long *pnIndex);
	[id(706)]HRESULT MakeOutlineFromXml([in]BSTR bsXML);

	//----- Функции для работы с картинками -----------------------------------------------------------

	[id(801)]HRESULT LoadJpegFromFile([in]BSTR bsFileName);
	[id(802)]HRESULT LoadJpxFromFile([in]BSTR bsFileName, [in]long nFlag);
	[id(803)]HRESULT LoadImageFromFile ([in]BSTR bsFileName,                     [in]long nWidth, [in]long nHeight, [in]long nColorSpace);
	[id(804)]HRESULT LoadImageFromArray([in, satype("byte")]SAFEARRAY **ppImage, [in]long nWidth, [in]long nHeight, [in]long nColorSpace, [in]long nBitsPerComponent);
	[id(805)]HRESULT LoadImageFromInterface([in]IUnknown **pInterface, [in] BOOL bAlpha = FALSE);
	[id(806)]HRESULT DrawCurrentImage([in]float fX, [in]float fY, [in]float fWidth, [in]float fHeight);
	[id(807)]HRESULT GetImageBitsPerComponent([out, retval]long *pnBitsPerComponent);
	[id(808)]HRESULT GetImageColorSpace([out, retval]long *pnColorSpace);
	[id(809)]HRESULT GetImageHeight([out, retval]long *pnHeight);
	[id(810)]HRESULT GetImageWidth([out, retval]long *pnWidth);
	[id(811)]HRESULT SetImageColorMask([in]long nRMin, [in]long nRMax, [in]long nGMin, [in]long nGMax, [in]long nBMin, [in]long nBMax);
	[id(812)]HRESULT SetImageMaskImage([in]long nMaskImageIndex);
	[id(813)]HRESULT SetCurrentImage([in]long nIndex);
	[id(814)]HRESULT GetCurrentImageIndex([out, retval]long *pnIndex);


	//----- Функции для работы с шифрованием ----------------------------------------------------------

	[id(901)]HRESULT SetEncryptOn         ();
	[id(902)]HRESULT SetPDFPassword       ([in]BSTR bsOwnerPassword, [in]BSTR bsUserPassword);
	[id(903)]HRESULT SetPDFPermission     ([in]long nPermission);
	[id(904)]HRESULT SetPDFEncryptionMode ([in]long nMode, [in]long nKeyLen);
	[id(905)]HRESULT SetEncryptOff        ();

	//----- Функции для работы с метаданными ----------------------------------------------------------

	[id(1001)]HRESULT GetInfoItem([in]long nDataType, [out, retval]BSTR *pbsItem);
	[id(1002)]HRESULT SetInfoItem([in]long nDataType, [in]BSTR bsData);
	[id(1003)]HRESULT SetInfoDateItem([in]long nType, [in]long nYear, [in]long nMonth, [in]long nDay, [in]long nHour, [in]long nMinutes, [in]long nSeconds, [in]long nInd, [in]long nOffHour, [in]long nOffMinutes);

	//----- Для дополнительных функций ----------------------------------------------------------------

	[id(10001)]	HRESULT SetAdditionalParam([in] BSTR ParamName, [in] VARIANT	ParamValue);
	[id(10002)]	HRESULT GetAdditionalParam([in] BSTR ParamName, [out] VARIANT *	ParamValue);

};

#ifndef _ONLY_PDF_WRITER_INTERFACE

// IPDFRenderer
[
	object,
	uuid("D08C792F-6989-4a55-8F78-C962FE895BA6"),
	dual,	helpstring("IPDFRenderer Interface"),
	pointer_default(unique)
]
__interface IPDFRenderer : IASCRenderer
{

};

// IOnlineWordToPDFWriter
[
	object,
	uuid("3B5E1A55-58E8-4458-A5D2-6709F4BC3E99"),
	dual,	helpstring("IOnlineWordToPDFWriter Interface"),
	pointer_default(unique)
]
__interface IOnlineWordToPDFWriter: IDispatch
{
	[id(10101)] HRESULT OnlineWordToPdf (BSTR sPathXml, BSTR sDstFile, BSTR sHtmlPlace, LONG nReg);
};


// CPDFWriter

[
	coclass,
	default(IPDFWriter),
	threading(apartment),
	vi_progid("AVSOfficePDFWriter.PDFWriter"),
	progid("AVSOfficePDFWriter.PDFWriter.1"),
	version(1.0),
	uuid("D2F0543F-2CEC-4A57-A579-8059EBF71EE0"),
	helpstring("PDFWriter Class")
]
class ATL_NO_VTABLE CPDFWriter 
	: public IPDFWriter
	, public IPDFRenderer
	, public IOnlineWordToPDFWriter
{

private:

	// для IPDFWriter

	Doc								m_pDocument;
	FontDict						m_pCurrentFont;
	ExtGState						m_pCurrentExtGState;

	XObject							m_pCurrentXObject;
	List							m_pXObjectList;

	Annotation						m_pCurrentAnnotation;
	List							m_pAnnotList;

	Destination						m_pCurrentDestination;
	List							m_pDestList;

	Outline							m_pCurrentOutline;
	List							m_pOutlineList;

	List							m_pFontEncodingList;

	PDF::PatternStorage				m_oPatterns;			//	add patterns in commands
	PDF::PaintState					m_oPatternState;		//	current pattern

	PDF::XForm*						m_XForm;
	CString							m_MaskWithFormCommands;
	int								m_BlockCommandsStart;
	BOOL							m_IsStrokeShape;

	// для вырезки, хардкор

	CString							m_strPatternFill;
	CString							m_strPatternStroke;

	// для IPDFRenderer

	NSStructures::CPen				m_oPen;
	NSStructures::CBrush			m_oBrush;
	NSStructures::CFont				m_oFont;
	NSStructures::CShadow			m_oShadow;
	NSStructures::CEdgeText			m_oEdgeText;

	Gdiplus::GraphicsPath			m_oCurPath;

	double							m_dCharSpace;

	BOOL							m_bStartSubPath;
	BOOL							m_bGStateChange;

	BOOL							m_bClipPath;
	TMatrix							m_oClipCTM;
	TMatrix							m_oBaseTransform;
	TCommandParams					m_oCommandParams;
	TCommandType*					m_pCurCommand;

	CFindFonts*						m_pFindFonts;
	CGdiPath*						m_pCurPath;
	BOOL                            m_bUseTextureRect; // Используем ли рект для текстурной заливки (заданный в m_oBrush)
	BOOL                            m_bUseImageTransform; // Заглушка для функции DrawImage (использовать ли там трансформ)

	CFontLoader						m_oFontLoader;
	HANDLE							m_hSynchMutex;
	CString							m_wsTempDir;

#ifdef BUILD_CONFIG_OPENSOURCE_VERSION
	OfficeCore::IWinFonts*			m_pFontManager;
#else
	AVSGraphics::IASCFontManager*	m_pFontManager;
#endif

	BOOL							m_bIsWhiteBackImage;
	BOOL							m_bUseImageTextureAlpha;

	CMatrix							m_oTransform;   // Текущая матрица преобразования
	CContiniousText					m_oContiniousText;
	CRendererState					m_oRendererState;
	BOOL                            m_bFirstMoveTo;

	CGdiPlusInit					m_oGdiplusInit;

	BOOL							m_bIsFontsInitialize;

public:
	CPDFWriter()
	{
#ifdef _DEBUG
		_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
		_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_WNDW );
#endif
		m_oGdiplusInit.Init();
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
#ifdef BUILD_CONFIG_OPENSOURCE_VERSION
		CoCreateInstance( OfficeCore::CLSID_CWinFonts, NULL, CLSCTX_ALL, OfficeCore::IID_IWinFonts, (void**)&m_pFontManager );
#else
		CoCreateInstance( __uuidof( AVSGraphics::CASCFontManager ), NULL, CLSCTX_ALL, __uuidof( AVSGraphics::IASCFontManager ), (void**)&m_pFontManager );		
#endif

		m_bIsFontsInitialize = FALSE;
		
		m_pFindFonts = NULL;

		m_hSynchMutex = CreateMutex(NULL, FALSE, _T("AVSPDFWriterMutex") );

		m_pDocument         = NULL;
		m_pCurrentFont      = NULL;
		m_pCurrentExtGState = NULL;
		m_pCurrentXObject   = NULL;
		m_pXObjectList      = NULL;
		m_pOutlineList      = NULL;
		m_pDestList           = NULL;
		m_pCurrentDestination = NULL;
		m_pAnnotList          = NULL;
		m_pCurrentAnnotation  = NULL;

		m_pFontEncodingList   = NULL;

		m_bStartSubPath = FALSE;
		m_bGStateChange = FALSE;

		m_oCommandParams.dAngle  =  0;
		m_oCommandParams.dHeight = -1;
		m_oCommandParams.dLeft   = -1;
		m_oCommandParams.dTop    = -1;
		m_oCommandParams.dWidth  = -1;
		m_oCommandParams.nFlag   =  0;
		m_oCommandParams.oMatrix.fA = 1.0f;
		m_oCommandParams.oMatrix.fB = 0.0f;
		m_oCommandParams.oMatrix.fC = 0.0f;
		m_oCommandParams.oMatrix.fD = 1.0f;
		m_oCommandParams.oMatrix.fE = 0.0f;
		m_oCommandParams.oMatrix.fF = 0.0f;

		m_oShadow.Visible = FALSE;

		m_oFont.Name = CString( _T("Arial") );
		m_oFont.Size = 12.0;

		m_dCharSpace = 0.0;

		m_pCurCommand = NULL;

		m_pCurPath = NULL;

		m_bClipPath = FALSE;

		m_wsTempDir = _T("");

		m_bIsWhiteBackImage     = FALSE;
		m_bUseTextureRect       = FALSE;
		m_bUseImageTransform    = TRUE;
		m_bUseImageTextureAlpha = FALSE;

		m_XForm					=	NULL;
		m_IsStrokeShape			=	FALSE;

		return S_OK;
	}

	void FinalRelease()
	{
		FreePDF();

		RELEASEOBJECT(m_pFindFonts);
		RELEASEHANDLE(m_hSynchMutex);
		RELEASEINTERFACE(m_pFontManager);
	}

private:

	void FreePDF()
	{
		m_pCurrentFont      = NULL;
		m_pCurrentExtGState = NULL;
		m_pCurrentXObject   = NULL;

		if ( m_pOutlineList )
			ListFree2( m_pOutlineList );
		m_pOutlineList = NULL;
		m_pCurrentOutline = NULL;

		if ( m_pDestList )
			ListFree2( m_pDestList );
		m_pDestList = NULL;
		m_pCurrentDestination = NULL;

		if ( m_pAnnotList )
			ListFree2( m_pAnnotList );
		m_pAnnotList = NULL;
		m_pCurrentAnnotation = NULL;

		if ( m_pXObjectList )
			ListFree2( m_pXObjectList );
		m_pXObjectList = NULL;
		m_pCurrentXObject = NULL;

		if ( m_pFontEncodingList )
			ListFree( m_pFontEncodingList );
		m_pFontEncodingList = NULL;

		// Документ освобождаем в конце, т.к. все списки строились
		// через m_pDocument->oMMgr

		if ( m_pDocument )
			Free( m_pDocument );
		m_pDocument         = NULL;

		while( m_pCurCommand )
		{
			TCommandType *pPrev = m_pCurCommand->pPrev;
			delete m_pCurCommand;
			m_pCurCommand = pPrev;
		}

		RELEASEOBJECT(m_pCurPath);
	}

	TFontEncodingPair *FindFontEncodingPair( char* sFontName, char* sEncodingName = NULL )
	{
		if ( NULL == m_pFontEncodingList )
			return NULL;

		for ( int nIndex = 0; nIndex < m_pFontEncodingList->nCount; nIndex++ )
		{
			TFontEncodingPair *pPair = (TFontEncodingPair *)ListItemAt( m_pFontEncodingList, nIndex );
			if ( NULL == sEncodingName )
			{
				if ( 0 == UtilsStrCmp( pPair->sRealFontName, sFontName ) )
					return pPair;
			}
			else
			{
				if ( 0 == UtilsStrCmp( pPair->sRealFontName, sFontName ) && 0 == UtilsStrCmp( pPair->sEncodingName, sEncodingName ) )
					return pPair;
			}
		}
		return NULL;
	}
	unsigned long FontFromFileToPdfFont()
	{
		USES_CONVERSION;
		unsigned long nRet = OK;

		if ( _T("") != m_oFont.Path )
		{
			CString wsFontName, wsEncodingName, wsToUnicodeName;
			if ( m_oFontLoader.Find( m_oFont.Path, &wsFontName, &wsEncodingName, &wsToUnicodeName ) )
			{
				BSTR bsFontName = NULL;
				if ( wsFontName.GetLength() <= 0 )
				{
					bsFontName = ::SysAllocString( _T("Helvetica") );
					nRet = SetCurrentFont( _T("Helvetica"), NULL, FALSE, NULL );
					::SysFreeString( bsFontName );

					return nRet;
				}

				bsFontName = wsFontName.AllocSysString();
				BSTR bsEncoding = NULL, bsToUnicode = NULL;
				if ( wsEncodingName.GetLength()  > 0 ) bsEncoding  = wsEncodingName.AllocSysString();
				if ( wsToUnicodeName.GetLength() > 0 ) bsToUnicode = wsToUnicodeName.AllocSysString();

				nRet = SetCurrentFont( bsFontName, bsEncoding, FALSE, bsToUnicode );

				::SysFreeString( bsFontName );
				if ( bsEncoding  ) ::SysFreeString( bsEncoding );
				if ( bsToUnicode ) ::SysFreeString( bsToUnicode );

				return nRet;
			}

			wchar_t wsExt[MAX_PATH], wsFileName[MAX_PATH];
			_wsplitpath( m_oFont.Path.GetBuffer(), NULL, NULL, wsFileName, wsExt );
			CStringW sExt( wsExt ), sFileName( wsFileName );
			sExt.MakeLower();

			BSTR bsPath = m_oFont.Path.AllocSysString();
			BSTR bsPDFFontName = NULL;

			BOOL bEmb = TRUE, bCIDfont = FALSE;
			if ( _T(".non") == sExt )
				bEmb = FALSE;
			else if ( _T(".cid_non") == sExt )
			{
				bEmb = FALSE;
				bCIDfont = TRUE;
			}
			else if ( _T(".n022003l") == sExt )
				bsPDFFontName = CString( _T(FONT_COURIER) ).AllocSysString();
			else if ( _T(".n022004l") == sExt )
				bsPDFFontName = CString( _T(FONT_COURIER_BOLD) ).AllocSysString();
			else if ( _T(".n022024l") == sExt )
				bsPDFFontName = CString( _T(FONT_COURIER_BOLD_OBLIQUE) ).AllocSysString();
			else if ( _T(".n022023l") == sExt )
				bsPDFFontName = CString( _T(FONT_COURIER_OBLIQUE) ).AllocSysString();
			else if ( _T(".n019003l") == sExt )
				bsPDFFontName = CString( _T(FONT_HELVETICA) ).AllocSysString();
			else if ( _T(".n019004l") == sExt )
				bsPDFFontName = CString( _T(FONT_HELVETICA_BOLD) ).AllocSysString();
			else if ( _T(".n019024l") == sExt )
				bsPDFFontName = CString( _T(FONT_HELVETICA_BOLD_OBLIQUE) ).AllocSysString();
			else if ( _T(".n019023l") == sExt )
				bsPDFFontName = CString( _T(FONT_HELVETICA_OBLIQUE) ).AllocSysString();
			else if ( _T(".s050000l") == sExt )
				bsPDFFontName = CString( _T(FONT_SYMBOL) ).AllocSysString();
			else if ( _T(".n021004l") == sExt )
				bsPDFFontName = CString( _T(FONT_TIMES_BOLD) ).AllocSysString();
			else if ( _T(".n021024l") == sExt )
				bsPDFFontName = CString( _T(FONT_TIMES_BOLD_ITALIC) ).AllocSysString();
			else if ( _T(".n021023l") == sExt )
				bsPDFFontName = CString( _T(FONT_TIMES_ITALIC) ).AllocSysString();
			else if ( _T(".n021003l") == sExt )
				bsPDFFontName = CString( _T(FONT_TIMES_ROMAN) ).AllocSysString();
			else if ( _T(".d050000l") == sExt )
				bsPDFFontName = CString( _T(FONT_ZAPF_DINGBATS) ).AllocSysString();
			else if ( _T(".pfb") == sExt || _T(".pfa") == sExt || _T(".pfb_t1") == sExt || _T(".pfb_t1c") == sExt || _T(".pfb_t1cot") == sExt )
			{
				// Значит шрифт не один из 14 стандартных

				CStringW wsPFBpath(bsPath);
				// Ищем файл *.afm, с тем же именем, что и *.pfb
				wchar_t wsDrive[MAX_PATH], wsDir[MAX_PATH], wsFilename[MAX_PATH];
				_wsplitpath( wsPFBpath.GetBuffer(), wsDrive, wsDir, wsFilename, NULL );
				CStringW wsAFMpath = CStringW( wsDrive ) + CStringW( wsDir ) + CStringW( wsFilename ) + CStringW( _T(".afm") );
				BSTR bsAFMpath = wsAFMpath.AllocSysString();

				unsigned long nRes = LoadT1FFromFile( bsAFMpath, bsPath, &bsPDFFontName );

				::SysFreeString( bsAFMpath );
				::SysFreeString( bsPath );
				if ( OK != nRes )
				{
					ResetError( m_pDocument );
					SetCurrentFont( _T(FONT_HELVETICA), _T("CP1251"), FALSE, NULL );
					return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
				}
			}
			else if ( _T(".ttf") == sExt || _T(".otf") == sExt )
			{
				unsigned long nRes = LoadTTFFromFile( bsPath, TRUE, NULL, &bsPDFFontName );
				::SysFreeString( bsPath );

				if ( OK != nRes )
				{
					ResetError( m_pDocument );
					SetCurrentFont( _T(FONT_HELVETICA), _T("CP1251"), FALSE, NULL );
					return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
				}
			}
			else if ( _T(".cid_0") == sExt || _T(".cid_0c") == sExt || _T(".cid_0cot") == sExt || _T(".cid_2") == sExt || _T(".cid_2ot") == sExt )
			{
				bCIDfont = TRUE;
			}
			else
			{
				::SysFreeString( bsPath );
				ResetError( m_pDocument );
				SetCurrentFont( _T(FONT_HELVETICA), _T("CP1251"), FALSE, NULL );
				return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
			}

			// Шрифт загружен, нужно установить кодировку, которая должна лежать рядом с файлом, с таким же названием и расширением ".enc"

			wchar_t wsDrive[MAX_PATH], wsDir[MAX_PATH], wsFilename[MAX_PATH];
			_wsplitpath( m_oFont.Path.GetBuffer(), wsDrive, wsDir, wsFilename, NULL );
			CString wsEncodingPath = CString(wsDrive) + CString(wsDir) + CString(wsFileName) + CString(_T(".enc"));

			if ( !FileExist( wsEncodingPath ) )
				return SetCurrentFont( bsPDFFontName, NULL, FALSE, NULL );

			XmlUtils::CXmlNode oMainNode;
			oMainNode.FromXmlFile( wsEncodingPath );
			if ( _T("PDF-resources") == oMainNode.GetName() )
			{
				if ( !bCIDfont )
				{
					CString wsEncodingName, wsToUnicodeName;

					XmlUtils::CXmlNode oNode;

					if ( oMainNode.GetNode( _T("FontBase"), oNode ) )
					{
						CString sValue = oNode.GetAttribute( _T("value"), _T("Helvetica") );
						if ( !bEmb )
						{
							bsPDFFontName = ::SysAllocString( sValue.GetBuffer() );
						}
						else if ( _T("") == CString( bsPDFFontName ) )
						{
							::SysFreeString( bsPDFFontName );
							bsPDFFontName = ::SysAllocString( sValue.GetBuffer() );
						}
					}

					if ( oMainNode.GetNode( _T("Encoding"), oNode ) )
					{
						CString sValue;
						sValue = oNode.GetAttribute( _T("type"), _T("-1") );
						int nEncodingType = XmlUtils::GetInteger( sValue );
						sValue = oNode.GetAttribute( _T("base"), _T("-1") );
						int nBaseEncoding = XmlUtils::GetInteger( sValue );

						if ( -1 != nEncodingType )
						{
							char *sBaseName;
							switch ( nBaseEncoding )
							{
							case 0:  sBaseName = ENCODING_MAC_ROMAN;     break;
							case 1:  sBaseName = ENCODING_MAC_EXPERT;    break;
							case 2:  sBaseName = ENCODING_WIN_ANSI;      break;
							default: sBaseName = ENCODING_FONT_SPECIFIC; break;
							}

							Encoder pEncoding = BasicEncoderNew( m_pDocument->oMMgr, sBaseName );
							strcpy( pEncoding->sName, W2A( wsFileName ) );

							if ( 1 == nEncodingType )
							{
								BasicEncoderAttr pAttr = (BasicEncoderAttr)pEncoding->pAttr;
								pAttr->bHasDifferences = TRUE;

								XmlUtils::CXmlNode oDiff;
								if( oNode.GetNode( _T("Differences"), oDiff ) )
								{
									int nCount = XmlUtils::GetInteger( oDiff.GetAttribute( _T("count"), _T("0") ) );
									XmlUtils::CXmlNodes oDiffNodes;
									oDiff.GetNodes( _T("*"), oDiffNodes );

									int nCode = 0;
									for ( int nIndex = 0; nIndex < nCount; nIndex++ )
									{
										XmlUtils::CXmlNode oCurNode;
										oDiffNodes.GetAt( nIndex, oCurNode );
										if ( _T("Code") == oCurNode.GetName() )
										{
											nCode = XmlUtils::GetInteger( oCurNode.GetAttribute( _T("value"), _T("0") ) );
										}
										else if ( _T("Name") == oCurNode.GetName() )
										{
											if ( nCode < BASIC_ENCODER_MAX_CHAR_INDEX )
											{
												pAttr->anDifferences[nCode] = 1;
												char * sName = W2A( oCurNode.GetAttribute( _T("value"), _T(".notdef") ) );
												pAttr->anUnicodeMap[nCode]  = GlyphNameToUnicode( sName ); 
												strcpy( (char *)pAttr->asGlyphNameMap[nCode], sName );
												nCode++;
											}
										}
									}
								}
							}

							unsigned long nRes = DocRegisterEncoder( m_pDocument, pEncoding );
							if ( AVS_OFFICEPDFWRITER_ERROR_DUPLICATE_REGISTRATION == nRes )
								ResetError( m_pDocument );
							else if ( OK != nRes )
								return nRes;

							wsEncodingName = CString( wsFileName ).AllocSysString();
						}
					}

					if ( oMainNode.GetNode( _T("ToUnicode"), oNode ) ) 
					{
						USES_CONVERSION;
						CStringA sValue = W2A( oNode.GetText() );

						CBase64 oBase64;
						oBase64.Decode( (BYTE *)sValue.GetBuffer(), (unsigned int)sValue.GetLength() );
						PToUnicode pToUnicode = GetToUnicode( m_pDocument, (BYTE *)oBase64.GetBuffer(), oBase64.GetSize() );

						wsToUnicodeName = CStringW( pToUnicode->sName );
					}

					if ( NULL != bsPDFFontName )
						m_oFontLoader.Add( m_oFont.Path, CStringW( bsPDFFontName ), wsEncodingName, wsToUnicodeName );
					else
						m_oFontLoader.Add( m_oFont.Path, _T(""), wsEncodingName, wsToUnicodeName );

					BSTR bsToUnicodeName = NULL, bsEncodingName = NULL;
					if ( wsToUnicodeName.GetLength() > 0 ) bsToUnicodeName = wsToUnicodeName.AllocSysString();
					if ( wsEncodingName.GetLength()  > 0 ) bsEncodingName  = wsEncodingName.AllocSysString();

					nRet = SetCurrentFont( bsPDFFontName, bsEncodingName, FALSE, bsToUnicodeName );

					if ( bsToUnicodeName ) ::SysFreeString( bsToUnicodeName );
					if ( bsEncodingName  ) ::SysFreeString( bsEncodingName  );

					if ( OK != nRet )
						return nRet;

					if ( oMainNode.GetNode( _T("FontDescriptor"), oNode ) )
					{
						FontAttr pFontAttr = (FontAttr)m_pCurrentFont->pAttr;

						XmlUtils::CXmlNode oCurNode;
						if ( oNode.GetNode( _T("Ascent"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nAscent = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("Descent"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nDescent = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("Flags"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nFlags = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("FontBBox"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value0") );
							short nValue0 = XmlUtils::GetInteger( sValue );
							sValue = oCurNode.GetAttribute( _T("value1") );
							short nValue1 = XmlUtils::GetInteger( sValue );
							sValue = oCurNode.GetAttribute( _T("value2") );
							short nValue2 = XmlUtils::GetInteger( sValue );
							sValue = oCurNode.GetAttribute( _T("value3") );
							short nValue3 = XmlUtils::GetInteger( sValue );
							pFontAttr->pFontDef->oFontBox = ToBox( nValue0, nValue1, nValue2, nValue3 );
						}
						if ( oNode.GetNode( _T("ItalicAngle"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nItalicAngle = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("StemV"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nStemV = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("AvgWidth"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nAvgWidth = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("MaxWidth"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nMaxWidth = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("MissingWidth"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nMissingWidth = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("StemH"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nStemH = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("XHeight"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nXHeight = XmlUtils::GetInteger( sValue );
						}
						if ( oNode.GetNode( _T("CapHeight"), oCurNode ) )
						{
							CString sValue = oCurNode.GetAttribute( _T("value") );
							pFontAttr->pFontDef->nCapHeight = XmlUtils::GetInteger( sValue );
						}
					}
					if ( oMainNode.GetNode( _T("Widths"), oNode ) )
					{
						FontAttr pFontAttr = (FontAttr)m_pCurrentFont->pAttr;

						pFontAttr->oExternWidths.bUse = true;

						CString sValue;
						sValue = oNode.GetAttribute( _T("FirstChar"), _T("0") );
						pFontAttr->oExternWidths.nFirstChar = XmlUtils::GetInteger( sValue );

						sValue = oNode.GetAttribute( _T("LastChar"), _T("0") );
						pFontAttr->oExternWidths.nLastChar = XmlUtils::GetInteger( sValue );

						XmlUtils::CXmlNodes oWidthNodes;
						oNode.GetNodes( _T("Width"), oWidthNodes );
						pFontAttr->oExternWidths.anWidths = (short *)GetMem( m_pDocument->oMMgr, sizeof(short) * oWidthNodes.GetCount()  );
						for ( int nIndex = 0; nIndex < oWidthNodes.GetCount(); nIndex++ )
						{
							XmlUtils::CXmlNode oWidthNode;
							oWidthNodes.GetAt( nIndex, oWidthNode );
							sValue = oWidthNode.GetAttribute( _T("value") );
							pFontAttr->oExternWidths.anWidths[nIndex] = XmlUtils::GetInteger( sValue );
						}
					}

					return nRet;
				}
				else //if ( bCIDfont )
				{
					CString wsEncodingName, wsToUnicodeName;
					XmlUtils::CXmlNode oType0Node;

					if ( oMainNode.GetNode( _T("Type0"), oType0Node ) )
					{
						CString sValue = oType0Node.GetAttribute( _T("value") );
						bsPDFFontName = ::SysAllocString( sValue.GetBuffer() );

						XmlUtils::CXmlNode oNode;

						if ( oType0Node.GetNode( _T("ToUnicode"), oNode ) ) 
						{
							USES_CONVERSION;
							CStringA sValue = W2A( oNode.GetText() );

							CBase64 oBase64;
							oBase64.Decode( (BYTE *)sValue.GetBuffer(), (unsigned int)sValue.GetLength() );
							PToUnicode pToUnicode = GetToUnicode( m_pDocument, (BYTE *)oBase64.GetBuffer(), oBase64.GetSize() );

							wsToUnicodeName = CStringW( pToUnicode->sName );
						}

						if ( oType0Node.GetNode( _T("Encoding"), oNode ) )
						{
							int nType = 0;
							wsEncodingName = oNode.GetAttribute( _T("name") );
							Stream pStream = NULL, pUseCMapStream = NULL;

							CStringW wsCMapName, wsRegistry, wsOrdering, wsUseCMap;
							int nSupplement = 0, nWMode = 0;

							if ( _T("") == wsEncodingName )
							{
								nType = 1;

								XmlUtils::CXmlNode oEncNode;

								if ( oNode.GetNode( _T("CMapName"), oEncNode ) )
								{
									wsCMapName = oEncNode.GetAttribute( _T("name") );
									wsEncodingName = wsCMapName;
								}
								if ( oNode.GetNode( _T("CIDSystemInfo"), oEncNode ) )
								{
									XmlUtils::CXmlNode oInfo;
									if ( oEncNode.GetNode( _T("Registry"), oInfo ) )
									{
										wsRegistry = oInfo.GetAttribute( _T("string") );
									}
									if ( oEncNode.GetNode( _T("Ordering"), oInfo ) )
									{
										wsOrdering = oInfo.GetAttribute( _T("string") );
									}
									if ( oEncNode.GetNode( _T("Supplement"), oInfo ) )
									{
										sValue = oInfo.GetAttribute( _T("integer") );
										nSupplement = XmlUtils::GetInteger( sValue );
									}
								}
								if ( oNode.GetNode( _T("WMode"), oEncNode ) )
								{
									sValue = oEncNode.GetAttribute( _T("integer") );
									nWMode = XmlUtils::GetInteger( sValue );
								}
								if ( oNode.GetNode( _T("UseCMap"), oEncNode ) )
								{
									wsUseCMap = oEncNode.GetAttribute( _T("name") );
									USES_CONVERSION;
									CStringA sText = W2A( oEncNode.GetText() );
									if ( sText.GetLength() > 0 )
									{
										CBase64 oBase64;
										oBase64.Decode( (BYTE *)sText.GetBuffer(), (unsigned int)sText.GetLength() );
										pUseCMapStream = TempFileStreamNew( m_pDocument->oMMgr );
										if ( pUseCMapStream )
										{
											StreamSeek( pUseCMapStream, 0, SeekSet );
											StreamWrite( pUseCMapStream, (BYTE *)oBase64.GetBuffer(), oBase64.GetSize(), true );
										}
									}
								}
								if ( oNode.GetNode( _T("Stream"), oEncNode ) )
								{
									USES_CONVERSION;
									CStringA sText = W2A( oEncNode.GetText() );
									if ( sText.GetLength() > 0 )
									{
										CBase64 oBase64;
										oBase64.Decode( (BYTE *)sText.GetBuffer(), (unsigned int)sText.GetLength() );
										pStream = TempFileStreamNew( m_pDocument->oMMgr );
										if ( pStream )
										{
											StreamSeek( pStream, 0, SeekSet );
											StreamWrite( pStream, (BYTE *)oBase64.GetBuffer(), oBase64.GetSize(), true );
										}
									}
								}
							}

							Encoder pEncoder = CMapEncoderStreamNew( m_pDocument->oMMgr, nType, W2A(wsEncodingName), pStream );
							if ( !pEncoder )
								return AVS_OFFICEPDFWRITER_ERROR_FAILD_TO_ALLOC_MEM;

							//// Ищем Cmap файл и парсим его

							//CString wsCMapPath = CString(wsDrive) + CString(wsDir) + CString(wsFileName) + CString(_T(".cmap"));

							//if ( FileExist( wsCMapPath ) )
							//	CMapEncoderStreamLoadVector( pEncoder, wsCMapPath );

							CMapEncoderStreamSetAttrs( pEncoder, W2A( wsCMapName ), W2A( wsRegistry ), W2A( wsOrdering), nSupplement, (WritingMode)nWMode, W2A( wsUseCMap ), pUseCMapStream );
							nRet = DocRegisterEncoder( m_pDocument, pEncoder );
							if ( nRet == AVS_OFFICEPDFWRITER_ERROR_DUPLICATE_REGISTRATION )
								ResetError( m_pDocument);
						}

						if ( oType0Node.GetNode( _T("DescendantFonts"), oNode ) )
						{
							XmlUtils::CXmlNode oDescNode;
							int nCIDtype = 0; // 0 - Type 0, 2 - Type 2
							CStringW wsBaseFont;

							if ( oNode.GetNode( _T("Subtype"), oDescNode ) )
							{
								sValue = oDescNode.GetAttribute( _T("name") );
								if      ( _T("CIDFontType0") == sValue ) nCIDtype = 0;
								else if ( _T("CIDFontType2") == sValue ) nCIDtype = 2;
							}
							if ( oNode.GetNode( _T("BaseFont"), oDescNode ) )
							{
								wsBaseFont = oDescNode.GetAttribute( _T("name") );
							}

							// Создаем FontDef с данным именем
							FontDef pFontDef = CIDFontDefNew( m_pDocument->oMMgr, W2A( bsPDFFontName/*wsBaseFont*/ ), NULL );

							// Добовляем в него CIDSystemInfo
							if ( oNode.GetNode( _T("CIDSystemInfo"), oDescNode ) )
							{
								XmlUtils::CXmlNode oInfo;
								CStringW wsRegistry, wsOrdering;
								int nSupplement = 0;

								if ( oDescNode.GetNode( _T("Registry"), oInfo ) )
								{
									wsRegistry = oInfo.GetAttribute( _T("string") );
								}
								if ( oDescNode.GetNode( _T("Ordering"), oInfo ) )
								{
									wsOrdering = oInfo.GetAttribute( _T("string") );
								}
								if ( oDescNode.GetNode( _T("Supplement"), oInfo ) )
								{
									sValue = oInfo.GetAttribute( _T("integer") );
									nSupplement = XmlUtils::GetInteger( sValue );
								}

								CIDFontDefSetInfoSys( pFontDef, W2A( wsRegistry.GetBuffer() ), W2A( wsOrdering.GetBuffer() ), nSupplement );
							}

							// Записываем всевозможные настройки FontDescriptor
							if ( oNode.GetNode( _T("FontDescriptor"), oDescNode ) )
							{
								XmlUtils::CXmlNode oFDNode;

								if ( oDescNode.GetNode( _T("FontName"), oFDNode ) )
								{
									CString wsFontName = oFDNode.GetAttribute( _T("name") );
								}
								if ( oDescNode.GetNode( _T("FontStretch"), oFDNode ) )
								{
									CString wsStretch = oFDNode.GetAttribute( _T("name") );
								}
								if ( oDescNode.GetNode( _T("FontWeight"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									int nWeight = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("Flags"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("integer") );
									pFontDef->nFlags = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("FontBBox"), oFDNode ) )
								{
									short shValue[4];
									sValue = oFDNode.GetAttribute( _T("value0") );
									shValue[0] = XmlUtils::GetInteger( sValue );
									sValue = oFDNode.GetAttribute( _T("value1") );
									shValue[1] = XmlUtils::GetInteger( sValue );
									sValue = oFDNode.GetAttribute( _T("value2") );
									shValue[2] = XmlUtils::GetInteger( sValue );
									sValue = oFDNode.GetAttribute( _T("value3") );
									shValue[3] = XmlUtils::GetInteger( sValue );

									pFontDef->oFontBox = ToBox( shValue[0], shValue[1], shValue[2], shValue[3] );
								}
								if ( oDescNode.GetNode( _T("ItalicAngle"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nItalicAngle = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("Ascent"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nAscent = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("Descent"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nDescent = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("Leading"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									int nLeading = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("CapHeight"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nCapHeight = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("XHeight"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nXHeight = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("StemV"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nStemV = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("StemH"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nStemH = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("AvgWidth"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nAvgWidth = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("MaxWidth"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nMaxWidth = XmlUtils::GetInteger( sValue );
								}
								if ( oDescNode.GetNode( _T("MissingWidth"), oFDNode ) )
								{
									sValue = oFDNode.GetAttribute( _T("number") );
									pFontDef->nMissingWidth = XmlUtils::GetInteger( sValue );
								}
							}

							// Записываем файл с шрифтом и устанавливаем его тип

							CIDFontFileType eType;

							if      ( _T(".cid_0"   ) == sExt ) eType = cidType0;
							else if ( _T(".cid_0c"  ) == sExt ) eType = cidType0C;
							else if ( _T(".cid_0cot") == sExt ) eType = cidType0COT;
							else if ( _T(".cid_2"   ) == sExt ) eType = cidType2;
							else if ( _T(".cid_2ot" ) == sExt ) eType = cidType2OT;
							else
							{
								if ( 0 == nCIDtype )
									eType = cidType0;
								else
									eType = cidType2;
							}

							if ( bEmb )
							{
								if ( OK != ( nRet = CIDFontDefLoadFontData( pFontDef, m_oFont.Path.GetBuffer(), eType ) ) )
									return nRet;
							}
							else
							{
								if ( OK != ( nRet = CIDFontDefLoadFontData( pFontDef, NULL, eType ) ) )
									return nRet;
							}

							// Пишим ширины 
							if ( oNode.GetNode( _T("DW"), oDescNode ) )
							{
								sValue = oDescNode.GetAttribute( _T("integer") );
								int nDW = XmlUtils::GetInteger( sValue );
								CIDFontDefSetDW( pFontDef, nDW );
							}
							if ( oNode.GetNode( _T("W"), oDescNode ) )
							{
								int nPrevType = -1; // -1 - ничего, 0 - cid, 1 - cid_last, 2 - array, 3 - width
								int nCid_first = 0, nCid_last = 0, nWidth = 0;
								CIDWidth oWidth;

								XmlUtils::CXmlNodes oNodesW;
								// Забираем все ноды
								oDescNode.GetNodes( _T("*"), oNodesW );
								for ( int nIndex = 0; nIndex < oNodesW.GetCount(); nIndex++ )
								{
									XmlUtils::CXmlNode oNodeW;
									if ( oNodesW.GetAt( nIndex, oNodeW ) )
									{
										if ( _T("Int") == oNodeW.GetName() )
										{
											sValue = oNodeW.GetAttribute( _T("value") );
											if ( -1 == nPrevType || 2 == nPrevType || 3 == nPrevType )
											{
												nPrevType = 0;
												nCid_first = XmlUtils::GetInteger( sValue );
											}
											else if ( 0 == nPrevType )
											{
												nPrevType = 1;
												nCid_last = XmlUtils::GetInteger( sValue );
											}
											else // if ( 1 == nPrevType )
											{
												nPrevType = 3;
												nWidth = XmlUtils::GetInteger( sValue );

												oWidth.unCid_First = nCid_first;
												oWidth.unCid_Last  = nCid_last;
												oWidth.shWidth     = nWidth;

												CIDFontDefAddWidth( pFontDef, oWidth );
											}
										}
										else if ( _T("Array") == oNodeW.GetName() )
										{
											nPrevType = 2;

											XmlUtils::CXmlNodes oArrayNodes;
											oNodeW.GetNodes( _T("Int"), oArrayNodes );
											for ( int nArrayIndex = 0; nArrayIndex < oArrayNodes.GetCount(); nArrayIndex++ )
											{
												XmlUtils::CXmlNode oArrayItem;
												if ( oArrayNodes.GetAt( nArrayIndex, oArrayItem ) )
												{
													sValue = oArrayItem.GetAttribute( _T("value") );
													nWidth = XmlUtils::GetInteger( sValue );

													oWidth.unCid_First = nCid_first;
													oWidth.unCid_Last  = nCid_first;
													oWidth.shWidth     = nWidth;

													nCid_first++;

													CIDFontDefAddWidth( pFontDef, oWidth );
												}
											}
										}
									}
								}
							}
							if ( oNode.GetNode( _T("DW2"), oDescNode ) )
							{
								int anDW2[2];
								sValue = oDescNode.GetAttribute( _T("value0") );
								anDW2[0] = XmlUtils::GetInteger( sValue );
								sValue = oDescNode.GetAttribute( _T("value1") );
								anDW2[1] = XmlUtils::GetInteger( sValue );
								CIDFontDefSetDW2( pFontDef, anDW2 );
							}
							if ( oNode.GetNode( _T("W2"), oDescNode ) )
							{
								int nPrevType = -1; // -1 - ничего, 0 - cid, 1 - cid_last, 2 - array, 3 - W, 4 - Vx, 5 - Vy
								int nCid_first = 0, nCid_last = 0, nWidth = 0, nVx = 0, nVy = 0;
								CIDWidth2 oWidth2;

								XmlUtils::CXmlNodes oNodesW;
								// Забираем все ноды
								oDescNode.GetNodes( _T("*"), oNodesW );
								for ( int nIndex = 0; nIndex < oNodesW.GetCount(); nIndex++ )
								{
									XmlUtils::CXmlNode oNodeW;
									if ( oNodesW.GetAt( nIndex, oNodeW ) )
									{
										if ( _T("Int") == oNodeW.GetName() )
										{
											sValue = oNodeW.GetAttribute( _T("value") );
											if ( -1 == nPrevType || 2 == nPrevType || 5 == nPrevType )
											{
												nPrevType = 0;
												nCid_first = XmlUtils::GetInteger( sValue );
											}
											else if ( 0 == nPrevType )
											{
												nPrevType = 1;
												nCid_last = XmlUtils::GetInteger( sValue );
											}
											else if ( 1 == nPrevType )
											{
												nPrevType = 3;
												nWidth = XmlUtils::GetInteger( sValue );
											}
											else if ( 3 == nPrevType )
											{
												nPrevType = 4;
												nVx = XmlUtils::GetInteger( sValue );
											}
											else // if ( 4 == nPrevType )
											{
												nPrevType = 5;
												nVy = XmlUtils::GetInteger( sValue );

												oWidth2.unCid_First = nCid_first;
												oWidth2.unCid_Last  = nCid_last;
												oWidth2.shW         = nWidth;
												oWidth2.shVx        = nVx;
												oWidth2.shVy        = nVy;

												CIDFontDefAddWidth2( pFontDef, oWidth2 );
											}
										}
										else if ( _T("Array") == oNodeW.GetName() )
										{
											nPrevType = 2;

											int nWidthPrevType = -1; // -1 - ничего, 0 - W, 1 - Vx, 2 - Vy

											XmlUtils::CXmlNodes oArrayNodes;
											oNodeW.GetNodes( _T("Int"), oArrayNodes );
											for ( int nArrayIndex = 0; nArrayIndex < oArrayNodes.GetCount(); nArrayIndex++ )
											{
												XmlUtils::CXmlNode oArrayItem;
												if ( oArrayNodes.GetAt( nArrayIndex, oArrayItem ) )
												{
													sValue = oArrayItem.GetAttribute( _T("value") );

													if ( -1 == nWidthPrevType || 2 == nWidthPrevType )
													{
														nWidthPrevType = 0;
														nWidth = XmlUtils::GetInteger( sValue );
													}
													else if ( 0 == nWidthPrevType )
													{
														nWidthPrevType = 1;
														nVx = XmlUtils::GetInteger( sValue );
													}
													else // if ( 1 == nWidthPrevType )
													{
														nWidthPrevType = 2;
														nVy = XmlUtils::GetInteger( sValue );

														oWidth2.unCid_First = nCid_first;
														oWidth2.unCid_Last  = nCid_first;
														oWidth2.shW         = nWidth;
														oWidth2.shVx        = nVx;
														oWidth2.shVy        = nVy;

														nCid_first++;

														CIDFontDefAddWidth2( pFontDef, oWidth2 );
													}
												}
											}
										}
									}
								}
							}
							if ( oNode.GetNode( _T("CIDToGIDMap"), oDescNode ) )
							{
								sValue = oDescNode.GetAttribute( _T("name"), _T("") );
								if ( _T("") != sValue )
								{
									CIDFontDefSetCIDtoGID( pFontDef, W2A( sValue.GetBuffer() ) );
								}
								else
								{
									USES_CONVERSION;
									CStringA sText = W2A( oDescNode.GetText() );
									if ( sText.GetLength() > 0 )
									{
										CBase64 oBase64;
										oBase64.Decode( (BYTE *)sText.GetBuffer(), (unsigned int)sText.GetLength() );
										CIDFontDefSetCIDtoGID( pFontDef, (BYTE *)oBase64.GetBuffer(), oBase64.GetSize() );
									}
								}
							}

							Encoder pEncoder = GetEncoder( m_pDocument, W2A( wsEncodingName ) );
							PToUnicode pToUnicode = GetToUnicode( m_pDocument, W2A( wsToUnicodeName ) );
							FontDict pFont = Type0FontNew2( m_pDocument->oMMgr, pFontDef, pEncoder, m_pDocument->pXref, pToUnicode);

							// Регистрируем FontDef и Font в документе
							if ( pFontDef )
								ListAdd( m_pDocument->pFontDefList, pFontDef );

							if ( pFont )
								ListAdd( m_pDocument->pFontManager, pFont );	

							if ( NULL != bsPDFFontName )
								m_oFontLoader.Add( m_oFont.Path, CStringW( bsPDFFontName ), wsEncodingName, wsToUnicodeName );
							else
								m_oFontLoader.Add( m_oFont.Path, _T(""), wsEncodingName, wsToUnicodeName );

							BSTR bsToUnicodeName = NULL, bsEncodingName = NULL;
							if ( wsToUnicodeName.GetLength() > 0 ) bsToUnicodeName = wsToUnicodeName.AllocSysString();
							if ( wsEncodingName.GetLength()  > 0 ) bsEncodingName  = wsEncodingName.AllocSysString();

							nRet = SetCurrentFont( bsPDFFontName, bsEncodingName, FALSE, bsToUnicodeName );

							if ( bsToUnicodeName ) ::SysFreeString( bsToUnicodeName );
							if ( bsEncodingName  ) ::SysFreeString( bsEncodingName  );

							return nRet;
						}
					}
				}
			}

			if ( NULL != bsPDFFontName )
				nRet = SetCurrentFont( bsPDFFontName, NULL, FALSE, NULL );

			return nRet;
		}

		return OK;
	}
	unsigned long GdiFontToPdfFont(BSTR bsEncodingName = L"CP1251", BOOL bNameIsUnicodeArray = FALSE)
	{
		BSTR bsDefaultFont     = L"Helvetica";
		BSTR bsDefaultEncoding = L"CP1251"; 
		USES_CONVERSION;

		BOOL bBold   = m_oFont.Bold;
		BOOL bItalic = m_oFont.Italic;

		wchar_t wsDisplayName[1000];
		wchar_t wsFontName[1000];

		// получаем фонт по его названию
		BSTR bsFileName;
		if ( !m_pFindFonts->Find( m_oFont.Name, &bsFileName, &bBold, &bItalic ) )
		{
			BOOL bOldBold   = bBold;
			BOOL bOldItalic = bItalic;

			if ( !GetFontFile( &m_oFont, (LPCTSTR)m_oFont.Name.GetBuffer(), (LPTSTR)wsDisplayName, 1000, (LPTSTR)wsFontName, 1000, &bBold, &bItalic ) )
			{
				m_pFindFonts->Add( m_oFont.Name, CString(_T("")), bOldBold, bOldItalic, bBold, bItalic );

				SetCurrentFont( bsDefaultFont, bsDefaultEncoding, bNameIsUnicodeArray, NULL );
				return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
			}

			m_pFindFonts->Add( m_oFont.Name, CString(wsFontName), bOldBold, bOldItalic, bBold, bItalic );

		}
		else
		{
			CString sFName = CString( bsFileName );
			if ( sFName.GetLength() <= 0 || sFName.GetLength() >= 1000 )
			{
				SetCurrentFont( bsDefaultFont, bsDefaultEncoding, bNameIsUnicodeArray, NULL );
				return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
			}
			else
			{
				_tcscpy( wsFontName, sFName.GetBuffer() );
			}
		}
		char *sDisplayName = W2A( wsDisplayName );
		char *sFontFile    = W2A( wsFontName );

		m_oFont.Bold   = bBold;
		m_oFont.Italic = bItalic;

		// пока фонт не включаем в документ 
		// TO DO: 1. Сначала пытаемся включить фонт в документ
		//        2. Если этого сделать нельзя, тогда загружаем фонт не включая его в документ.
		BSTR bsPDFFontName = ::SysAllocString( _T("Embedded") );
		BSTR bsFontFile = A2W( sFontFile );

		unsigned long nRes = LoadTTFFromFile( bsFontFile, TRUE, bsEncodingName, &bsPDFFontName );
		if ( OK == nRes )
		{
			nRes = SetCurrentFont( bsPDFFontName, bsEncodingName, bNameIsUnicodeArray, NULL );
			::SysFreeString( bsPDFFontName );
			return nRes;
		}
		else if ( AVS_OFFICEPDFWRITER_ERROR_FILE_OPEN_ERROR == nRes )
			ResetError( m_pDocument );
		else
		{
			ResetError( m_pDocument );
			SetCurrentFont( bsDefaultFont, bsDefaultEncoding, bNameIsUnicodeArray, NULL );
			::SysFreeString( bsPDFFontName );
			return nRes;
		}

		// Скорее всего фонт не загрузился из-за того, что sFontFile содержит не полный путь
		char *pValue;
		size_t len;
		errno_t err = _dupenv_s( &pValue, &len, "windir" );
		CString sFontFilePath(pValue);
		free( pValue );
		sFontFilePath += "\\Fonts\\";
		sFontFilePath += sFontFile;
		bsFontFile = sFontFilePath.AllocSysString();

		nRes = LoadTTFFromFile( bsFontFile, TRUE, bsEncodingName, &bsPDFFontName );
		if ( OK == nRes )
		{
			nRes = SetCurrentFont( bsPDFFontName, bsEncodingName, bNameIsUnicodeArray, NULL );
			::SysFreeString( bsPDFFontName );
			::SysFreeString( bsFontFile );
			return nRes;
		}
		else 
		{
			ResetError( m_pDocument );
			SetCurrentFont( bsDefaultFont, bsDefaultEncoding, bNameIsUnicodeArray, NULL );
			::SysFreeString( bsFontFile );
			return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
		}
	}
	unsigned long GdiFontToPdfFont2(BSTR bsToUnicodeName = NULL, BSTR bsEncodingName = NULL)
	{
		BSTR bsDefaultFont     = L"Helvetica";
		USES_CONVERSION;

		BOOL bBold   = m_oFont.Bold;
		BOOL bItalic = m_oFont.Italic;

		wchar_t wsDisplayName[1000];
		wchar_t wsFontName[1000];

		// получаем фонт по его названию
		BSTR bsFileName;

		BOOL bPath = ( m_oFont.Path != _T("") ? TRUE : FALSE );
		if ( bPath )
			m_oFont.Name = m_oFont.Path;

		if ( !m_pFindFonts->Find( m_oFont.Name, &bsFileName, &bBold, &bItalic ) )
		{
			BOOL bOldBold   = bBold;
			BOOL bOldItalic = bItalic;

			if ( !bPath )
			{
				if ( !GetFontFile2( &m_oFont, (LPCTSTR)m_oFont.Name.GetBuffer(), (LPTSTR)wsDisplayName, 1000, (LPTSTR)wsFontName, 1000, &bBold, &bItalic, m_pFontManager ) )
				{
					m_pFindFonts->Add( m_oFont.Name, CString(_T("")), bOldBold, bOldItalic, bBold, bItalic );

					SetCurrentFont( bsDefaultFont, NULL, FALSE, NULL );
					return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
				}
			}
			else
			{
				int nTempLen = min( 499, m_oFont.Path.GetLength() );
				::memcpy( wsFontName, m_oFont.Path.GetBuffer(), sizeof(wchar_t) * nTempLen );
				wsFontName[nTempLen + 0] = 0;
				wsFontName[nTempLen + 1] = 0;

				::memcpy( wsDisplayName, m_oFont.Path.GetBuffer(), sizeof(wchar_t) * nTempLen );
				wsDisplayName[nTempLen + 0] = 0;
				wsDisplayName[nTempLen + 1] = 0;
			}

			m_pFindFonts->Add( m_oFont.Name, CString(wsFontName), bOldBold, bOldItalic, bBold, bItalic );

		}
		else
		{
			CString sFName = CString( bsFileName );
			if ( sFName.GetLength() <= 0 || sFName.GetLength() >= 1000 )
			{
				SetCurrentFont( bsDefaultFont, NULL, FALSE, NULL );
				return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
			}
			else
			{
				_tcscpy( wsFontName, sFName.GetBuffer() );
			}
		}
		char *sDisplayName = W2A( wsDisplayName );
		char *sFontFile    = W2A( wsFontName );

		m_oFont.Bold   = bBold;
		m_oFont.Italic = bItalic;

		// пока фонт не включаем в документ 
		// TO DO: 1. Сначала пытаемся включить фонт в документ
		//        2. Если этого сделать нельзя, тогда загружаем фонт не включая его в документ.
		BSTR bsPDFFontName = ::SysAllocString( _T("Embedded") );
		BSTR bsFontFile = A2W( sFontFile );

		unsigned long nRes = LoadTTFFromFile( bsFontFile, TRUE, bsToUnicodeName, &bsPDFFontName );
		if ( OK == nRes )
		{
			nRes = SetCurrentFont( bsPDFFontName, bsEncodingName, FALSE, bsToUnicodeName );
			::SysFreeString( bsPDFFontName );
			return nRes;
		}
		else if ( AVS_OFFICEPDFWRITER_ERROR_FILE_OPEN_ERROR == nRes )
			ResetError( m_pDocument );
		else
		{
			ResetError( m_pDocument );
			SetCurrentFont( bsDefaultFont, NULL, FALSE, NULL );
			::SysFreeString( bsPDFFontName );
			return nRes;
		}

		// Скорее всего фонт не загрузился из-за того, что sFontFile содержит не полный путь
		char *pValue;
		size_t len;
		errno_t err = _dupenv_s( &pValue, &len, "windir" );
		CString sFontFilePath(pValue);
		free( pValue );
		sFontFilePath += "\\Fonts\\";
		sFontFilePath += sFontFile;
		bsFontFile = sFontFilePath.AllocSysString();

		nRes = LoadTTFFromFile( bsFontFile, TRUE, bsEncodingName, &bsPDFFontName );
		if ( OK == nRes )
		{
			nRes = SetCurrentFont( bsPDFFontName, bsEncodingName, FALSE, bsToUnicodeName );
			::SysFreeString( bsPDFFontName );
			::SysFreeString( bsFontFile );
			return nRes;
		}
		else 
		{
			ResetError( m_pDocument );
			SetCurrentFont( bsDefaultFont, NULL, FALSE, NULL );
			::SysFreeString( bsFontFile );
			return AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND;
		}
	}
	unsigned long GdiDashToPDFDash( int nDashStyle = 0, double *pDashPattern = NULL, int nDashPatternSize = 0, float fDashOffset = 0 )
	{
		unsigned long nRet = OK;

		float fWidth = PageGetLineWidth( m_pDocument->pCurPage );

		// Константы для стилей от 1 до 4 вычислены на основе MicrosoftOfficePowerPoint
		if ( 0 == nDashStyle ) // Solid
		{
			nRet = PageSetDash( m_pDocument->pCurPage, NULL, 0, 0 );
		}
		else if ( 1 == nDashStyle )
		{
			double arrDashPtn[2] = { 4 * fWidth, 3 * fWidth };
			nRet = PageSetDash( m_pDocument->pCurPage, arrDashPtn, 2, fDashOffset );
		}
		else if ( 2 == nDashStyle )
		{
			double arrDashPtn[2] = { fWidth, fWidth };
			nRet = PageSetDash( m_pDocument->pCurPage, arrDashPtn, 2, fDashOffset );
		}
		else if ( 3 == nDashStyle )
		{
			double arrDashPtn[4] = { 4 * fWidth, 3 * fWidth, fWidth, 3 * fWidth };
			nRet = PageSetDash( m_pDocument->pCurPage, arrDashPtn, 4, fDashOffset );
		}
		else if ( 4 == nDashStyle )
		{
			double arrDashPtn[6] = { 8 * fWidth, 3 * fWidth, fWidth, 3 * fWidth, fWidth, 3 * fWidth };
			nRet = PageSetDash( m_pDocument->pCurPage, arrDashPtn, 6, fDashOffset );
		}
		else if ( 5 == nDashStyle ) // Custom
		{
			nRet = PageSetDash( m_pDocument->pCurPage, pDashPattern, nDashPatternSize, fDashOffset );
		}

		return nRet;
	}
	unsigned long ReadOutlineChilds(CString sXml, int nRootIndex)
	{
		HRESULT hRes = S_OK;
		XmlUtils::CXmlNode oNode;
		oNode.FromXmlString(sXml);

		XmlUtils::CXmlNodes oNodes;
		oNode.GetNodes( _T("Chapter"), oNodes);

		for ( int nIndex = 0; nIndex < oNodes.GetCount(); nIndex++ )
		{
			XmlUtils::CXmlNode oCurNode;
			oNodes.GetAt( nIndex, oCurNode );
			if ( -1 != oCurNode.GetName().Find( _T("Chapter") ) )
			{
				CStringA sName = (CStringA)oCurNode.GetAttribute( _T("name") );
				CStringA sPage = (CStringA)oCurNode.GetAttribute( _T("page") );
				int nPageNum = UtilsAToI( sPage.GetBuffer() );

				if ( FAILED ( hRes = SetCurrentPage( nPageNum ) ) )
					return hRes;

				BSTR bsName = sName.AllocSysString();
				CString sNode = oNode.GetXml();

				if ( FAILED ( hRes = CreateNewOutline( nRootIndex, bsName, NULL ) ) )
					return hRes;
				if ( FAILED ( hRes = CreateNewDestination() ) )
					return hRes;
				if ( FAILED ( hRes = OutlineSetCurrentDestination() ) )
					return hRes;
				if ( FAILED ( hRes = SetOutlineOpened( FALSE ) ) )
					return hRes;
				::SysFreeString( bsName );
				long nCurrentIndex = -1;
				if ( FAILED ( hRes = GetCurrentOutlineIndex(&nCurrentIndex) ) )
					return hRes;
				if ( FAILED ( hRes = ReadOutlineChilds( oCurNode.GetXml(), nCurrentIndex ) ) )
					return hRes;
			}
		}
		return S_OK;
	}
	unsigned long UpdateGState()
	{
		HRESULT hRes = S_OK;

		if ( ! ( NULL != m_pCurCommand->pPrev && c_nClipType == m_pCurCommand->pPrev->nType ) )
		{
			if ( FAILED( hRes = GSave() ) )
				return hRes;

			if ( FAILED( hRes = UpdateCoordSpace() ) )
				return hRes;

			long nColor = m_oBrush.Color1;
			float fR = ( nColor & 0xFF ) / 255.0f; 
			float fG = ( ( nColor >> 8 ) & 0xFF ) / 255.0f; 
			float fB = ( (nColor >> 16) ) / 255.0f; 

			if ( FAILED( hRes = SetRGBFill( fR, fG, fB ) ) )
				return hRes;

			float fLineWidth = MMToPDFCoords( m_oPen.Size );
			if ( FAILED( hRes = SetLineWidth( fLineWidth ) ) )
				return hRes;

			float  fDashOffset      = m_oPen.DashOffset;
			int    nDashStyle       = m_oPen.DashStyle;

			double *pDashPattern     = m_oPen.DashPattern;
			int     nDashPatternSize = m_oPen.Count;

			if ( FAILED( hRes = GdiDashToPDFDash( nDashStyle, pDashPattern, nDashPatternSize, fDashOffset ) ) )
				return hRes;

			//if ( 0 != nLineCap )
			//	if ( FAILED( hRes = SetLineCap( nLineCap ) ) )
			//		return hRes;

			//int nLineJoin = m_oPen.LineJoin;
			//if ( 0 != nLineJoin )
			//	if ( FAILED( hRes = SetLineJoin( nLineJoin ) ) )
			//		return hRes;

			nColor = m_oPen.Color;
			fR = ( nColor & 0xFF ) / 255.0f; 
			fG = ( ( nColor >> 8 ) & 0xFF ) / 255.0f; 
			fB = ( (nColor >> 16) ) / 255.0f; 

			if (FAILED(hRes = SetRGBStroke(fR, fG, fB)))
				return hRes;

			if (CGdiPath::c_nTextureBrush == m_oBrush.Type && c_BrushTextureModeStretch == m_oBrush.TextureMode)
			{
				if (255 != m_oBrush.TextureAlpha)
				{
					XmlUtils::CXmlWriter oWriter;

					oWriter.WriteNodeBegin(_T("ExtGState"));

					if (255 != m_oBrush.Alpha1)
					{
						oWriter.WriteNodeBegin(_T("AlphaFill"), TRUE);
						oWriter.WriteAttribute(_T("value"), (double)m_oBrush.TextureAlpha/255.0f);
						oWriter.WriteNodeEnd(_T("AlphaFill"), TRUE, TRUE);
					}

					oWriter.WriteNodeEnd(_T("ExtGState"));

					BSTR bsXml = oWriter.GetXmlString().AllocSysString();
					if (FAILED(hRes = SetExtGraphicsState2(bsXml)))
					{
						::SysFreeString(bsXml);
						return hRes;
					}

					::SysFreeString(bsXml);
				}
			}
			else 
			{
				if (255 != m_oBrush.Alpha1 || 255 != m_oPen.Alpha)
				{
					XmlUtils::CXmlWriter oWriter;

					oWriter.WriteNodeBegin( _T("ExtGState") );

					if (255 != m_oBrush.Alpha1)
					{
						oWriter.WriteNodeBegin( _T("AlphaFill"), TRUE);
						oWriter.WriteAttribute( _T("value"), (double)m_oBrush.Alpha1/255.0f);
						oWriter.WriteNodeEnd( _T("AlphaFill"), TRUE, TRUE);
					}

					if ( 255 != m_oPen.Alpha )
					{
						oWriter.WriteNodeBegin(_T("AlphaStroke"), TRUE);
						oWriter.WriteAttribute(_T("value"), (double)m_oPen.Alpha/255.0f);
						oWriter.WriteNodeEnd(_T("AlphaStroke"), TRUE, TRUE);
					}

					oWriter.WriteNodeEnd(_T("ExtGState"));

					BSTR bsXml = oWriter.GetXmlString().AllocSysString();
					if (FAILED(hRes = SetExtGraphicsState2(bsXml)))
					{
						::SysFreeString(bsXml);
						return hRes;
					}

					::SysFreeString(bsXml);
				}
			}
		}
		else
		{
			if (FAILED(hRes = UpdateCoordSpace()))
				return hRes;
		}

		return S_OK;
	}
	unsigned long UpdateCoordSpace()
	{
		// Здесь предполагается, что текущая матрица CTM единичная
		// Поэтому этой функцией надо пользоваться аккуратно

		HRESULT hRes = S_OK;

		float fPageHeight = 0.0f;
		float fPageWidth  = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;

		if ( FAILED( hRes = GetWidth( &fPageWidth ) ) )
			return hRes;

		DWORD  nFlags  = m_oCommandParams.nFlag;
		if ( !( nFlags == 16 ) )
		{

			double dAngle  = m_oCommandParams.dAngle;
			double dLeft   = m_oCommandParams.dLeft;
			double dHeight = m_oCommandParams.dHeight;
			double dWidth  = m_oCommandParams.dWidth;
			double dTop    = m_oCommandParams.dTop;

			if ( 0 == nFlags && 0 == dAngle )
				return S_OK;

			// Миллиметры -> координаты PDF (72dpi)

			dLeft   = MMToPDFCoords( dLeft );
			dTop    = MMToPDFCoords( dTop );
			dWidth  = MMToPDFCoords( dWidth );
			dHeight = MMToPDFCoords( dHeight );

			dTop = fPageHeight - dTop;
			dAngle =  dAngle * 3.141592f / 180;

			// Высчитываем центр прямоугольника ( относительно него производится поворот )

			double dX0 = dLeft + dWidth  / 2;
			double dY0 = dTop  - dHeight / 2;

			double dA =  cos( dAngle );
			double dB =  sin( dAngle );
			double dC = -sin( dAngle );
			double dD =  cos( dAngle );
			double dE = dX0 - dX0 * cos ( dAngle ) + dY0 * sin( dAngle );
			double dF = dY0 - dX0 * sin ( dAngle ) - dY0 * cos( dAngle );

			BOOL bFlipX = nFlags & 1;
			BOOL bFlipY = nFlags & 2;

			if ( !bFlipX && !bFlipY )
			{
				// Ничего не делаем
				//if ( FAILED( hRes = Concat( dA, dB, dC, dD, dE, dF ) ) )
				//	return hRes;
			}
			else if ( bFlipX && !bFlipY )
			{
				dA = -dA;
				dC = -dC;
				dE = -dE + 2 * dX0;
				//if ( FAILED( hRes = Concat( -dA, dB, -dC, dD, -dE + 2 * dX0, dF ) ) )
				//	return hRes;
			}
			else if ( !bFlipX && bFlipY )
			{
				dB = -dB;
				dD = -dD;
				dF = -dF + 2 * dY0;

				//if ( FAILED( hRes = Concat( dA, -dB, dC, -dD, dE, -dF + 2 * dY0 ) ) )
				//	return hRes;
			}
			else
			{
				dA = -dA;
				dB = -dB;
				dC = -dC;
				dD = -dD;
				dE = -dE + 2 * dX0;
				dF = -dF + 2 * dY0;
				//if ( FAILED( hRes = Concat( -dA, -dB, -dC, -dD, -dE + 2 * dX0, -dF + 2 * dY0 ) ) )
				//	return hRes;
			}

			if ( FAILED( hRes = Concat( dA, dB, dC, dD, dE, dF ) ) )
				return hRes;

			//if ( (NULL != m_pCurCommand->pPrev && c_nClipType == m_pCurCommand->pPrev->nType) || c_nClipType == m_pCurCommand->nType )
			m_oClipCTM.Set( dA, dB, dC, dD, dE, dF );
		}
		else
		{
			float fA = m_oCommandParams.oMatrix.fA;
			float fB = m_oCommandParams.oMatrix.fB;
			float fC = m_oCommandParams.oMatrix.fC;
			float fD = m_oCommandParams.oMatrix.fD;
			float fE = m_oCommandParams.oMatrix.fE;
			float fF = m_oCommandParams.oMatrix.fF;

			if ( FAILED( hRes = Concat( fA, -fB, -fC, fD, MMToPDFCoords( fE ) + fC * fPageHeight, fPageHeight - fPageHeight * fD - MMToPDFCoords( fF ) ) ) )
				return hRes;

			//if ( (NULL != m_pCurCommand->pPrev && c_nClipType == m_pCurCommand->pPrev->nType) || c_nClipType == m_pCurCommand->nType )
			m_oClipCTM.Set( fA, -fB, -fC, fD, MMToPDFCoords( fE ) + fC * fPageHeight, fPageHeight - fPageHeight * fD - MMToPDFCoords( fF ) );

		}
		return S_OK;

	}
	unsigned long UpdateCoordSpace2(CMatrix *pTransform)
	{
		// Здесь предполагается, что текущая матрица CTM единичная
		// Поэтому этой функцией надо пользоваться аккуратно

		HRESULT hRes = S_OK;

		float fPageHeight = 0.0f;
		float fPageWidth  = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;

		if ( FAILED( hRes = GetWidth( &fPageWidth ) ) )
			return hRes;


		float fA = (float)pTransform->get_A();
		float fB = (float)pTransform->get_B();
		float fC = (float)pTransform->get_C();
		float fD = (float)pTransform->get_D();
		float fE = (float)pTransform->get_E();
		float fF = (float)pTransform->get_F();

		if ( FAILED( hRes = Concat( fA, -fB, -fC, fD, MMToPDFCoords( fE ) + fC * fPageHeight, fPageHeight - fPageHeight * fD - MMToPDFCoords( fF ) ) ) )
			return hRes;

		m_oClipCTM.Set( fA, -fB, -fC, fD, MMToPDFCoords( fE ) + fC * fPageHeight, fPageHeight - fPageHeight * fD - MMToPDFCoords( fF ) );

		return S_OK;

	}
	bool          FileExist(CString sFilePath )
	{
		return ( -1 != _waccess( sFilePath.GetBuffer(), 0 ) || CFileDownloader::IsNeedDownload(sFilePath) );
	}

	// Устанавливаем текущее состояние рендерера
	BOOL SetState ( ERendererState eState )
	{
		m_oRendererState.set_NewState( eState, m_oTransform );

		if ( rendstatePath == m_oRendererState.get_PrevState() && rendstatePath != m_oRendererState.get_State() )
		{
			// TODO: перенести сюда запись пата
		}
		else if ( rendstateClipPath == m_oRendererState.get_PrevState() && rendstateClipReset == m_oRendererState.get_State() )
		{
			// Набили клип и его удалили, в данном случае ничего не делаем. Обнуляем клип
		}
		else if ( rendstateClipPath == m_oRendererState.get_PrevState() && rendstateClipPath != m_oRendererState.get_State() )
		{
			// TODO: Перенести сюда набивку клипа
		}
		else if ( rendstateClipReset == m_oRendererState.get_PrevState() && rendstateClipReset != m_oRendererState.get_State() )
		{
			// TODO: Reset клипа
		}
		else if ( rendstateText == m_oRendererState.get_PrevState() && ( rendstateText != m_oRendererState.get_State() || m_oRendererState.IsMatrixChanged() ) )
		{
			// TODO: Пока оставим так, но в будущем сделать, чтобы можно было менять матрицу сразу у текста

			int nTextsCount = m_oContiniousText.GetSize();

			// Если матрица преобразования изменилась, тогда последний текстовый
			// элемент не нужно записывать. С него нужно начать новый текст.
			if ( rendstateText == m_oRendererState.get_State() && m_oRendererState.IsMatrixChanged() )
				nTextsCount--;	

			if ( nTextsCount > 0 )
			{
				CSynchAccess oSynchAccess = m_hSynchMutex;

				// Загрузка шрифтов проиходит через m_oFont, поэтому далее этот параметр изменится
				NSStructures::CFont CurFont = m_oFont;

				// Запоминаем некоторые настройки, чтобы потом их восстановить
				float fOldLineWidth = 0.0f;
				float fFillR, fFillG, fFillB, fStrokeR, fStrokeG, fStrokeB;

				if ( FAILED( GetLineWidth( &fOldLineWidth ) ) )
					return FALSE;

				if ( FAILED( GetRGBFill( &fFillR, &fFillG, &fFillB ) ) )
					return FALSE;

				if ( FAILED( GetRGBStroke( &fStrokeR, &fStrokeG, &fStrokeB ) ) )
					return FALSE;


				BOOL bDefaultFont = FALSE;
				bool bWasHorScale = false;
				bool bFirst = true;
				NSStructures::CFont oPrevFont;
				CContiniousText::TColor oPrevColor;
				PToUnicode pPrevToUnicode = NULL;
				double dPrevCharSpacing = 0;

				long nAscent = 0;
				long nDescent = 0;
				long nXHeight = 0;
				double dItalicAngle = 0;
				float fPageHeight = 0.0f;
				float fFontSize = 0;

				float fXHeight = (float)nXHeight / 1000;
				float fAscent  = (float)nAscent / 1000;
				float fDescent = fabs( (float)nDescent / 1000 );
				float fR = 0;
				float fG = 0;
				float fB = 0;

				if ( FAILED( GetHeight( &fPageHeight ) ) )
					return FALSE;

				// Делаем сохранение состояния
				ATLTRACE2( _T("GSave: DrawText\n") );
				if ( FAILED( GSave() ) )
					return FALSE;

				// Выставляем систему координат
				CMatrix oTransform = m_oContiniousText.get_Matrix();
				if ( FAILED( UpdateCoordSpace2( &oTransform ) ) )
					return FALSE;

				// Устанавливаем альфу для данного текста
				float fAlphaFill   = (float)m_oContiniousText.get_Color( 0 )->unA / 255.0f;
				float fAlphaStroke = (float)m_oContiniousText.get_Color( 0 )->unA / 255.0f;
				m_pCurrentExtGState = GetExtGState( m_pDocument, fAlphaStroke, fAlphaFill );
				if ( OK != ( PageSetExtGState( m_pDocument->pCurPage, m_pCurrentExtGState ) ) )
					return FALSE;

				if ( FAILED( BeginText() ) )
					return FALSE;

				// Выясним как нам рисовать текст (пока сделаем всегда fill)
				// TODO: В будущем надо добавить данную настройку в ContiniusText, и следить
				//       за ее изменениями, как, например, при изменении шрифта
				ETextRenderingMode eRenderingMode = ETextRenderingMode::Fill; // Fill (по умолчанию)
				//if ( c_nStrokeTextType == m_pCurCommand->nType )
				//	eRenderingMode = ETextRenderingMode::Stroke; // Stroke

				if ( FAILED( SetTextRenderingMode( (long)eRenderingMode ) ) )
					return FALSE;

				/*
				if ( ETextRenderingMode::Fill == eRenderingMode )
				{
				// Если данный фонт не нашли с атрибутом Bold, тогда заливаем и обводим текст, тем самым утолщяя его
				if ( m_oFont.Bold )
				{
				if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::FillThenStroke) ) )
				{
				::SysFreeString( bsCodedString );
				return hRes;
				}
				}
				else
				if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::Fill) ) )
				{
				::SysFreeString( bsCodedString );
				return hRes;
				}
				}
				else
				{
				if ( FAILED( hRes = SetTextRenderingMode( (long)eRenderingMode ) ) )
				{
				::SysFreeString( bsCodedString );
				return hRes;
				}
				}
				*/


				for ( int nIndex = 0; nIndex < nTextsCount; nIndex++ )
				{
					const CContiniousText::TText    *pText    = m_oContiniousText.get_Text   ( nIndex );
					const NSStructures::CFont       *pFont    = m_oContiniousText.get_Font   ( nIndex );
					const CContiniousText::TColor   *pColor   = m_oContiniousText.get_Color  ( nIndex );
					const double                     dCharSp  = m_oContiniousText.get_CharSp ( nIndex );

					if ( !pText || !pFont || !pColor )
						continue;

					// Ищем кодировку ToUnicode для данной строки
					PToUnicode pToUnicode = FindToUnicodeForString( m_pDocument, pText->bsText );
					if ( !pToUnicode )
						continue;

					// Кодируем нашу строку в соответствии с текущей ToUnicode
					CString sCodedString;
					ToUnicodeWCharToString( pToUnicode, pText->bsText, &sCodedString );

					bool bFontChange = false, bSizeChange = false, bColorChange = false, bCharSpChange = false;

					if ( bFirst )
					{
						// Для первого текста выставляем все настройки
						bFontChange   = true;
						bSizeChange   = true;
						bColorChange  = true;
						bCharSpChange = true;

						bFirst        = false;
					}
					else
					{
						if (  ( CString( pToUnicode->sName ) != CString( pPrevToUnicode->sName ) ) || ( oPrevFont.Path != pFont->Path ) || ( _T("") == pFont->Path && ( oPrevFont.Name != pFont->Name || oPrevFont.Bold != pFont->Bold || oPrevFont.Italic != pFont->Italic ) ) )
							bFontChange = true;
						if ( fabs( oPrevFont.Size - pFont->Size ) > 0.001 )
							bSizeChange = true;
						if ( oPrevColor.unA != pColor->unA || oPrevColor.unB != pColor->unB || oPrevColor.unG != pColor->unG || oPrevColor.unR != pColor->unR )
							bColorChange = true;
						if ( fabs( dPrevCharSpacing - dCharSp ) > 0.001  )
							bCharSpChange = true;
					}

					// Запоминаем настройки
					oPrevColor       = *pColor;
					oPrevFont        = *pFont;
					pPrevToUnicode   = pToUnicode;
					dPrevCharSpacing = dCharSp;

					m_oFont = *pFont;
					BOOL bOldBold     = m_oFont.Bold;
					BOOL bOldItalic   = m_oFont.Italic;

					if ( bSizeChange )
						fFontSize = (float)m_oFont.Size;

					if ( bFontChange )
					{
						USES_CONVERSION;

						// Запоминаем значения Bold и Italic, потому что в функции GdiFontToPdfFont они могут измениться

						HRESULT hRes = S_OK;
						if ( FAILED( hRes = GdiFontToPdfFont2( A2W( pToUnicode->sName ), FALSE ) ) )
						{
							if ( AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND == hRes )
							{
								ResetError( m_pDocument );
								sCodedString = CString( pText->bsText );
								bDefaultFont = TRUE;
							}
							else
							{
								continue;
							}
						}
						else
						{
							bDefaultFont = FALSE;

							if ( bWasHorScale )
							{
								// Отменяем горизонтальное сжатие/растяжение
								if ( FAILED( SetHorizontalScalling( 100 ) ) )
									continue;

								bWasHorScale = false;
							}
						}

						if ( !m_oFont.Italic )
							dItalicAngle = 0;
						else
							dItalicAngle = 3.141592f / 12;

						if ( FAILED( GetFontAscent( &nAscent ) ) )
							continue;

						if ( FAILED( GetFontDescent( &nDescent ) ) )
							continue;

						if ( FAILED( GetFontXHeight( &nXHeight ) ) )
							continue;

						fXHeight = (float)nXHeight / 1000;
						fAscent  = (float)nAscent / 1000;
						fDescent = fabs( (float)nDescent / 1000 );

						// Данная ветка сделана специально для конвертации Djvu -> PDF
						if ( _T("AVSEmptyFont") == pFont->Name )
						{						
							float fVKoef;

							if ( fabs( pFont->Size ) < 0.01 )
								fVKoef = 1;
							else		
								fVKoef = pText->fHeight / pFont->Size;

							// Если данный фонт не нашли с атрибутом Italic, тогда наколняем текст сами на угол dItalicAngle
							if ( FAILED( SetTextMatrix( 1, (float)tan( 0.0 ), (float)fVKoef * tan( dItalicAngle ), fVKoef * 1, 0, 0 ) ) )
								continue;
						}
						else
						{
							// Если данный фонт не нашли с атрибутом Italic, тогда наколняем текст сами на угол dItalicAngle
							if ( FAILED( SetTextMatrix( 1, (float)tan( 0.0 ), (float)tan( dItalicAngle ), 1, 0, 0 ) ) )
								continue;
						}
					}

					if ( bColorChange )
					{
						fR = ( pColor->unR ) / 255.0f; 
						fG = ( pColor->unG ) / 255.0f; 
						fB = ( pColor->unB ) / 255.0f; 

						// Выставляем цвет текста и линий
						if ( FAILED( SetRGBFill( fR, fG, fB ) ) )
							continue;

						if ( FAILED( SetRGBStroke( fR, fG, fB ) ) )
							continue;
					}

					if ( bCharSpChange )
					{
						// Устанавливаем межсимвольный интервал
						if ( FAILED( SetCharSpace( (float)dCharSp ) ) )
							continue;
					}

					if ( bFontChange || bSizeChange )
					{
						// Устанавливаем текущий шрифт и размер шрифта
						if ( FAILED( SetFontAndSizeToGState( fFontSize ) ) )
							continue;
					}

					BSTR bsCodedString = sCodedString.AllocSysString();


					// Если шрифт не нашли, и используется стандартный шрифт, значит, ширина слов будет неверной.
					// Чтобы слова не наползали друг на друга скейлим текст к его реальной ширине.
					if ( bDefaultFont )
					{
						bWasHorScale = true;

						// Измеряем размер
						float fTextWidth = 0.0f;
						if ( FAILED( GetTextWidth( bsCodedString, &fTextWidth ) ) )
						{
							::SysFreeString( bsCodedString );
							continue;
						}

						float fKoef;
						if ( fabs( fTextWidth ) < 0.01 )
							fKoef = 1;
						else
							fKoef = pText->fWidth / fTextWidth * 100; // Scale задается в процентах

						if ( fKoef > 0.001 )
						{
							if ( FAILED( SetHorizontalScalling( fKoef ) ) )
							{
								::SysFreeString( bsCodedString );
								continue;
							}
						}
					}

					// Выводим текст
					if ( FAILED( TextOut( (float)pText->fX, fPageHeight - (float)(pText->fY + pText->fBaseLineOffset), bsCodedString ) ) )
					{
						::SysFreeString( bsCodedString );
						continue;
					}

					::SysFreeString( bsCodedString );


					if ( bFontChange )
					{
						m_oFont.Bold = bOldBold;
						m_oFont.Italic = bOldItalic;
					}
				}

				// Заканчиваем запись текста
				if ( FAILED( EndText() ) )
					return FALSE;

				// Восстанавливаем систему координат
				ATLTRACE2( _T("GRestore: DrawText\n") );
				if ( FAILED( GRestore() ) )
					return FALSE;

				// Восстанавливаем старые настройки
				if ( FAILED( SetLineWidth( fOldLineWidth ) ) )
					return FALSE;

				if ( FAILED( SetRGBFill( fFillR, fFillG, fFillB ) ) )
					return FALSE;

				if ( FAILED( SetRGBStroke( fStrokeR, fStrokeG, fStrokeB ) ) )
					return FALSE;

				// Восстанавливаем текущий шрифт
				m_oFont = CurFont;
			}

			if ( rendstateText == m_oRendererState.get_State() && m_oRendererState.IsMatrixChanged() )
				m_oContiniousText.LeaveLast();
			else
				m_oContiniousText.Reset();
		}

		return TRUE;
	}

public:
	//-----------------------------------------------------------------------------------------------------
	//
	// Интерфейс IPDFWriter
	//
	//-----------------------------------------------------------------------------------------------------
	STDMETHOD(CreatePDF)()
	{
		if ( m_pFontManager && !m_bIsFontsInitialize )
		{
#ifdef BUILD_CONFIG_OPENSOURCE_VERSION
			m_pFontManager->Init( L"", TRUE, TRUE );
#else
			m_pFontManager->Initialize( _T("") );
#endif
			m_bIsFontsInitialize = TRUE;
		}

		if ( !CRegistratorClient::IsRegistered() )
			return AVS_OFFICEPDFWRITER_ERROR_AVS_REGISTRATION;
		m_pDocument = New();
		if ( !m_pDocument )
			return AVS_OFFICEPDFWRITER_ERROR_FAILD_TO_ALLOC_MEM;

		// m_pDocument->patterns = &m_oPatterns;

		// Создаем стек команд
		m_pCurCommand = new TCommandType();
		m_pCurCommand->nType = c_nNone;
		m_pCurCommand->nFlag = 0;
		m_pCurCommand->pPrev = NULL;

		m_pFindFonts = new CFindFonts();

		m_bClipPath = FALSE;
		m_wsTempDir = _T("");

		m_oTransform.Reset();
		m_oRendererState.Reset();
		m_bFirstMoveTo = TRUE;

		return S_OK;
	}
	STDMETHOD(DeletePDF)()
	{
		FreePDF();
		return S_OK;
	}
	STDMETHOD(SaveToFile)(BSTR bsPath)
	{
		SetState( rendstateNone );

		if ( !CRegistratorClient::IsRegistered() )
			return AVS_OFFICEPDFWRITER_ERROR_AVS_REGISTRATION;

		CString sFileName( bsPath );

		// Проверяем не пустой ли документ мы пытаемся записать.
		if ( m_pDocument->pPageList->nCount <= 0 )
			return AVS_OFFICEPDFWRITER_ERROR_INVALID_DOCUMENT;

		unsigned long nRet = SaveDocToFile( m_pDocument, sFileName.GetBuffer() );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(SetPDFPageMode)(long nMode)
	{
		unsigned long nRet = SetPageMode( m_pDocument, (EPageMode)nMode);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetPDFPageMode)(long *pnMode)
	{
		*pnMode = (long)GetPageMode( m_pDocument );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetPDFPageLayout)(long nLayout)
	{
		unsigned long nRet = SetPageLayout( m_pDocument, (EPageLayout)nLayout);
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetPDFPageLayout)(long *pnLayout)
	{
		*pnLayout = (long)GetPageLayout( m_pDocument );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetPDFViewerPreference)(long nValue )
	{
		unsigned long nRet = SetViewerPreference( m_pDocument, nValue );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetPDFViewerPreference)(long *pnValue)
	{
		*pnValue = (long)GetViewerPreference( m_pDocument );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetPDFCompressionMode)(long nMode)
	{
		unsigned long nRet = SetCompressionMode( m_pDocument, nMode );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetPDFOpenAction)(long nAction)
	{
		if ( !m_pCurrentDestination )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_DESTINATION_NOT_FOUND;
		unsigned long nRet = SetOpenAction( m_pDocument, m_pCurrentDestination );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetLastErrorCode)(long *pnErrorCode)
	{
		*pnErrorCode = ErrorGetCode( &m_pDocument->oError );

		return S_OK;
	}
	STDMETHOD(GetLastErrorString)(BSTR *pbsErrorString)
	{
		const char *sErrorString = ErrorGetString( &m_pDocument->oError );
		CString sErr(sErrorString);

		*pbsErrorString = sErr.AllocSysString();
		return S_OK;
	}
	//-----------------------------------------------------------------------------------------------------
	STDMETHOD(AddNewPage)()
	{		
		if ( !m_pDocument )
			return AVS_OFFICEPDFWRITER_ERROR_INVALID_DOCUMENT;

		// новая страница становится текущей
		Page page = AddPage( m_pDocument );
		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	STDMETHOD(GetPagesCount)(long *pnCount )
	{
		*pnCount = m_pDocument->pPageList->nCount;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;		
	}
	STDMETHOD(SetCurrentPage)(long nIndex)
	{
		if ( nIndex > m_pDocument->pPageList->nCount )
			return S_FALSE;

		Page pTempPage = (Page)ListItemAt( m_pDocument->pPageList, nIndex );
		DocSetCurrentPage( m_pDocument, pTempPage );

		return S_OK;
	}

	STDMETHOD(GetCurrentPageIndex)(long *pnIndex)
	{
		*pnIndex = ListFind( m_pDocument->pPageList, m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetPageWidth)(float fWidth)
	{
		unsigned long nRet = PageSetWidth( m_pDocument->pCurPage, fWidth );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetPageHeight)(float fHeight)
	{
		unsigned long nRet = PageSetHeight( m_pDocument->pCurPage, fHeight );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetWidth)(float *pfWidth)
	{
		*pfWidth = PageGetWidth( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetHeight)(float *pfHeight)
	{
		*pfHeight = PageGetHeight( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetSize)(long nSize, long nDirection)
	{
		unsigned long nRet = PageSetSize(m_pDocument->pCurPage, (EPageSizes)nSize, (EPageDirection)nDirection);
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetRotate)(long nAngle)
	{
		unsigned long nRet = PageSetRotate( m_pDocument->pCurPage, nAngle );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(AddLabel)(long nPageNum, long nNumStyle, long nFirstPage, BSTR bsPrefix )
	{
		USES_CONVERSION;
		const char* sPrefix = W2A(bsPrefix);
		unsigned long nRet = AddPageLabel( m_pDocument, nPageNum, (PageNumStyle)nNumStyle, nFirstPage, sPrefix );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	//-----------------------------------------------------------------------------------------------------
	STDMETHOD(SetLineWidth)(float fLineWidth)
	{
		unsigned long nRet = PageSetLineWidth( m_pDocument->pCurPage, fLineWidth );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetLineWidth)(float *pfLineWidth)
	{
		*pfLineWidth = PageGetLineWidth( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetLineCap)(long nLineCap)
	{
		unsigned long nRet = PageSetLineCap( m_pDocument->pCurPage, (ELineCapStyle)nLineCap);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetLineCap)(long *pnLineCap)
	{
		*pnLineCap = PageGetLineCap( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetLineJoin)(long nLineJoin)
	{
		unsigned long nRet = PageSetLineJoin( m_pDocument->pCurPage, (LineJoinStyle)nLineJoin);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetLineJoin)(long *pnLineJoin)
	{
		*pnLineJoin = PageGetLineJoin( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetMiterLimit)(float fMiterLimit)
	{
		unsigned long nRet = PageSetMiterLimit( m_pDocument->pCurPage, fMiterLimit);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetMiterLimit)(float *pfMiterLimit)
	{
		*pfMiterLimit = PageGetMiterLimit( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetDash)(SAFEARRAY **ppnDashPtn, long   nNumParam, float   fPhase)
	{
		double *pArray = new double[nNumParam];
		if ( 0 != nNumParam )
		{
			// check for valid pixel array size
			if ( 1 != SafeArrayGetDim(*ppnDashPtn) )
				return FALSE;

			VARTYPE vType;
			// check for valid array element type
			if ( FAILED(SafeArrayGetVartype(*ppnDashPtn, &vType)) || VT_R4 != vType )
				return S_OK;

			float* pTemp = (float*)(*ppnDashPtn)->pvData;
			for ( int nIndex = 0 ; nIndex < nNumParam; nIndex++ )
			{
				pArray[nIndex] = *(pTemp + nIndex);
			}
		}

		unsigned long nRet = PageSetDash( m_pDocument->pCurPage, pArray, nNumParam, fPhase);
		delete[] pArray;
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(GetDash)(SAFEARRAY **ppnDashPtn, long *pnNumParam, float *pfPhase)
	{
		DashMode oMode = {{0, 0, 0, 0, 0, 0, 0, 0}, 0, 0};		
		oMode = PageGetDash( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		if ( 0 == oMode.nNumPoints )
		{
			*ppnDashPtn = NULL;
			*pnNumParam = 0;
			*pfPhase = 0;
			return S_OK;
		}
		float* pTemp = new float[oMode.nNumPoints];
		for ( int nIndex = 0; nIndex < oMode.nNumPoints; nIndex++ )
			pTemp[nIndex] = (float)oMode.afPtn[nIndex];

		SAFEARRAYBOUND bounds[1];

		bounds[0].lLbound = 0;
		bounds[0].cElements = oMode.nNumPoints;

		(*ppnDashPtn) = SafeArrayCreate(VT_R4, 1, bounds);

		if ( !(*ppnDashPtn) )
		{
			delete[] pTemp;
			return S_OK;
		}

		memcpy( (*ppnDashPtn)->pvData, pTemp, oMode.nNumPoints * sizeof(float) );
		delete[] pTemp;
		*pnNumParam = (long)oMode.nNumPoints;
		*pfPhase    = (float)oMode.fPhase;
		return S_OK;
	}
	STDMETHOD(SetFlat)(float   fFlatness)
	{
		unsigned long nRet = PageSetFlat( m_pDocument->pCurPage, fFlatness );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetFlat)(float *pfFlatness)
	{
		*pfFlatness = PageGetFlat( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(NewExtGraphicsState)()
	{
		m_pCurrentExtGState = CreateExtGState( m_pDocument );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(ExtGraphicsStateSetAlphaStroke)(float fValue)
	{
		unsigned long nRet = ExtGStateSetAlphaStroke( m_pCurrentExtGState, fValue );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(ExtGraphicsStateSetAlphaFill)(float fValue)
	{
		unsigned long nRet = ExtGStateSetAlphaFill( m_pCurrentExtGState, fValue );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(ExtGraphicsStateSetBlendMode)(long nBlendMode)
	{
		unsigned long nRet = ExtGStateSetBlendMode( m_pCurrentExtGState, (EBlendMode)nBlendMode );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(ExtGraphicsStateSetStrokeAdjustment)(int nFlag)
	{
		BOOL bFlag = ( 0 == nFlag ? FALSE : TRUE);

		unsigned long nRet = ExtGStateSetStrokeAdjustment( m_pCurrentExtGState, bFlag );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(SetExtGraphicsState)()
	{
		if ( !m_pCurrentExtGState )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_EXTGSTATE_NOT_FOUND;

		unsigned long nRet = PageSetExtGState( m_pDocument->pCurPage, m_pCurrentExtGState );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GSave)()
	{
		unsigned long nRet = PageGSave( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GRestore)()
	{
		BOOL bIsPrevGState = FALSE;

		if ( m_pDocument->pCurPage && m_pDocument->pCurPage )
		{
			PageAttr pAttr = (PageAttr)m_pDocument->pCurPage->pAttr;
			if ( pAttr->pGState->pPrev )
				bIsPrevGState = TRUE;
		}
		if ( bIsPrevGState )
		{
			unsigned long nRet = PageGRestore( m_pDocument->pCurPage );
			if ( OK != nRet )
				return nRet;
		}
		return S_OK;
	}
	STDMETHOD(GetGStateDepth)(long *pnDepth)
	{
		*pnDepth = PageGetGStateDepth( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetGMode)(long *pnGMode)
	{
		*pnGMode = PageGetGMode( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(Concat)(float fA, float fB, float fC, float fD, float fX, float fY)
	{
		unsigned long nRet = PageConcat( m_pDocument->pCurPage, fA, fB, fC, fD, fX, fY);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(MoveTo)(float fX, float fY)
	{
		unsigned long nRet = PageMoveTo( m_pDocument->pCurPage, fX, fY);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetCurrentPosition)(float *pfX, float *pfY)
	{
		TPoint oCurPos = {0,0};

		unsigned long nRet = PageGetCurrentPos2( m_pDocument->pCurPage, &oCurPos );
		if ( OK != nRet )
		{
			*pfX = 0.0f;
			*pfY = 0.0f;
			return nRet;
		}

		*pfX = oCurPos.fX;
		*pfY = oCurPos.fY;
		return S_OK;
	}
	STDMETHOD(LineTo)(float fX, float fY)
	{
		unsigned long nRet = PageLineTo( m_pDocument->pCurPage, fX, fY);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(CurveTo)(float fX1, float fY1, float fX2, float fY2, float fX3, float fY3)
	{
		unsigned long nRet = PageCurveTo( m_pDocument->pCurPage, fX1, fY1, fX2, fY2, fX3, fY3);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(CurveTo2)(float fX2, float fY2, float fX3, float fY3)
	{
		unsigned long nRet = PageCurveTo2( m_pDocument->pCurPage, fX2, fY2, fX3, fY3);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(CurveTo3)(float fX1, float fY1, float fX3, float fY3)
	{
		unsigned long nRet = PageCurveTo3( m_pDocument->pCurPage, fX1, fY1, fX3, fY3);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(ClosePath)()
	{
		unsigned long nRet = PageClosePath( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(AppendRectangle)(float fX, float fY, float fWidth, float fHeight)
	{
		unsigned long nRet = PageRectangle( m_pDocument->pCurPage, fX, fY, fWidth, fHeight );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(Stroke)()
	{
		unsigned long nRet = PageStroke( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetStrokingColorSpace)(long *pnColorSpace)
	{
		*pnColorSpace = (long)PageGetStrokingColorSpace( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(ClosePathStroke)()
	{
		unsigned long nRet = PageClosePathStroke( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(Fill)()
	{
		unsigned long nRet = PageFill( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetFillingColorSpace)(long *pnColorSpace)
	{
		*pnColorSpace = (long)PageGetFillingColorSpace( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(EoFill)()
	{
		unsigned long nRet = PageEoFill( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(FillStroke)()
	{
		unsigned long nRet = PageFillStroke( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(EoFillStroke)()
	{
		unsigned long nRet = PageEoFillStroke( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(ClosePathFillStroke)()
	{
		unsigned long nRet = PageClosePathFillStroke( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(ClosePathEoFillStroke)()
	{
		unsigned long nRet = PageClosePathEoFillStroke( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(EndPath)()
	{
		unsigned long nRet = PageEndPath( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(Clip)()
	{
		unsigned long nRet = PageClip( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(EoClip)()
	{
		unsigned long nRet = PageEoclip( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(BeginText)()
	{
		unsigned long nRet = PageBeginText( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(EndText)()
	{
		unsigned long nRet = PageEndText( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(SetCharSpace)(float fValue)
	{
		unsigned long nRet = PageSetCharSpace( m_pDocument->pCurPage, fValue );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetCharSpace)(float *pfValue)
	{
		*pfValue = PageGetCharSpace( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetWordSpace)(float fValue)
	{
		unsigned long nRet = PageSetWordSpace( m_pDocument->pCurPage, fValue );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetWordSpace)(float *pfValue)
	{
		*pfValue = PageGetWordSpace( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetHorizontalScalling)(float fValue)
	{
		unsigned long nRet = PageSetHorizontalScalling( m_pDocument->pCurPage, fValue  );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetHorizontalScalling)(float *pfValue)
	{
		*pfValue = PageGetHorizontalScalling( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetTextLeading)(float fValue)
	{
		unsigned long nRet = PageSetTextLeading( m_pDocument->pCurPage, fValue  );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetTextLeading)(float *pfValue)
	{
		*pfValue = PageGetTextLeading( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetFontAndSizeToGState)(float fSize)
	{
		unsigned long nRet = PageSetFontAndSize( m_pDocument->pCurPage, m_pCurrentFont, fSize);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetCurrentFontFromGState)(BSTR *pbsFontName, BSTR *pbsEncodingName)
	{
		FontDict pFont = PageGetCurrentFont( m_pDocument->pCurPage );
		if ( !pFont )
		{
			*pbsFontName = NULL;
			*pbsEncodingName = NULL;
		}
		else
		{
			CString sFontName(FontGetFontName( pFont ));
			CString sEncodingName(((FontAttr)pFont->pAttr)->pEncoder->sName);

			*pbsFontName     = sFontName.AllocSysString();
			*pbsEncodingName = sEncodingName.AllocSysString();
		}

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetCurrentFontSizeFromGState)(float *pfSize)
	{
		*pfSize = PageGetCurrentFontSize( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetTextRenderingMode)(long nMode)
	{
		unsigned long nRet = PageSetTextRenderingMode( m_pDocument->pCurPage, (ETextRenderingMode)nMode );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetTextRenderingMode)(long *pnMode)
	{
		*pnMode = (long)PageGetTextRenderingMode( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetTextRise)(float fValue)
	{
		unsigned long nRet = PageSetTextRise( m_pDocument->pCurPage, fValue );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetTextRise)(float *pfValue)
	{
		*pfValue = PageGetTextRise( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(MoveTextPos)(float fX, float fY)
	{
		unsigned long nRet = PageMoveTextPos( m_pDocument->pCurPage, fX, fY );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(MoveTextPos2)(float fX, float fY)
	{
		unsigned long nRet = PageMoveTextPos2( m_pDocument->pCurPage, fX, fY );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetCurrentTextPosition)(float *pfX, float *pfY)
	{
		TPoint oCurPos = {0,0};

		oCurPos = PageGetCurrentTextPos( m_pDocument->pCurPage);

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
		{
			*pfX = 0.0f;
			*pfY = 0.0f;
			return nRet;
		}

		*pfX = oCurPos.fX;
		*pfY = oCurPos.fY;
		return S_OK;
	}
	STDMETHOD(SetTextMatrix)(float   fA, float   fB, float   fC, float   fD, float   fX, float   fY)
	{
		unsigned long nRet = PageSetTextMatrix( m_pDocument->pCurPage, fA, fB, fC, fD, fX, fY );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(GetTextMatrix)(float *pfA, float *pfB, float *pfC, float *pfD, float *pfX, float *pfY)
	{
		TransMatrix oMatrix = { 1, 0, 0, 1, 0, 0};

		oMatrix = PageGetTextMatrix( m_pDocument->pCurPage );
		*pfA = oMatrix.fA;
		*pfB = oMatrix.fB;
		*pfC = oMatrix.fC;
		*pfD = oMatrix.fD;
		*pfX = oMatrix.fX;
		*pfY = oMatrix.fY;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}	
	STDMETHOD(MoveToNextLine)()
	{
		unsigned long nRet = PageMoveToNextLine( m_pDocument->pCurPage );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(ShowText)(BSTR bsText)
	{
		USES_CONVERSION;
		const char* sText = W2A(bsText);

		// TO DO: ShowText: надо нормально конвертировать текст, иизмерять его длину
		unsigned long nRet = PageShowText( m_pDocument->pCurPage, (BYTE *)sText, strlen(sText), NULL, 0 );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(ShowTextNextLine)(BSTR bsText)
	{
		USES_CONVERSION;
		const char* sText = W2A(bsText);

		// TO DO: ShowText: надо нормально конвертировать текст, иизмерять его длину
		unsigned long nRet = PageShowTextNextLine( m_pDocument->pCurPage, (BYTE *)sText, strlen(sText), NULL, 0 );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(ShowTextNextLineEx)(float fWordSpace, float fCharSpace, BSTR bsText)
	{
		USES_CONVERSION;
		const char* sText = W2A(bsText);

		// TO DO: ShowText: надо нормально конвертировать текст, иизмерять его длину
		unsigned long nRet = PageShowTextNextLineEx( m_pDocument->pCurPage, fWordSpace, fCharSpace, (BYTE *)sText, strlen(sText), NULL, 0 );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(SetGrayStroke)(float fGray)
	{
		unsigned long nRet = PageSetGrayStroke( m_pDocument->pCurPage, fGray );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(GetGrayStroke)(float *pfGray)
	{
		*pfGray = PageGetGrayStroke( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}	
	STDMETHOD(SetGrayFill)(float fGray)
	{
		unsigned long nRet = PageSetGrayFill( m_pDocument->pCurPage, fGray );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(GetGrayFill)(float *pfGray)
	{
		*pfGray = PageGetGrayFill( m_pDocument->pCurPage );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetRGBStroke)(float   fR, float   fG, float   fB)
	{
		unsigned long nRet = PageSetRGBStroke( m_pDocument->pCurPage, fR, fG, fB);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(GetRGBStroke)(float *pfR, float *pfG, float *pfB)
	{
		RGBColor oRGB = { 0, 0, 0};
		oRGB = PageGetRGBStroke( m_pDocument->pCurPage );
		*pfR = oRGB.r;
		*pfG = oRGB.g;
		*pfB = oRGB.b;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}	
	STDMETHOD(SetRGBFill)(float fR, float fG, float fB)
	{
		//unsigned long nRet = PageSetShadingFill( m_pDocument->pCurPage, fR, fG, fB);
		//if ( OK != nRet )
		//	return nRet;
		//return S_OK;

		unsigned long nRet = PageSetRGBFill( m_pDocument->pCurPage, fR, fG, fB);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(GetRGBFill)(float *pfR, float *pfG, float *pfB)
	{
		RGBColor oColor = PageGetRGBFill( m_pDocument->pCurPage );
		*pfR = oColor.r;
		*pfG = oColor.g;
		*pfB = oColor.b;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetCMYKStroke)(float   fC, float   fM, float   fY, float   fK)
	{
		unsigned long nRet = PageSetCMYKStroke( m_pDocument->pCurPage, fC, fM, fY, fK);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(GetCMYKStroke)(float *pfC, float *pfM, float *pfY, float *pfK)
	{
		CMYKColor oCMYK = { 0, 0, 0, 0};
		oCMYK = PageGetCMYKStroke( m_pDocument->pCurPage );
		*pfC = oCMYK.c;
		*pfM = oCMYK.m;
		*pfY = oCMYK.y;
		*pfK = oCMYK.k;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}	
	STDMETHOD(SetCMYKFill)(float   fC, float   fM, float   fY, float   fK)
	{
		unsigned long nRet = PageSetCMYKFill( m_pDocument->pCurPage, fC, fM, fY, fK);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}	
	STDMETHOD(GetCMYKFill)(float *pfC, float *pfM, float *pfY, float *pfK)
	{
		CMYKColor oCMYK = { 0, 0, 0, 0};
		oCMYK = PageGetCMYKFill( m_pDocument->pCurPage );
		*pfC = oCMYK.c;
		*pfM = oCMYK.m;
		*pfY = oCMYK.y;
		*pfK = oCMYK.k;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(ExecuteXObject)()
	{
		unsigned long nRet = PageExecuteXObject( m_pDocument->pCurPage, m_pCurrentXObject );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(SetExtGraphicsState2)(BSTR bsXmlOptions)
	{
		CString wsXml( bsXmlOptions );

		XmlUtils::CXmlNode oMainNode;
		oMainNode.FromXmlString( wsXml );

		if ( _T("ExtGState") == oMainNode.GetName() )
		{
			float fAlphaStroke = -1, fAlphaFill = -1;
			BlendMode eMode = BMEOF;
			int nStrokeAdjustment = -1;

			CString sValue;
			XmlUtils::CXmlNode oNode;
			if ( oMainNode.GetNode( _T("AlphaStroke"), oNode ) )
			{
				sValue = oNode.GetAttribute( _T("value"), _T("-1") );
				fAlphaStroke = (float)XmlUtils::GetDouble( sValue );
			}
			if ( oMainNode.GetNode( _T("AlphaFill"), oNode ) )
			{
				sValue = oNode.GetAttribute( _T("value"), _T("-1") );
				fAlphaFill = (float)XmlUtils::GetDouble( sValue );
			}
			if ( oMainNode.GetNode( _T("BlendMode"), oNode ) )
			{
				sValue = oNode.GetAttribute( _T("value"), _T("12") );
				eMode = (BlendMode)XmlUtils::GetInteger( sValue );
			}
			if ( oMainNode.GetNode( _T("StrokeAdjustment"), oNode ) )
			{
				sValue = oNode.GetAttribute( _T("value"), _T("-1") );
				nStrokeAdjustment = XmlUtils::GetInteger( sValue );
			}

			m_pCurrentExtGState = GetExtGState( m_pDocument, fAlphaStroke, fAlphaFill, eMode, nStrokeAdjustment );
			return PageSetExtGState( m_pDocument->pCurPage, m_pCurrentExtGState );
		}


		return S_OK;
	}
	//-----------------------------------------------------------------------------------------------------
	STDMETHOD(AppendCircle)(float fX, float fY, float fRad)
	{
		unsigned long nRet = PageCircle( m_pDocument->pCurPage, fX, fY, fRad );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(AppendEllipse)(float fX, float fY, float fXRad, float fYRad)
	{
		unsigned long nRet = PageEllipse( m_pDocument->pCurPage, fX, fY, fXRad, fYRad );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(AppendArc)(float fX, float fY, float fRad, float fAngle1, float fAngle2)
	{
		unsigned long nRet = PageArc( m_pDocument->pCurPage, fX, fY, fRad, fAngle1, fAngle2);
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(AppendEllipseArc)(float fX, float fY, float fXRad, float fYRad, float fAngle1, float fAngle2, BOOL bClockDirection = FALSE)
	{
		unsigned long nRet = PageEllipseArc2( m_pDocument->pCurPage, fX, fY, fXRad, fYRad, fAngle1, fAngle2, bClockDirection );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(TextOut)(float fXPos, float fYPos, BSTR bsText)
	{
		USES_CONVERSION;

		if ( !m_pCurrentFont )
			return S_OK;

		FontAttr pFontAttr = (FontAttr)m_pCurrentFont->pAttr;
		if ( FontDefCID != pFontAttr->pFontDef->eType )
		{
			// В данном случае все символы имеют значение от 0 до 255, т.е. на них нужен 1 байт

			wchar_t* wsText = (wchar_t*)bsText;
			char* sText = new char[wcslen(wsText) + 1];
			sText[wcslen(wsText)] = '\0';

			BOOL *pZeros = new BOOL[wcslen(wsText)];
			BOOL bCodedString = TRUE;
			for ( int nIndex = 0; nIndex < wcslen(wsText); nIndex++ )
			{
				if ( (unsigned int)bsText[nIndex] >= 256 )
				{
					bCodedString = FALSE;
				}

				if ( 0xFFFE == (unsigned int)bsText[nIndex] )
				{
					pZeros[nIndex] = 1;
				}
				else
				{
					pZeros[nIndex] = 0;
				}
			}
			if ( bCodedString )
				wcstombs( sText, wsText, wcslen(wsText) );
			else
			{
				delete []sText;
				sText = W2A( wsText );
			}

			BYTE *pString = new BYTE[wcslen(wsText)];
			for ( int nIndex = 0; nIndex < wcslen(wsText); nIndex++ )
			{
				if ( 0 == pZeros[nIndex] )
					pString[nIndex] = sText[nIndex];
				else
					pString[nIndex] = '\0';
			}
			delete []pZeros;

			unsigned long nRet = PageTextOut( m_pDocument->pCurPage, fXPos, fYPos, pString, wcslen(wsText), NULL, 0 );
			delete []pString;

			if ( bCodedString )
				delete []sText;

			if ( OK != nRet )
				return nRet;

		}
		else
		{
			// В CID шрифтах количество байт на каждый символ зависит от самого символа
			// и от кодировки CMap, заданной в шрифте.

			Encoder pEncoder = pFontAttr->pEncoder;
			if ( EncoderTypeDoubleByteStream != pEncoder->eType )
				return S_OK;

			CMapEncoderStreamAttr pEncoderAttr = (CMapEncoderStreamAttr)pEncoder->pAttr;

			wchar_t* wsText = (wchar_t*)bsText;
			int nSrcLen = wcslen( wsText );
			int nDstLen = 0;

			// Для начала рассчитаем длину выходной строки
			for ( int nIndex = 0; nIndex < nSrcLen; nIndex++ )
			{
				int nCID = (int)wsText[nIndex];
				if ( 0xFFFE == nCID )
					nCID = 0;

				int nUsedLen = 0;
				char *sBuffer = new char[4];
				CMapEncoderStreamGetCodeByCID( pEncoder, nCID, (char **)&sBuffer, &nUsedLen );
				delete []sBuffer;
				nDstLen += nUsedLen;
			}

			BYTE *pText = new BYTE[nDstLen + 1];
			pText[nDstLen] = '\0';

			for ( int nIndex = 0, nIndex2 = 0; nIndex < nSrcLen; nIndex++ )
			{
				int nCID = (int)wsText[nIndex];
				if ( 0xFFFE == nCID )
					nCID = 0;

				int nUsedLen = 0;
				char *sBuffer = new char [4];
				CMapEncoderStreamGetCodeByCID( pEncoder, nCID, (char **)&sBuffer, &nUsedLen );

				for ( int nCurIndex = 0; nCurIndex < nUsedLen; nCurIndex++ )
				{
					pText[nIndex2 + nCurIndex] = sBuffer[4 - nUsedLen + nCurIndex];
				}
				delete []sBuffer;

				nIndex2 += nUsedLen;
			}

			unsigned int *pCIDs = new unsigned int[nSrcLen];
			for ( int nIndex = 0; nIndex < nSrcLen; nIndex++ )
			{
				pCIDs[nIndex] = (unsigned int)wsText[nIndex];
			}

			unsigned long nRet = PageTextOut( m_pDocument->pCurPage, fXPos, fYPos, pText, nDstLen, pCIDs, nSrcLen );

			delete []pCIDs;
			delete []pText;

			if ( OK != nRet )
				return nRet;

		}
		return S_OK;
	}
	STDMETHOD(TextRect)(float fLeft, float fTop, float fRight, float fBottom, BSTR bsText, long nAlign, unsigned int *pnLen)
	{
		USES_CONVERSION;
		const char* sText = W2A(bsText);
		unsigned long nRet = PageTextRect( m_pDocument->pCurPage, fLeft, fTop, fRight, fBottom, sText, (ETextAlignment)nAlign, pnLen, NULL, 0 );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(SetSlideShow)(long nType, float fDispTime, float fTransTime)
	{
		unsigned long nRet = PageSetSlideShow( m_pDocument->pCurPage, (ETransitionStyle)nType, fDispTime, fTransTime );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(GetTextWidth)(BSTR bsText, float *pfResult)
	{
		USES_CONVERSION;
		const char* sText = W2A(bsText);
		*pfResult = PageTextWidth( m_pDocument->pCurPage, (BYTE *)sText, strlen(sText), NULL, 0 );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(MeasureText)(BSTR bsText, float fWidth, BOOL bWordWrap, float *pfRealWidth, long *pnLength)
	{
		USES_CONVERSION;
		const char* sText = W2A(bsText);
		BOOL bWW = ( bWordWrap == 0 ? FALSE : TRUE);
		*pnLength = PageMeasureText( m_pDocument->pCurPage, sText, NULL, 0, fWidth, bWW, pfRealWidth );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	//-----------------------------------------------------------------------------------------------------
	STDMETHOD(LoadT1FFromFile)( BSTR bsAFMFileName, BSTR bsDataFileName, BSTR *bsFontName)
	{
		CString sAFMFileName( bsAFMFileName );
		CString sDataFileName( bsDataFileName );

		wchar_t *wsData = sDataFileName.GetBuffer();
		if ( sDataFileName.GetLength() <= 0 )
			wsData = NULL;

		// Чтобы не изменять интерфейс, при перезаписи PDF, храним тип шрифта в его расширении
		short nType = 0;
		if ( wsData )
		{
			wchar_t wsExtension[MAX_PATH];
			_wsplitpath( wsData, NULL, NULL, NULL, wsExtension );

			CStringW wsExt( wsExtension );

			if ( _T(".pfb_t1cot") == wsExt )
				nType = 2;
			else if ( _T(".pfb_t1c") == wsExt )
				nType = 1;
			else 
				nType = 0;
		}

		const char* sFontName = LoadType1FontFromFile( m_pDocument, sAFMFileName.GetBuffer(), wsData, nType );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( AVS_OFFICEPDFWRITER_ERROR_FONT_EXISTS == nRet )
			ResetError( m_pDocument );
		else if ( OK != nRet )
		{
			(*bsFontName) = NULL;
			return nRet;
		}


		CString sTemp(sFontName);
		(*bsFontName) = sTemp.AllocSysString();

		return S_OK;
	}
	STDMETHOD(LoadTTFFromFile)( BSTR bsFileName, BOOL bEmbedding, BSTR bsEncodingName, BSTR *bsFontName)
	{
		CString sFileName( bsFileName );
		if ( !FileExist( sFileName ) )
			return AVS_OFFICEPDFWRITER_ERROR_FILE_OPEN_ERROR;

		USES_CONVERSION;
		const char* sEncodingName = ( NULL == bsEncodingName ? NULL : W2A( bsEncodingName ) );
		if ( NULL != sEncodingName && strlen( sEncodingName ) < 1 )
			sEncodingName = NULL;

		BOOL bEmbed = ( bEmbedding == 0 ? FALSE : TRUE);

		const char *sFontName = ( bsFontName == NULL ? LoadTTFontFromFile( m_pDocument, sFileName.GetBuffer(), bEmbed, sEncodingName ) : LoadTTFontFromFile( m_pDocument, sFileName.GetBuffer(), bEmbed, sEncodingName, "_Embedded" ) );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( AVS_OFFICEPDFWRITER_ERROR_FONT_EXISTS == nRet )
			ResetError( m_pDocument );
		else if ( OK != nRet )
		{
			(*bsFontName) = NULL;

			return nRet;
		}

		CString sTemp(sFontName);
		(*bsFontName) = sTemp.AllocSysString();

		return S_OK;
	}
	STDMETHOD(LoadTTCFromFile)( BSTR bsFileName, long nIndex, BOOL bEmbedding, BSTR *bsFontName)
	{
		CString sFileName( bsFileName );

		const char* sFontName = LoadTTFontFromFile2( m_pDocument, sFileName.GetBuffer(), (unsigned int)nIndex,  bEmbedding );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
		{
			(*bsFontName) = NULL;
			return nRet;
		}

		CString sTemp(sFontName);
		(*bsFontName) = sTemp.AllocSysString();

		return S_OK;
	}
	STDMETHOD(SetCurrentFont)( BSTR bsFontName, BSTR bsEncodingName, BOOL bNameIsUnicodeArray, BSTR bsToUnicodeName)
	{
		USES_CONVERSION;
		const char* sFontName      = W2A(bsFontName);
		const char* sEncodingName  = W2A(bsEncodingName);
		const char* sToUnicodeName = W2A(bsToUnicodeName);

		if ( UtilsStrLen( sEncodingName, LIMIT_MAX_NAME_LEN ) <= 0 )
			sEncodingName = NULL;

		if ( UtilsStrLen( sToUnicodeName, LIMIT_MAX_NAME_LEN ) <= 0 )
			sToUnicodeName = NULL;

		if ( !bNameIsUnicodeArray )
			m_pCurrentFont = GetFont( m_pDocument, sFontName, sEncodingName, sToUnicodeName );
		else
		{
			BOOL bNewEncoding;
			Encoder pCurEncoder = FindEncoderForString( m_pDocument, bsEncodingName, &bNewEncoding );

			m_pCurrentFont = GetFont( m_pDocument, sFontName, pCurEncoder->sName, sToUnicodeName );

			//CStringW oArray = (CStringW)bsEncodingName;
			//int nCount = oArray.GetLength();
			//unsigned short *pUnicode = new unsigned short[nCount];
			//for ( int nIndex = 0; nIndex < nCount; nIndex++ )
			//{
			//	pUnicode[nIndex] = (unsigned short)oArray.GetAt(nIndex);
			//}
			//m_pCurrentFont = GetFont( m_pDocument, sFontName, sEncodingName, pUnicode, nCount );
			//delete []pUnicode;
		}

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetCurrentFont)( BSTR *pbsFontName, BSTR *pbsEncodingName )
	{
		if ( !m_pCurrentFont )
		{
			*pbsFontName = NULL;
			*pbsEncodingName = NULL;
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_FONT_NOT_FOUND;
		}
		else
		{
			CString sFontName(FontGetFontName( m_pCurrentFont ));
			CString sEncodingName(((FontAttr)m_pCurrentFont->pAttr)->pEncoder->sName);

			*pbsFontName     = sFontName.AllocSysString();
			*pbsEncodingName = sEncodingName.AllocSysString();
		}

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetFontUnicodeWidth)(long nCode, long *pnUnicode)
	{
		if ( !m_pCurrentFont )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_FONT_NOT_FOUND;
		*pnUnicode = (long)FontGetUnicodeWidth( m_pCurrentFont, (unsigned int)nCode );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetFontBBox        )(float *pfLeft, float *pfBottom, float *pfRight, float *pfTop)
	{
		if ( !m_pCurrentFont )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_FONT_NOT_FOUND;
		Box oBox = { 0, 0, 0, 0};
		oBox = FontGetBBox( m_pCurrentFont );
		*pfLeft   = oBox.fLeft;
		*pfBottom = oBox.fBottom;
		*pfRight  = oBox.fRight;
		*pfTop    = oBox.fTop;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetFontAscent      )(long *pnAscent)	
	{
		if ( !m_pCurrentFont )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_FONT_NOT_FOUND;

		*pnAscent = (long)FontGetAscent( m_pCurrentFont );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetFontDescent     )(long *pnDescent)
	{
		if ( !m_pCurrentFont )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_FONT_NOT_FOUND;
		*pnDescent = (long)FontGetDescent( m_pCurrentFont );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetFontXHeight     )(long *pnXHeight)
	{
		if ( !m_pCurrentFont )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_FONT_NOT_FOUND;
		*pnXHeight = (long)FontGetXHeight( m_pCurrentFont );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetFontCapHeight   )(long *pnCapHeight)
	{
		if ( !m_pCurrentFont )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_FONT_NOT_FOUND;
		*pnCapHeight = (long)FontGetCapHeight( m_pCurrentFont );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	//-----------------------------------------------------------------------------------------------------
	STDMETHOD(SetCurrentEncoder)( BSTR bsEncodingName )
	{
		USES_CONVERSION;
		const char *sEncodingName = W2A(bsEncodingName);

		unsigned long nRet = DocSetCurrentEncoder( m_pDocument, sEncodingName);
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetCurrentEncoder)( BSTR *pbsEncodingName )
	{
		Encoder pCurEncoder = DocGetCurrentEncoder( m_pDocument );
		if ( !pCurEncoder )
			*pbsEncodingName = NULL;
		else
		{
			CString sEncodingName(pCurEncoder->sName);

			*pbsEncodingName = sEncodingName.AllocSysString();
		}

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	STDMETHOD(GetEncoderUnicode)    (long nCode, long *pnUnicode)
	{
		Encoder pCurEncoder = DocGetCurrentEncoder( m_pDocument );
		*pnUnicode = EncoderGetUnicode( pCurEncoder, nCode );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetEncoderByteType)   (BSTR bsText, long nIndex, long *pnByteType)
	{
		USES_CONVERSION;
		const char *sText = W2A(bsText);
		Encoder pCurEncoder = DocGetCurrentEncoder( m_pDocument);
		*pnByteType = (long)EncoderGetByteType( pCurEncoder, sText, nIndex );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetEncoderType)       (long *pnEncoderType)
	{
		Encoder pCurEncoder = DocGetCurrentEncoder( m_pDocument);
		*pnEncoderType = (long)EncoderGetType( pCurEncoder );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetEncoderWritingMode)(long *pnWritingMode)
	{
		Encoder pCurEncoder = DocGetCurrentEncoder( m_pDocument);
		*pnWritingMode = (long)EncoderGetWritingMode( pCurEncoder );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	//-----------------------------------------------------------------------------------------------------
	STDMETHOD(CreateNewDestination)()
	{
		if ( !m_pDestList )
			m_pDestList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		m_pCurrentDestination = PageCreateDestination( m_pDocument->pCurPage );
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pDestList, m_pCurrentDestination ) ) )
			return nRet;
		return S_OK;
	}
	STDMETHOD(DestSetXYZ)(float fLeft, float fTop, float fZoom)
	{
		unsigned long nRet = DestinationSetXYZ( m_pCurrentDestination, fLeft, fTop, fZoom );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(DestSetFit)()
	{
		unsigned long nRet = DestinationSetFit( m_pCurrentDestination );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(DestSetFitH)(float fTop)
	{
		unsigned long nRet = DestinationSetFitH( m_pCurrentDestination, fTop );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(DestSetFitV)(float fLeft)
	{
		unsigned long nRet = DestinationSetFitV( m_pCurrentDestination, fLeft );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(DestSetFitR) (float fLeft, float fBottom, float fRight, float fTop)
	{
		unsigned long nRet = DestinationSetFitR( m_pCurrentDestination, fLeft, fBottom, fRight, fTop );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(DestSetFitB)()
	{
		unsigned long nRet = DestinationSetFitB( m_pCurrentDestination );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(DestSetFitBH)(float fTop)
	{
		unsigned long nRet = DestinationSetFitBH( m_pCurrentDestination, fTop );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(DestSetFitBV)(float fLeft)
	{
		unsigned long nRet = DestinationSetFitBV( m_pCurrentDestination, fLeft );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(SetCurrentDest)(long nIndex)
	{
		Destination pTemp = (Destination)ListItemAt( m_pDestList, nIndex );
		m_pCurrentDestination = pTemp;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	STDMETHOD(GetCurrentDestIndex)(long *pnIndex)
	{
		if ( !m_pCurrentDestination || !m_pDestList )
		{
			*pnIndex = -1;
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_DESTINATION_NOT_FOUND;
		}
		else
			*pnIndex = ListFind( m_pDestList, m_pCurrentDestination );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	//------------------------------------------------------------------------------------------------
	STDMETHOD(CreateTextAnnot)(float fLeft, float fBottom, float fRight, float fTop, BSTR bsText, BSTR bsEncoder)
	{
		USES_CONVERSION;
		const char* sText = W2A(bsText);
		const char* sEncoder = W2A(bsEncoder);

		Encoder pEncoder = NULL;
		if ( UtilsStrLen( sEncoder, LIMIT_MAX_NAME_LEN ) > 0 )
			pEncoder = GetEncoder( m_pDocument, sEncoder );

		TRect oRect = { fLeft, fBottom, fRight, fTop};

		if ( !m_pAnnotList )
			m_pAnnotList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		m_pCurrentAnnotation = PageCreateTextAnnot( m_pDocument->pCurPage, oRect, sText, pEncoder);
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pAnnotList, m_pCurrentAnnotation) ) )
			return nRet;

		return S_OK;
	}
	STDMETHOD(CreateLinkAnnot)(float fLeft, float fBottom, float fRight, float fTop)
	{
		unsigned long nRet = OK;

		if ( !m_pAnnotList )
		{
			m_pAnnotList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		TRect oRect = { fLeft, fBottom, fRight, fTop};
		if ( !m_pCurrentDestination )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_DESTINATION_NOT_FOUND;

		m_pCurrentAnnotation = PageCreateLinkAnnot( m_pDocument->pCurPage, oRect, m_pCurrentDestination );
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pAnnotList, m_pCurrentAnnotation) ) )
			return nRet;

		return S_OK;
	}
	STDMETHOD(CreateUriLinkAnnot)(float fLeft, float fBottom, float fRight, float fTop, BSTR bsUrl)
	{
		unsigned long nRet = OK;
		if ( !m_pAnnotList )
		{
			m_pAnnotList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		USES_CONVERSION;
		const char* sUrl = W2A(bsUrl);
		TRect oRect = { fLeft, fBottom, fRight, fTop};

		m_pCurrentAnnotation = PageCreateUriLinkAnnot( m_pDocument->pCurPage, oRect, sUrl );
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pAnnotList, m_pCurrentAnnotation) ) )
			return nRet;

		return S_OK;
	}
	STDMETHOD(ArbAnnotationSetBorderStyle)(long nSubtype, float fWidth, long nDashOn, long nDashOff, long nDashPhase)
	{
		unsigned long nRet = AnnotationSetBorderStyle( m_pCurrentAnnotation, (BSSubtype)nSubtype, fWidth, (unsigned short)nDashOn, (unsigned short)nDashOff, (unsigned short)nDashPhase );
		if( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(LinkAnnotationSetBorderStyle)(float fWidth, long nDashOn, long nDashOff )
	{
		unsigned long nRet = LinkAnnotSetBorderStyle( m_pCurrentAnnotation, fWidth, (unsigned short)nDashOn, (unsigned short)nDashOff );
		if( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(LinkAnnotationSetHighlightMode)(long nMode)
	{
		unsigned long nRet = LinkAnnotSetHighlightMode( m_pCurrentAnnotation, (AnnotHighlightMode)nMode );
		if( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(TextAnnotationSetIcon)(long nIcon)
	{
		unsigned long nRet = TextAnnotSetIcon( m_pCurrentAnnotation, (AnnotIcon)nIcon );
		if( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(TextAnnotationSetOpened)(BOOL bOpened)
	{
		unsigned long nRet = TextAnnotSetOpened( m_pCurrentAnnotation, bOpened );
		if( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(SetCurrentAnnot)(long nIndex)
	{
		Annotation pTemp = (Annotation)ListItemAt( m_pAnnotList, nIndex );
		m_pCurrentAnnotation = pTemp;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	STDMETHOD(GetCurrentAnnotIndex)(long *pnIndex)
	{
		if ( !m_pCurrentAnnotation || !m_pAnnotList )
		{
			*pnIndex = -1;
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_ANNOTATION_NOT_FOUND;
		}
		else
			*pnIndex = ListFind( m_pAnnotList, m_pCurrentAnnotation );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(MakeAnnotationFromXml)(BSTR bsXML)
	{
		HRESULT hRes = S_OK;

		// Запоминаем текущую страницу
		long nStartPageIndex = 0;
		if ( FAILED( hRes = GetCurrentPageIndex( &nStartPageIndex ) ) )
			return hRes;

		// Считываем количество страниц (для контроля)
		long nPagesCount = 0;
		if ( FAILED( hRes = GetPagesCount( &nPagesCount ) ) )
			return hRes;

		float fPageHeight = 0;
		float fPageWidth  = 0;

		if ( FAILED( hRes = GetWidth( &fPageWidth ) ) )
			return hRes;
		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;


		XmlUtils::CXmlNode oLinker;
		oLinker.FromXmlString( CString( bsXML ) );

		if ( -1 != oLinker.GetName().Find( _T("linker") ) )
		{
			XmlUtils::CXmlNodes oLinks;
			oLinker.GetNodes( _T("link"), oLinks );

			for ( int nIndex = 0; nIndex < oLinks.GetCount(); nIndex++ )
			{
				XmlUtils::CXmlNode oLink;
				oLinks.GetAt( nIndex, oLink );

				XmlUtils::CXmlNode oSource;
				XmlUtils::CXmlNode oTarget;

				float fSrcX = 0;
				float fSrcY = 0;
				float fSrcH = 0;
				float fSrcW = 0;
				int nSrcPageIndex = nStartPageIndex;

				if ( oLink.GetNode( _T("source"), oSource ) )
				{
					CString sValue;

					sValue = oSource.GetAttribute( _T("page"), _T("0") );
					nSrcPageIndex = max( 0, min( nPagesCount - 1, _wtoi( sValue.GetBuffer() ) ) );

					sValue = oSource.GetAttribute( _T("x"), _T("0") );
					fSrcX = (float)_wtof( sValue.GetBuffer() );

					sValue = oSource.GetAttribute( _T("y"), _T("0") );
					fSrcY = (float)_wtof( sValue.GetBuffer() );

					sValue = oSource.GetAttribute( _T("width"), _T("0") );
					fSrcW = (float)_wtof( sValue.GetBuffer() );

					sValue = oSource.GetAttribute( _T("height"), _T("0") );
					fSrcH = (float)_wtof( sValue.GetBuffer() );
				}

				float fDstX = 0;
				float fDstY = 0;
				float fDstH = 0;
				float fDstW = 0;
				int nDstPageIndex = nStartPageIndex;
				CString sURL = _T("");
				BOOL bLinkURL = FALSE;

				if ( oLink.GetNode( _T("target"), oTarget ) )
				{
					CString sValue;

					sValue = oTarget.GetAttribute( _T("url"), _T("") );
					if ( sValue.GetLength() > 0 )
					{
						sURL = sValue;
						bLinkURL = TRUE;
					}
					else
					{
						sValue = oTarget.GetAttribute( _T("page"), _T("0") );
						nDstPageIndex = max( 0, min( nPagesCount - 1, _wtoi( sValue.GetBuffer() ) ) );

						sValue = oTarget.GetAttribute( _T("x"), _T("0") );
						fDstX = (float)_wtof( sValue.GetBuffer() );

						sValue = oTarget.GetAttribute( _T("y"), _T("0") );
						fDstY = (float)_wtof( sValue.GetBuffer() );

						sValue = oTarget.GetAttribute( _T("width"), _T("0") );
						fDstW = (float)_wtof( sValue.GetBuffer() );

						sValue = oTarget.GetAttribute( _T("height"), _T("0") );
						fDstH = (float)_wtof( sValue.GetBuffer() );
					}
				}

				if ( bLinkURL )
				{
					if ( FAILED( hRes = SetCurrentPage( nSrcPageIndex ) ) )
						return hRes;

					if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
						return hRes;

					BSTR bsURL = sURL.AllocSysString();
					if ( FAILED( hRes = CreateUriLinkAnnot( fSrcX, fPageHeight - ( fSrcY + fSrcH ), fSrcX + fSrcW, fPageHeight - fSrcY, bsURL  ) )  )
						return hRes;
					::SysFreeString( bsURL );

					if ( FAILED( hRes  = ArbAnnotationSetBorderStyle( 0, 0, 0, 0, 0 ) ) )
						return hRes;
				}
				else
				{
					// Создаем объект Destination
					if ( FAILED( hRes = SetCurrentPage( nDstPageIndex ) ) )
						return hRes;

					if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
						return hRes;

					if ( FAILED( hRes = CreateNewDestination() ) )
						return hRes;

					if ( FAILED( hRes = DestSetXYZ( 0, fPageHeight - fDstY, 0  ) ) )
						return hRes;

					// Создаем ссылку на текущий объект Destionation
					if ( FAILED( hRes = SetCurrentPage( nSrcPageIndex ) ) )
						return hRes;

					if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
						return hRes;

					if ( FAILED( hRes = CreateLinkAnnot( fSrcX, fPageHeight - ( fSrcY + fSrcH ), fSrcX + fSrcW, fPageHeight - fSrcY ) ) )
						return hRes;

					if ( FAILED( hRes  = ArbAnnotationSetBorderStyle( 0, 0, 0, 0, 0 ) ) )
						return hRes;

				}
			}
		}

		// Восстанавливаем текущую страницу
		if ( FAILED( hRes = SetCurrentPage( nStartPageIndex ) ) )
			return hRes;

		return S_OK;
	}
	//------------------------------------------------------------------------------------------------
	STDMETHOD(CreateNewOutline)(long nParentIndex, BSTR bsTitle, BSTR bsEncoder)
	{
		unsigned long nRet = OK;

		USES_CONVERSION;
		const char* sTitle = W2A(bsTitle);
		const char* sEncoder = W2A(bsEncoder);

		Encoder pEncoder = NULL;
		if ( UtilsStrLen( sEncoder, LIMIT_MAX_NAME_LEN ) > 0 )
		{
			pEncoder = GetEncoder( m_pDocument, sEncoder );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		if ( !m_pOutlineList )
		{
			m_pOutlineList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		Outline pRoot = NULL;
		if ( nParentIndex < m_pOutlineList->nCount && nParentIndex >= 0 )
		{
			pRoot = (Outline)ListItemAt( m_pOutlineList, nParentIndex );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		m_pCurrentOutline = CreateOutline( m_pDocument, pRoot, sTitle, pEncoder );
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pOutlineList, m_pCurrentOutline ) ) )
			return nRet;

		return S_OK;
	}
	STDMETHOD(OutlineSetCurrentDestination)()
	{
		unsigned long nRet = OutlineSetDestination( m_pCurrentOutline, m_pCurrentDestination );
		if( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(SetOutlineOpened)(BOOL bOpened)
	{
		unsigned long nRet = OutlineSetOpened( m_pCurrentOutline, bOpened );
		if( OK != nRet )
			return nRet;
		return S_OK;
	}

	STDMETHOD(SetCurrentOutline)(long nIndex)
	{
		Outline pTemp = (Outline)ListItemAt( m_pOutlineList, nIndex );
		m_pCurrentOutline = pTemp;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	STDMETHOD(GetCurrentOutlineIndex)(long *pnIndex)
	{
		if ( !m_pCurrentOutline || !m_pOutlineList )
		{
			*pnIndex = -1;
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_OUTLINE_NOT_FOUND;
		}
		else
			*pnIndex = ListFind( m_pOutlineList, m_pCurrentOutline );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(MakeOutlineFromXml)(BSTR bsXML)
	{
		HRESULT hRes = S_OK;
		// текущая страница изменится, поэтому ее запоминаем и восстанавливаем
		long nCurPageIndex = 0;

		if ( FAILED ( hRes = GetCurrentPageIndex( &nCurPageIndex ) ) )
			return hRes;
		CString sXml(bsXML);

		XmlUtils::CXmlReader oReader;				
		oReader.SetXmlString(sXml);
		if ( -1 != oReader.ReadNodeName().Find( _T("PDF-Chapters") ) || -1 != oReader.ReadNodeName().Find( _T("Outline") ) )
			if ( FAILED ( hRes = ReadOutlineChilds( oReader.ReadNodeXml(), -1 ) ) ) 
				return hRes;

		if ( FAILED ( hRes = SetCurrentPage( nCurPageIndex ) ) )
			return hRes;

		return S_OK;
	}
	//------------------------------------------------------------------------------------------------
	STDMETHOD(LoadJpegFromFile)(BSTR bsFileName)
	{
		unsigned long nRet = OK;
		CString sFileName( bsFileName );

		if ( !m_pXObjectList )
		{
			m_pXObjectList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		m_pCurrentXObject = LoadJpegImageFromFile( m_pDocument, sFileName.GetBuffer() );

		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pXObjectList, m_pCurrentXObject) ) ) 
			return nRet;

		return S_OK;
	}
	STDMETHOD(LoadJpxFromFile)(BSTR bsFileName, long nFlag)
	{
		unsigned long nRet = OK;

		CString sFileName( bsFileName );

		if ( !m_pXObjectList )
		{
			m_pXObjectList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		// Параметр nFlag соответсвуют значению SMaskInData в записи о загружаемом Jpx
		// nFlag: 0, даже если в Jpx есть прозрачность, игнорируем ее
		//        1, наличие в Jpx SMask
		//        2, наличие в Jpx отдельных каналов с прозрачностью

		long nOpacityFlag = max( 0, min ( 2, nFlag ));

		m_pCurrentXObject = LoadJpxImageFromFile( m_pDocument, sFileName.GetBuffer(), nOpacityFlag );
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pXObjectList, m_pCurrentXObject) ) ) 
			return nRet;

		return S_OK;
	}
	STDMETHOD(LoadImageFromFile)(BSTR bsFileName,     long nWidth, long nHeight, long nColorSpace)
	{
		unsigned long nRet = OK;

		CString sFileName( bsFileName );

		if ( !m_pXObjectList )
		{
			m_pXObjectList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		m_pCurrentXObject = LoadRawImageFromFile( m_pDocument, sFileName.GetBuffer(), nWidth, nHeight, (ColorSpace)nColorSpace );
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pXObjectList, m_pCurrentXObject) ) ) 
			return nRet;

		return S_OK;
	}
	STDMETHOD(LoadImageFromArray)(SAFEARRAY **ppImage, long nWidth, long nHeight, long nColorSpace, long nBitsPerComponent)
	{
		unsigned long nRet = OK;

		BYTE *pArray;
		if ( nHeight && nWidth )
		{
			// check for valid pixel array size
			if ( 1 != SafeArrayGetDim(*ppImage) )
				return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;

			VARTYPE vType;
			// check for valid array element type
			if ( FAILED(SafeArrayGetVartype(*ppImage, &vType)) || VT_UI1 != vType )
				return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;

			pArray = (BYTE*)(*ppImage)->pvData;
		}
		if ( !m_pXObjectList )
		{
			m_pXObjectList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
				return nRet;
		}

		m_pCurrentXObject = LoadRawImageFromMem( m_pDocument, pArray, nWidth, nHeight, (ColorSpace)nColorSpace, nBitsPerComponent );
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ListAdd( m_pXObjectList, m_pCurrentXObject) ) ) 
			return nRet;

		return S_OK;
	}
	STDMETHOD(LoadImageFromInterface)(IUnknown **pInterface, BOOL bAlpha = FALSE)
	{
		// check for valid input parameters
		if (!pInterface || !*pInterface)
			return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;

		int nWidth = 0;
		int nHeight = 0;
		BYTE* pPixels = 0;

#ifdef BUILD_CONFIG_OPENSOURCE_VERSION
		MediaCore::IAVSUncompressedVideoFrame* pMediaData = NULL;
		if ( NULL == pInterface || NULL == (*pInterface) )
			return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;

		(*pInterface)->QueryInterface(MediaCore::IID_IAVSUncompressedVideoFrame, (void**)(&pMediaData));
		if ( NULL == pMediaData )
			return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;

		LONG lWidth = 0;
		LONG lHeight = 0;
#else
		MediaCore::IAVSUncompressedVideoFrame* pMediaData = NULL;
		if ( NULL == pInterface || NULL == (*pInterface) )
			return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;

		MediaCore::IAVSUncompressedVideoFrame* pMediaDataIn = NULL;
		(*pInterface)->QueryInterface(MediaCore::IID_IAVSUncompressedVideoFrame, (void**)(&pMediaDataIn));
		if ( NULL == pMediaDataIn )
			return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;

		LONG lWidth = 0; pMediaDataIn->get_Width(&lWidth);
		LONG lHeight = 0; pMediaDataIn->get_Height(&lHeight);
		LONG lAspectX = 0; pMediaDataIn->get_AspectRatioX(&lAspectX);
		LONG lAspectY = 0; pMediaDataIn->get_AspectRatioY(&lAspectY);

		// преобразуем к BGR формату
		if (TRUE)
		{
			MediaFormat::IAVSVideoFormat* pMediaFormat = NULL;
			CoCreateInstance(MediaFormat::CLSID_CAVSVideoFormat, NULL, CLSCTX_ALL, MediaFormat::IID_IAVSVideoFormat, (void**)(&pMediaFormat));
			if (NULL == pMediaFormat)
			{
				pMediaDataIn->Release();
				return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;
			}

			MediaCore::IAVSVideoFrameTransform* pMediaTransform = NULL;
			CoCreateInstance(MediaCore::CLSID_CAVSVideoFrameTransform, NULL, CLSCTX_ALL, MediaCore::IID_IAVSVideoFrameTransform, (void**)(&pMediaTransform));
			if (NULL == pMediaTransform)
			{
				pMediaDataIn->Release();
				pMediaFormat->Release();
				return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;
			}

			pMediaFormat->SetDefaultProperties();
			pMediaFormat->Width = lWidth;
			pMediaFormat->Height = lHeight;
			pMediaFormat->AspectRatioX = lAspectX;
			pMediaFormat->AspectRatioY = lAspectY;
			pMediaFormat->ColorSpace = 1<< 6;//CSP_BGRA

			pMediaTransform->SetVideoFormat(pMediaFormat);

			IUnknown *pTransformResult = NULL;
			pMediaTransform->raw_TransformFrame(pMediaDataIn, &pTransformResult);
			if (NULL != pTransformResult)
			{
				if ((*pInterface)==pTransformResult)
				{
					MediaCore::IAVSMediaData *pData = NULL;
					pTransformResult->QueryInterface(MediaCore::IID_IAVSMediaData, (void**)(&pData));
					if (NULL!=pData)
					{
						MediaCore::IAVSMediaData *pmdOutFrame = NULL;
						pData->raw_CreateDuplicate(2, &pmdOutFrame);
						pData->Release();
						if (NULL!=pmdOutFrame)
						{
							pmdOutFrame->QueryInterface(MediaCore::IID_IAVSUncompressedVideoFrame, (void**)(&pMediaData));
							pmdOutFrame->Release();
						}
					}					
				}
				else
				{
					pTransformResult->QueryInterface(MediaCore::IID_IAVSUncompressedVideoFrame, (void**)(&pMediaData));
				}
				pTransformResult->Release();
			}

			pMediaFormat->Release();
			pMediaTransform->Release();
		}

		pMediaDataIn->Release();
#endif

		if (NULL == pMediaData)
			return AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE;

		// 

		lWidth = 0; pMediaData->get_Width(&lWidth);
		lHeight = 0; pMediaData->get_Height(&lHeight);
		LONG lColorSpace = 0; pMediaData->get_ColorSpace(&lColorSpace);
		LONG lBufferSize = 0; pMediaData->get_BufferSize(&lBufferSize);
		BYTE* pSourceBuffer = 0; pMediaData->get_Buffer(&pSourceBuffer);

		BYTE* pImage = new BYTE[ lWidth * lHeight * 3];
		BYTE* pAlpha = new BYTE[ lWidth * lHeight ];
		BYTE* pImagePointer = pImage; 
		BYTE* pAlphaPointer = pAlpha;
		BOOL  bHaveAlpha = FALSE;

		// Разделяем саму картинку и альфа-канал. Одновременно с этим, посчитаем количество цветов в картинке.
		CSimpleArray<TRGBColor> arrColors;
		for ( int nIndex = 0; nIndex < lWidth * lHeight; nIndex++, pImagePointer += 3, pSourceBuffer += 4, pAlphaPointer++ )
		{
			pImagePointer[ 0 ] = pSourceBuffer[ 2 ];
			pImagePointer[ 1 ] = pSourceBuffer[ 1 ];
			pImagePointer[ 2 ] = pSourceBuffer[ 0 ];

			// Картинки с количеством цветом > 256 считаем полноцветными. (формат RGB)
			if ( arrColors.GetSize() <= 256 )
			{
				TRGBColor oColor; 
				oColor.r = pImagePointer[ 0 ];
				oColor.g = pImagePointer[ 1 ];
				oColor.b = pImagePointer[ 2 ];
				if ( -1 == arrColors.Find( oColor ) )
					arrColors.Add( oColor );
			}

			pAlphaPointer[ 0 ] = pSourceBuffer[ 3 ];
			if ( 255 != pAlphaPointer[0] )
				bHaveAlpha = TRUE;
		}
		pMediaData->Release();

		TRGBColor oBlack = {   0,   0,   0 };
		TRGBColor oWhite = { 255, 255, 255 };

		BOOL bBnW = FALSE; // Черно-белая картинка
		if ( ( ( arrColors.GetSize() == 2 && ( ( arrColors.GetData()[0] == oBlack && arrColors.GetData()[1] == oWhite ) || ( arrColors.GetData()[1] == oBlack && arrColors.GetData()[0] == oWhite ) ) ) ||
			( arrColors.GetSize() == 1 && ( arrColors.GetData()[0] == oBlack || arrColors.GetData()[1] == oWhite ) ) ) && !bHaveAlpha )
			bBnW = TRUE;

		unsigned long nRet = OK;
		if ( !m_pXObjectList )
		{
			m_pXObjectList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );
			if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			{
				delete[] pAlpha;
				delete[] pImage;
				return nRet;
			}
		}

		// Проверим нужен ли нам альфа-канал
		if ( bAlpha )
		{
			bool bFakeAlpha = true;
			for ( int nIndex = 0; nIndex < lWidth * lHeight; nIndex++ )
			{
				if ( 255 != pAlpha[nIndex] )
				{
					bFakeAlpha = false;
					break;
				}
			}

			if ( bFakeAlpha )
				bAlpha = FALSE;
		}

		// Проверяем, возможно, такая картинка уже есть в нашем файле
		XObject pOldImage = NULL;

		CRC32 oCRC;
		oCRC.ProcessCRC( pImage, lWidth * lHeight * 3 );
		unsigned int unImageCheckSum = oCRC.m_nCRC32;
		oCRC.Init();
		oCRC.ProcessCRC( pAlpha, lWidth * lHeight );
		unsigned int unAlphaCheckSum = oCRC.m_nCRC32;

		for ( int nIndex = 0; nIndex < m_pXObjectList->nCount; ++nIndex )
		{
			XObject pCurImage = (XObject)ListItemAt( m_pXObjectList, nIndex );
			if ( !ImageValidate( pCurImage ) )
				continue;

			unsigned int unHeight = ImageGetHeight( pCurImage );
			unsigned int unWidth  = ImageGetWidth( pCurImage );
			unsigned int unBPC    = ImageGetBitsPerComponent( pCurImage );
			EColorSpace  eCS      = ImageGetColorSpace2( pCurImage );

			if ( unHeight != lHeight || unWidth != lWidth || CSDeviceRGB != eCS || 8 != unBPC )
				continue;

			if ( !StreamValidate( pCurImage->pStream ) )
				continue;

			//unsigned int unSize = StreamSize( pCurImage->pStream );
			//if ( unSize != lWidth * lHeight * 3 )
			//	continue;

			if ( bAlpha && pAlpha  )
			{
				XObject pSMask = ImageGetSMask( pCurImage );

				if ( !ImageValidate( pSMask ) )
					continue;

				unsigned int unMaskHeight = ImageGetHeight( pSMask );
				unsigned int unMaskWidth  = ImageGetWidth( pSMask );
				unsigned int unMaskBPC    = ImageGetBitsPerComponent( pSMask );
				EColorSpace  eMaskCS      = ImageGetColorSpace2( pSMask );

				if ( unMaskHeight != lHeight || unMaskWidth != lWidth || CSDeviceGray != eMaskCS || 8 != unMaskBPC )
					continue;

				if ( !StreamValidate( pSMask->pStream ) )
					continue;

				//unsigned int unMaskSize = StreamSize( pSMask->pStream );
				//if ( unMaskSize != lWidth * lHeight )
				//	continue;

				if ( unAlphaCheckSum != pSMask->pStream->nCheckSum )
					continue;

				//BYTE *pAlphaBuffer = new BYTE[unMaskSize];
				//StreamRead( pSMask->pStream, pAlphaBuffer, &unMaskSize );
				//StreamSeek( pSMask->pStream, 0, SeekSet );


				//if ( 0 != ::memcmp( pAlphaBuffer, pAlpha, unMaskSize ) )
				//{
				//	delete []pAlphaBuffer;
				//	continue;
				//}

				//delete []pAlphaBuffer;


			}

			if ( unImageCheckSum != pCurImage->pStream->nCheckSum )
				continue;

			//BYTE *pBuffer = new BYTE[unSize];
			//StreamRead( pCurImage->pStream, pBuffer, &unSize );
			//StreamSeek( pCurImage->pStream, 0, SeekSet );


			//if ( 0 != ::memcmp( pBuffer, pImage, unSize ) )
			//{
			//	delete []pBuffer;
			//	continue;
			//}

			//delete []pBuffer;

			// Если мы дошли до этого места, значит картинки полностью совпадают и нет смысла загружать картинку заново

			pOldImage = pCurImage;
			break;
		}


		//
		if ( pOldImage )
			m_pCurrentXObject = pOldImage;
		else if ( bBnW )
			m_pCurrentXObject = LoadJbig2ImageFromInt( m_pDocument, pInterface, lWidth, lHeight, unImageCheckSum, bAlpha, pAlpha, unAlphaCheckSum);
		else
		{
			//m_pCurrentXObject = LoadRawImageFromMem ( m_pDocument, pImage, lWidth, lHeight, CSDeviceRGB, 8, bAlpha, pAlpha );
			m_pCurrentXObject = LoadJpegImageFromMem( m_pDocument, pImage, lWidth, lHeight, unImageCheckSum, bAlpha, pAlpha, unAlphaCheckSum );
			//m_pCurrentXObject = LoadJpxImageFromMem ( m_pDocument, pImage, lWidth, lHeight, unImageCheckSum, bAlpha, pAlpha, unAlphaCheckSum );
		}

		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
		{
			delete[] pAlpha;
			delete[] pImage;
			return nRet;
		}

		if ( !pOldImage )
		{
			if ( OK != ( nRet = ListAdd( m_pXObjectList, m_pCurrentXObject) ) ) 
			{
				delete[] pAlpha;
				delete[] pImage;
				return nRet;
			}
		}

		delete[] pAlpha;
		delete[]pImage;
		return S_OK;
	}
	STDMETHOD(DrawCurrentImage)(float fX, float fY, float fWidth, float fHeight)
	{
		if ( !m_pCurrentXObject )
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_IMAGE_NOT_FOUND;
		unsigned long nRet = PageDrawImage( m_pDocument->pCurPage, m_pCurrentXObject, fX, fY, fWidth, fHeight );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	STDMETHOD(GetImageBitsPerComponent)(long *pnBitsPerComponent)
	{
		*pnBitsPerComponent = ImageGetBitsPerComponent( m_pCurrentXObject );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetImageColorSpace)(long *pnColorSpace)
	{
		EColorSpace eCS = ImageGetColorSpace2( m_pCurrentXObject );
		*pnColorSpace = (long)eCS;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetImageHeight)(long *pnHeight)
	{
		*pnHeight = ImageGetHeight( m_pCurrentXObject );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(GetImageWidth)(long *pnWidth)
	{
		*pnWidth = ImageGetWidth( m_pCurrentXObject );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetImageColorMask)(long nRMin, long nRMax, long nGMin, long nGMax, long nBMin, long nBMax)
	{
		unsigned long nRet = ImageSetColorMask( m_pCurrentXObject, nRMin, nRMax, nGMin, nGMax, nBMin, nBMax );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(SetImageMaskImage)(long nMaskImageIndex)
	{
		unsigned long nRet = OK;
		XObject pTemp = (XObject)ListItemAt( m_pXObjectList, nMaskImageIndex );
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
			return nRet;

		if ( OK != ( nRet = ImageSetMaskImage( m_pCurrentXObject, pTemp ) ) )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetCurrentImage)(long nIndex)
	{
		XObject pTemp = (XObject)ListItemAt( m_pXObjectList, nIndex );
		m_pCurrentXObject = pTemp;

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	STDMETHOD(GetCurrentImageIndex)(long *pnIndex)
	{
		if ( !m_pCurrentXObject || !m_pXObjectList )
		{
			*pnIndex = -1;
			return AVS_OFFICEPDFWRITER_ERROR_CURRENT_IMAGE_NOT_FOUND;
		}
		else
			*pnIndex = ListFind( m_pXObjectList, m_pCurrentXObject );

		// проверяем не появилась ли ошибка
		unsigned long nRet = ErrorGetCode( &m_pDocument->oError );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	//------------------------------------------------------------------------------------------------
	STDMETHOD(SetEncryptOn)()
	{
		unsigned long nRet = DocSetEncryptOn( m_pDocument );
		if ( OK != nRet )
			return nRet;
		return S_OK;
	}
	STDMETHOD(SetPDFPassword)(BSTR bsOwnerPassword, BSTR bsUserPassword)
	{
		USES_CONVERSION;
		const char* sOwnerPassword = W2A( bsOwnerPassword );
		const char* sUserPassword  = W2A( bsUserPassword );

		if ( UtilsStrLen(sOwnerPassword, LIMIT_MAX_NAME_LEN ) <= 0 )
			sOwnerPassword = NULL;

		if ( UtilsStrLen(sUserPassword, LIMIT_MAX_NAME_LEN ) <= 0 )
			sUserPassword = NULL;

		// Паролей нет, ничего не делаем
		if ( NULL == sOwnerPassword && NULL == sUserPassword )
			return S_OK;

		// Если пароли одинаковые, тогда устанавливаем только пользовательский пароль
		if ( sOwnerPassword && sUserPassword && 0 == UtilsStrCmp( sOwnerPassword, sUserPassword ) )
			sUserPassword = NULL;

		unsigned long nRet = SetPassword( m_pDocument, sOwnerPassword, sUserPassword );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetPDFPermission)(long nPermission)
	{
		unsigned long nRet = SetPermission( m_pDocument, (unsigned long)nPermission);
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetPDFEncryptionMode)(long nMode, long nKeyLen)
	{
		unsigned long nRet = SetEncryptionMode( m_pDocument, (EEncryptMode)nMode, nKeyLen );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetEncryptOff)()
	{
		unsigned long nRet = DocSetEncryptOff( m_pDocument );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}

	//------------------------------------------------------------------------------------------------
	STDMETHOD(GetInfoItem)(long nDataType, BSTR *pbsItem)
	{
		unsigned long nRet = OK;
		const char* sItem = GetInfoAttr( m_pDocument, (InfoType)nDataType);
		if ( OK != ( nRet = ErrorGetCode( &m_pDocument->oError ) ) )
		{
			*pbsItem = NULL;
			return nRet;
		}

		CString sTemp(sItem);
		*pbsItem = sTemp.AllocSysString();
		return S_OK;
	}
	STDMETHOD(SetInfoItem)(long nDataType, BSTR bsData)
	{
		USES_CONVERSION;
		const char *sData = W2A(bsData);
		unsigned long nRet = SetInfoAttr( m_pDocument, (InfoType)nDataType, sData );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	STDMETHOD(SetInfoDateItem)(long nType, long nYear, long nMonth, long nDay, long nHour, long nMinutes, long nSeconds, long nInd, long nOffHour, long nOffMinutes)
	{
		TDate oDate;
		oDate.nYear = nYear;
		oDate.nMinutes = nMinutes;
		oDate.nMonth = nMonth;
		oDate.nDay = nDay;
		oDate.nHour = nHour;
		oDate.nSeconds = nSeconds;
		oDate.nInd = nInd;
		oDate.nOffHour = nOffHour;
		oDate.nOffMinutes = nOffMinutes;

		unsigned long nRet = SetInfoDateAttr( m_pDocument, (InfoType)nType, oDate );
		if ( OK != nRet )
			return nRet;

		return S_OK;
	}
	//------------------------------------------------------------------------------------------------
	STDMETHOD(SetAdditionalParam)(BSTR ParamName, VARIANT	ParamValue)
	{
		CString sParamName; sParamName = ParamName;

		if ( _T("TempDirectory") == sParamName && VT_BSTR == ParamValue.vt )
		{
			m_wsTempDir = CString( ParamValue.bstrVal );
			DocSetTempDir( m_pDocument, m_wsTempDir.GetBuffer() );
		}
		else if ( _T("WhiteBackImage") == sParamName && VT_BOOL == ParamValue.vt )
		{
			m_bIsWhiteBackImage = (ParamValue.boolVal == VARIANT_TRUE) ? TRUE : FALSE;
		}
		else if ( _T("BaseTransform") == sParamName && VT_ARRAY == ParamValue.vt )
		{
			// check for valid pixel array size
			if ( 1 != SafeArrayGetDim(*ParamValue.pparray) )
				return S_FALSE;

			VARTYPE vType;
			// check for valid array element type
			if ( FAILED(SafeArrayGetVartype(*ParamValue.pparray, &vType)) || VT_R8 != vType )
				return S_FALSE;

			double* pTemp = (double*)(*ParamValue.pparray)->pvData;
			m_oBaseTransform.fA = pTemp[0]; m_oBaseTransform.fB = pTemp[1];
			m_oBaseTransform.fC = pTemp[2]; m_oBaseTransform.fD = pTemp[3];
			m_oBaseTransform.fE = pTemp[4]; m_oBaseTransform.fF = pTemp[5];
		}
		else if ( _T("BrushFillBoundsEnable") == sParamName && VT_BOOL == ParamValue.vt )
		{
			m_bUseTextureRect = (ParamValue.boolVal == VARIANT_TRUE) ? TRUE : FALSE;
		}
		// NOTE: пока градиенты выставим в виде svg-xml
		// TODO: потом убрать
		else if (_T("Fill-LinearGradient") == sParamName && VT_BSTR == ParamValue.vt)
		{
			if (!CreateLinearGradientFromSvgXml(CString(ParamValue.bstrVal), TRUE))
				return S_FALSE;
		}
		// NOTE: пока градиенты выставим в виде svg-xml
		// TODO: потом убрать
		else if (_T("Stroke-LinearGradient") == sParamName && VT_BSTR == ParamValue.vt)
		{
			if (!CreateLinearGradientFromSvgXml(CString(ParamValue.bstrVal), FALSE))
				return S_FALSE;
		}
		// NOTE: пока градиенты выставим в виде svg-xml
		// TODO: потом убрать
		else if (_T("Fill-RadialGradient") == sParamName && VT_BSTR == ParamValue.vt)
		{
			if (!CreateRadialGradientFromSvgXml(CString(ParamValue.bstrVal), TRUE))
				return S_FALSE;
		}
		// NOTE: пока градиенты выставим в виде svg-xml
		// TODO: потом убрать
		else if (_T("Stroke-RadialGradient") == sParamName && VT_BSTR == ParamValue.vt)
		{
			if (!CreateRadialGradientFromSvgXml(CString(ParamValue.bstrVal), FALSE))
				return S_FALSE;
		}
		else if (_T("InitializeFromFolder") == sParamName && VT_BSTR == ParamValue.vt)
		{
			if (NULL != m_pFontManager)
			{
				m_pFontManager->SetAdditionalParam(ParamName, ParamValue);
				m_bIsFontsInitialize = TRUE;
			}
		}

		return S_OK;
	}
	STDMETHOD(GetAdditionalParam)(BSTR ParamName, VARIANT *	ParamValue)
	{
		return S_OK;
	}

	//-----------------------------------------------------------------------------------------------------
	//
	// Интерфейс IAVSOfficeRendererTemplate (IPDFRenderer) IAVSRenderer
	//
	//-----------------------------------------------------------------------------------------------------
	//-------- Тип рендерера--------------------------------------------------------------------------
	STDMETHOD(get_Type)(LONG *plType)
	{
		if ( !plType )
			return S_FALSE;

		*plType = c_nPDFWriter;

		return S_OK;
	}
	//-------- Функции для работы со страницей -------------------------------------------------------
	STDMETHOD(NewPage)()
	{
		m_bStartSubPath = FALSE;
		m_bGStateChange = FALSE;
		m_bClipPath     = FALSE;

		m_dCharSpace    = 0.0;

		m_oClipCTM.Set( 1, 0, 0, 1, 0, 0 );
		m_oBaseTransform.Set( 1, 0, 0, 1, 0, 0 );

		m_oPen.SetDefaultParams();
		m_oFont.SetDefaultParams();
		m_oBrush.SetDefaultParams();
		m_oShadow.SetDefaultParams();
		m_oEdgeText.SetDefaultParams();

		m_oTransform.Reset();
		// Заканчиваем последнее состояние
		SetState( rendstateNone );
		// Сбрасываем состояние
		m_oRendererState.Reset();

		m_bFirstMoveTo = TRUE;

		m_oContiniousText.Reset();

		return AddNewPage();
	}
	STDMETHOD(put_Height)(double   dHeight)
	{
		HRESULT hRes = S_OK;

		dHeight = MMToPDFCoords( dHeight );

		if ( FAILED( hRes = SetPageHeight( (float)dHeight ) ) )
			return hRes;

		return S_OK;
	}
	STDMETHOD(get_Height)(double *pdHeight)
	{
		HRESULT hRes = S_OK;

		float fHeight = 0;
		if ( FAILED( hRes = GetHeight( &fHeight ) ) )
			return hRes;

		*pdHeight = PDFCoordsToMM( (double)fHeight );

		return S_OK;
	}
	STDMETHOD(put_Width)(double dWidth)
	{
		HRESULT hRes = S_OK;

		dWidth = MMToPDFCoords( dWidth );

		if ( FAILED( hRes = SetPageWidth( (float)dWidth ) ) )
			return hRes;

		return S_OK;
	}
	STDMETHOD(get_Width)(double *pdWidth)
	{
		HRESULT hRes = S_OK;

		float fWidth = 0;

		if ( FAILED( hRes = GetWidth( &fWidth ) ) )
			return hRes;

		*pdWidth = PDFCoordsToMM( (double)fWidth );

		return S_OK;
	}
	STDMETHOD(get_DpiX)(double *pdDpiX)
	{
		*pdDpiX = 72.0;

		return S_OK;
	}
	STDMETHOD(get_DpiY)(double *pdDpiY)
	{
		*pdDpiY = 72.0;

		return S_OK;
	}
	//-------- Функции для работы с Pen --------------------------------------------------------------
	STDMETHOD(SetPen)(BSTR bsXML)
	{
		CString strXML( bsXML );
		m_oPen.FromXmlString( strXML );
		m_bGStateChange = TRUE; 

		return S_OK;
	}
	STDMETHOD(get_PenColor)(LONG *plColor)
	{
		*plColor = m_oPen.Color;

		return S_OK;
	}
	STDMETHOD(put_PenColor)(LONG lColor)
	{
		m_bGStateChange = TRUE;
		m_oPen.Color = lColor;

		return S_OK;
	}
	STDMETHOD(get_PenAlpha)(LONG *plAlpha)
	{
		*plAlpha = m_oPen.Alpha;

		return S_OK;
	}
	STDMETHOD(put_PenAlpha)(LONG lAlpha)
	{
		m_bGStateChange = TRUE;
		m_oPen.Alpha = lAlpha;

		return S_OK;
	}
	STDMETHOD(get_PenSize)(double *pdSize)
	{
		*pdSize = m_oPen.Size;

		return S_OK;
	}
	STDMETHOD(put_PenSize)(double dSize)
	{
		m_bGStateChange = TRUE;
		m_oPen.Size = dSize;

		return S_OK;
	}
	STDMETHOD(get_PenDashStyle)(BYTE *pnStyle)
	{
		*pnStyle = m_oPen.DashStyle;

		return S_OK;
	}
	STDMETHOD(put_PenDashStyle)(BYTE nStyle)
	{
		m_bGStateChange = TRUE;
		m_oPen.DashStyle = nStyle;

		return S_OK;
	}
	STDMETHOD(get_PenLineStartCap)(BYTE *pnStartCap)
	{
		*pnStartCap = m_oPen.LineStartCap;

		return S_OK;
	}
	STDMETHOD(put_PenLineStartCap)(BYTE nStartCap)
	{
		m_bGStateChange = TRUE;
		m_oPen.LineStartCap = nStartCap;

		return S_OK;
	}
	STDMETHOD(get_PenLineEndCap)(BYTE *pnEndCap)
	{
		*pnEndCap = m_oPen.LineEndCap;

		return S_OK;
	}
	STDMETHOD(put_PenLineEndCap)(BYTE nEndCap)
	{
		m_bGStateChange = TRUE;
		m_oPen.LineEndCap = nEndCap;

		return S_OK;
	}
	STDMETHOD(get_PenLineJoin)(BYTE *pnJointStyle)
	{
		*pnJointStyle = m_oPen.LineJoin;

		return S_OK;
	}
	STDMETHOD(put_PenLineJoin)(BYTE nJointStyle)
	{
		m_bGStateChange = TRUE;
		m_oPen.LineJoin = nJointStyle;

		return S_OK;
	}
	STDMETHOD(get_PenDashOffset)(double *pdOffset)
	{
		*pdOffset = m_oPen.DashOffset;

		return S_OK;
	}
	STDMETHOD(put_PenDashOffset)(double dOffset)
	{
		m_bGStateChange = TRUE;
		m_oPen.DashOffset = dOffset;

		return S_OK;
	}
	STDMETHOD(get_PenAlign)(LONG *plAlign)
	{
		*plAlign = m_oPen.Align;

		return S_OK;
	}
	STDMETHOD(put_PenAlign)(LONG lAlign)
	{
		m_bGStateChange = TRUE;
		m_oPen.Align = lAlign;

		return S_OK;
	}
	STDMETHOD(get_PenMiterLimit)(double *pdMiterLimit)
	{
		*pdMiterLimit = m_oPen.MiterLimit;

		return S_OK;
	}
	STDMETHOD(put_PenMiterLimit)(double dMiterLimit)
	{
		m_bGStateChange = TRUE;
		m_oPen.MiterLimit = dMiterLimit;

		return S_OK;
	}
	STDMETHOD(PenDashPattern)(SAFEARRAY* pPattern)
	{
		m_bGStateChange = TRUE;
		m_oPen.SetDashPattern( (double*)pPattern->pvData, pPattern->rgsabound[0].cElements );

		return S_OK;
	}
	//-------- Функции для работы с Brush ------------------------------------------------------------
	STDMETHOD(SetBrush)(BSTR bsXML)
	{
		CString strXML( bsXML );
		m_oBrush.FromXmlString( strXML );
		m_bGStateChange = TRUE; 

		return S_OK;
	}
	STDMETHOD(get_BrushType)(LONG *plType)
	{
		*plType = m_oBrush.Type;

		return S_OK;
	}
	STDMETHOD(put_BrushType)(LONG lType)
	{
		m_bGStateChange = TRUE;
		m_oBrush.Type = lType;

		return S_OK;
	}
	STDMETHOD(get_BrushColor1)(LONG *plColor)
	{
		*plColor = m_oBrush.Color1;

		return S_OK;
	}
	STDMETHOD(put_BrushColor1)(LONG lColor)
	{
		m_bGStateChange = TRUE;
		m_oBrush.Color1 = lColor;

		return S_OK;
	}
	STDMETHOD(get_BrushAlpha1)(LONG *plAlpha)
	{
		*plAlpha = m_oBrush.Alpha1;

		return S_OK;
	}
	STDMETHOD(put_BrushAlpha1)(LONG lAlpha)
	{
		m_bGStateChange = TRUE;
		m_oBrush.Alpha1 = lAlpha;

		return S_OK;
	}
	STDMETHOD(get_BrushColor2)(LONG *plColor)
	{
		*plColor = m_oBrush.Color2;

		return S_OK;
	}
	STDMETHOD(put_BrushColor2)(LONG lColor)
	{
		m_bGStateChange = TRUE;
		m_oBrush.Color2 = lColor;

		return S_OK;
	}
	STDMETHOD(get_BrushAlpha2)(LONG *plAlpha)
	{
		*plAlpha = m_oBrush.Alpha2;

		return S_OK;
	}
	STDMETHOD(put_BrushAlpha2)(LONG lAlpha)
	{
		m_bGStateChange = TRUE;
		m_oBrush.Alpha2 = lAlpha;

		return S_OK;
	}
	STDMETHOD(get_BrushTexturePath)(BSTR *pbsPath)
	{
		*pbsPath = m_oBrush.TexturePath.AllocSysString();

		return S_OK;
	}
	STDMETHOD(put_BrushTexturePath)(BSTR bsPath)
	{
		m_bGStateChange = TRUE;
		m_oBrush.TexturePath = CString(bsPath);

		return S_OK;
	}
	STDMETHOD(get_BrushTextureMode)(LONG *plMode)
	{
		*plMode = m_oBrush.TextureMode;

		return S_OK;
	}
	STDMETHOD(put_BrushTextureMode)(LONG lMode)
	{
		m_bGStateChange = TRUE;
		m_oBrush.TextureMode = lMode;

		if (c_BrushTextureModeTile == m_oBrush.TextureMode)
			m_oPatternState.SetTileMode(TRUE);

		return S_OK;
	}
	STDMETHOD(get_BrushTextureAlpha)(LONG *plTxAlpha)
	{
		*plTxAlpha = m_oBrush.TextureAlpha;

		return S_OK;
	}
	STDMETHOD(put_BrushTextureAlpha)(LONG lTxAlpha)
	{
		m_bGStateChange = TRUE;
		m_oBrush.TextureAlpha = lTxAlpha;

		return S_OK;
	}
	STDMETHOD(get_BrushLinearAngle)(double *pdAngle)
	{
		*pdAngle = m_oBrush.LinearAngle;

		return S_OK;
	}
	STDMETHOD(put_BrushLinearAngle)(double dAngle)
	{
		m_bGStateChange = TRUE;
		m_oBrush.LinearAngle = dAngle;

		return S_OK;
	}
	STDMETHOD(BrushRect)(BOOL bVal, double dLeft, double dTop, double dWidth, double dHeight)
	{
		m_oBrush.Rectable    = bVal;
		m_oBrush.Rect.X      = (float)dLeft;
		m_oBrush.Rect.Y      = (float)dTop;
		m_oBrush.Rect.Width  = (float)dWidth;
		m_oBrush.Rect.Height = (float)dHeight;

		return S_OK;
	}
	//-------- Функции для работы с Шрифтом ----------------------------------------------------------
	STDMETHOD(SetFont)(BSTR bsXML)
	{
		CString strXML( bsXML );
		m_oFont.FromXmlString( strXML );

		//if ( m_bCurFontGIDString && !m_bEncoderGID )
		//{
		//	BOOL bNew = FALSE;

		//	wchar_t wsString[255];
		//	for ( int nCode = 1; nCode < 256; nCode++ )
		//	{
		//		wsString[nCode - 1] = nCode;
		//	}
		//	FindEncoderForString( m_pDocument, (BSTR)wsString ,&bNew);
		//}
		//unsigned long unRes = GdiFontToPdfFont(/*L""*/(CStringW(L"qwertyuiop[]';lkjhgfdsazxcvbnm,./QWERTYUIOP{}\":LKJHGFDSAZXCVBNM<>?ЙЦУКЕНГШЩЗХЪЭЖДЛОРПАВЫФЯЧСМИТЬБЮ,.юбьтимсчяфывапролджэъхзщшгнекуцйЁё1234567890-=+_)(*?:%;№!qwertyuiop[]';lkjhgfdsazxcvbnm,./QWERTYUIOP{}\":LKJHGFDSAZXCVBNM<>?ЙЦУКЕНГ ")).AllocSysString(), TRUE);
		//if ( S_OK != unRes )
		//	return unRes;

		//if ( !m_pFontEncodingList )
		//	m_pFontEncodingList = ListNew( m_pDocument->oMMgr, DEF_ITEMS_PER_BLOCK );

		//TFontEncodingPair *pPair = new TFontEncodingPair;
		//const char *sPdfFontName  = FontGetFontName( m_pCurrentFont );
		//const char *sRealFontName = FontGetFontName( m_pCurrentFont, TRUE );
		//const char *sEncodingName = FontGetEncodingName( m_pCurrentFont );

		//UtilsMemCpy( (BYTE *)pPair->sPdfFontName,  (BYTE *)sPdfFontName,  LIMIT_MAX_NAME_LEN + 1 );
		//UtilsMemCpy( (BYTE *)pPair->sRealFontName, (BYTE *)sRealFontName, LIMIT_MAX_NAME_LEN + 1 );
		//UtilsMemCpy( (BYTE *)pPair->sEncodingName, (BYTE *)sEncodingName, LIMIT_MAX_NAME_LEN + 1 );

		//ListAdd( m_pFontEncodingList, pPair );

		return S_OK;

	}
	STDMETHOD(get_FontName)(BSTR *pbsName)
	{
		*pbsName = m_oFont.Name.AllocSysString();

		return S_OK;
	}
	STDMETHOD(put_FontName)(BSTR bsName)
	{
		m_oFont.Name = CString( bsName );

		return S_OK;
	}
	STDMETHOD(get_FontPath)(BSTR *pbsPath)
	{
		*pbsPath = m_oFont.Path.AllocSysString();

		return S_OK;
	}
	STDMETHOD(put_FontPath)(BSTR bsName)
	{		
		m_oFont.Path = CString( bsName );
		m_oFont.Path.Replace(_T("\\\\"), _T("\\") );
		m_oFont.Path.Replace(_T("\\\\"), _T("\\") );

		m_oFont.Path.Replace(_T("//"), _T("/") );
		m_oFont.Path.Replace(_T("//"), _T("/") );

		return S_OK;
	}
	STDMETHOD(get_FontSize)(double *pdSize)
	{
		*pdSize = m_oFont.Size;

		return S_OK;
	}
	STDMETHOD(put_FontSize)(double dSize)
	{
		m_oFont.Size = dSize;

		return S_OK;
	}
	STDMETHOD(get_FontStyle)(LONG *plStyle)
	{
		*plStyle = m_oFont.GetStyle();

		return S_OK;
	}
	STDMETHOD(put_FontStyle)(LONG lStyle)
	{
		m_oFont.SetStyle( lStyle );
		return S_OK;
	}
	STDMETHOD(get_FontStringGID)(BOOL *pbGID)
	{
		*pbGID = m_oFont.StringGID;

		return S_OK;
	}
	STDMETHOD(put_FontStringGID)(BOOL bGID)
	{
		m_oFont.StringGID = bGID;

		return S_OK;
	}
	STDMETHOD(get_FontCharSpace)(double *pdSpace)
	{
		if ( !pdSpace )
			return S_FALSE;

		*pdSpace = PDFCoordsToMM( m_dCharSpace );

		return S_OK;
	}
	STDMETHOD(put_FontCharSpace)(double dSpace)
	{
		m_dCharSpace = MMToPDFCoords( dSpace );
		return S_OK;
	}

	//-------- Функции для работы с Shadow -----------------------------------------------------------
	STDMETHOD(SetShadow)(BSTR bsXML)
	{
		CString strXML( bsXML );
		m_oShadow.FromXmlString( strXML );

		return S_OK;
	}
	STDMETHOD(get_ShadowDistanceX)(double *pdX)
	{
		*pdX = m_oShadow.DistanceX;

		return S_OK;
	}
	STDMETHOD(put_ShadowDistanceX)(double dX)
	{
		m_oShadow.DistanceX = dX;

		return S_OK;
	}
	STDMETHOD(get_ShadowDistanceY)(double *pdY)
	{
		*pdY = m_oShadow.DistanceY;

		return S_OK;
	}
	STDMETHOD(put_ShadowDistanceY)(double dY)
	{
		m_oShadow.DistanceY = dY;

		return S_OK;
	}
	STDMETHOD(get_ShadowBlurSize)(double *pdSize)
	{
		*pdSize = m_oShadow.BlurSize;

		return S_OK;
	}
	STDMETHOD(put_ShadowBlurSize)(double dSize)
	{
		m_oShadow.BlurSize = dSize;

		return S_OK;
	}
	STDMETHOD(get_ShadowColor)(LONG *plColor)
	{
		*plColor = m_oShadow.Color;

		return S_OK;
	}
	STDMETHOD(put_ShadowColor)(LONG lColor)
	{
		m_oShadow.Color = lColor;

		return S_OK;
	}
	STDMETHOD(get_ShadowAlpha)(LONG *plAlpha)
	{
		*plAlpha = m_oShadow.Alpha;

		return S_OK;
	}
	STDMETHOD(put_ShadowAlpha)(LONG lAlpha)
	{
		m_oShadow.Alpha = lAlpha;

		return S_OK;
	}
	STDMETHOD(get_ShadowVisible)(BOOL *pbVisible)
	{
		*pbVisible = m_oShadow.Visible;

		return S_OK;
	}
	STDMETHOD(put_ShadowVisible)(BOOL bVisible)
	{
		m_oShadow.Visible = bVisible;

		return S_OK;
	}
	//-------- Функции для работы с Edge Text --------------------------------------------------------
	STDMETHOD(SetEdgeText)(BSTR bsXML)
	{
		CString strXML( bsXML );
		m_oEdgeText.FromXmlString( strXML );

		return S_OK;
	}
	STDMETHOD(get_EdgeVisible)(LONG *plVisible)
	{
		*plVisible = m_oEdgeText.Visible;

		return S_OK;
	}
	STDMETHOD(put_EdgeVisible)(LONG lVisible)
	{
		m_oEdgeText.Visible = lVisible;

		return S_OK;
	}
	STDMETHOD(get_EdgeColor)(LONG *plColor)
	{
		*plColor = m_oEdgeText.Color;

		return S_OK;
	}
	STDMETHOD(put_EdgeColor)(LONG lColor)
	{
		m_oEdgeText.Color = lColor;

		return S_OK;
	}
	STDMETHOD(get_EdgeAlpha)(LONG *plAlpha)
	{
		*plAlpha = m_oEdgeText.Alpha;

		return S_OK;
	}
	STDMETHOD(put_EdgeAlpha)(LONG lAlpha)
	{
		m_oEdgeText.Alpha = lAlpha;

		return S_OK;
	}
	STDMETHOD(get_EdgeDist)(double *pdDist)
	{
		*pdDist = m_oEdgeText.Dist;

		return S_OK;
	}
	STDMETHOD(put_EdgeDist)(double dDist)
	{
		m_oEdgeText.Dist = dDist;

		return S_OK;
	}
	//--------- Функции для вывода текста ------------------------------------------------------------
	STDMETHOD(CommandDrawText)  (BSTR bsText, double fX, double fY, double fWidth, double fHeight, double fBaseLineOffset)
	{
		HRESULT hRes = S_OK;

		// Работа с сылками тоже проходит с помощью функции CommandDrawText
		if ( c_nHyperlinkType == m_pCurCommand->nType )
		{
			SetState( rendstateNone );

			if ( FAILED( hRes = MakeAnnotationFromXml( bsText ) ) )
				return hRes;

			return S_OK;
		}

		if ( c_nClipType != m_pCurCommand->nType )
		{
			m_oContiniousText.Add( bsText, bsText, fX, fY, fWidth, fHeight, fBaseLineOffset, false, m_oFont, m_oBrush, m_oTransform, m_dCharSpace );
			SetState( rendstateText );

			return S_OK;
		}
		else
		{
			SetState( rendstateClipText );
		}


		CSynchAccess oSynchAccess = m_hSynchMutex;

		// Работа с сылками тоже проходит с помощью функции CommandDrawText
		if ( c_nHyperlinkType == m_pCurCommand->nType )
		{
			if ( FAILED( hRes = MakeAnnotationFromXml( bsText ) ) )
				return hRes;

			return S_OK;
		}

		// Переводим в миллиметры
		fX = MMToPDFCoords( fX );
		fY = MMToPDFCoords( fY );
		fWidth = MMToPDFCoords( fWidth );
		fHeight = MMToPDFCoords( fHeight );
		fBaseLineOffset = MMToPDFCoords( fBaseLineOffset );

		PToUnicode pToUnicode = FindToUnicodeForString( m_pDocument, bsText );
		if ( !pToUnicode )
			return S_OK;

		CString sCodedString;
		BOOL bResult = ToUnicodeWCharToString( pToUnicode, bsText, &sCodedString );

		USES_CONVERSION;

		// Запоминаем значения Bold и Italic, потому что в функции GdiFontToPdfFont они могут измениться
		BOOL bOldBold   = m_oFont.Bold;
		BOOL bOldItalic = m_oFont.Italic;

		BOOL bDefaultFont = FALSE;
		if ( FAILED( hRes = GdiFontToPdfFont2( A2W( pToUnicode->sName ), FALSE ) ) )
		{
			if ( AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND == hRes )
			{
				ResetError( m_pDocument );
				sCodedString = CString( bsText );
				bDefaultFont = TRUE;
			}
			else
			{
				return hRes;
			}
		}

		BSTR bsCodedString = sCodedString.AllocSysString();

		long nAscent = 0;
		long nDescent = 0;
		long nXHeight = 0;

		double dItalicAngle = 3.141592f / 12;

		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( !m_oFont.Italic )
			dItalicAngle = 0;

		float fFontSize = (float)m_oFont.Size;

		if ( FAILED( hRes = GetFontAscent( &nAscent ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = GetFontDescent( &nDescent ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = GetFontXHeight( &nXHeight ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		// Выясним как нам рисовать текст
		ETextRenderingMode eRenderingMode = ETextRenderingMode::Fill; // Fill (по умолчанию)
		if ( c_nStrokeTextType == m_pCurCommand->nType )
			eRenderingMode = ETextRenderingMode::Stroke; // Stroke
		if ( c_nClipType == m_pCurCommand->nType )
		{
			ATLTRACE2( _T( "TextClip" ) );
			eRenderingMode = ETextRenderingMode::Clipping; // Clip
		}

		float fXHeight = (float)nXHeight / 1000;
		float fAscent  = (float)nAscent / 1000;
		float fDescent = fabs( (float)nDescent / 1000 );

		long nColor1 = m_oBrush.Color1;
		float fR = ( nColor1 & 0xFF ) / 255.0f; 
		float fG = ( ( nColor1 >> 8 ) & 0xFF ) / 255.0f; 
		float fB = ( nColor1 >> 16 ) / 255.0f; 
		float fTextWidth = 0.0f;
		float fLineWidth = fFontSize / ( bOldBold ? 10.f : 15.0f );
		float fOldLineWidth = 0.0f;

		if ( FAILED( hRes = GetLineWidth( &fOldLineWidth ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		float fFillR, fFillG, fFillB, fStrokeR, fStrokeG, fStrokeB;
		if ( FAILED( hRes = GetRGBFill( &fFillR, &fFillG, &fFillB ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = GetRGBStroke( &fStrokeR, &fStrokeG, &fStrokeB ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}
		// Рисуем тени

		if ( m_oShadow.Visible )
		{
			//if ( FAILED( hRes = GRestore() ) )
			//{
			//	::SysFreeString( bsCodedString );
			//	return hRes;
			//}
			ATLTRACE2( _T("GSave: DrawText - Shadow\n") );
			if ( FAILED( hRes = GSave() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = SetLineWidth( fLineWidth ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			// Выставляем систему координат
			if ( FAILED( hRes = UpdateCoordSpace(  ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}


			double dXShadow = fX + MMToPDFCoords( m_oShadow.DistanceX );
			double dYShadow = fY + MMToPDFCoords( m_oShadow.DistanceY );

			long nAlpha = m_oShadow.Alpha;
			long nShadowColor = m_oShadow.Color;

			float fAlpha = (float)nAlpha / 255.0f;
			float fBShadow = ( nShadowColor & 0xFF ) / 255.0f; 
			float fGShadow = ( ( nShadowColor >> 8 ) & 0xFF ) / 255.0f; 
			float fRShadow = ( nShadowColor >> 16 ) / 255.0f; 

			{
				XmlUtils::CXmlWriter oWriter;

				oWriter.WriteNodeBegin( _T("ExtGState") );

				if ( 255 != fAlpha )
				{
					oWriter.WriteNodeBegin( _T("AlphaFill"), TRUE );
					oWriter.WriteAttribute( _T("value"), (double)fAlpha );
					oWriter.WriteNodeEnd( _T("AlphaFill"), TRUE, TRUE );
				}

				if ( 255 != fAlpha )
				{
					oWriter.WriteNodeBegin( _T("AlphaStroke"), TRUE );
					oWriter.WriteAttribute( _T("value"), (double)fAlpha );
					oWriter.WriteNodeEnd( _T("AlphaStroke"), TRUE, TRUE );
				}

				oWriter.WriteNodeEnd( _T("ExtGState") );

				BSTR bsXml = oWriter.GetXmlString().AllocSysString();
				if ( FAILED( hRes = SetExtGraphicsState2( bsXml ) ) )
				{
					::SysFreeString( bsCodedString );
					::SysFreeString( bsXml );
					return hRes;
				}

				::SysFreeString( bsXml );

				//if ( FAILED( hRes = NewExtGraphicsState() ) )
				//{
				//	::SysFreeString( bsCodedString );
				//	return hRes;
				//}
				////if ( FAILED( hRes = ExtGraphicsStateSetBlendMode( EBlendMode::BMOverlay ) ) )
				////{
				////	::SysFreeString( bsCodedString );
				////	return hRes;
				////}
				//if ( FAILED( hRes = ExtGraphicsStateSetAlphaFill( fAlpha ) ) )
				//{
				//	::SysFreeString( bsCodedString );
				//	return hRes;
				//}
				//if ( FAILED( hRes = ExtGraphicsStateSetAlphaStroke( fAlpha ) ) )
				//{
				//	::SysFreeString( bsCodedString );
				//	return hRes;
				//}
				//if ( FAILED( hRes = SetExtGraphicsState() ) )
				//{
				//	::SysFreeString( bsCodedString );
				//	return hRes;
				//}
			}

			// Выставляем цвет текста и линий
			if ( FAILED( hRes = SetRGBFill( fRShadow, fGShadow, fBShadow ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = SetRGBStroke( fRShadow, fGShadow, fBShadow ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = BeginText() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			// Устанавливаем текущий фонт и размер фонта
			if ( FAILED( hRes = SetFontAndSizeToGState( fFontSize ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			// Если данный фонт не нашли с атрибутом Italic, тогда наколняем текст сами на угол dItalicAngle
			if ( FAILED( hRes = SetTextMatrix( 1, (float)tan( 0.0 ), (float)tan( dItalicAngle ), 1, 0, 0 ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( eRenderingMode == ETextRenderingMode::Fill  )
			{
				// Если данный фонт не нашли с атрибутом Bold, тогда заливаем и обводим текст, тем самым утолщяя его
				if ( m_oFont.Bold )
				{
					if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::FillThenStroke) ) )
					{
						::SysFreeString( bsCodedString );
						return hRes;
					}
				}
				else
					if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::Fill) ) )
					{
						::SysFreeString( bsCodedString );
						return hRes;
					}
			}
			else 
			{
				if ( FAILED( hRes = SetTextRenderingMode( (long)eRenderingMode ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
			}

			// Выводим текст
			if ( FAILED( hRes = TextOut( (float)dXShadow, fPageHeight - (float)(dYShadow + fBaseLineOffset) , bsCodedString ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}


			if ( FAILED( hRes = EndText() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			//// Перечеркивание текста. Текст перечеркиваем по середине буквы 'x'. (См. XHeight)
			//if ( m_oFont.Strikeout )
			//{
			//	double dItalicAdd = tan( (double)dItalicAngle ) * fXHeight * fFontSize / 2;
			//	if ( !m_oFont.Italic )
			//		dItalicAdd = 0;
			//	if ( FAILED( hRes = MoveTo( (float)dXShadow + dItalicAdd, fPageHeight - (float)( dYShadow + fBaseLineOffset - fXHeight * fFontSize / 2 ) ) ) )
			//	{
			//		::SysFreeString( bsCodedString );
			//		return hRes;
			//	}
			//	if ( FAILED( hRes = LineTo( (float)dXShadow + fTextWidth + dItalicAdd, fPageHeight - (float)( dYShadow + fBaseLineOffset - fXHeight * fFontSize / 2 ) ) ) )
			//	{
			//		::SysFreeString( bsCodedString );
			//		return hRes;
			//	}
			//	if ( FAILED( hRes = Stroke( ) ) )
			//	{
			//		::SysFreeString( bsCodedString );
			//		return hRes;
			//	}
			//}

			//// Подчеркивание текста.
			//if ( m_oFont.Underline )
			//{
			//	float fTextWidth = 0.0f;
			//	float fUnderLineOffset = 3 + fLineWidth / 2;
			//	if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
			//	{
			//		::SysFreeString( bsCodedString );
			//		return hRes;
			//	}
			//	if ( FAILED( hRes = MoveTo( (float)dXShadow, fPageHeight - ( (float)dYShadow + fBaseLineOffset + fUnderLineOffset /*fDescent * fFontSize*/ ) ) ) )
			//	{
			//		::SysFreeString( bsCodedString );
			//		return hRes;
			//	}
			//	if ( FAILED( hRes = LineTo( (float)dXShadow + fTextWidth, fPageHeight - ( (float)dYShadow + fBaseLineOffset + fUnderLineOffset /*fDescent * fFontSize*/ ) ) ) )
			//	{
			//		::SysFreeString( bsCodedString );
			//		return hRes;
			//	}
			//	if ( FAILED( hRes = Stroke( ) ) )
			//	{
			//		::SysFreeString( bsCodedString );
			//		return hRes;
			//	}
			//}

			ATLTRACE2( _T("GRestore: DrawText - Shadow\n") );
			if ( FAILED( hRes = GRestore() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		//if ( FAILED( hRes = GRestore() ) )
		//{
		//	::SysFreeString( bsCodedString );
		//	return hRes;
		//}

		// Дальше рисуем все, что непосредственно связанно с самим текстом
		// Выставляем цвет текста и линий

		if ( ETextRenderingMode::Fill == eRenderingMode )
		{
			if ( FAILED( hRes = SetRGBFill( fR, fG, fB ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = SetRGBStroke( fR, fG, fB ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}
		else
		{
			if ( FAILED( hRes = SetRGBFill( fR, fG, fB ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}


			if ( FAILED( hRes = SetRGBStroke( fR, fG, fB ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		// Выставляем систему координат
		if ( c_nClipType != m_pCurCommand->nType )
		{
			ATLTRACE2( _T("GSave: DrawText\n") );
			if ( FAILED( hRes = GSave() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
			if ( FAILED( hRes = UpdateCoordSpace(  ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			float fAlphaFill   = (float)m_oBrush.Alpha1 / 255.0f;
			float fAlphaStroke = (float)m_oPen.Alpha / 255.0f;
			m_pCurrentExtGState = GetExtGState( m_pDocument, fAlphaStroke, fAlphaFill );
			if ( OK != ( hRes = PageSetExtGState( m_pDocument->pCurPage, m_pCurrentExtGState ) ) )
				return hRes;
		}
		else
		{
			if ( FAILED( hRes = UpdateCoordSpace(  ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		if ( FAILED( hRes = BeginText() ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		// Устанавливаем межсимвольный интервал
		if ( FAILED( hRes = SetCharSpace( (float)m_dCharSpace ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		// Устанавливаем текущий фонт и размер фонта
		if ( FAILED( hRes = SetFontAndSizeToGState( fFontSize ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		// Если шрифт не нашли, и используется стандартный шрифт, значит, ширина слов будет неверной.
		// Чтобы слова не наползали друг на друга скейлим текст к его реальной ширине.
		if ( bDefaultFont )
		{
			// Измеряем размер
			float fTextWidth = 0.0f;
			if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			float fKoef;
			if ( fabs( fTextWidth ) < 0.01 )
				fKoef = 1;
			else
				fKoef = fWidth / fTextWidth * 100; // Scale задается в процентах

			if ( fKoef > 0.001 )
			{
				if ( FAILED( hRes = SetHorizontalScalling( fKoef ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
			}
		}

		if ( _T("AVSEmptyFont") == m_oFont.Name )
		{
			// Данная ветка сделана специально для конвертации Djvu -> PDF

			float fVKoef;

			if ( fabs( m_oFont.Size ) < 0.01 )
				fVKoef = 1;
			else		
				fVKoef = fHeight / m_oFont.Size;

			// Если данный фонт не нашли с атрибутом Italic, тогда наколняем текст сами на угол dItalicAngle
			if ( FAILED( hRes = SetTextMatrix( 1, (float)tan( 0.0 ), (float)fVKoef * tan( dItalicAngle ), fVKoef * 1, 0, 0 ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}
		else
		{
			// Если данный фонт не нашли с атрибутом Italic, тогда наколняем текст сами на угол dItalicAngle
			if ( FAILED( hRes = SetTextMatrix( 1, (float)tan( 0.0 ), (float)tan( dItalicAngle ), 1, 0, 0 ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( ETextRenderingMode::Fill == eRenderingMode )
		{
			// Если данный фонт не нашли с атрибутом Bold, тогда заливаем и обводим текст, тем самым утолщяя его
			if ( m_oFont.Bold )
			{
				if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::FillThenStroke) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
			}
			else
				if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::Fill) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
		}
		else
		{
			if ( FAILED( hRes = SetTextRenderingMode( (long)eRenderingMode ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		// Выводим текст
		if ( FAILED( hRes = TextOut( (float)fX, fPageHeight - (float)(fY + fBaseLineOffset), bsCodedString ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = EndText() ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		//if ( FAILED( hRes = SetLineWidth( fLineWidth ) ) )
		//{
		//	::SysFreeString( bsCodedString );
		//	return hRes;
		//}

		//// Перечеркивание текста. Текст перечеркиваем по середине буквы 'x'. (См. XHeight)
		//if ( m_oFont.Strikeout )
		//{
		//	double dItalicAdd = tan( (double)dItalicAngle ) * fXHeight * fFontSize / 2;
		//	if ( !m_oFont.Italic )
		//		dItalicAdd = 0;
		//	if ( FAILED( hRes = MoveTo( (float)fX + dItalicAdd, fPageHeight - (float)( fY + fBaseLineOffset - fXHeight * fFontSize / 2 ) ) ) )
		//	{
		//		::SysFreeString( bsCodedString );
		//		return hRes;
		//	}
		//	if ( FAILED( hRes = LineTo( (float)fX + fTextWidth + dItalicAdd, fPageHeight - (float)( fY + fBaseLineOffset - fXHeight * fFontSize / 2 ) ) ) )
		//	{
		//		::SysFreeString( bsCodedString );
		//		return hRes;
		//	}
		//	if ( FAILED( hRes = Stroke( ) ) )
		//	{
		//		::SysFreeString( bsCodedString );
		//		return hRes;
		//	}
		//	//MoveTo(dX, dY - fDescent * fFontSize );
		//	//LineTo(dX + dItalicAdd * 2, dY + fFontSize * ( 1 - fDescent ) );
		//	//LineTo(dX + fTextWidth + dItalicAdd * 2, dY + fFontSize * ( 1 - fDescent ) );
		//	//LineTo(dX + fTextWidth, dY - fDescent * fFontSize );
		//	//LineTo(dX, dY - fDescent * fFontSize );
		//	//Stroke();
		//}

		//// Подчеркивание текста.
		//if ( m_oFont.Underline )
		//{
		//	float fTextWidth = 0.0f;
		//	float fUnderLineOffset = 3 + fLineWidth / 2;
		//	if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
		//	{
		//		::SysFreeString( bsCodedString );
		//		return hRes;
		//	}
		//	if ( FAILED( hRes = MoveTo( (float)fX, fPageHeight - (float)(fY + fBaseLineOffset + fUnderLineOffset) /*fDescent * fFontSize*/ ) ) )
		//	{
		//		::SysFreeString( bsCodedString );
		//		return hRes;
		//	}
		//	if ( FAILED( hRes = LineTo( (float)fX + fTextWidth, fPageHeight - (float)(fY + fBaseLineOffset + fUnderLineOffset) /*fDescent * fFontSize*/ ) ) )
		//	{
		//		::SysFreeString( bsCodedString );
		//		return hRes;
		//	}
		//	if ( FAILED( hRes = Stroke( ) ) )
		//	{
		//		::SysFreeString( bsCodedString );
		//		return hRes;
		//	}
		//}

		::SysFreeString( bsCodedString );

		// Восстанавливаем систему координат
		if ( c_nClipType != m_pCurCommand->nType )
		{
			ATLTRACE2( _T("GRestore: DrawText\n") );
			if ( FAILED( hRes = GRestore() ) )
				return hRes;
		}
		else
		{
			float fDelta = m_oClipCTM.fA * m_oClipCTM.fD - m_oClipCTM.fB * m_oClipCTM.fC;
			if ( 0.0f != fDelta  )
			{
				float fIDelta = 1 / fDelta;
				float fA =  fIDelta * m_oClipCTM.fD;
				float fB =  fIDelta * ( -m_oClipCTM.fB );
				float fC =  fIDelta * ( -m_oClipCTM.fC );
				float fD =  fIDelta * m_oClipCTM.fA;
				float fE =  fIDelta * (m_oClipCTM.fC * m_oClipCTM.fF - m_oClipCTM.fE * m_oClipCTM.fD);
				float fF =  fIDelta * (m_oClipCTM.fE * m_oClipCTM.fB - m_oClipCTM.fA * m_oClipCTM.fF);

				// Делаем матрицу CTM единичной
				if ( FAILED( hRes = Concat( fA, fB, fC, fD, fE, fF ) ) )
					return hRes;
			}

			m_oClipCTM.Set( 1, 0, 0, 1, 0, 0 );
		}

		// Восстанавливаем старые настройки
		if ( FAILED( hRes = SetLineWidth( fOldLineWidth ) ) )
			return hRes;

		if ( FAILED( hRes = SetRGBFill( fFillR, fFillG, fFillB ) ) )
			return hRes;

		if ( FAILED( hRes = SetRGBStroke( fStrokeR, fStrokeG, fStrokeB ) ) )
			return hRes;

		m_oFont.Bold   = bOldBold;
		m_oFont.Italic = bOldItalic;

		return S_OK;
	}
	STDMETHOD(CommandDrawTextEx)(BSTR bsUnicodeText, BSTR bsGidText, BSTR bsSrcCodeText, double fX, double fY, double fWidth, double fHeight, double fBaseLineOffset, DWORD nFlags)
	{
		// TODO: Сделать обработку DrawTextEx тоже через Состояния рендерера
		SetState( rendstateNone );

		if ( !bsUnicodeText && !bsSrcCodeText )
			return S_OK;

		CSynchAccess oSynchAccess = m_hSynchMutex;

		HRESULT hRes = S_OK;

		// Работа с сылками тоже проходит с помощью функции CommandDrawText
		if ( c_nHyperlinkType == m_pCurCommand->nType )
		{
			if ( FAILED( hRes = MakeAnnotationFromXml( bsUnicodeText ) ) )
				return hRes;

			return S_OK;
		}

		// Переводим в миллиметры
		fX = MMToPDFCoords( fX );
		fY = MMToPDFCoords( fY );
		fWidth = MMToPDFCoords( fWidth );
		fHeight = MMToPDFCoords( fHeight );
		fBaseLineOffset = MMToPDFCoords( fBaseLineOffset );

		BSTR bsCodedString = NULL;

		// Запоминаем значения Bold и Italic, потому что в функции GdiFontToPdfFont они могут измениться
		BOOL bOldBold   = m_oFont.Bold;
		BOOL bOldItalic = m_oFont.Italic;
		BOOL bDefaultFont = FALSE;

		// Проверяем как задан шрифт, через путь к файлу, или по имени
		if ( _T("") != m_oFont.Path )
		{
			XmlUtils::CXmlNode oNode;
			oNode.FromXmlString( CString(bsSrcCodeText) );

			// TO DO: Пока если шрифт задан путем, значит он пришел из PDF, как только
			//        появится другой формат, с внедренными шрифтами, доделать тут.
			if ( _T("PDF-Text") == oNode.GetName() )
			{
				// Загружаем шрифт и кодировки
				if ( FAILED( hRes = FontFromFileToPdfFont() ) )
				{
					return hRes;
				}

				int nCode = 0, nCID = 0;
				if ( FontDefCID == ((FontAttr)m_pCurrentFont->pAttr)->pFontDef->eType )
				{
					int nCID;

					nCID  = XmlUtils::GetInteger( oNode.GetAttribute( _T("cid") ) );
					nCode = XmlUtils::GetInteger( oNode.GetAttribute( _T("code") ) );
					int nLen = XmlUtils::GetInteger( oNode.GetAttribute( _T("len") ) );

					char pBuffer[4];

					pBuffer[0] = (char)(nCode >> 24);
					pBuffer[1] = (char)(nCode >> 16);
					pBuffer[2] = (char)(nCode >> 8);
					pBuffer[3] = (char)nCode;


					CMapEncoderStreamAddCIDtoCode( ((FontAttr)m_pCurrentFont->pAttr)->pEncoder, nCID, pBuffer ,nLen );

					bsCodedString = CString( wchar_t(nCID) ).AllocSysString();
				}
				else
				{
					nCode = XmlUtils::GetInteger( oNode.GetAttribute( _T("code") ) );

					bsCodedString = CString( wchar_t(nCode) ).AllocSysString();
				}

			}
			else 
			{
				return S_OK;
			}
		}
		else
		{
			PToUnicode pToUnicode = FindToUnicodeForString( m_pDocument, bsUnicodeText );
			if ( !pToUnicode )
				return S_OK;

			CString sCodedString;
			BOOL bResult = ToUnicodeWCharToString( pToUnicode, bsUnicodeText, &sCodedString );

			USES_CONVERSION;

			if ( FAILED( hRes = GdiFontToPdfFont2( A2W( pToUnicode->sName ), FALSE ) ) )
			{
				if ( AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND == hRes )
				{
					ResetError( m_pDocument );
					sCodedString = CString( bsUnicodeText );
					bDefaultFont = TRUE;
				}
				else
				{
					return hRes;
				}
			}

			bsCodedString = sCodedString.AllocSysString();
		}


		long nAscent = 0;
		long nDescent = 0;
		long nXHeight = 0;

		double dItalicAngle = 3.141592f / 12;

		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( !m_oFont.Italic )
			dItalicAngle = 0;

		float fFontSize = (float)m_oFont.Size;

		if ( FAILED( hRes = GetFontAscent( &nAscent ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = GetFontDescent( &nDescent ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = GetFontXHeight( &nXHeight ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		// Выясним как нам рисовать текст
		ETextRenderingMode eRenderingMode = ETextRenderingMode::Fill; // Fill (по умолчанию)
		if ( c_nStrokeTextType == m_pCurCommand->nType )
			eRenderingMode = ETextRenderingMode::Stroke; // Stroke
		if ( c_nClipType == m_pCurCommand->nType )
		{
			ATLTRACE2( _T( "TextClip" ) );
			eRenderingMode = ETextRenderingMode::Clipping; // Clip
		}

		float fXHeight = (float)nXHeight / 1000;
		float fAscent  = (float)nAscent / 1000;
		float fDescent = fabs( (float)nDescent / 1000 );

		long nColor1 = m_oBrush.Color1;
		float fR = ( nColor1 & 0xFF ) / 255.0f; 
		float fG = ( ( nColor1 >> 8 ) & 0xFF ) / 255.0f; 
		float fB = ( nColor1 >> 16 ) / 255.0f; 
		float fTextWidth = 0.0f;
		float fLineWidth = fFontSize / ( bOldBold ? 10.f : 15.0f );
		float fOldLineWidth = 0.0f;

		if ( FAILED( hRes = GetLineWidth( &fOldLineWidth ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		float fFillR, fFillG, fFillB, fStrokeR, fStrokeG, fStrokeB;
		if ( FAILED( hRes = GetRGBFill( &fFillR, &fFillG, &fFillB ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = GetRGBStroke( &fStrokeR, &fStrokeG, &fStrokeB ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}
		// Рисуем тени

		if ( m_oShadow.Visible )
		{
			//if ( FAILED( hRes = GRestore() ) )
			//{
			//	::SysFreeString( bsCodedString );
			//	return hRes;
			//}
			ATLTRACE2( _T("GSave: DrawText - Shadow\n") );
			if ( FAILED( hRes = GSave() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = SetLineWidth( fLineWidth ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			// Выставляем систему координат
			if ( FAILED( hRes = UpdateCoordSpace(  ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}


			double dXShadow = fX + MMToPDFCoords( m_oShadow.DistanceX );
			double dYShadow = fY + MMToPDFCoords( m_oShadow.DistanceY );

			long nAlpha = m_oShadow.Alpha;
			long nShadowColor = m_oShadow.Color;

			float fAlpha = (float)nAlpha / 255.0f;
			float fBShadow = ( nShadowColor & 0xFF ) / 255.0f; 
			float fGShadow = ( ( nShadowColor >> 8 ) & 0xFF ) / 255.0f; 
			float fRShadow = ( nShadowColor >> 16 ) / 255.0f; 

			{
				XmlUtils::CXmlWriter oWriter;

				oWriter.WriteNodeBegin( _T("ExtGState") );

				if ( 255 != fAlpha )
				{
					oWriter.WriteNodeBegin( _T("AlphaFill"), TRUE );
					oWriter.WriteAttribute( _T("value"), (double)fAlpha );
					oWriter.WriteNodeEnd( _T("AlphaFill"), TRUE, TRUE );
				}

				if ( 255 != fAlpha )
				{
					oWriter.WriteNodeBegin( _T("AlphaStroke"), TRUE );
					oWriter.WriteAttribute( _T("value"), (double)fAlpha );
					oWriter.WriteNodeEnd( _T("AlphaStroke"), TRUE, TRUE );
				}

				oWriter.WriteNodeEnd( _T("ExtGState") );

				BSTR bsXml = oWriter.GetXmlString().AllocSysString();
				if ( FAILED( hRes = SetExtGraphicsState2( bsXml ) ) )
				{
					::SysFreeString( bsCodedString );
					::SysFreeString( bsXml );
					return hRes;
				}

				::SysFreeString( bsXml );
				//if ( FAILED( hRes = NewExtGraphicsState() ) )
				//{
				//	::SysFreeString( bsCodedString );
				//	return hRes;
				//}
				////if ( FAILED( hRes = ExtGraphicsStateSetBlendMode( EBlendMode::BMOverlay ) ) )
				////{
				////	::SysFreeString( bsCodedString );
				////	return hRes;
				////}
				//if ( FAILED( hRes = ExtGraphicsStateSetAlphaFill( fAlpha ) ) )
				//{
				//	::SysFreeString( bsCodedString );
				//	return hRes;
				//}
				//if ( FAILED( hRes = ExtGraphicsStateSetAlphaStroke( fAlpha ) ) )
				//{
				//	::SysFreeString( bsCodedString );
				//	return hRes;
				//}
				//if ( FAILED( hRes = SetExtGraphicsState() ) )
				//{
				//	::SysFreeString( bsCodedString );
				//	return hRes;
				//}

			}

			// Выставляем цвет текста и линий
			if ( FAILED( hRes = SetRGBFill( fRShadow, fGShadow, fBShadow ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = SetRGBStroke( fRShadow, fGShadow, fBShadow ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = BeginText() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			// Устанавливаем текущий фонт и размер фонта
			if ( FAILED( hRes = SetFontAndSizeToGState( fFontSize ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			// Если данный фонт не нашли с атрибутом Italic, тогда наколняем текст сами на угол dItalicAngle
			if ( FAILED( hRes = SetTextMatrix( 1, (float)tan( 0.0 ), (float)tan( dItalicAngle ), 1, 0, 0 ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( eRenderingMode == ETextRenderingMode::Fill  )
			{
				// Если данный фонт не нашли с атрибутом Bold, тогда заливаем и обводим текст, тем самым утолщяя его
				if ( m_oFont.Bold )
				{
					if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::FillThenStroke) ) )
					{
						::SysFreeString( bsCodedString );
						return hRes;
					}
				}
				else
					if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::Fill) ) )
					{
						::SysFreeString( bsCodedString );
						return hRes;
					}
			}
			else 
			{
				if ( FAILED( hRes = SetTextRenderingMode( (long)eRenderingMode ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
			}

			// Выводим текст
			if ( FAILED( hRes = TextOut( (float)dXShadow, fPageHeight - (float)(dYShadow + fBaseLineOffset) , bsCodedString ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}


			if ( FAILED( hRes = EndText() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			// Перечеркивание текста. Текст перечеркиваем по середине буквы 'x'. (См. XHeight)
			if ( m_oFont.Strikeout )
			{
				double dItalicAdd = tan( (double)dItalicAngle ) * fXHeight * fFontSize / 2;
				if ( !m_oFont.Italic )
					dItalicAdd = 0;
				if ( FAILED( hRes = MoveTo( (float)dXShadow + dItalicAdd, fPageHeight - (float)( dYShadow + fBaseLineOffset - fXHeight * fFontSize / 2 ) ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
				if ( FAILED( hRes = LineTo( (float)dXShadow + fTextWidth + dItalicAdd, fPageHeight - (float)( dYShadow + fBaseLineOffset - fXHeight * fFontSize / 2 ) ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
				if ( FAILED( hRes = Stroke( ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
			}

			// Подчеркивание текста.
			if ( m_oFont.Underline )
			{
				float fTextWidth = 0.0f;
				float fUnderLineOffset = 3 + fLineWidth / 2;
				if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
				if ( FAILED( hRes = MoveTo( (float)dXShadow, fPageHeight - ( (float)dYShadow + fBaseLineOffset + fUnderLineOffset /*fDescent * fFontSize*/ ) ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
				if ( FAILED( hRes = LineTo( (float)dXShadow + fTextWidth, fPageHeight - ( (float)dYShadow + fBaseLineOffset + fUnderLineOffset /*fDescent * fFontSize*/ ) ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
				if ( FAILED( hRes = Stroke( ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
			}

			ATLTRACE2( _T("GRestore: DrawText - Shadow\n") );
			if ( FAILED( hRes = GRestore() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		//if ( FAILED( hRes = GRestore() ) )
		//{
		//	::SysFreeString( bsCodedString );
		//	return hRes;
		//}

		// Дальше рисуем все, что непосредственно связанно с самим текстом
		// Выставляем цвет текста и линий

		if ( ETextRenderingMode::Fill == eRenderingMode )
		{
			if ( FAILED( hRes = SetRGBFill( fR, fG, fB ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			if ( FAILED( hRes = SetRGBStroke( fR, fG, fB ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}
		else
		{
			if ( FAILED( hRes = SetRGBFill( fR, fG, fB ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}


			if ( FAILED( hRes = SetRGBStroke( fR, fG, fB ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		// Выставляем систему координат
		if ( c_nClipType != m_pCurCommand->nType )
		{
			ATLTRACE2( _T("GSave: DrawText\n") );
			if ( FAILED( hRes = GSave() ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
			if ( FAILED( hRes = UpdateCoordSpace(  ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}
		else
		{
			if ( FAILED( hRes = UpdateCoordSpace(  ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		if ( FAILED( hRes = BeginText() ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		// Устанавливаем текущий фонт и размер фонта
		if ( FAILED( hRes = SetFontAndSizeToGState( fFontSize ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		// Если шрифт не нашли, и используется стандартный шрифт, значит, ширина слов будет неверной.
		// Чтобы слова не наползали друг на друга скейлим текст к его реальной ширине.
		if ( bDefaultFont )
		{
			// Измеряем размер
			float fTextWidth = 0.0f;
			if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}

			float fKoef = fWidth / fTextWidth * 100; // Scale задается в процентах

			if ( fKoef > 0.001 )
			{
				if ( FAILED( hRes = SetHorizontalScalling( fKoef ) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
			}
		}

		// Если данный фонт не нашли с атрибутом Italic, тогда наколняем текст сами на угол dItalicAngle
		if ( FAILED( hRes = SetTextMatrix( 1, (float)tan( 0.0 ), (float)tan( dItalicAngle ), 1, 0, 0 ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( ETextRenderingMode::Fill == eRenderingMode )
		{
			// Если данный фонт не нашли с атрибутом Bold, тогда заливаем и обводим текст, тем самым утолщяя его
			if ( m_oFont.Bold )
			{
				if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::FillThenStroke) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
			}
			else
				if ( FAILED( hRes = SetTextRenderingMode((long)ETextRenderingMode::Fill) ) )
				{
					::SysFreeString( bsCodedString );
					return hRes;
				}
		}
		else
		{
			if ( FAILED( hRes = SetTextRenderingMode( (long)eRenderingMode ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		// Выводим текст
		if ( FAILED( hRes = TextOut( (float)fX, fPageHeight - (float)(fY + fBaseLineOffset), bsCodedString ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = EndText() ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		if ( FAILED( hRes = SetLineWidth( fLineWidth ) ) )
		{
			::SysFreeString( bsCodedString );
			return hRes;
		}

		// Перечеркивание текста. Текст перечеркиваем по середине буквы 'x'. (См. XHeight)
		if ( m_oFont.Strikeout )
		{
			double dItalicAdd = tan( (double)dItalicAngle ) * fXHeight * fFontSize / 2;
			if ( !m_oFont.Italic )
				dItalicAdd = 0;
			if ( FAILED( hRes = MoveTo( (float)fX + dItalicAdd, fPageHeight - (float)( fY + fBaseLineOffset - fXHeight * fFontSize / 2 ) ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
			if ( FAILED( hRes = LineTo( (float)fX + fTextWidth + dItalicAdd, fPageHeight - (float)( fY + fBaseLineOffset - fXHeight * fFontSize / 2 ) ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
			if ( FAILED( hRes = Stroke( ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
			//MoveTo(dX, dY - fDescent * fFontSize );
			//LineTo(dX + dItalicAdd * 2, dY + fFontSize * ( 1 - fDescent ) );
			//LineTo(dX + fTextWidth + dItalicAdd * 2, dY + fFontSize * ( 1 - fDescent ) );
			//LineTo(dX + fTextWidth, dY - fDescent * fFontSize );
			//LineTo(dX, dY - fDescent * fFontSize );
			//Stroke();
		}

		// Подчеркивание текста.
		if ( m_oFont.Underline )
		{
			float fTextWidth = 0.0f;
			float fUnderLineOffset = 3 + fLineWidth / 2;
			if ( FAILED( hRes = GetTextWidth( bsCodedString, &fTextWidth ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
			if ( FAILED( hRes = MoveTo( (float)fX, fPageHeight - (float)(fY + fBaseLineOffset + fUnderLineOffset) /*fDescent * fFontSize*/ ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
			if ( FAILED( hRes = LineTo( (float)fX + fTextWidth, fPageHeight - (float)(fY + fBaseLineOffset + fUnderLineOffset) /*fDescent * fFontSize*/ ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
			if ( FAILED( hRes = Stroke( ) ) )
			{
				::SysFreeString( bsCodedString );
				return hRes;
			}
		}

		::SysFreeString( bsCodedString );

		// Восстанавливаем систему координат
		if ( c_nClipType != m_pCurCommand->nType )
		{
			ATLTRACE2( _T("GRestore: DrawText\n") );
			if ( FAILED( hRes = GRestore() ) )
				return hRes;
		}
		else
		{
			float fDelta = m_oClipCTM.fA * m_oClipCTM.fD - m_oClipCTM.fB * m_oClipCTM.fC;
			if ( 0.0f != fDelta  )
			{
				float fIDelta = 1 / fDelta;
				float fA =  fIDelta * m_oClipCTM.fD;
				float fB =  fIDelta * ( -m_oClipCTM.fB );
				float fC =  fIDelta * ( -m_oClipCTM.fC );
				float fD =  fIDelta * m_oClipCTM.fA;
				float fE =  fIDelta * (m_oClipCTM.fC * m_oClipCTM.fF - m_oClipCTM.fE * m_oClipCTM.fD);
				float fF =  fIDelta * (m_oClipCTM.fE * m_oClipCTM.fB - m_oClipCTM.fA * m_oClipCTM.fF);

				// Делаем матрицу CTM единичной
				if ( FAILED( hRes = Concat( fA, fB, fC, fD, fE, fF ) ) )
					return hRes;
			}

			m_oClipCTM.Set( 1, 0, 0, 1, 0, 0 );
		}

		// Восстанавливаем старые настройки
		if ( FAILED( hRes = SetLineWidth( fOldLineWidth ) ) )
			return hRes;

		if ( FAILED( hRes = SetRGBFill( fFillR, fFillG, fFillB ) ) )
			return hRes;

		if ( FAILED( hRes = SetRGBStroke( fStrokeR, fStrokeG, fStrokeB ) ) )
			return hRes;

		m_oFont.Bold   = bOldBold;
		m_oFont.Italic = bOldItalic;

		return S_OK;
	}
	//--------- Маркеры для команд -------------------------------------------------------------------
	STDMETHOD(BeginCommand)(DWORD nFlag)
	{
		wchar_t sTemp[32];		
		_itow(nFlag, sTemp, 10);

		if (c_nPathType == nFlag)
			ATLTRACE2(_T("Begin") + CString(_T(" - PathType")) + _T("\n"));
		else if (c_nClipType == nFlag)
			ATLTRACE2(_T("Begin") + CString(_T(" - ClipType")) + _T("\n"));
		else if (c_nResetClipType == nFlag)
			ATLTRACE2(_T("Begin") + CString(_T(" - ResetClipType")) + _T("\n"));
		else if ( c_nPageType == nFlag )
			ATLTRACE2(_T("Begin") + CString(_T(" - PageType")) + _T("\n"));
		else
			ATLTRACE2(_T("Begin") + CString(sTemp) + _T("\n"));

		if ( nFlag == c_nTableCell || nFlag == c_nHeader || nFlag == c_nColumnCount || nFlag == c_nFootnote
			|| nFlag == c_nShape || nFlag == c_nShapeGroup || nFlag == c_nShapeWrap || nFlag == c_nTable 
			|| nFlag == c_nTableXml || nFlag == c_nBlock || nFlag == c_nBlockHeadingLevel || nFlag == c_nBlockNumberingLevel
			|| nFlag == c_nBaselineShift 
			)
			return S_OK;

		TCommandType *pNewCommand = new TCommandType();
		pNewCommand->nType = nFlag;
		pNewCommand->pPrev = m_pCurCommand;
		m_pCurCommand = pNewCommand;

		HRESULT hRes = S_OK;
		if ( c_nPathType == nFlag )
		{
			SetState( rendstatePath );
			// Сейчас начинаем рисовать Path

			m_BlockCommandsStart = ((PageAttr)m_pDocument->pCurPage->pAttr)->pStream->nSize;		
			
			ATLTRACE2( _T("GSave: PathType\n") );
			if ( FAILED( hRes = UpdateGState() ) )
				return hRes;

			int c = 0;
		}
		else if ( c_nClipType == nFlag )
		{
			// Запоминаем состояние без обрезающего пата
			if ( FALSE == m_bClipPath )
			{
				ATLTRACE2( _T("GSave: ClipPathType\n") );
				if ( FAILED( hRes = GSave() ) )
					return hRes;

				m_bClipPath = TRUE;
			}
		}
		else if ( c_nResetClipType == nFlag )
		{
			// Откатываемся к состоянию без обрезающего пата
			if ( TRUE == m_bClipPath )
			{
				SetState( rendstateClipReset );

				ATLTRACE2( _T("GRestore: ClipPathType\n") );
				if ( FAILED( hRes = GRestore() ) )
					return hRes;

				m_oClipCTM.Set( 1, 0, 0, 1, 0, 0 );

				m_bClipPath = FALSE;
			}
		}

		return S_OK;
	}
	STDMETHOD(EndCommand)(DWORD nFlag)
	{
		wchar_t sTemp[32];		
		_itow(nFlag, sTemp, 10);

		if (c_nPathType == nFlag)
			ATLTRACE2( _T("End") + CString( _T(" - PathType") ) + _T("\n") );
		else if (c_nPageType == nFlag)
			ATLTRACE2( _T("End") + CString( _T(" - PageType") ) + _T("\n") );
		else if (c_nResetClipType == nFlag)
			ATLTRACE2( _T("End") + CString( _T(" - ResetClipType") ) + _T("\n") );
		else if ( c_nClipType == nFlag )
			ATLTRACE2( _T("End") + CString( _T(" - ClipType") ) + _T("\n") );
		else 
			ATLTRACE2( _T("End") + CString( sTemp ) + _T("\n") );

		if (nFlag == c_nTableCell || nFlag == c_nHeader || nFlag == c_nColumnCount || nFlag == c_nFootnote
			|| nFlag == c_nShape || nFlag == c_nShapeGroup || nFlag == c_nShapeWrap || nFlag == c_nTable 
			|| nFlag == c_nTableXml || nFlag == c_nBlock || nFlag == c_nBlockHeadingLevel || nFlag == c_nBlockNumberingLevel || nFlag == c_nBaselineShift)
		{
			return S_OK;
		}

		if ( !m_pCurCommand || nFlag != m_pCurCommand->nType  )
			return AVS_OFFICEPDFWRITER_ERROR_BAD_COMMAND_TYPE;

		HRESULT hRes = S_OK;
		if (c_nPathType == nFlag)
		{
			// Если данный пат набивался как клип, тогда мы должны подать команду о завершении
			if ( NULL != m_pCurCommand->pPrev && c_nClipType == m_pCurCommand->pPrev->nType )
			{ 
				if ( c_nClipRegionTypeWinding == m_pCurCommand->nFlag )
				{
					if ( FAILED( hRes = Clip() ) )
						return hRes;
				}
				else if ( c_nClipRegionTypeEvenOdd == m_pCurCommand->nFlag )
				{
					if ( FAILED( hRes = EoClip() ) )
						return hRes;
				}

				if ( FAILED( hRes = EndPath() ) )
					return hRes;

				float fDelta = m_oClipCTM.fA * m_oClipCTM.fD - m_oClipCTM.fB * m_oClipCTM.fC;
				if ( 0.0f != fDelta  )
				{
					float fIDelta = 1 / fDelta;
					float fA =  fIDelta * m_oClipCTM.fD;
					float fB =  fIDelta * ( -m_oClipCTM.fB );
					float fC =  fIDelta * ( -m_oClipCTM.fC );
					float fD =  fIDelta * m_oClipCTM.fA;
					float fE =  fIDelta * (m_oClipCTM.fC * m_oClipCTM.fF - m_oClipCTM.fE * m_oClipCTM.fD);
					float fF =  fIDelta * (m_oClipCTM.fE * m_oClipCTM.fB - m_oClipCTM.fA * m_oClipCTM.fF);

					// Делаем матрицу CTM единичной
					if ( FAILED( hRes = Concat( fA, fB, fC, fD, fE, fF ) ) )
						return hRes;
				}

			}
			else
			{
				ATLTRACE2( _T("GRestore: PathType\n") );
				if ( FAILED( hRes = GRestore() ) )
					return hRes;
			}
		}
		else if ( c_nPageType == nFlag )
		{
			SetState( rendstateNone );
		}

		TCommandType *pPrev = m_pCurCommand->pPrev;
		delete m_pCurCommand;
		m_pCurCommand = pPrev;

		return S_OK;
	}
	//--------- Функции для работы с Graphics Path ---------------------------------------------------
	STDMETHOD(PathCommandStart)()
	{
		ATLTRACE2( _T("Start\n") );

		if ( CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath || (m_oPatternState.IsUse() && m_pCurPath))
			m_pCurPath->Start();

		//BSTR bsError;
		//GetLastErrorString(&bsError);
		//HRESULT hRes = S_OK;
		//if ( FAILED ( hRes = EndPath() ) ) 
		//	return hRes;
		m_bStartSubPath = TRUE;
		return S_OK;
	}	
	STDMETHOD(PathCommandEnd)()
	{
		ATLTRACE2( _T("End\n") );

		if (CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath || (m_oPatternState.IsUse() && m_pCurPath))
			m_pCurPath->End();

		//HRESULT hRes = S_OK;
		//if ( FAILED ( hRes = EndPath() ) ) 
		//	return hRes;
		//m_bStartSubPath = TRUE;

		// NOTE : решение хардкорное 

		// градиент имеет прозрачность, поэтому все команды перемещаем в форму
		// TODO : переписать запись команд таким образом что бы они сыпались во временный объект

		if (m_MaskWithFormCommands.GetLength())
		{
			if (m_XForm)
			{
				Stream stream			=	((PageAttr)m_pDocument->pCurPage->pAttr)->pStream;
				unsigned int bufferSize =	stream->nSize - m_BlockCommandsStart;
				if (bufferSize && stream)
				{
					CStringA str;
					CHAR* buffer		=	str.GetBuffer(bufferSize + 1);
					if (buffer)
					{
						StreamSeek(stream, m_BlockCommandsStart, WhenceMode::SeekSet);
						StreamRead(stream, (BYTE*)buffer, &bufferSize);
						StreamSeek(stream, m_BlockCommandsStart, WhenceMode::SeekWrite);

						buffer[bufferSize] = L'\0';

						CString data(str);
						m_XForm->SetStream(data);

						// Example : q /s13 gs /x14 Do Q
						// к /x объекту применяется маска /s

						StreamWriteStr(stream, CStringA(m_MaskWithFormCommands));

						if (m_IsStrokeShape)
						{
						
							if (m_strPatternFill.GetLength())	data.Replace(m_strPatternFill, L"");
							if (m_strPatternStroke.GetLength()) data.Replace(m_strPatternStroke, L"");
							
							data.Replace(L"B\012", L"S\012");
							data.Replace(L"f\012", L"s\012");
						
							data.Replace(L"B*\012", L"S*\012");
							data.Replace(L"f*\012", L"s*\012");

							StreamWriteStr(stream, CStringA(data));
						}

						str.ReleaseBuffer();
					}
				}
			}

			m_BlockCommandsStart	=	0;			

			m_XForm					=	NULL;
			m_MaskWithFormCommands	=	L"";
			m_IsStrokeShape			=	FALSE;
			
			m_strPatternFill		=	L"";
			m_strPatternStroke		=	L"";
		}

		return S_OK;
	}
	//
	STDMETHOD(PathCommandMoveTo) (double fX,  double fY)
	{
		ATLTRACE2( _T("Move To\n") );

		HRESULT hRes = S_OK;

		if ( TRUE == m_bFirstMoveTo )
		{
			// Текущее состояние - Path
			SetState( /*m_bClip ? rendstateClipPath :*/ rendstatePath );

			m_bFirstMoveTo = FALSE;
		}

		if ( !m_bStartSubPath || m_oPatternState.IsUse())
		{
			if ( CGdiPath::c_nTextureBrush == m_oBrush.Type || m_oPatternState.IsUse())
			{
				if (m_oPatternState.IsUse())
				{
					if (NULL == m_pCurPath)
					{
						m_pCurPath = new CGdiPath();
						m_pCurPath->Create();
					}
				}
				else 
				{
					if (m_pCurPath)
						m_pCurPath->Delete();
					else
						m_pCurPath = new CGdiPath();

					m_pCurPath->Create();
				}
			}
		}

		if ( CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath || (m_oPatternState.IsUse() && m_pCurPath))
			m_pCurPath->MoveTo( fX, fY );

		fX = MMToPDFCoords( fX );
		fY = MMToPDFCoords( fY );

		m_bStartSubPath = FALSE;
		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;
		if ( FAILED( hRes = MoveTo( fX, fPageHeight - fY ) ) )
			return hRes;
		return S_OK;
	}
	STDMETHOD(PathCommandLineTo) (double fX,  double fY)
	{
		ATLTRACE2( _T("Line To\n") );

		if ( CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath || (m_oPatternState.IsUse() && m_pCurPath))
			m_pCurPath->LineTo( fX, fY );

		fX = MMToPDFCoords( fX );
		fY = MMToPDFCoords( fY );

		HRESULT hRes = S_OK;
		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;
		if ( FAILED( hRes = LineTo( fX, fPageHeight - fY ) ) )
			return hRes;
		return S_OK;
	}
	STDMETHOD(PathCommandLinesTo) (SAFEARRAY *pPoints)
	{
		ATLTRACE2( _T("Lines To\n") );

		if ( CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath || (m_oPatternState.IsUse() && m_pCurPath))
			m_pCurPath->LinesTo( &pPoints );


		HRESULT hRes = S_OK;
		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;
		if ( 1 != SafeArrayGetDim(pPoints) )
			return AVS_OFFICEPDFWRITER_ERROR_BAD_SAFEARRAY;

		VARTYPE vType;
		// check for valid array element type
		if ( FAILED(SafeArrayGetVartype(pPoints, &vType)) || VT_R8 != vType )
			return AVS_OFFICEPDFWRITER_ERROR_BAD_SAFEARRAY;

		double* pArray = (double*)(pPoints)->pvData;
		int nPointsCount = (pPoints)->rgsabound->cElements / 2;

		if ( m_bStartSubPath )
		{
			//if ( FAILED( hRes = GRestore() ) )
			//	return hRes;			
			if ( FAILED( hRes = PathCommandMoveTo( pArray[0], pArray[1] ) ) )
				return hRes;			
		}
		pArray += 2;
		nPointsCount--;

		for ( int nIndex = 0; nIndex < nPointsCount; nIndex++, pArray += 2 )
			if ( FAILED( hRes = LineTo( MMToPDFCoords( pArray[0] ), fPageHeight - MMToPDFCoords( pArray[1] ) ) ) )
				return hRes;

		return S_OK;
	}
	STDMETHOD(PathCommandCurveTo)(double fX1, double fY1, double fX2, double fY2, double fX3, double fY3)
	{
		ATLTRACE2( _T("Curve To\n") );

		if ( CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath|| (m_oPatternState.IsUse() && m_pCurPath) )
			m_pCurPath->CurveTo( fX1, fY1, fX2, fY2, fX3, fY3 );

		HRESULT hRes = S_OK;
		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;
		if ( FAILED( hRes = CurveTo( MMToPDFCoords( fX1 ), fPageHeight - MMToPDFCoords( fY1 ), MMToPDFCoords( fX2 ), fPageHeight - MMToPDFCoords( fY2 ), MMToPDFCoords( fX3 ), fPageHeight - MMToPDFCoords( fY3 ) ) ) )
			return hRes;
		return S_OK;
	}
	STDMETHOD(PathCommandCurvesTo)(SAFEARRAY *pPoints)
	{
		ATLTRACE2( _T("Curves To\n") );

		if ( CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath || (m_oPatternState.IsUse() && m_pCurPath))
			m_pCurPath->CurvesTo( &pPoints );

		HRESULT hRes = S_OK;
		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;
		if ( 1 != SafeArrayGetDim(pPoints) )
			return AVS_OFFICEPDFWRITER_ERROR_BAD_SAFEARRAY;

		VARTYPE vType;
		// check for valid array element type
		if ( FAILED(SafeArrayGetVartype(pPoints, &vType)) || VT_R8 != vType )
			return AVS_OFFICEPDFWRITER_ERROR_BAD_SAFEARRAY;		

		double* pArray = (double*)(pPoints)->pvData;
		int nPointsCount = (pPoints)->rgsabound->cElements / 2;

		if ( m_bStartSubPath )
		{
			//if ( FAILED( hRes = GRestore() ) )
			//	return hRes;			
			if ( FAILED( hRes = PathCommandMoveTo( pArray[0], pArray[1] ) ) )
				return hRes;			
		}

		pArray += 2;
		nPointsCount--;

		for ( int nIndex = 0; nIndex < nPointsCount / 3; nIndex++, pArray += 6 )
		{
			if ( FAILED( hRes = CurveTo( MMToPDFCoords( pArray[0] ), fPageHeight - MMToPDFCoords( pArray[1] ), MMToPDFCoords( pArray[2] ), fPageHeight - MMToPDFCoords( pArray[3] ), MMToPDFCoords( pArray[4] ), fPageHeight - MMToPDFCoords( pArray[5] ) ) ) )
				return hRes;
		}
		return S_OK;
	}
	STDMETHOD(PathCommandArcTo) (double fX, double fY, double fWidth, double fHeight, double fStartAngle, double fSweepAngle)
	{
		ATLTRACE2( _T("Arc To\n") );

		if ( CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath || (m_oPatternState.IsUse() && m_pCurPath))
			m_pCurPath->ArcTo( fX, fY, fWidth, fHeight, fStartAngle, fSweepAngle );

		fX = MMToPDFCoords( fX );
		fY = MMToPDFCoords( fY );
		fWidth = MMToPDFCoords( fWidth );
		fHeight = MMToPDFCoords( fHeight );

		HRESULT hRes = S_OK;
		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;

		if ( m_bStartSubPath )
		{
			double dStartAngle = fStartAngle * 3.141592f / 180;
			float fStartX = fX + fWidth / 2.0f + fWidth / 2 * cos( AngToEllPrm( dStartAngle, fWidth / 2, fHeight / 2 ) );
			float fStartY = fY + fHeight / 2.0f + fHeight / 2 * sin( AngToEllPrm ( dStartAngle, fWidth / 2, fHeight / 2 ) );

			// Аналог PathCommandMoveTo, но без пересчета координат
			m_bStartSubPath = FALSE;

			// В случае, когда эллипс рисуется целиком используется команда AppendEllipse, в которой команда MoveTo уже есть
			if ( !( fSweepAngle >= 360 ) )
				if ( FAILED( hRes = MoveTo( fStartX, fPageHeight - fStartY ) ) )
					return hRes;			

		}


		BOOL bClockDirection = FALSE;
		float fEndAngle = 360 - ( fSweepAngle + fStartAngle );
		float fSrtAngle = 360 - fStartAngle;
		if( fSweepAngle > 0 )
			bClockDirection = TRUE;

		if( fSweepAngle >= 360 ) // Целый эллипс
		{
			if ( FAILED( hRes = AppendEllipse( fX + fWidth / 2, fPageHeight - ( fY + fHeight / 2 ), fWidth / 2,  fHeight / 2 ) ) )
				return hRes;
		}
		else // Дуга эллипса
		{
			if ( FAILED ( hRes = AppendEllipseArc( fX + fWidth / 2, fPageHeight - ( fY + fHeight / 2 ), fWidth / 2,  fHeight / 2,  fSrtAngle, fEndAngle, bClockDirection ) ) )
				return hRes;
		}
		return S_OK;
	}
	STDMETHOD(PathCommandClose)()
	{
		ATLTRACE2( _T("Close\n") );

		if (CGdiPath::c_nTextureBrush == m_oBrush.Type && m_pCurPath || (m_oPatternState.IsUse() && m_pCurPath))
			m_pCurPath->Close();

		HRESULT hRes = S_OK;
		if (FAILED(hRes = ClosePath())) 
			return hRes;

		m_bStartSubPath = TRUE;

		return S_OK;
	}
	//
	STDMETHOD(DrawPath)(long nType)
	{
		m_bFirstMoveTo	=	TRUE;
		m_IsStrokeShape	=	FALSE;

		// Обводка текста делается в CommandDrawText (а эта команда приходит для согласования с вьювером)
		
		if (c_nStrokeTextType == m_pCurCommand->nType)
			return S_OK;

		ATLTRACE2(_T("Draw Path\n"));

		// TO DO: Потом надо будет этот случай убрать
		if ( 0 == nType )
			nType = c_nStroke;

		m_bStartSubPath = FALSE;

		BOOL IsBrushTexture		=	CGdiPath::c_nTextureBrush == m_oBrush.Type;
		BOOL IsNoStroke			=	c_nStroke != nType;
		BOOL IsBrushFileExist	=	FileExist(m_oBrush.TexturePath);

		HRESULT hRes = S_OK;
		if (IsBrushTexture && IsNoStroke && IsBrushFileExist && (m_pCurPath || m_bUseTextureRect))
		{
			if (c_BrushTextureModeStretch == m_oBrush.TextureMode)
			{
				// Меняем текущее состояние с пата на клип по пату и добавляем данный пат к клипу
				
				m_oRendererState.change_State(rendstateClipPath);
				SetState(rendstateNone);

				if (c_nWindingFillMode & nType)
				{
					if (FAILED(hRes = Clip()))
						return hRes;
				}
				else if (c_nEvenOddFillMode & nType)
				{
					if (FAILED(hRes = EoClip()))
						return hRes;
				}
				else
				{
					return S_FALSE;
				}

				if (FAILED(hRes = EndPath()))
					return hRes;

				float fX = 0, fY = 0, fW = 0, fH = 0;

				if (TRUE != m_bUseTextureRect)
				{
					m_pCurPath->GetBounds(&fX, &fY, &fW, &fH);
				}
				else
				{
					fX = m_oBrush.Rect.X;
					fY = m_oBrush.Rect.Y;
					fW = m_oBrush.Rect.Width;
					fH = m_oBrush.Rect.Height;
				}

				CString sPath = m_oBrush.TexturePath;
				BSTR bsPath = sPath.AllocSysString();

				m_bUseImageTransform    =	FALSE;
				m_bUseImageTextureAlpha =	TRUE;	

				if (FAILED(hRes = DrawImageFromFile(bsPath, fX, fY, fW, fH)))
				{
					::SysFreeString(bsPath);
					ResetError(m_pDocument);
					return hRes;
				}

				m_bUseImageTransform    =	TRUE;
				m_bUseImageTextureAlpha	=	FALSE;	

				SysFreeString(bsPath);	

				return S_OK;
			}
			else if (c_BrushTextureModeTile == m_oBrush.TextureMode)
			{
				ApplyTileFill();
			}

			// TODO: добавить тайловые заливки с реверсным узором
		}
		else if (IsBrushTexture && IsNoStroke && !IsBrushFileExist)
		{
			if (c_nWindingFillMode & nType)
				nType = c_nWindingFillMode;
			else 
				nType = c_nEvenOddFillMode;
		}

		ApplyFillGradient();
		ApplyStrokeGradient();

		if (c_nWindingFillMode != nType && c_nEvenOddFillMode != nType)
		{
			m_IsStrokeShape = TRUE;
		}

		RELEASEOBJECT(m_pCurPath);

		switch (nType)
		{
		case c_nStroke:							if (FAILED(hRes = Stroke()))		{	ATLTRACE2(_T("Stroke\n"));			return hRes; } break; 
		case c_nWindingFillMode:				if (FAILED(hRes = Fill()))			{	ATLTRACE2(_T("Fill\n"));			return hRes; } break; 
		case c_nEvenOddFillMode:				if (FAILED(hRes = EoFill()))		{	ATLTRACE2(_T("EoFill\n"));			return hRes; } break; 
		case c_nStroke | c_nWindingFillMode:	if (FAILED(hRes = FillStroke()))	{	ATLTRACE2(_T("FillStroke\n"));		return hRes; } break; 
		case c_nStroke | c_nEvenOddFillMode:	if (FAILED(hRes = EoFillStroke()))	{	ATLTRACE2(_T("EoFillStroke\n"));	return hRes; } break; 
		default:
			{
				if (FAILED(hRes = Stroke())) 
				{
					ATLTRACE2(_T("Stroke\n"));
					return hRes;  
				}
				else
					return AVS_OFFICEPDFWRITER_ERROR_DRAW_PATH;
			}
		}

		return S_OK;
	}

	STDMETHOD(PathCommandGetCurrentPoint)(double *pfX, double *pfY)
	{
		ATLTRACE2( _T("GetCurrentPoint\n") );

		HRESULT hRes = S_OK;
		float fPageHeight = 0.0f, fX = 0.0f, fY = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;

		if ( FAILED ( hRes = GetCurrentPosition( &fX, &fY ) ) ) 
			return hRes;

		fY = fPageHeight - fY;

		*pfX = (double)fX;
		*pfY = (double)fY;

		return S_OK;
	}
	STDMETHOD(PathCommandText)  (BSTR bsText, double fX, double fY, double fWidth, double fHeight, double fBaseLineOffset )
	{
		// В данная команда может прийти либо для обводки текста, либо для клипа по тексту
		CommandDrawText( bsText, fX, fY, fWidth, fHeight, fBaseLineOffset );
		return S_OK;
	}

	STDMETHOD(PathCommandTextEx)(BSTR bsUnicodeText, BSTR bsGidText, BSTR bsSrcCodeText, double fX, double fY, double fWidth, double fHeight, double fBaseLineOffset, DWORD nFlags )
	{
		// В данная команда может прийти либо для обводки текста, либо для клипа по тексту
		CommandDrawTextEx( bsUnicodeText, bsGidText, bsSrcCodeText, fX, fY, fWidth, fHeight, fBaseLineOffset, nFlags );
		return S_OK;
	}

	//--------- Функции для вывода изображений -------------------------------------------------------
	STDMETHOD(DrawImage)(IUnknown *pInterface, double fX, double fY, double fWidth, double fHeight)
	{
		SetState( rendstateImage );

		//BeginCommand( c_nPathType );
		//PathCommandMoveTo( fX, fY );
		//PathCommandLineTo( fX + fWidth, fY + fHeight );
		//DrawPath( c_nWindingFillMode );
		//EndCommand( c_nPathType );

		fX = MMToPDFCoords( fX );
		fY = MMToPDFCoords( fY );
		fWidth = MMToPDFCoords( fWidth );
		fHeight = MMToPDFCoords( fHeight );


		//if ( fWidth < 1 || fHeight < 1 )
		//	return S_OK;

		HRESULT hRes = S_OK;
		float fPageHeight = 0.0f;

		if ( FAILED( hRes = GetHeight( &fPageHeight ) ) )
			return hRes;
		if ( FAILED ( hRes = LoadImageFromInterface( &pInterface, TRUE ) ) )
			return hRes;

		ATLTRACE2( _T("GSave: DrawImage\n") );
		if ( FAILED( hRes = GSave() ) )
			return hRes;

		//if ( FAILED( hRes = UpdateCoordSpace() ) )
		//	return hRes;

		if ( TRUE == m_bUseImageTransform )
		{
			DWORD  nFlags  = m_oCommandParams.nFlag;
			if ( !( nFlags == 16 ) )
			{
				double dAngle  = m_oCommandParams.dAngle;
				double dLeft   = m_oCommandParams.dLeft;
				double dHeight = m_oCommandParams.dHeight;
				double dWidth  = m_oCommandParams.dWidth;
				double dTop    = m_oCommandParams.dTop;

				if ( !(0 == nFlags && 0 == dAngle) )
				{
					// Миллиметры -> координаты PDF (72dpi)

					dLeft   = MMToPDFCoords( dLeft );
					dTop    = MMToPDFCoords( dTop );
					dWidth  = MMToPDFCoords( dWidth );
					dHeight = MMToPDFCoords( dHeight );

					dTop = fPageHeight - dTop;
					dAngle =  dAngle * 3.141592f / 180;

					// Высчитываем центр прямоугольника ( относительно него производится поворот )

					double dX0 = dLeft + dWidth  / 2;
					double dY0 = dTop  - dHeight / 2;

					double dA =  cos( dAngle );
					double dB =  sin( dAngle );
					double dC = -sin( dAngle );
					double dD =  cos( dAngle );
					double dE = dX0 - dX0 * cos ( dAngle ) + dY0 * sin( dAngle );
					double dF = dY0 - dX0 * sin ( dAngle ) - dY0 * cos( dAngle );

					BOOL bFlipX = nFlags & 1;
					BOOL bFlipY = nFlags & 2;

					if ( !bFlipX && !bFlipY )
					{
						// Ничего не делаем
					}
					else if ( bFlipX && !bFlipY )
					{
						dA = -dA;
						dC = -dC;
						dE = -dE + 2 * dX0;
					}
					else if ( !bFlipX && bFlipY )
					{
						dB = -dB;
						dD = -dD;
						dF = -dF + 2 * dY0;
					}
					else
					{
						dA = -dA;
						dB = -dB;
						dC = -dC;
						dD = -dD;
						dE = -dE + 2 * dX0;
						dF = -dF + 2 * dY0;
					}

					if ( FAILED( hRes = Concat( dA, dB, dC, dD, dE, dF ) ) )
						return hRes;
				}
			}
			else
			{
				float fA = m_oCommandParams.oMatrix.fA;
				float fB = m_oCommandParams.oMatrix.fB;
				float fC = m_oCommandParams.oMatrix.fC;
				float fD = m_oCommandParams.oMatrix.fD;
				float fE = m_oCommandParams.oMatrix.fE;
				float fF = m_oCommandParams.oMatrix.fF;

				if ( FAILED( hRes = Concat( fA, -fB, -fC, fD, MMToPDFCoords( fE ) + fC * fPageHeight, fPageHeight - fPageHeight * fD - MMToPDFCoords( fF ) ) ) )
					return hRes;
			}
		}

		if ( FAILED ( hRes = DrawCurrentImage( fX, fPageHeight - fY - fHeight, fWidth, fHeight ) ) )
			return hRes;

		ATLTRACE2( _T("GRestore: DrawImage\n") );
		if ( FAILED( hRes = GRestore() ) )
			return hRes;

		return S_OK;
	}
	STDMETHOD(DrawImageFromFile)(BSTR bsFilePath, double fX, double fY, double fWidth, double fHeight)
	{
		NSImageExt::CImageExt oExt;

#ifdef BUILD_CONFIG_FULL_VERSION
		AVSGraphics::IASCRenderer* render = NULL;
		if (SUCCEEDED(QueryInterface(__uuidof(AVSGraphics::IASCRenderer), (void**)&render)))
		{
			if (render)
			{
				BOOL bRes = oExt.DrawOnRenderer(render, bsFilePath, fX, fY, fWidth, fHeight);
				RELEASEINTERFACE(render);

				if (bRes)
					return S_OK;
			}
		}
#endif

		IUnknown* pImage = ImageUtils::LoadImage(CString(bsFilePath));
		if (NULL == pImage)
			return S_FALSE;

		if ((m_bUseImageTextureAlpha || m_bIsWhiteBackImage) && (NULL != pImage))
		{
			MediaCore::IAVSUncompressedVideoFrame* pUnFrame = NULL;
			pImage->QueryInterface(&pUnFrame);

			if (NULL != pUnFrame)
			{
				LONG lWidth		= 0;
				LONG lHeight	= 0;
				BYTE* pBuffer	= NULL;

				pUnFrame->get_Width(&lWidth);
				pUnFrame->get_Height(&lHeight);
				pUnFrame->get_Buffer(&pBuffer);

				LONG lCountPix = lWidth * lHeight;

				if ( m_bIsWhiteBackImage )
				{
					while (lCountPix > 0)
					{
						if (0 == pBuffer[3])
							memset(pBuffer, 0xFF, 4);

						--lCountPix;
						pBuffer += 4;
					}
				}
				else if ( m_bUseImageTextureAlpha )
				{
					while (lCountPix > 0)
					{
						pBuffer[3] *= ((double)m_oBrush.TextureAlpha / 255.0);
						--lCountPix;
						pBuffer += 4;
					}
				}

				RELEASEINTERFACE(pUnFrame);
			}
		}

		HRESULT hRes = S_OK;
		if (FAILED(hRes = DrawImage(pImage, fX, fY, fWidth, fHeight)))
		{
			RELEASEINTERFACE(pImage);
			return hRes;
		}

		RELEASEINTERFACE(pImage);
		
		return S_OK;
	}
	//--------- Transform ----------------------------------------------------------------------------
	STDMETHOD(GetCommandParams)(double *pdAngle, double *pdLeft, double *pdTop, double *pdWidth, double *pdHeight, DWORD *pnFlags )
	{
		*pdAngle  = -m_oCommandParams.dAngle;
		*pdLeft   = m_oCommandParams.dLeft;
		*pdHeight = m_oCommandParams.dHeight;
		*pdWidth  = m_oCommandParams.dWidth;
		*pdTop    = m_oCommandParams.dTop;
		*pnFlags  = m_oCommandParams.nFlag;

		return S_OK;
	}
	STDMETHOD(SetCommandParams)(double   dAngle, double   dLeft, double   dTop, double   dWidth, double   dHeight, DWORD   nFlags )
	{
		if ( 0 != nFlags )
			ATLTRACE2( _T("SetCommandParams: Flip <--------------------------------------------- \n") );
		HRESULT hRes = S_OK;

		m_oCommandParams.dAngle  = -dAngle;
		m_oCommandParams.dLeft   = dLeft;
		m_oCommandParams.dHeight = dHeight;
		m_oCommandParams.dWidth  = dWidth;
		m_oCommandParams.dTop    = dTop;
		m_oCommandParams.nFlag   = nFlags;

		if ( !(0 == nFlags && 0 == dAngle) )
		{
			LONG lLeft   = dLeft;
			LONG lTop    = dTop;
			LONG lWidth  = dWidth;
			LONG lHeight = dHeight;

			dAngle =  dAngle * 3.141592f / 180;

			// Высчитываем центр прямоугольника ( относительно него производится поворот )

			double dX0 = lLeft + lWidth  / 2;
			double dY0 = lTop  + lHeight / 2;

			// Рассчитываем flip
			BOOL bFlipX = ( 0 != ( 1 & nFlags ) );
			BOOL bFlipY = ( 0 != ( 2 & nFlags ) );

			LONG lFlipX = bFlipX ? -1 : 1;
			LONG lFlipY = bFlipY ? -1 : 1;

			// Наше преобразование можно записать в виде произведения матриц:
			// 
			// |  1   0  0 |   | cos(p) sin(p) 0 |   | ScaleX   0     0 |   | 1   0   0 | 
			// |  0   1  0 | * |-sin(p) cos(p) 0 | * |   0    ScaleY  0 | * | 0   1   0 |
			// |-X0 -Y0  1 |   |   0      0    1 |   |   0      0     1 |   | X0  Y0  1 |

			double dCos = cos( dAngle );
			double dSin = sin( dAngle );

			double dA =  lFlipX * dCos;
			double dB =  lFlipY * dSin;
			double dC = -lFlipX * dSin;
			double dD =  lFlipY * dCos;
			double dE = dX0 - lFlipX * dX0 * dCos + lFlipX * dY0 * dSin;
			double dF = dY0 - lFlipY * dX0 * dSin - lFlipY * dY0 * dCos;

			m_oTransform.Set( dA, dB, dC, dD, dE, dF );
		}
		else
		{
			m_oTransform.Set( 1, 0, 0, 1, 0, 0 );
		}

		return S_OK;
	}

	STDMETHOD(SetTransform)(double   dA, double   dB, double   dC, double   dD, double   dE, double   dF)
	{
		ATLTRACE2( _T("SetTransform\n") );

		m_oCommandParams.nFlag = 16;

		m_oCommandParams.oMatrix.fA = m_oBaseTransform.fA * dA + m_oBaseTransform.fB * dC;
		m_oCommandParams.oMatrix.fC = m_oBaseTransform.fC * dA + m_oBaseTransform.fD * dC;
		m_oCommandParams.oMatrix.fE = m_oBaseTransform.fE * dA + m_oBaseTransform.fF * dC + dE;

		m_oCommandParams.oMatrix.fB = m_oBaseTransform.fA * dB + m_oBaseTransform.fB * dD;
		m_oCommandParams.oMatrix.fD = m_oBaseTransform.fC * dB + m_oBaseTransform.fD * dD;
		m_oCommandParams.oMatrix.fF = m_oBaseTransform.fE * dB + m_oBaseTransform.fF * dD + dF;

		m_oTransform.Set( dA, dB, dC, dD, dE, dF );

		return S_OK;
	}

	STDMETHOD(GetTransform)(double *pdA, double *pdB, double *pdC, double *pdD, double *pdE, double *pdF)
	{
		*pdA = (double)m_oCommandParams.oMatrix.fA;
		*pdB = (double)m_oCommandParams.oMatrix.fB;
		*pdC = (double)m_oCommandParams.oMatrix.fC;
		*pdD = (double)m_oCommandParams.oMatrix.fD;
		*pdE = (double)m_oCommandParams.oMatrix.fE;
		*pdF = (double)m_oCommandParams.oMatrix.fF;

		return S_OK;
	}
	STDMETHOD(ResetTransform)(void)
	{
		m_oCommandParams.nFlag = 16;
		m_oCommandParams.oMatrix.fA = (float)1;
		m_oCommandParams.oMatrix.fB = (float)0;
		m_oCommandParams.oMatrix.fC = (float)0;
		m_oCommandParams.oMatrix.fD = (float)1;
		m_oCommandParams.oMatrix.fE = (float)0;
		m_oCommandParams.oMatrix.fF = (float)0;

		m_oTransform.Set( 1, 0, 0, 1, 0, 0 );

		return S_OK;
	}

	//--------- Clip ---------------------------------------------------------------------------------
	STDMETHOD(get_ClipMode)(LONG* plMode)
	{
		*plMode = 0;

		if ( c_nClipType == m_pCurCommand->nType )
			*plMode = m_pCurCommand->nFlag;

		return S_OK;
	}
	STDMETHOD(put_ClipMode)(LONG lMode)
	{
		if ( c_nClipType == m_pCurCommand->nType )
			m_pCurCommand->nFlag = lMode;

		return S_OK;
	}

	//--------- for teamlab --------------------------------------------------------------------------

	STDMETHOD (OnlineWordToPdf) (BSTR sPathXml, BSTR sDstFile, BSTR sHtmlPlace, LONG nReg);

private:

	// NODE: пока в виде заглушки
	// NOTE: пока градиенты выставим в виде svg-xml

	BOOL ApplyFillGradient();
	BOOL ApplyStrokeGradient();
	BOOL CreateLinearGradientFromSvgXml(const CString& sXml, BOOL fill);
	BOOL CreateRadialGradientFromSvgXml(const CString& sXml, BOOL fill);

	BOOL ApplyTileFill();

	BOOL RebuildResources();
	
	//  
	
	template<typename T> Proxy GenXRef(T* object, int Type);

	PDF::Rect PathBounds();
	PDF::Rect PageBounds();
};

#endif

