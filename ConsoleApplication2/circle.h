#pragma once
#include <iostream>
#include "iostream"
#include "fstream"

using namespace std;


struct circle
{
	int x, y, r; // ����� �����
};

void InCircle(circle &cir, ifstream &ifst);
void OutCircle(circle &cir, ofstream &ofst);