#pragma once
#define MAX 10001

#ifndef NUMBER_H


class Number

{
	int a; /// value in base 10
	char n[MAX]=""; /// value char
	int b; /// base

public:

	Number(const char* value, int base); // where base is between 2 and 16

	Number(int s); /// for n4 

	~Number();

	// add operators and copy/move constructor
	
	Number(const Number &n1); //copy / move constructor

	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

	// add operators
	char operator[](int i);

	void operator=(const Number& n1);

	Number operator+ ( Number n1);

	Number operator- (Number n1);

	bool operator> (const Number& n1);

	void operator= (int n);

	void operator+= (const Number& n1);

	void operator= (const char* s);

	void operator-- (); //--n4

	void operator-- (int n); //n4--;
};

#endif 
