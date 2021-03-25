#include "Toyota.h"

float Toyota::GetFuelCapacity()
{
	return 42;
}
float Toyota::GetFuelConsumption()
{
	return 12;
}
float Toyota::GetAverageSpeed(Wheather W)
{
	if (W == Wheather::Sunny)
	{
		return 120;
	}
	if (W == Wheather::Rain)
	{
		return 90;
	}
	else
	{
		return 70;
	}
}
const char* Toyota::GetName()
{
	return "Toyota";
}
