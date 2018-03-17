#include "stdafx.h"
#include "Stack.h"

using namespace std;

int Stack::Push(double val)
{
	SELEMENT *tmp = (SELEMENT*)malloc(sizeof(SELEMENT));
	if (tmp == NULL) return 0;
	tmp->Next = SHead;
	SHead = tmp;
	tmp->Val = val;
	return 1;
}

double Stack::Pop(double val)
{
	SELEMENT *tmp = SHead;
	if (tmp == NULL) return 0;
	SHead = SHead->Next;
	val = tmp->Val;
	return tmp->Val;
}

void Stack::DestroyS()
{
	SELEMENT *tmp = SHead;
	while (SHead != NULL) {
		SHead = SHead->Next;
		delete tmp;
		tmp = SHead;
	}
}

void Stack::Print()
{
	Stack temp = *this;
	auto start = temp.SHead;
	while (temp.SHead != NULL)
	{
		cout << temp.Pop(temp.SHead->Val) << endl;
	}
	this->SHead = start;
}

void Stack::operator<<(double a)
{
	this->Push(a);
}

double Stack::operator>>(double a)
{
	return this->Pop(a);
}

Stack& Stack::operator-=(double a)
{
	int whole = (int)a;
	double frac = 0, num = 0;
	Stack res;
		
	while (this->SHead != NULL)
	{
		num = this->Pop(this->SHead->Val);
		whole = (int)num;
		frac = (num - whole) * 10;
		if (frac < 0)
			frac *= -1;
		if (frac < a)
			res << num;
	}

	while (res.SHead != NULL)
	{
		this->Push(res.Pop(res.SHead->Val));
	}
	return *this;
}

void Stack::operator=(Stack & b)
{
	SELEMENT *temp = new SELEMENT;
	this->SHead = temp;
	do
	{
		this->Push(b.Pop(b.SHead->Val));
	} while (b.SHead != NULL);
}

Stack::Stack()
{
}

Stack::Stack(int length)
{
	for (int i = 0; i < length; i++)
	{
		this->Push(rand() % 10 - 5);
	}
}


Stack::~Stack()
{
	this->DestroyS();
}