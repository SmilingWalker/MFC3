
// LCGCExeView.h : CLCGCExeView ��Ľӿ�
//

#pragma once
#include "ddaline.h"


class CLCGCExeView : public CView
{
protected: // �������л�����
	CLCGCExeView();
	DECLARE_DYNCREATE(CLCGCExeView)

// ����
public:
	CLCGCExeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CLCGCExeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CDDALine cddaLine;
};

#ifndef _DEBUG  // LCGCExeView.cpp �еĵ��԰汾
inline CLCGCExeDoc* CLCGCExeView::GetDocument() const
   { return reinterpret_cast<CLCGCExeDoc*>(m_pDocument); }
#endif

