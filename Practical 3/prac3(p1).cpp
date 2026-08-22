#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{
    for(int i=0;i<n-1;i++) 
    {
        for(int j=0;j<n-i-1;j++) 
        {
            if(arr[j]>arr[j+1]) 
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout<<"Bubble Sort: ";
    for(int i=0; i<n; i++) 
    {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int n) 
{
    for(int i=0;i<n-1;i++) 
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++) 
        {
            if(arr[j]<arr[minIndex]) 
            {
                minIndex=j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    cout<<"Selection Sort: ";
    for(int i=0; i<n; i++) 
    {
        cout<<arr[i]<<" ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) 
{
    for(int i=1;i<n;i++) 
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    cout<<"Insertion Sort: ";
    for(int i=0; i<n; i++) 
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() 
{
    int marks1[] = {45, 12, 78, 34, 23, 56};
    int marks2[] = {45, 12, 78, 34, 23, 56};
    int marks3[] = {45, 12, 78, 34, 23, 56};
    int n = sizeof(marks1)/sizeof(marks1[0]);

    cout<<"Original Marks: ";
    for(int i=0; i<n; i++) 
    {
        cout << marks1[i] << " ";
    }
    cout << endl;

    bubbleSort(marks1, n);
    selectionSort(marks2, n);
    insertionSort(marks3, n);

    return 0;
}
