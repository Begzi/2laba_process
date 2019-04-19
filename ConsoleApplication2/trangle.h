#pragma once

#include <iostream>
#include "iostream"
#include "fstream"

using namespace std;


struct trangle
{
	int x1,x2, y1,y2,z1,z2; // центр круга
};

void InTrangle(trangle &tr, ifstream &ifst);
void OutTrangle(trangle &tr, ofstream &ofst);
float tranglePerimeter(trangle cir);