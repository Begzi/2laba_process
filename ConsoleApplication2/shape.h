#include"circle.h"
#include "rectangle.h"
#include "trangle.h"

struct shape
{
	// �������� ������ ��� ������ �� �����
	enum key { CIRCLE, RECTANGLE, TRANGLE };
	enum color_shape { RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET };
	color_shape color;
	key k; // ����
	// ������������ ������������
	union
	{ // ���������� ������ ���������
		rectangle r;
		circle cir;
		trangle tr;
	};

};


shape* InGeneral(ifstream &ifst);

