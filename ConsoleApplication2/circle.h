#pragma once
#include <iostream>
#include "iostream"
#include "fstream"

using namespace std;


struct circle
{
	//const double PI = 3.1415926535897932384626433832795;
	int x, y, r; // центр круга
};

void InCircle(circle &cir, ifstream &ifst);
void OutCircle(circle &cir, ofstream &ofst);
float circlePerimeter(circle cir);