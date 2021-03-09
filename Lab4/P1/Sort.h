#pragma once
#define MAX 1001
#ifndef SORT_H
#define SORT_H

class Sort
{

    int n, a[MAX];

public:

    Sort(int dim, int min, int max); ///random values within a specific interval (min , max)

    Sort(int v1, int v2, int v3, int v4); ///initialization list
       
    Sort(int v1, int v2, int v3, int v4,int v5);
       
    Sort(int v1, int v2, int v3, int v4, int v5,int v6);
    
    Sort(int* b, int m);   ///existing vector

    Sort(int size,...); /// variadic parameters

    Sort(const char* c);  ///a string

    void InsertSort(bool ascendent = false); 

    void QuickSort(int s, int d, bool ascendent = false);

    void BubbleSort(bool ascendent = false); 

    void Print(); 

    int  GetElementsCount(); 

    int  GetElementFromIndex(int index); 

};

#endif 