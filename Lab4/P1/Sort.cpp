#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Sort.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

using namespace std;


Sort::Sort(const int dim,const int min,const int max)
{
	this->n = dim;
	for (int i = 0; i <dim; i++)
	{
		this->a[i] =rand() % (max-min+1)  +min ;
	}
}


Sort::Sort(int v1, int v2, int v3, int v4)
{
	this->n = 4;
	this->a[0] = v1;
	this->a[1] = v2;
	this->a[2] = v3;
	this->a[3] = v4;
}


Sort::Sort(int v1, int v2, int v3, int v4, int v5)
{
	this->n = 5;
	this->a[0] = v1;
	this->a[1] = v2;
	this->a[2] = v3;
	this->a[3] = v4;
	this->a[4] = v5;
}
Sort::Sort(int v1, int v2, int v3, int v4, int v5, int v6)
{
	this->n = 6;
	this->a[0] = v1;
	this->a[1] = v2;
	this->a[2] = v3;
	this->a[3] = v4;
	this->a[4] = v5;
	this->a[5] = v6;
}

Sort::Sort(int* b, int m)
{
	this->n = m;
	for (int i = 0; i < this->n; i++)
	{
		this->a[i] = b[i];
	}
}

Sort::Sort(int size, ...)
{
	va_list p;
	va_start(p, size);
	for (int i = 0; i < size; i++)
		this->a[i] = va_arg(p, int);
	this->n = size;
	va_end(p);
}

/*int Convert( char* s)
{
	int n = 0;
	for (int i = 0; s[i] != NULL; i++)
		n = n * 10 + (s[i] - '0');
	return n;
}

Sort::Sort( const char* c)
{
	this->n = 0;
	char* p = strtok(c, ",");
	while (p)
	{
		this->a[n] = Convert(p);
		n++;
		p = strtok(NULL, ",");
	}
}*/

Sort::Sort(const char* s)
{
	int i ,num=0;
	this->n = 0;
	for (i = 0; s[i]!=NULL; i++)
	{
		if (s[i] != ',')
		{
			num = num * 10 + s[i] - '0';
		}
		else
		{
			this->a[n] = num;
			n++;
			num = 0;
		}
	}
	
	this->a[n] = num;
	n++;
}

void Sort::BubbleSort(bool ascendent)
{
	bool ok = 0;
	while (!ok)
	{
		ok = 1;
		for(int i=0; i<this->n-1; i++)
			if (ascendent == false)
			{
				if (this->a[i] < this->a[i + 1])
				{
					int aux = this->a[i];
					this->a[i] = this->a[i + 1];
					this->a[i + 1] = aux;
					ok = 0;
				}
			}
			else
			{
				if (this->a[i] > this->a[i + 1])
				{
					int aux = this->a[i];
					this->a[i] = this->a[i + 1];
					this->a[i + 1] = aux;
					ok = 0;
				}
			}
	 }
}

/*void __InsertSort(int* vector, int size, int elem, bool ascendent)
{
	int i;
	if (ascendent)
	{
		for ( i = 0; i < size; i++)
		{
			if (elem < vector[i])
				break;
		}
		for (int j = size - 1; i >= i; j--)
			vector[j + 1] = vector[j];

		vector[i] = elem;
	}
	else
	{
		///pentru descrescator
	}

}

void  Sort::InsertSort(bool ascendent)
{
	int tempVector[MAX];
	for (int index = 0; index < this->n; index++)
		__InsertSort(tempVector, index, this->a[index], ascendent);
	for (int i = 0; i < n; i++)
		this->a[i] = tempVector[i];
	///memccpy(a,tempVector,sizeof(int)*n);
}*/

void  Sort::InsertSort(bool ascendent)
{	
	if (ascendent == false)
	{
		for (int i = 1; i < this->n; i++)
		{
			int x = this->a[i];
			int p = i - 1;
			while (p >= 0 && this->a[p] < x)
			{
				this->a[p + 1] = this->a[p];
				p--;
			}
			a[p + 1] = x;
		}
	}
	else
	{
		for (int i = 1; i < this->n; i++)
		{
			int x = this->a[i];
			int p = i - 1;
			while (p >= 0 && this->a[p] > x)
			{
				this->a[p + 1] = this->a[p];
				p--;
			}
			a[p + 1] = x;
		}
	}
}

 int Pivot(int a[], int s, int d, bool ascendent)
{
	int i=s, j=d;
	int pasi = 0, pasj = 1;
	if (ascendent==0)
	{
		while (i < j)
		{
			if (a[i] <a[j])
			{
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;

				pasi = 1 - pasi;
				pasj = 1 - pasj;
			}
			i += pasi;
			j -= pasj;
		}
	}
	else
	{
		while (i < j)
		{
			if (a[i] > a[j])
			{
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;

				pasi = 1 - pasi;
				pasj = 1 - pasj;
			}
			i += pasi;
			j -= pasj;
		}

	}
	return i;
}

void Sort::QuickSort(int l, int r, bool ascendent )
{
	int s = l , d = r-1;
	if (s < d)
	{
		int p = Pivot(this->a, s, d, ascendent);
		QuickSort(s, p - 1, ascendent);
		QuickSort(p + 1, d, ascendent);
	}
}
void Sort::Print()
{
	for (int i = 0; i < this->n; i++)
		cout << this->a[i] << " ";
}

int  Sort::GetElementsCount()
{
	return this->n;
}

int Sort::GetElementFromIndex(int index)
{
	return this->a[index];
}

