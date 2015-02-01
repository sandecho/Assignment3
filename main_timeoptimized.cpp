//============================================================================
// Name        : ass3.cpp
// Author      : sandeep
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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

void swap(int *X,int *Y)
{
int temp;
temp = *X;
*X = *Y;
*Y = temp;
}
void Rotate(int *p){
        int i = *p;
        *p  = *(p+3);
        *(p+3)  = *(p+2);
        *(p+2)  = *(p+1);
        *(p+1)  = i;
        return ;
}
void permutation(int a[], int sum)
{
        int j =0;
        for(int i=0; i<5; i++){
                if((a[0] + a[1])+( a[2] *a[3]) <= sum){
                        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
                        cout<<a[0]<<" "<<a[1]<<" "<<a[3]<<" "<<a[2]<<endl;
                        cout<<a[1]<<" "<<a[0]<<" "<<a[2]<<" "<<a[3]<<endl;
                        cout<<a[1]<<" "<<a[0]<<" "<<a[3]<<" "<<a[2]<<endl;
                }
                if(i==3){
			swap(&a[0], &a[3]);
                }else{
			Rotate(a);
                }
        }
	Rotate(a);
	if((a[0] + a[1])+( a[2] * a[3]) <= sum){
                        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
                        cout<<a[0]<<" "<<a[1]<<" "<<a[3]<<" "<<a[2]<<endl;
                        cout<<a[1]<<" "<<a[0]<<" "<<a[2]<<" "<<a[3]<<endl;
                        cout<<a[1]<<" "<<a[0]<<" "<<a[3]<<" "<<a[2]<<endl;
      }

}

void combinations (int v[], int start, int n, int k, int maxk, int sum1)
{
        int     i;
	int sum = sum1;
        int b[4];
        if (k > maxk) {
                for (i=1; i<=maxk; i++)
		{ int k=v[i]; b[i-1] = a[k-1];}
		permutation(b, sum);
		return;
        }

        for (i=start; i<=n; i++) {
                v[k] = i;
                combinations (v, i+1, n, k+1, maxk, sum);
        }
}

int main ()
{
     int     v[100], n, sum, k;
	cout<<"Enter total no of integer :  ";
	cin>>n;
	cout<<"Enter the value of sum  :  ";
	cin>>sum;
	for(int i=0; i< n; i++)
	{
	printf("%d value of a ", i);
	cin>>a[i];
	}
       	k=4;
        combinations (v, 1, n, 1, k, sum);
        cout<<"Done"<<endl;
        return 0;
}





