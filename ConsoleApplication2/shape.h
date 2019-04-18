#pragma once

#include"circle.h"
#include "rectangle.h"

struct shape
{
	// �������� ������ ��� ������ �� �����
	enum key { CIRCLE, RECTANGLE};
	enum color_shape { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };
	color_shape color;
	key k; // ����
	// ������������ ������������
	union
	{ // ���������� ������ ���������
		rectangle r;
		circle cir;
	};

};


shape* InGeneral(ifstream &ifst);
void OutShape(shape &s, ofstream &ofst);
float Perimeter(shape s);