
#include "pch.h"
#include "rectangle.h"


void InRectangle(rectangle &r, ifstream &ifst)
{
	ifst >> r.a; ifst >> r.b; ifst >> r.c; ifst >> r.d;
}

void OutRectangle(rectangle &r, ofstream &ofst)
{
	ofst << " a = " << r.a
		<< ", b = " << r.b << ", c = " << r.c << ", d = " << r.d << endl;
}
