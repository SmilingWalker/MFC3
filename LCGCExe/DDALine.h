#pragma once
class CDDALine
{
	
public:
	int x1,y1;
	int x2,y2;
public:
	void setPoint(int x1,int y1,int x2,int y2);
	void Draw(CDC *pDC);
	void DrawB(CDC *pDC);
	CDDALine(void);
	~CDDALine(void);
};

