
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define N 300
using namespace std;
char a[N][N];
int n;
void Split(char s[])
{
	char* p = strtok(s, " ");
	while (p)
	{
		strcpy(a[n], p);
		n++;
		p = strtok(NULL, " ");
	}
}
void sortare()
{
	bool ordo = 0; char aux[300];
	while (ordo == 0)
	{
		ordo = 1;
		for (int i = 0; i < n - 1; i++)
		{
			int n1, n2;
			n1 = strlen(a[i]);
			n2 = strlen(a[i + 1]);
			if (n1 < n2)
			{
				strcpy(aux, a[i]);
				strcpy(a[i], a[i + 1]); strcpy(a[i + 1], aux);
				ordo = 0;
			}
			else if (n1 == n2)
			{
				if (strcmp(a[i], a[i + 1]) > 0)
				{
					strcpy(aux, a[i]);
					strcpy(a[i], a[i + 1]); strcpy(a[i + 1], aux);
					ordo = 0;
				}
			}
		}

	}
}
int main()
{
	char s[N];
	cin.getline(s, N);
	Split(s);
	sortare();
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\n";
	}
	return 0;
}

