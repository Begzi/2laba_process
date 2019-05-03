
#include "pch.h"
#include"circle.h"

void InCircle(circle &cir, ifstream &ifst)
{
	ifst >> cir.x >> cir.y >> cir.r;

}

void OutCircle(circle &cir, ofstream &ofst)
{
	ofst << " x = "
		<< cir.x << ", y = " << cir.y << ", r = " << cir.r;
}

float circlePerimeter(circle cir)
{
	//int P = PI*2* cir.r;
	float P = 2* 3.14 *cir.r;
	return P;
}
