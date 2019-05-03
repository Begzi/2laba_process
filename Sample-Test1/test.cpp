#include "pch.h"
#include "conteiner.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "trangle.h"
#include <iostream>
#include "iostream"
#include "fstream"
#include "shape.cpp"
#include "circle.cpp"
#include "rectangle.cpp"
#include "trangle.cpp"
#include "conteiner.cpp"

using namespace std;

TEST(In, Rectangle)
{
	rectangle r;
	r.a = 3; r.b = 2; r.c = 55; r.d = 5;
	ifstream ifst("D:\InRectangle.txt");

	conteiner c;
	c.cont[0] = InGeneral(ifst);
	EXPECT_EQ(r.a, c.cont[0]->r.a);
	EXPECT_EQ(r.b, c.cont[0]->r.b);
	EXPECT_EQ(r.c, c.cont[0]->r.c);
	EXPECT_EQ(r.d, c.cont[0]->r.d);
}

TEST(In, Circle)
{
	circle cir;
	cir.x = 3; cir.y = 2; cir.r = 55;
	ifstream ifst("D:\InCircle.txt");

	conteiner c;
	c.cont[0] = InGeneral(ifst);
	EXPECT_EQ(cir.x, c.cont[0]->cir.x);
	EXPECT_EQ(cir.y, c.cont[0]->cir.y);
	EXPECT_EQ(cir.r, c.cont[0]->cir.r);
}

TEST(In, Trangle)
{
	trangle tr;
	tr.x1 = 1; tr.x2 = 1; 
	tr.y1 = 2; tr.y2 = 1;
	tr.z1 = 1; tr.z2 = 2;
	ifstream ifst("D:\InTrangle.txt");

	conteiner c;
	c.cont[0] = InGeneral(ifst);
	EXPECT_EQ(tr.x1, c.cont[0]->tr.x1);
	EXPECT_EQ(tr.x2, c.cont[0]->tr.x2);
	EXPECT_EQ(tr.y1, c.cont[0]->tr.y1);
	EXPECT_EQ(tr.y2, c.cont[0]->tr.y2);
	EXPECT_EQ(tr.z1, c.cont[0]->tr.z1);
	EXPECT_EQ(tr.z2, c.cont[0]->tr.z2);
}

TEST(In, Conteiner)
{
	ifstream ifst("D:\InConteiner.txt");

	conteiner c;
	Init(c);
	InConteiner(ifst, c);
	int expected_len = 50;
	EXPECT_EQ(expected_len, c.len);
}


TEST(Out, Circle)
{
	ifstream ifst("D:\ExpectedCircle.txt");
	string expected;
	string result;
	circle cir;
	cir.x = 3; cir.y = 2; cir.r = 55;

	getline(ifst, expected, '\0');

	ofstream ofst("D:\ResultOut.txt");
	OutCircle(cir, ofst);
	ofst.close();

	ifstream ifst1("D:\ResultOut.txt");
	getline(ifst1, result, '\0');
	EXPECT_EQ(result, expected);
}

TEST(Out, rectangle)
{
	ifstream ifst("D:\ExpectedRectangle.txt");
	string expected;
	string result;
	rectangle r;
	r.a = 1; r.b = 1; r.c = 2; r.d = 2;

	getline(ifst, expected, '\0');

	ofstream ofst("D:\ResultOut.txt");
	OutRectangle(r, ofst);
	ofst.close();

	ifstream ifst1("D:\ResultOut.txt");
	getline(ifst1, result, '\0');
	EXPECT_EQ(result, expected);
}

TEST(Out, trangle)
{
	ifstream ifst("D:\ExpectedTrangle.txt");
	string expected;
	string result;
	trangle tr;
	tr.x1 = 1; tr.x2 = 1;
	tr.y1 = 2; tr.y2 = 1;
	tr.z1 = 1; tr.z2 = 2;

	getline(ifst, expected, '\0');

	ofstream ofst("D:\ResultOut.txt");
	OutTrangle(tr, ofst);
	ofst.close();

	ifstream ifst1("D:\ResultOut.txt");
	getline(ifst1, result, '\0');
	EXPECT_EQ(result, expected);
}

TEST(PERIMETER, Circle)
{
	circle cir;
	cir.x = 3; cir.y = 2; cir.r = 55;
	float expected = 345.4;
	float result = circlePerimeter(cir);
	EXPECT_EQ(expected, result);
}

TEST(PERIMETER, Rectangle)
{
	rectangle r;
	r.a = 1; r.b = 1; r.c = 2; r.d = 2;
	float expected = 2;
	float result = rectanglePerimeter(r);
	EXPECT_EQ(expected, result);
}

TEST(PERIMETER, Trangle)
{
	trangle tr;
	tr.x1 = 1; tr.x2 = 1; 
	tr.y1 = 4; tr.y2 = 1;
	tr.z1 = 1; tr.z2 = 3;
	int expected = 8;
	int result = tranglePerimeter(tr);
	EXPECT_EQ(expected, result);
}

TEST(Function, Sort)
{
	ifstream ifst("D:\InConteiner.txt");

	conteiner c;
	Init(c);
	InConteiner(ifst, c);
	Sort(c);
	ifst.close();

	string expected;
	ifstream ifstExpect("D:\ExpectedSort.txt");
	getline(ifstExpect, expected, '\0');

	ofstream ofst("D:\ResultOut.txt");
	OutConteiner(ofst, c);
	ofst.close();

	string result;
	ifstream ifstResult("D:\ResultOut.txt");
	getline(ifstResult, result, '\0');
	EXPECT_EQ(result, expected);
}


TEST(Function, OutRect)
{
	ifstream ifst("D:\InConteiner.txt");

	conteiner c;
	Init(c);
	InConteiner(ifst, c);
	Sort(c);
	ifst.close();

	string expected;
	ifstream ifstExpect("D:\ExpectedOutRect.txt");
	getline(ifstExpect, expected, '\0');

	ofstream ofst("D:\ResultOut.txt");
	OutConteiner(ofst, c);
	OutRect(c, ofst);
	ofst.close();

	string result;
	ifstream ifstResult("D:\ResultOut.txt");
	getline(ifstResult, result, '\0');
	EXPECT_EQ(result, expected);
}


