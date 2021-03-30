#include <iostream>
using namespace std;
#define MAX 10001
template<class  T>
class vector
{
    T arry[MAX];
     int n;
 public:
     vector() { n = 0;}
   
     void push(const T& x) 
     {
         arry[n++] = x; 
     };

     T& pop()
     {
         return arry[--n];
     }

     void remove(int index)
     {
         if (index<0 || index>n - 1)
             return;
         for (int i=index;i<=n-1;i++)
             arry[i] = arry[i+1];
         n--;
     }

     void insert(const T& elem, int index) 
     {
         if (index<0 || index>n - 1)
             return;
         for (int i = n-1; i >=index; i--)
             arry[i+1] = arry[i];
         arry[index] = elem;
         n++;
     
     }

     void sort(bool (*isLower) (const T& elem1, const T& elem2))  
     {
         bool ok = 0;
         while (!ok)
         {
             ok = 1;
             for (int i = 0; i < n - 1; i++)
             {
                 if (isLower != nullptr)
                 {
                     if (isLower(arry[i], arry[i + 1]))
                     {
                         T aux = arry[i];
                         arry[i] = arry[i + 1];
                         arry[i + 1] = aux;
                         ok = 0;
                     }
                 }
                 else
                 {
                     if (arry[i] < arry[i + 1])
                     {
                         T aux = arry[i];
                         arry[i] = arry[i + 1];
                         arry[i + 1] = aux;
                         ok = 0;
                     }
                 }
             }
         }
     
     }

      T& get(int index) 
     {
         if (index<0 || index>n - 1)
             return;
         return arry[index];
     };

     void set(int index,const T& elem)
     {
         if (index<0 || index>n - 1)
             return;
         arry[index] = elem;
     }

     int count() 
     {
         return n;
     }

     int firstIndexOf(const T& elem, bool (isEqual(const T& e1, const T& e2)))
     {
         for(int i=0;i<n;i++)
         if (isEqual == nullptr)
         {
             if (elem == arry[i]) return i;
         }
         else
         {
             if (isEqual(elem, arry[i])) return i;
         }

     }
    
     void aifs()
     {
         for (int i = 0; i <= n - 1; i++)
             cout << arry[i]<<" ";
     }
};



int main()
{
    vector <int> s;
    s.push(9);
    s.push(10);
    s.push(8);
    s.insert(11, 2);
    s.pop();
    cout << s.count()<<"\n";
    s.sort(nullptr);
    cout << s.firstIndexOf(11, nullptr)<<"\n";
    s.aifs();
   
    return 0;
}


