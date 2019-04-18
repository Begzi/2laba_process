#include "pch.h"
#include "trangle.h"


void InTrangle(trangle & tr, ifstream & ifst)
{
	ifst >> tr.x1; ifst >> tr.x2; ifst >> tr.y1; ifst >> tr.y2; ifst >> tr.z1; ifst >> tr.z2;
}

void OutTrangle(trangle & tr, ofstream & ofst)
{
	ofst << " x1 = " << tr.x1 << " x2 = " << tr.x2 
		<< " y1 = " << tr.y1 << " y2 = " << tr.y2 
		<< " z1 = " << tr.z1 << " z2 = " << tr.z2 << endl;
}