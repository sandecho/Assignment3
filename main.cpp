/*
 * main.cpp
 *
 *  Created on: 31-Jan-2015
 *      Author: sandeep
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int a[4];

void swap(int *X, int *Y)
{
	int temp;
	temp = *X;
	*X = *Y;
	*Y = temp;
}

void permutation(int arr[], int i, int n, int sum)
{
	int j;
	if(i == n)
	{
		if((arr[0] + arr[1] + arr[2]*arr[3]) <= sum)
			printf("  %d, %d, %d, %d  \n", arr[0], arr[1], arr[2], arr[3]);
	}
	else
	{
		for(j = i; j <= n; j++)
		{
			swap(arr[i], arr[j]);
			permutation(arr, i + 1, n, sum);
			swap(arr[i], arr[j]);
		}
	}
	return;
}


void combinations(int v[], int start, int n, int k, int maxk, int sum1)
{
	int     i;
	int sum = sum1;
	int b[4];
	if(k > maxk)
	{
		for(i = 1; i <= maxk; i++)
		{
			int k = v[i];
			b[i - 1] = a[k - 1];
		}
		permutation(b, 0, 3, sum);
		return;
	}
	for(i = start; i <= n; i++)
	{
		v[k] = i;
		combinations(v, i + 1, n, k + 1, maxk, sum);
	}
}

int main()
{
	int     v[100], n, sum, k;
	cout << "Enter total no of integer :  ";
	cin >> n;
	cout << "Enter the value of sum  :  ";
	cin >> sum;
	for(int i = 0; i < n; i++)
	{
		printf("%d value of a ", i);
		cin >> a[i];
	}
	k = 4;
	combinations(v, 1, n, 1, k, sum);
	cout << "Done" << endl;
	return 0;
}




