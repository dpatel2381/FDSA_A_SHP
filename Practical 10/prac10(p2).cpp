#include <iostream>
using namespace std;

int main()
{
    int table[10][100], count[10] = {0};
    int n, value;

    cout << "Enter number of book codes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter book code: ";
        cin >> value;

        int index = value % 10;

        if (count[index] < 100)
            table[index][count[index]++] = value;
        else
            cout << "Shelf capacity exceeded.\n";
    }

    cout << "\nShelf\tBook Codes\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t";

        if (count[i] == 0)
            cout << "Empty";

        for (int j = 0; j < count[i]; j++)
            cout << table[i][j] << " ";

        cout << "\n";
    }

    return 0;
}