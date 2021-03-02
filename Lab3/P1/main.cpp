#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
    Math x;
    cout<<x.Add(10,4)<<"\n";
    cout << x.Add(10, 4,5) << "\n";
    cout << x.Add(6.5, 3.5) << "\n";
    cout << x.Add(10.8, 4.2,0.5) << "\n";

	cout << x.Mul(2, 7) << "\n";
	cout << x.Mul(2, 7, 4) << "\n";
	cout << x.Mul(1.5, 4.3) << "\n";
	cout << x.Mul(4.3, 2.7, 5.2) << "\n";

	cout << x.Add(6, 1, 2, 3, 4, 5,6) << "\n";

	char* temp;
	cout << (temp = x.Add("Am rezolvat", " problema!"))<< "\n";
	delete[] temp; ///dealocare memorie
}

