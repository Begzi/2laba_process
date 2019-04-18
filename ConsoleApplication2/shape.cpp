
#include "pch.h"
#include "shape.h"

shape* InGeneral(ifstream &ifst)
{
	shape *sp;
	int k;
	int color;

	ifst >> k;
	ifst >> color;
	sp = new shape;
	sp->k = (shape::key)(k-1);
	sp->color = (shape::color_shape)(color - 1);
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

		OutCircle(s.cir, ofst);
		break;

	case shape::key::RECTANGLE:
		ofst << "It is Rectangle ";
		ofst << colorNames[s.color].data();
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
