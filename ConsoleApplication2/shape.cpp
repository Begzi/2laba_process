
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
	default:
		return 0;
	}
}
// Ввод параметров обобщенной фигуры из файла
// Вывод параметров текущей фигуры в поток

void OutShape(shape &s, ofstream &ofst)
{
	string colorNames[] = { "red","orange","yellow","green","blue","violet" };
	switch (s.k)
	{
	case shape::key::CIRCLE:
		ofst << "It is CIRCLE ";
		ofst << colorNames[s.color].data(); //стриг в чар, благодаря чар
		ofst << "p = " << s.p << "кг/м*м*м  ";
		OutCircle(s.cir, ofst);
		break;

	case shape::key::RECTANGLE:
		ofst << "It is Rectangle ";
		ofst << colorNames[s.color].data();
		ofst << "p = " << s.p << "кг/м*м*м  ";
		OutRectangle(s.r, ofst);
		break;
	default:
		ofst << "Incorrect figure!" << endl;
	}
}
