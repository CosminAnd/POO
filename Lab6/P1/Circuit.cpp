#include "Circuit.h"

#define OUT_OF_TIME 99999999.0f 

Circuit::Circuit()
{
	dimensiune_circuit = 1;
	vreme = Wheather::Sunny;
	masini_in_lista = 0;

}
void Circuit::SetLength(int L)
{
	if(L > 0)
		dimensiune_circuit = L;	
}
void Circuit::SetWeather(Wheather W)
{
	vreme = W;
}
void Circuit::AddCar(Masina* m)
{
	if (masini_in_lista < 128)
	{
		lista_masini[masini_in_lista] = m;
		masini_in_lista++;
	}
}
float Circuit::ComputeFinishTime(Masina* m) //dimensiunea : viteza
{
	float drum_maxim_parcurs = m->GetFuelCapacity() * 100.0f / m->GetFuelConsumption();
	if (drum_maxim_parcurs < dimensiune_circuit)
	{
		return OUT_OF_TIME;
	}
	else
	{
		return (float)dimensiune_circuit / m->GetAverageSpeed(this->vreme);
	}
}
void Circuit::Race()
{
	bool Sorted;
	do
	{
		Sorted = true;
		for (int i = 0; i < this->masini_in_lista - 1; i++)
		{
			if (ComputeFinishTime(lista_masini[i]) > ComputeFinishTime(lista_masini[i + 1]))
			{
				Masina* temp = lista_masini[i];
				lista_masini[i] = lista_masini[i + 1];
				lista_masini[i + 1] = temp;

				Sorted = false;
			}
		}
	}while(!Sorted);
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < this->masini_in_lista; i++)
	{
		float time = ComputeFinishTime(lista_masini[i]);
		if (time != OUT_OF_TIME)
		{
			printf("Name: %s, Time: %.2f \n", lista_masini[i]->GetName(), time);
		}
	}
}
void Circuit::ShowWhoDidNotFinis()
{
	for (int i = 0; i < this->masini_in_lista; i++)
	{
		float time = ComputeFinishTime(lista_masini[i]);
		if (time == OUT_OF_TIME)
		{
			printf("Nu a terminat: %s \n", lista_masini[i]->GetName());
		}
	}
}
