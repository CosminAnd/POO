#pragma once
#include "Masina.h"
#include <stdio.h>

class Circuit
{
	int dimensiune_circuit;
	Wheather vreme;
	Masina* lista_masini[128];
	int masini_in_lista;

	float ComputeFinishTime(Masina*);
	
public:
	void SetLength(int L);
	void SetWeather(Wheather W);
	void AddCar(Masina* m);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();
	
	Circuit();
};