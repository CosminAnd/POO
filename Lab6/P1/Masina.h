#pragma once
//fuel capacity, fuel consumption, average speed on different conditions

enum Wheather
{
	Rain, Sunny, Snow
};

class Masina
{
public:
	virtual float GetFuelCapacity() = 0;
	virtual float GetFuelConsumption() = 0;
	virtual float GetAverageSpeed(Wheather W) = 0;
	virtual const char* GetName() = 0;
};