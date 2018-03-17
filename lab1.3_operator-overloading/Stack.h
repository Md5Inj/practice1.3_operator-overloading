#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;
#pragma once

typedef struct _SELEMENT {
	double Val; _SELEMENT *Next;
} SELEMENT;

class Stack
{
private:
	SELEMENT * SHead = NULL;
	SELEMENT * temp = NULL;
public:
	Stack();
	Stack(int length);
	int Push(double val);
	double Pop(double val);
	void DestroyS();
	void Print();
	void operator<<(double a);
	double operator>>(double a);
	Stack& operator-=(double a);
	void operator= (Stack& b);
	~Stack();
};