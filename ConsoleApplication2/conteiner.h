#pragma once
#include "shape.h"


struct conteiner
{
	enum { max_len = 51 };
	int len;
	shape *cont[(max_len)-1];
};


void Init(conteiner &c);
void Clear(conteiner &c);
void InConteiner(ifstream &ifst, conteiner &c);
void OutConteiner(ofstream &ofst, conteiner &c);
void Sort(conteiner &c);
