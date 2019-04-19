
#include "pch.h"
#include "conteiner.h"


void Init(conteiner &c)
{
	c.len = 0;
}

void Clear(conteiner &c)
{
	for (int i = 0; i < c.len; i++)
	{
		delete c.cont[i];
	}
	c.len = 0;
}

void InConteiner(ifstream &ifst, conteiner &c)
{
	while (!ifst.eof())
	{
		if (c.len < 50)
		{
			if ((c.cont[c.len] = InGeneral(ifst)) != 0)
			{
				c.len++;
			}
		}
		else
		{
			InGeneral(ifst);
			if (ifst.eof())
			{
				cout << "\nI work with 50 elements, input.txt have more then 50 elements";
			}
		}
	}
}



// ¬ывод содержимого контейнера в указанный поток/*
void OutConteiner(ofstream &ofst, conteiner &c)
{
	ofst << "Container contains " << c.len
		<< " elements." << endl;
	for (int i = 0; i < c.len; i++) {
		ofst << i + 1 << ": ";
		OutShape(*(c.cont[i]), ofst);
		ofst << " Perimeter = " << Perimeter(*(c.cont[i])) << endl;
	}
}
void Sort(conteiner &c)
{
	for (int i = 0; i < c.len - 1; i++)
	{
		for (int j = i + 1; j < c.len; j++)
		{
			if (Compare(c.cont[i], c.cont[j]))
			{
				shape *tmp = c.cont[i];
				c.cont[i] = c.cont[j];
				c.cont[j] = tmp;
			}
		}
	}
}