#include <iostream>
using namespace std;

template<class  T>
 class vector
 {
     T* arry;
     int n;
 public:
     vector(int x) 
     { 
         arry = new T[n]; 
         n = x; 
         int a;
         for (int i = 0; i < n; i++)
         {
             cin >> a;
             arry[i] = a;
         }
     };

    /* ~vector()  ????
     {
         delete arry; 
         arry = nullptr; 
     };*/

     bool operator<(T elem1) ///????
     {
         return arry<elem1;
     };

     void push(T x) 
     {
         arry[n++] = x; 
     };

     T pop() 
     {
         return arry[--n]; 
     };

     void remove(int index)
     {
         if (index<0 || index>n - 1)
             return;
         for (int i=index;i<=n-1;i++)
             arry[i] = arry[i+1];
         n--;
     };

     void insert(T elem, int index) 
     {
         if (index<0 || index>n - 1)
             return;
         for (int i = n-1; i >=index; i--)
             arry[i+1] = arry[i];
         arry[index] = elem;
         n++;
     
     };

     void sort()  //????
     {
         bool ok = 0;
         while (!ok)
         {
             ok = 1;
             for (int i = 0; i < n - 1; i++)
                 if (arry[i] < arry[i + 1])
                 {
                     T aux = arry[i];
                     arry[i] = arry[i + 1];
                     arry[i + 1] = aux;
                     ok = 0;
                 }
         }
     
     }; 

     const T get(int index) /// ?????
     {
         if (index<0 || index>n - 1)
             return;
         return &arry[index];
     }; 

     void set(int index,T elem)
     {
         if (index<0 || index>n - 1)
             return;
         arry[index] = elem;
     };

     int count() 
     {
         return n;
     };

     /*void find();/// to do ?????

     T firstIndexOf(T elem, void find()) {}; ///to do
     */
     void aifs()
     {
         for (int i = 0; i <= n - 1; i++)
             cout << arry[i]<<" ";
     };
};



int main()
{
    vector <int> s(10);
    s.insert(11, 2);
    s.aifs();
   
    return 0;
}


