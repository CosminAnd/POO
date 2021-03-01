#include <iostream>
#include "Comparation.h"
#include "Students.h"
using namespace std;

void Input(Student *p)
{
	char s[Max];
	float x;
	cout << "Name: ";
	cin >> s;
	p->SetName(s);
	cout << "\n";
	
	cout << "Math: ";
	cin >> x;
	p->SetMat(x);
	cout << "\n";

	cout << "Eng: ";
	cin >> x;
	p->SetEng(x);
	cout << "\n";

	cout << "Ist: ";
	cin >> x;
	p->SetIst(x);
	cout << "\n";

}

int main()
{
	Student a, b;
	cout << "Info 1-st stud: \n";
	Input(&a);
	cout << "\n";
	cout << "Info 2-end stud: \n";
	Input(&b);

	cout << "\n\nComparisons:\n";
	cout << "Name: " << CmpName(a, b);
	cout << "\nMathematics: " << CmpMat(a, b);
	cout << "\nEnglish: " << CmpEng(a, b);
	cout << "\nHistory: " << CmpIst(a, b);
	cout << "\nAverage: " << CmpAvg(a, b);
   
}

