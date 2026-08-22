#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) 
{
    int maxVal=arr[0];
    for(int i=1;i<arr.size();i++) 
    {
        if(arr[i]>maxVal) 
        {
            maxVal=arr[i];
        }
    }

    vector<int> count(maxVal + 1, 0);

    for(int num : arr) 
    {
        count[num]++;
    }

    int index=0;
    for (int i=0;i<=maxVal;i++) 
    {
        while(count[i]>0)
        {
            arr[index++]=i;
            count[i]--;
        }
    }
}

int main() 
{
    vector<int> colors={2, 0, 1, 2, 1, 0, 1, 2};

    cout<<"Original order: ";
    for(int c : colors) 
    {
        cout<<c<<" ";
    }
    cout<<endl;

    countingSort(colors);

    cout<<"Sorted order:   ";
    for (int c : colors) 
    {
        cout<<c<<" ";
    }
    cout<<endl;

    return 0;
}
