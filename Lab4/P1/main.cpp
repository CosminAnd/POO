#include <iostream>
#include <stdarg.h>
#include "Sort.h"
using namespace std;


int main()
{
	int task;
	cout << "Task 1 for  random val;\n";
	cout << "Task 2 for  initialization list;\n";
	cout << "Task 3 for  existing vector;\n";
	cout << "Task 4 for  variadic parameters;\n";
	cout << "Task 5 for  a string\;\n";
	cout << "Insert task: ";
	cin >> task;
	cout << "\n";

	if (task == 1)
	{
		///Exemple 1

		cout << "Constructor with random val\n";
		int dim, max, min;
		cout << "Size: ";
		cin >> dim;
		cout << "\Minim: ";
		cin >> min;
		cout << "Maxim: ";
		cin >> max;
		cout << "\n";

		Sort Arry1(dim, min, max);
		cout << "The elements are: ";
		Arry1.Print();

		cout << "\n\n";

		cout << "BubbleSort\n";
		Arry1.BubbleSort();
		Arry1.Print();

		cout << "\n\n";

		cout << "InsertionSort\n";
		Arry1.InsertSort();
		Arry1.Print();

		cout << "\n\n";

		cout << "QuickSort\n";
		Arry1.QuickSort(0, dim);
		Arry1.Print();

		cout << "\n\n";
	}

	else if (task == 2)
	{
		/// Exemple 2
	
		cout << "Constructor with initialization list, ascendent\n";
		Sort Arry2 = { 10,2,44,102,99 };
		cout << "The elements are: ";
		Arry2.Print();

		cout << "\n\n";

		cout << "BubbleSort\n";
		Arry2.BubbleSort(true);
		Arry2.Print();

		cout << "\n\n";

		cout << "InsertionSort\n";
		Arry2.InsertSort(true);
		Arry2.Print();

		cout << "\n\n";

		cout << "QuickSort\n";
		Arry2.QuickSort(0, 4, true);
		Arry2.Print();

		cout << "\n\n";
	}

	else if (task == 3)
	{
		/// Exemple 3
	
		cout << "Constructor with existing vector\n";
		int m, b[MAX];
		cout << "Size of vector: ";
		cin >> m;
		cout << "Elements of vector: ";
		for (int i = 0; i < m; i++)
			cin >> b[i];

		cout << "\n";

		Sort Arry3(b, m);

		cout << "BubbleSort\n";
		Arry3.BubbleSort(true);
		Arry3.Print();

		cout << "\n\n";

		cout << "InsertionSort\n";
		Arry3.InsertSort(true);
		Arry3.Print();

		cout << "\n\n";

		cout << "QuickSort\n";
		Arry3.QuickSort(0, m, true);
		Arry3.Print();

		cout << "\n\n";
	}

	else if (task == 4)
	{
	    ///Exemple 4

		cout << "Constructor with variadic parameters\n";
		cout << "Size: ";
		int m;
		cin >> m;

		Sort Arry4(m, 'c', 9, 10, "ana", 4, 6);
		cout << "The elements are: ";
		Arry4.Print();

		cout << "\n\n";

		cout << "BubbleSort\n";
		Arry4.BubbleSort();
		Arry4.Print();

		cout << "\n\n";

		cout << "InsertionSort\n";
		Arry4.InsertSort();
		Arry4.Print();

		cout << "\n\n";

		cout << "QuickSort\n";
		Arry4.QuickSort(0, m);
		Arry4.Print();

		cout << "\n\n";
	}

	else
	{ 
	    ///Exemple 5

		cout << "Constructor with a string\n";

		Sort Arry5("10,40,100,5,70");
		cout << "The elements are: ";
		Arry5.Print();

		cout << "\n\n";

		cout << "BubbleSort\n";
		Arry5.BubbleSort();
		Arry5.Print();

		cout << "\n\n";

		cout << "InsertionSort\n";
		Arry5.InsertSort();
		Arry5.Print();

		cout << "\n\n";

		int size = sizeof("10,40,100,5,70");
		cout << "QuickSort\n";
		Arry5.QuickSort(0, size);
		Arry5.Print();

		cout << "\n\n";

		return 0;

	}
	return 0;
}

