#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <cstring>
int conversie(char s[])
{
    bool semn = 0;
    int nr = 0;
    if (s[0] == '-')
        semn = 1;
    if (semn == 1)
        for (int i = 1; s[i]; i++)
            nr = nr * 10 + (s[i] - '0');
    else
        for (int i = 0; s[i]; i++)
            nr = nr * 10 + (s[i] - '0');
    if (semn == 1) nr = -nr;
    return nr;
}
int main()
{
    FILE* fisier;
    int  s = 0;
    char a[100];
    fisier = fopen("in.txt", "r +");
    while (fscanf(fisier, "%s", &a) != EOF)
        s += conversie(a);
    printf("%d", s);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
