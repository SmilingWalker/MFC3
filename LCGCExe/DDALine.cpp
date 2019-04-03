#include "stdafx.h"
#include "DDALine.h"


CDDALine::CDDALine(void)
{
}


CDDALine::~CDDALine(void)
{
}
void CDDALine::setPoint(int x1,int y1,int x2,int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
void CDDALine::Draw(CDC *pDC)
{
	float dx,dy,k,x,y;
	dx = (x2-x1);
	dy = (y2-y1);
	k = dy/dx;
	if(abs(long(k))<=1)
	{
		for(x=min(x1,x2);x<=max(x1,x2);x++)
		{
			pDC->SetPixel(CPoint(x,int(y+0.5)),RGB(200,200,200));
			y = y+k;
		}
	}
	else
	{
		for(y=min(y1,y2);y<max(y1,y2);y++)
		{
			pDC->SetPixel(CPoint(int(x+0.5),y),RGB(200,200,200));
			x = x+k;
			
		}

	}

}
void CDDALine::DrawB(CDC *pDC)
{

}