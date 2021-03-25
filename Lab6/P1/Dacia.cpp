#include "Dacia.h"

float Dacia::GetFuelCapacity()
{
	return 400;
}
float Dacia::GetFuelConsumption()
{
	return 9;
}
float Dacia::GetAverageSpeed(Wheather W)
{
	if (W == Wheather::Sunny)
	{
		return 100;
	}
	if (W == Wheather::Rain)
	{
		return 70;
	}
	else
	{
		return 50;
	}
}
const char* Dacia::GetName()
{
	return "Dacia";
}
