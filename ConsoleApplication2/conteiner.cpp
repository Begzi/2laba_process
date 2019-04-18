
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



// ����� ����������� ���������� � ��������� �����/*
void OutConteiner(ofstream &ofst, conteiner &c)
{
	ofst << "Container contains " << c.len
		<< " elements." << endl;
	for (int i = 0; i < c.len; i++) {
		ofst << i + 1 << ": ";
		OutShape(*(c.cont[i]), ofst);
	}
}

