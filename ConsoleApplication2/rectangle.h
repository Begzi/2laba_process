#pragma once
#include <iostream>
#include "iostream"
#include "fstream"

using namespace std;


struct  rectangle
{
	int a, b, c, d; // ���������� ������ �������� � ������� ������� �����
};


void InRectangle(rectangle &r, ifstream &ifst);
void OutRectangle(rectangle &r, ofstream &ofst);