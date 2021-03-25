#include "Mazda.h"

float Mazda::GetFuelCapacity()
{
	return 38;
}
float Mazda::GetFuelConsumption()
{
	return 7;
}
float Mazda::GetAverageSpeed(Wheather W) 
{
	if (W == Wheather::Sunny)
	{
		return 100;
	}
	if (W == Wheather::Rain)
	{
		return 80;
	}
	else 
	{
		return 60;
	}
}
const char* Mazda::GetName()
{
	return "Mazda";
}
