#include "Mercedes.h"

float Mercedes::GetFuelCapacity()
{
	return 44;
}
float Mercedes::GetFuelConsumption()
{
	return 10;
}
float Mercedes::GetAverageSpeed(Wheather W)
{
	if (W == Wheather::Sunny)
	{
		return 130;
	}
	if (W == Wheather::Rain)
	{
		return 100;
	}
	else
	{
		return 90;
	}
}
const char* Mercedes::GetName()
{
	return "Mercedes";
}
