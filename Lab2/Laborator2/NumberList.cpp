#include "NumberList.h"
#include <iostream>

void NumberList:: Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	this->numbers[this->count] = x;
	this->count++;
	return true;
}
void NumberList:: Sort()
{
	bool ok = 0;
	while (!ok)
	{
		ok = 1;
		for(int i=0;i<this->count-1;i++)
			if(this->numbers[i]>this->numbers[i+1])
			{
				int temp;
				temp = this->numbers[i];
				this->numbers[i] = this->numbers[i + 1];
				this->numbers[i + 1] = temp;
				ok = 0;
			}

	}
}

void NumberList::Print()
{
	for(int i=0;i<this->count;i++)
	{
		std::cout << this->numbers[i] << " ";
	}
	std::cout << std::endl;
}