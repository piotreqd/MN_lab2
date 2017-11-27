// Aproksymacja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

void DyskretyzujSinus(double dolPrzedziału, double goraPrzedzialu, int wezly, double wartosci[])
{
	double przedzial = abs(dolPrzedziału) + abs(goraPrzedzialu);
	double krok = przedzial / (double)(wezly - 1);
	double argumentSinusa = dolPrzedziału;

	cout << "krok = " << krok << endl;

	for (int i = 0; i < wezly; ++i)
	{
		wartosci[i] = cos(argumentSinusa) * cos(3 * argumentSinusa);
		cout << "f( " << argumentSinusa << " ) = " << wartosci[i] << endl;
		argumentSinusa += krok;
	}
}

double ObliczBlad(double tabX[], double tabY[], int a[], int m, int n)
{
	double firstSum, secondSum;

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			secondSum += a[j] * pow(tabX[i], j) - tabY[i];
		}
		firstSum += pow(secondSum, 2.0);
	}
	return sqrt(firstSum/(n-1));
}

int main()
{
	double tabX[50];
	double tabY[50];
	const int wezly = 50;
	int m = 3;
	double kresDolny = -2.0;
	double kresGorny = 2.0;

	DyskretyzujSinus(kresDolny, kresGorny, wezly, tabX);

	return 0;
}