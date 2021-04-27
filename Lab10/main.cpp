#include <iostream>
#include <cstdio>
#include <exception>
#define MAX 10001
using namespace std;

class exceptie : public exception 
{
	virtual const char* what() const throw()
	{
		return "Index out of range";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
	/*{
		if (e1 > e2)
			return 1;
		if (e1 < e2)
			return -1;
		return 0;
	}*/
};


template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	int Count;
	T Array[MAX];
public:
	ArrayIterator()
	{
		Current = 0;
		Count = 0;
	}

	ArrayIterator& operator ++ ()
	{
		if (Current < MAX)
		{
			Current++;
			return this->Array[Current];
		}
		else throw "Out of range";
	}

	ArrayIterator& operator -- ()
	{
		if (Current >= 0)
		{
			Current--;
			return this->Array[Current];
		}
		else throw "Out of range";
	}

	bool operator= (ArrayIterator<T>& x)
	{
		if (Current < MAX)
		{
			Array[Current] = x.Array[Current];
			return 1;
		}
		return 0;
	}

	bool operator!=(ArrayIterator<T>& x)
	{
		return Array[Current] != x.Array[Current];
	}

	T* GetElement()
	{
		return &this->Array[Current];
	}
};


template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
	exceptie  index_out_of_range;

public:

	Array() // Lista nu e alocata, Capacity si Size = 0
	{
		Capacity = 0;
		Size = 0;
	}

	~Array()  // destructor
	{
		delete[] List;
		List = nullptr;
		Capacity = 0;
		Size = 0;
	}

	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		Size = 0;
		Capacity = capacity;
		List = new T*[capacity];
	}

	Array(const Array<T>& otherArray) // constructor de copiere
	{
		otherArray.Capacity = Capacity;
		otherArray.Size = Size;
		for (int i = 0; i < Size; i++)
		{
			otherArray.List[i] = List[i];
		}
	}

	T& operator[] (int index)  // arunca exceptie daca index este out of range
	{
			if (index >= Size)
				throw index_out_of_range;
			else
				return List[index];
	}

	const Array<T>& operator+=(const T& newElem)  // adauga un element de tipul T la sfarsitul listei si returneaza this
	{ 	
			if (Size == Capacity)
				throw index_out_of_range;
			else
			{
				List[Size++] = newElem;
				return this;
			}
	}

	const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
			if (index >= Size)
				throw index_out_of_range;
			else 
			{
				for (int i = Size; i > index; i--)
					List[i] = List[i - 1];
				List[index] = newElem;
				Size++;
				return this;
			}
	}

	const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
			if (Size + otherArray->Size >= Capacity)
				throw index_out_of_range;
			else {
				for (int i = Size + otherArray->Size - 1; i >= index + otherArray->Size; i--)
					List[i] = List[i - otherArray->Size];
				for (int i = index, j = 0; i <= Size; i++, j++)
					List[i] = otherArray->List[j];

				Size += otherArray->Size;
				return this;
			}
	}

	const Array<T>& Delete(int index)  // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		
			if (index >= Size)
				throw index_out_of_range;
			else 
			{
				for (int i = index; i < Size - 1; i++)
					List[i] = List[i + 1];
				Size--;
				return this;
			}
	}


	bool operator=(const Array<T>& otherArray)
	{
		if (Capacity < otherArray->Capacity)
		{
			return 0;
		}
		for (int i = 0; i < otherArray->Size; i++)
		{
			List[i] = otherArray->List[i];
		}
		Size = otherArray->Size;
		Capacity = otherArray->Capacity;
		return 1;
	}



	void Sort()   // sorteaza folosind comparatia intre elementele din T
	{
		bool ok = 0;
		int i;
		while (!ok)
		{
			ok = 1;
			for(int i=0;i<Size-1;i++)
				if (List[i] > List[i + 1])
				{
					T aux;
					aux = List[i];
					List[i] = List[i+1];
					List[i + 1] = aux;
					ok = 0;
				}
		}
	}

	void Sort(int(*compare)(const T&, const T&))   // sorteaza folosind o functie de comparatie
	{
		bool ok = 0;
		int i;
		while (!ok)
		{
			ok = 1;
			for (int i = 0; i < Size - 1; i++)
				if (compare(List[i], List[i + 1])>0)
				{
					T aux;
					aux = List[i];
					List[i] = List[i + 1];
					List[i + 1] = aux;
					ok = 0;
				}
		}
	}

	void Sort(Compare* comparator)   // sorteaza folosind un obiect de comparatie
	{
		bool ok = 0;
		int i;
		while (!ok)
		{
			ok = 1;
			for (int i = 0; i < Size - 1; i++)
				if (comparator->CompareElements(List[i], List[i + 1])>0)
				{
					T aux;
					aux = List[i];
					List[i] = List[i + 1];
					List[i + 1] = aux;
					ok = 0;
				}
		}
	}


	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		int s = 0, d = Size-1;
		int m;
		while (s <= d)
		{
			 m = (s + d) / 2;
			 if (elem == List[m]) return m;
			 else if (elem < List[m])
			 {
				 d = m - 1;
			 }
			 else
			 {
				 s = m + 1;
			 }
		}
		return -1;

	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))  //  cauta un element folosind binary search si o functie de comparatie
	{
		int s = 0, d = Size - 1;
		int m;
		while (s <= d)
		{
			m = (s + d) / 2;
			if (compare(elem, List[m])==0) return m; /// compare == 0, elem==T[m]
			else if (compare(elem, List[m])==-1)    /// compare == -1. elem<T[m]
			{
				d = m - 1;
			}
			else if(compare(elem, List[m])==1)    /// compare == 1, elem>T[m]
			{
				s = m + 1;
			}
		}
		return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator) //  cauta un element folosind binary search si un comparator
	{
		int s = 0, d = Size - 1;
		int m;
		while (s <= d)
		{
			m = (s + d) / 2;
			if (comparator->CompareElements(elem, List[m])==0) return m; /// comparator == 0, elem==T[m]
			else if (comparator->CompareElements(elem, List[m]) == -1)    /// comparator == -1. elem<T[m]
			{
				d = m - 1;
			}
			else if (comparator->CompareElements(elem, List[m]) == 1)    /// comparator == 1, elem>T[m]
			{
				s = m + 1;
			}
		}
		return -1;
	}


	int Find(const T& elem)  // cauta un element in Array
	{
		for (int i = 0; i < Size; i++)
		{
			if (elem == List[i]) return i;
		}
		return -1;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&))   //  cauta un element folosind o functie de comparatie
	{
		for (int i = 0; i < Size; i++)
		{
			if (compare(elem, List[i])==0) return i;
		}
		return -1;
	}

	int Find(const T& elem, Compare* comparator)   //  cauta un element folosind un comparator
	{
		for (int i = 0; i < Size; i++)
		{
			if (comparator->CompareElements(elem, List[i]) == 0) return i;
				return i;
		}
		return -1;
	}


	int GetSize()
	{
		return Size;
	}

	int GetCapacity()
	{
		return Capacity;
	}


	ArrayIterator<T> GetBeginIterator()
	{
		return List[0];
	}

	ArrayIterator<T> GetEndIterator()
	{
		return List[Size];
	}
};


int main()
{
	return 0;
}
