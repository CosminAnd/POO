#include "Dacia.h"
#include "Mazda.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Circuit.h"

int main()
{
	Circuit c;
	c.SetLength(500);
	c.SetWeather(Wheather::Rain);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.Race();
	c.ShowFinalRanks(); 
	c.ShowWhoDidNotFinis(); 

	return 0;
}