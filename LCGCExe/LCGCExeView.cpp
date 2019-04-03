
// LCGCExeView.cpp : CLCGCExeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLCGCExeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CLCGCExeView 构造/析构

CLCGCExeView::CLCGCExeView()
{
	// TODO: 在此处添加构造代码

}

CLCGCExeView::~CLCGCExeView()
{
}

BOOL CLCGCExeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLCGCExeView 绘制

void CLCGCExeView::OnDraw(CDC* pDC)
{
	CLCGCExeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	/*if (!pDoc)
		return;*/
	cddaLine.setPoint(100,100,400,300);
	cddaLine.Draw(pDC);

	// TODO: 在此处为本机数据添加绘制代码
}


// CLCGCExeView 打印


void CLCGCExeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLCGCExeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLCGCExeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CLCGCExeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CLCGCExeView 诊断

#ifdef _DEBUG
void CLCGCExeView::AssertValid() const
{
	CView::AssertValid();
}

void CLCGCExeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLCGCExeDoc* CLCGCExeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLCGCExeDoc)));
	return (CLCGCExeDoc*)m_pDocument;
}
#endif //_DEBUG


// CLCGCExeView 消息处理程序
