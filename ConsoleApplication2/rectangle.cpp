
#include "pch.h"
#include "rectangle.h"


void InRectangle(rectangle &r, ifstream &ifst)
{
	ifst >> r.a; ifst >> r.b; ifst >> r.c; ifst >> r.d;
}

void OutRectangle(rectangle &r, ofstream &ofst)
{
	ofst << " a = " << r.a
		<< ", b = " << r.b << ", c = " << r.c << ", d = " << r.d;
}

float rectanglePerimeter(rectangle r) //A { a, b } D{ c,d } C{ c,b } B{ a,d }
{								//
	float P = sqrt((r.a - r.c)*(r.a - r.c) + (r.d - r.b)*(r.d - r.b));
	//float P = 5;
	return P;
}
