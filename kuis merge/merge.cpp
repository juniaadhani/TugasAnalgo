/*
Nama : Junia Adhani JUzar
NPM : 140810170015
*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>


using namespace std;



void merge(int arr[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;


	int L[n1], R[n2];


	for (i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[q + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = p; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int p, int r)
{
	if (p < r)
	{

		int q = p+(r-p)/2;

		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);

		merge(arr, p, q, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main()
{
	int arr[] = {20, 18, 8, 1, 4, 19, 21};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Array yang ingin di sorting \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nHasil dari merge sort \n");
	printArray(arr, arr_size);
	return 0;
}
