#include "stdafx.h"
#include "Stack.h"

int main()
{
	char input[6];
	double val = 0, whole = 0;
	int N;
	Stack positive;
	Stack negative;

	while (true)
	{
		cout << "Input the number: "; cin >> input;
		if (strcmp(input, "stop") == 0)
			break;

		val = atoi(input);
		whole = atoi(strchr(input, '.')+1);
		whole *= 0.1;
		if (val > 0)
			val += whole;
		else
			val -= whole;
		
		if (val > 0)
			positive << val;
		else
			negative << val;
	}

	positive >> 11.3;

	positive.Print();
	
	cout << "Newed stack: " << endl;
	Stack newStack;
	newStack = positive;
	newStack.Print();

	Stack st(10);
	st.Print();

	system("pause");
    return 0;
}

