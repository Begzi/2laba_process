
#include "pch.h"
#include "shape.h"

shape* InGeneral(ifstream &ifst)
{
	shape *sp;
	int k;
	int color;
	float p;
	ifst >> k;
	ifst >> color;
	ifst >> p;
	sp = new shape;
	sp->k = (shape::key)(k-1);
	sp->color = (shape::color_shape)(color - 1);
	sp->p = p;
	switch (k)
	{
	case 2:
		InRectangle(sp->r, ifst);
		return sp;
	case 1:
		InCircle(sp->cir, ifst);
		return sp;
	case 3:
		InTrangle(sp->tr, ifst);
		return sp;
	default:
		return 0;
	}
}
// ���� ���������� ���������� ������ �� �����
// ����� ���������� ������� ������ � �����

void OutShape(shape &s, ofstream &ofst)
{
	string colorNames[] = { "red","orange","yellow","green","blue","violet" };
	switch (s.k)
	{
	case shape::key::CIRCLE:
		ofst << "It is CIRCLE ";
		ofst << colorNames[s.color].data(); //����� � ���, ��������� ���
		ofst << "p = " << s.p << "��/�*�*�  ";
		OutCircle(s.cir, ofst);
		break;

	case shape::key::RECTANGLE:
		ofst << "It is Rectangle ";
		ofst << colorNames[s.color].data();
		ofst << "p = " << s.p << "��/�*�*�  ";
		OutRectangle(s.r, ofst);
		break;
	case shape::key::TRANGLE:
		ofst << "It is Trangle ";
		ofst << colorNames[s.color].data();
		OutTrangle(s.tr, ofst);
		break;
	default:
		ofst << "Incorrect figure!" << endl;
	}
}

float Perimeter(shape s)
{
	int k = (shape::key)(s.k) + 1;
	switch (k)
	{
	case 1:
		return circlePerimeter(s.cir);
	case 2:
		return rectanglePerimeter(s.r);
	case 3:
		return tranglePerimeter(s.tr);
	default:
		return 0;
	}
}

bool Compare(shape *first, shape *second) 
{
	return Perimeter(*first) < Perimeter(*second);
}
