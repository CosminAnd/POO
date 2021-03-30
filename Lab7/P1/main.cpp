#include <iostream>
using namespace std;


float operator""_Kelvin(unsigned long long int x)
{
    return (float)(x - 273.15);
   
}

float operator""_Fahrenheit(unsigned long long int  x)
{

    return (float)(x - 32) / 1.8;
   
}

int main() 
{

    float a = 300_Kelvin;

    float b = 120_Fahrenheit;
    
    cout << 300 << " Kelvins to Celsius =" <<" "<< a<<"\n";
    cout << 120 << " Fahrenheit to Celsius =" <<" "<< b;

    return 0;

}