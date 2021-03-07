#include <iostream>
#include "Canvas.h"
using namespace std;

int main()
{
	Canvas Draw(50, 50);

	Draw.DrawCircle(12, 12, 8, '*');
	Draw.FillCircle(12, 12, 8, '*');
	Draw.DrawRect(20, 25, 40, 30, '0');
	Draw.FillRect(10, 35, 35, 40, '1');
	Draw.SetPoint(45, 15, 'L');
	Draw.DrawLine(40,40, 50, 50, '$');
	
	Draw.Print();
    
}

