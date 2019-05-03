
#include "pch.h"
#include "shape.h"
#include <string>

shape* InGeneral(ifstream &ifst)
{
	shape *sp;
	int k;
	int color;
	float p;
	ifst >> k;
	if (k > 3 || k < 1)
	{
		cout << endl << "Key must be 0 or 1 or 3" << endl;
		k = 0;
	}
	ifst >> color;
	if (color > 6 || color < 1)
	{
		cout << endl << "color must be from 1 to 6" << endl;
		k = 0;
		color = 1;
	}
	ifst >> p;
	if (p < 1)
	{
		cout << endl << "P must be > 0" << endl;
		k = 0;
		p = 1;
	}
	sp = new shape;
	sp->k = (shape::key)(k-1);
	sp->color = (shape::color_shape)(color - 1);
	sp->p = p;
	string buff;
	int index = 0;
	int bufer = ifst.tellg();
	getline(ifst, buff, '\n');
	for (int j = 0; j < buff.size(); j++)
	{
		if (buff[j] == 32)
		{
			index++;
		}
	}
	ifst.seekg(bufer, iostream::beg);
	switch (k)
	{
	case 2:
		if (index == 4)
		{
			InRectangle(sp->r, ifst);
			return sp;
		}
		else
		{
			ifst.seekg(1, ios_base::end); //в последний символ файла
			ifst >> k; // читаем жтот символ
			cout << "not enough or more coordinates for rectangle";
			return 0;
		}
	case 1:
		if (index == 3)
		{
			InCircle(sp->cir, ifst);
			return sp;
		}
		else
		{
			ifst.seekg(1, ios_base::end); //в последний символ файла
			ifst >> k; // читаем жтот символ
			cout << "not enough or more  coordinates for circle";
			return 0;
		}
	case 3:
		if (index == 6)
		{
			InTrangle(sp->tr, ifst);
			return sp;
		}
		else
		{
			ifst.seekg(1, ios_base::end); //в последний символ файла
			ifst >> k; // читаем жтот символ
			cout << "not enough  or more  coordinates for trangle";
			return 0;
		}
	default:

		ifst.seekg(1, ios_base::end); //в последний символ файла
		ifst >> k; // читаем жтот символ
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
		ofst << " p = " << s.p << "кг/м*м*м  ";
		OutCircle(s.cir, ofst);
		break;

	case shape::key::RECTANGLE:
		ofst << "It is Rectangle ";
		ofst << colorNames[s.color].data();
		ofst << " p = " << s.p << "кг/м*м*м  ";
		OutRectangle(s.r, ofst);
		break;
	case shape::key::TRANGLE:
		ofst << "It is Trangle ";
		ofst << colorNames[s.color].data();
		ofst << " p = " << s.p << "кг/м*м*м  ";
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
