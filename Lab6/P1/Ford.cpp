#include "Ford.h"

float Ford::GetFuelCapacity()
{
	return 41;
}
float Ford::GetFuelConsumption()
{
	return 6;
}
float Ford::GetAverageSpeed(Wheather W)
{
	if (W == Wheather::Sunny)
	{
		return 140;
	}
	if (W == Wheather::Rain)
	{
		return 80;
	}
	else
	{
		return 70;
	}
}
const char* Ford::GetName()
{
	return "Ford";
}
