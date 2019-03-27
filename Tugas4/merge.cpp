/*
Nama : Junia Adhani Juzar
NPM : 140810170015
*/

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 =  right - middle;
int kiri[n1], kanan[n2];


    for (i = 0; i < n1; i++)
        kiri[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        kanan[j] = arr[middle + 1+ j];
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (kiri[i] <= kanan[j])
        {
            arr[k] = kiri[i];
            i++;
        }
        else
        {
            arr[k] = kanan[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = kiri[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = kanan[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left+(right-left)/2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);

        merge(arr, left, middle, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main()
{
    cout<<"=============================\n";
    cout<<"Data merge sort";
    int arr[] = {10,18,9,60,71,2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array nya \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout<<"\nArray yang telah disorting \n";
    printArray(arr, arr_size);
    cout<<"=============================\n";
    return 0;
}
