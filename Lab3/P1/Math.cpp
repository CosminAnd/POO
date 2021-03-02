#include "Math.h"
#include <stdlib.h>
#include <stdarg.h>


int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return (int)a + b;
}

int Math::Add(double a, double b, double c)
{
	return (int)a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c) 
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return (int)a * b;
}

int Math::Mul(double a, double b, double c)
{
	return (int)a * b * c;
}

int Math::Add(int count, ...)
{
	va_list ap;
	va_start(ap, count);
		int s = 0;
	for (int i = 1; i <= count; i++)
	{
		int x = va_arg(ap, int);
		s += x;
	}
	va_end(ap);
	return s;
}

char* Math::Add(const char* a, const char* b) {

	if (a == nullptr || b == nullptr)
		return nullptr;

	int n, m;
	n = m = 0;

	for (; a[n] != '\0'; n++);
	for (; b[m] != '\0'; m++);

	char* sol = new char[n + m + 1]; ///alocare memorie 
	int l = 0;

	for (int i = 0; i < n; i++) {
		sol[l++] = a[i];
	}

	for (int i = 0; i < m; i++) {
		sol[l++] = b[i];
	}

	sol[l] = '\0';

	return sol;
}


