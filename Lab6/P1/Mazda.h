#pragma once
#include "Masina.h"

class Mazda :public Masina
{
public:
	virtual float GetFuelCapacity() override;
	virtual float GetFuelConsumption() override;
	virtual float GetAverageSpeed(Wheather W) override;
	virtual const char* GetName() override;
};