

#include "pch.h"
#include "conteiner.h"
#include <string>

bool CheckForSymbol(ifstream &ifst, int &indexIgnore)
{
	string buff;
	getline(ifst, buff, '\0');
	bool check = true;
	int index = 0;
	indexIgnore = 1;
	while (buff[indexIgnore] != '\n')
	{
		indexIgnore++;
	}
	indexIgnore++;
	for (int i = indexIgnore; i < buff.size(); i++)
	{
		if (!isdigit(buff[i]) && buff[i] != 32 && buff[i] != '\n')
		{
			if (buff[i] == '.'  && check && index == 2)
			{
				if (!isdigit(buff[i - 1]) || !isdigit(buff[i + 1]))
				{
					return false;
				}
				check = false;
			}
			else
			{
				return false;
			}
		}
		else if (buff[i] == 32 && i > 0)
		{
			index++;
			if (!isdigit(buff[i - 1]) || !isdigit(buff[i + 1]))
			{
				return false;
			}
		}
		else if (buff[i] == '\n')
		{
			check = true;
			index = 0;
		}

	}
	return true;
}
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

void InConteiner(ifstream &ifst, conteiner &c, int indexIgnore)
{
	ifst.seekg(indexIgnore, iostream::beg);
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
			int buff;
			ifst.seekg(1, ios_base::end); //в последний символ файла
			ifst >> buff; // читаем жтот символ
			if (ifst.eof())
			{
				cout << "\nI work with 50 elements, input.txt have more then 50 elements";
			}
		}
	}
}



// Вывод содержимого контейнера в указанный поток/*
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


void OutRect(conteiner &c, ofstream &ofst)
{
	ofst << endl << "Only rectangles." << endl;
	int k = 1;
	for (int i = 0; i < c.len; i++)
	{
		if (c.cont[i]->k == shape::RECTANGLE)
		{
			ofst << k << ": ";
			OutShape(*(c.cont[i]), ofst);
			ofst << endl;
			k++;
		}
	}
}

void MultiMethod(conteiner &c, ofstream &ofst)
{
	ofst << endl << "Multimethod." << endl;
	for (int i = 0; i < c.len - 1; i++)
	{
		for (int j = i + 1; j < c.len; j++)
		{
			switch (c.cont[i]->k)
			{
			case shape::RECTANGLE:
				switch (c.cont[j]->k)
				{
				case shape::RECTANGLE:
					ofst << "Rectangle and Rectangle." << endl;
					break;
				case shape::CIRCLE:
					ofst << "Rectangle and Circle." << endl;
					break;
				case shape::TRANGLE:
					ofst << "Rectangle and Trangle." << endl;
				default:
					ofst << "Unknown type" << endl;
				}
				break;
			case shape::CIRCLE:
				switch (c.cont[j]->k)
				{
				case shape::RECTANGLE:
					ofst << "Circle and Rectangle." << endl;
					break;
				case shape::CIRCLE:
					ofst << "Circle and Circle." << endl;
					break;
				case shape::TRANGLE:
					ofst << "Circle and Trangle." << endl;
				default:
					ofst << "Unknown type" << endl;
				}
				break;
			case shape::TRANGLE:
				switch (c.cont[j]->k) {
				case shape::RECTANGLE:
					ofst << "Trangle and Rectangle." << endl;
					break;
				case shape::CIRCLE:
					ofst << "Trangle and Circle." << endl;
					break;
				case shape::TRANGLE:
					ofst << "Trangle and Trangle." << endl;
					break;
				default:
					ofst << "Unknown type" << endl;
				}

			default:
				ofst << "Unknown type" << endl;
			}
			OutShape(*(c.cont[i]), ofst);
			OutShape(*(c.cont[j]), ofst);
		}
	}

}
