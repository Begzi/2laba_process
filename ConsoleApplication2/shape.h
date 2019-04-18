#include"circle.h"
#include "rectangle.h"
#include "trangle.h"

struct shape
{
	// значения ключей для каждой из фигур
	enum key { CIRCLE, RECTANGLE, TRANGLE };
	enum color_shape { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };
	color_shape color;
	key k; // ключ
	// используемые альтернативы
	union
	{ // используем прямое включение
		rectangle r;
		circle cir;
		trangle tr;
	};

};


shape* InGeneral(ifstream &ifst);

