#pragma once

#include"circle.h"
#include "rectangle.h"

struct shape
{
	// значения ключей для каждой из фигур
	enum key { CIRCLE, RECTANGLE};
	enum color_shape { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };
	color_shape color;
	key k; // ключ
	// используемые альтернативы
	union
	{ // используем прямое включение
		rectangle r;
		circle cir;
	};

};


shape* InGeneral(ifstream &ifst);
void OutShape(shape &s, ofstream &ofst);
float Perimeter(shape s);