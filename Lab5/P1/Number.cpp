#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


///convert to base 10
int convert(const char* value, int base) 
{
	int lg = strlen(value);
	lg--;
	int nr = 0;
	for (int i = 0; value[i]; i++)
	{
		if (value[i] >= '0' && value[i] <= '9')
			nr = nr + (value[i] - '0') * pow(base, lg);

		else
		{
			nr = nr + (10 + value[i] - 'A') * pow(base, lg);
		}
		lg--;
	}
	return nr;
}

///constructor
Number::Number(const char* value, int base)
{
	if (base < 2 || base>16) return;
	this->a = convert(value, base);
	this->b = base;
	int i;
	for ( i = 0; value[i]; i++)
		this->n[i] = value[i];
	this->n[i] = 0;
}

int nr_cif(int nr)
{
	int ct = 0;
	while (nr)
	{
		ct++;
		nr /= 10;
	}
	return ct;
}

Number::Number(int s)  ///for n4 
{

	this->b = 10;
	this->a = s;
	int ct = nr_cif(s) - 1;
	this->n[ct + 1] = 0;
	this->SwitchBase(this->b);

}


/// destructor ???de completat
Number::~Number()
{
	this->n[0] = 0;
}

///copy/move construcor
Number::Number(const Number& n1)
{
	this->a = n1.a;
	this->b = n1.b;
	strcpy(this->n, n1.n);
}

///Methods
void function(int n, int b,  char * nou, int &k)
{
	if (n / b != 0) 
		function(n / b, b, nou, k);
	if (n % b < 10) 
		nou[k++] = '0' + n % b;
	else 
		nou[k++]=char('A' + n % b - 10);
}

void  Number::SwitchBase(int newBase)
{
	if (newBase < 2 || newBase>16) return;
	this->b = newBase;
	int k = 0;
	
		function(this->a, newBase, this->n, k);
		this->n[k] = 0;
	
	/*int temp = this->a;
	int k = 0;
	char* rez = new char;
	char m[256];
	while (temp)
	{
		int r = temp % newBase;
		if (r < 10)
			rez[k++] = r + '0';
		else
			rez[k++] = 'A' + r - 10;
		temp /= newBase;
	}
	rez[k] = 0;
	 ///de completat cu inversarea valorii
	int i, j;
	for ( i = k - 1, j = 0; i >= 0; i--, j++)
	{
		m[j] = rez[i];
	}
	m[j] = 0;
	///m contine nr in noua baza, trebuie pus in this->n...cum???
	*/
}

void Number::Print()
{
	cout << "Number is " << this->n<<"\n"; 
	//cout<< " in base " << this->b << "\n";
	//cout<< "In base 10 number is " << this->a << "\n";
}

int  Number::GetDigitsCount()
{ /*int ct = 0;
	while (this->a)
	{
		ct++;
		this->a = this->a / this->b;
	}
	return ct;
	*/
	return strlen(this->n);
}

int  Number::GetBase()
{
	return this->b;
}

///operators
char  Number::operator[ ](int i)
{
	return this->n[i];
}

void Number::operator=(Number n1)
{
	this->a = n1.a;
	this->b = n1.b;
	strcpy(this->n, n1.n);
}

Number Number::operator+ (Number n1)
{

	n1.a = this->a + n1.a;
	n1.b = 16;
	n1.SwitchBase(16);
	return n1;
}
Number Number::operator- (Number n1)
{

	n1.a = this->a - n1.a;
	n1.b = 16;
	n1.SwitchBase(16);
	return n1;
}

bool Number:: operator> (Number n1)
{
	return (this->a > n1.a);
}


void Number::operator= (int n)
{
	this->a = n;
	this->SwitchBase(this->b);
}

void Number::operator+= (Number n1)
{
	this->a = this->a + n1.a;
	this->b = 16;
	this->SwitchBase(16);
}


void Number::operator= (const char* s)
{
	this->a = convert(s, this -> b);
	strcpy(this->n, s);

}

void Number::operator-- () ///--n4
{
	int ct = nr_cif(this->a);
	long long p = pow(this->b, ct - 1);
	this->a = this->a % p;
	this->SwitchBase(this->b);
}

void Number::operator-- (int n) ///n4--
{
	this->a = this->a / this->b;
	this->SwitchBase(this->b);
}






