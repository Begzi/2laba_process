#include "pch.h"
#include "trangle.h"

void InTrangle(trangle & tr, ifstream & ifst)
{
	ifst >> tr.x1; ifst >> tr.x2; ifst >> tr.y1; ifst >> tr.y2; ifst >> tr.z1; ifst >> tr.z2;
}

void OutTrangle(trangle & tr, ofstream & ofst)
{
	ofst << " X { " << tr.x1 << ", " << tr.x2 << "}"
		<< " Y { " << tr.y1 << ", " << tr.y2 << "}"
		<< " Z { " << tr.z1 << ", " << tr.z2 << "}" << endl;
}


