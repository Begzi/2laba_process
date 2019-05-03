#pragma once
#include "shape.h"


struct conteiner
{
	enum { max_len = 51 };
	int len;
	shape *cont[(max_len)-1];
};


void Init(conteiner &c);
bool CheckForSymbol(ifstream &ifst, int &indexIgnore);
void Clear(conteiner &c);
void InConteiner(ifstream &ifst, conteiner &c, int indexIgnore);
void OutConteiner(ofstream &ofst, conteiner &c);
void Sort(conteiner &c);
void OutConteiner(ofstream &ofst, conteiner &c);
void OutRect(conteiner &c, ofstream &ofst);