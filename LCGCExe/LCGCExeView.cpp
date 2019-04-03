
// LCGCExeView.cpp : CLCGCExeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "LCGCExe.h"
#endif

#include "LCGCExeDoc.h"
#include "LCGCExeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLCGCExeView

IMPLEMENT_DYNCREATE(CLCGCExeView, CView)

BEGIN_MESSAGE_MAP(CLCGCExeView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLCGCExeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CLCGCExeView ����/����

CLCGCExeView::CLCGCExeView()
{
	// TODO: �ڴ˴���ӹ������

}

CLCGCExeView::~CLCGCExeView()
{
}

BOOL CLCGCExeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLCGCExeView ����

void CLCGCExeView::OnDraw(CDC* pDC)
{
	CLCGCExeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	/*if (!pDoc)
		return;*/
	cddaLine.setPoint(100,100,400,300);
	cddaLine.Draw(pDC);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CLCGCExeView ��ӡ


void CLCGCExeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLCGCExeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLCGCExeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLCGCExeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CLCGCExeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLCGCExeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLCGCExeView ���

#ifdef _DEBUG
void CLCGCExeView::AssertValid() const
{
	CView::AssertValid();
}

void CLCGCExeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLCGCExeDoc* CLCGCExeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLCGCExeDoc)));
	return (CLCGCExeDoc*)m_pDocument;
}
#endif //_DEBUG


// CLCGCExeView ��Ϣ�������
