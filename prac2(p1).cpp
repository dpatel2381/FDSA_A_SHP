#include <iostream>
#include <vector>
using namespace std;


int findPlateIterative(const vector<string>& plates, const string& target) 
{
    for (int i = 0; i < plates.size(); i++) 
    {
        if (plates[i] == target) 
        {
            return i;
        }
    }
    return -1;
}

int findPlateRecursive(const vector<string>& plates, const string& target, int index = 0) 
{
    if (index >= plates.size()) return -1;
    if (plates[index] == target) return index;
    return findPlateRecursive(plates, target, index + 1);
}

int main() 
{
    vector<string> plates={"GJ01AB1234", "MH02XY5678", "DL03PQ9999", "GJ01AB1234"};
    string target="GJ01AB1234";

    int i=findPlateIterative(plates, target);
    int r=findPlateRecursive(plates, target);

    if (i != -1)
        cout << "Iterative: Plate found at position " << i << endl;
    else
        cout << "Iterative: Plate not found" << endl;

    if (r != -1)
        cout << "Recursive: Plate found at position " << r << endl;
    else
        cout << "Recursive: Plate not found" << endl;

    return 0;
}
