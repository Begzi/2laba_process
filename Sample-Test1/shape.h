#pragma once

#include"circle.h"
#include "rectangle.h"
#include "trangle.h"

struct shape
{
	// �������� ������ ��� ������ �� �����
	enum key { CIRCLE, RECTANGLE, TRANGLE};
	enum color_shape { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };
	color_shape color;
	key k; // ����
	float p; //���������
	// ������������ ������������
	union
	{ // ���������� ������ ���������
		rectangle r;
		circle cir;
		trangle tr;
	};

};


shape* InGeneral(ifstream &ifst);
void OutShape(shape &s, ofstream &ofst);
float Perimeter(shape s);
bool Compare(shape *first, shape *second);