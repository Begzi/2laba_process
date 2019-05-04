﻿// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "conteiner.h"


int main(int argc, char* argv[])
{
	if (argc != 3) 
	{
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst1(argv[1]);
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	int indexIgnore = 0;
	bool check = CheckForSymbol(ifst1, indexIgnore);
	if (check)
	{
		cout << "Start";
		conteiner c;
		Init(c);
		InConteiner(ifst, c, indexIgnore);
		Sort(c);
		ofst << "\nFilled container. " << endl;
		OutConteiner(ofst, c);
		MultiMethod(c, ofst);
		OutRect(c, ofst);
		Clear(c);
		ofst << "\nEmpty container. " << endl;
		cout << "\nStop" << endl;
	}
	else
	{
		cout << "Symbol in input.txt" << endl;
	}
	return 0;

}




	// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
	// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

	// Советы по началу работы 
	//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
	//   2. В окне Team Explorer можно подключиться к системе управления версиями.
	//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
	//   4. В окне "Список ошибок" можно просматривать ошибки.
	//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
	//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
