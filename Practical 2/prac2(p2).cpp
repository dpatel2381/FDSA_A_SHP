#include <iostream>
#include <vector>
#include <string>
using namespace std;

int binarySearchIterative(const vector<string>& bookCodes, const string& target) 
{
    int low=0, high=bookCodes.size()-1;

    while(low<=high) 
    {
        int mid=(low + high)/2;

        if(bookCodes[mid]==target)
        {
            return mid;
        }
        else if(bookCodes[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
            
    }
    return -1; 
}

int binarySearchRecursive(const vector<string>& bookCodes, const string& target, int low, int high) 
{
    if(low>high)
    {
        return -1;
    }
        
    int mid=(low+high)/2;

    if(bookCodes[mid]==target)
    {
        return mid;
    }
    else if(bookCodes[mid] < target)
    {
        return binarySearchRecursive(bookCodes, target, mid+1, high);
    }
    else
    {
        return binarySearchRecursive(bookCodes, target, low, mid-1);
    }
}

int main() 
{
    vector<string> codes={"A101", "A205", "B310", "C220", "D105", "E500"};
    string target="C220";

    int i=binarySearchIterative(codes, target);
    int r=binarySearchRecursive(codes, target, 0, codes.size() - 1);

    cout<<"Iterative result: "<<i<<endl;
    cout<<"Recursive result: "<<r<<endl;

    return 0;
}
