#include <iostream>
#define MAX 10001

using namespace std;

/*template <typename T>
bool Sort(T vector[], int n)
 {
        bool ok = 0;
        if (n >= MAX || n <= 0)
            return 0;
        while (!ok)
        {                                 
            for (int i = 0; i <= n - 1; i++)  
            {
                    if (vector[i] < vector[i + 1])
                    {
                        T aux = vector[i+1];
                        vector[i] = vector[i + 1];
                        vector[i + 1] = aux;                               
                    }   
				ok = 1;                             
            }
        }
        return 1;
 }*/

template <typename T>
bool Sort(T* date, int Count)
{
    int i, j, ok = 0;
    T key;
    for (i = 0; i < Count - 1; i++)
    {
        ok = 1;
        key = date[i];
        j = i - 1;
        while (!(j < 0 && date[j] <= key))
        {
            date[j + 1] = date[j];
            j--;
        }
        date[j] = key;

    }
    if (ok)
        return true;
    return false;
}




int main()
{
    int x[] = { 4,3,5,2,0 };
    
    if (Sort<int>(x, 5) == false)
    {
        cout << "Nu s a efectuat sortare\n";
        return 0;
    }
    else {
        for (int tr = 0; tr < 3; tr++)
            if (x[tr] > x[tr + 1])
            {
               cout << "Sortarea pe scenariu 1 nu a mers !\n";
                return 0;
            }
        cout << "Scenariu 1 e OK!\n";
    }
	
    int v[] = { 1,1,1,2,1,1,1 };
    if (Sort<int>(v, 7) == 0)
    {
        cout << "Nu s a facut sortarea\n";
    }
    else
    {
        for (int i = 0; i < 6; i++)
        if(v[i]>v[i+1])
        {
            cout << "Sortarea nu a mers\n";
        }
        cout << "ok\n";
    }
    int a[] = { 1 };
    if (Sort<int>(a, 1) == 0)
    {
        cout << "test esuat! \n";
    }
    else cout << "test trecut3";
    cout << "Am ajuns la final";
    return 0;
}
