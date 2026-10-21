#include <iostream>
using namespace std;

int main()
{
    int table[10], n, value;
    int steps[4] = {1, 3, 7, 9};

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of student IDs: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter student ID: ";
        cin >> value;

        int h1 = value % 10;
        int h2 = steps[value % 4];
        int index = h1;
        int j = 0;

        while (table[index] != -1 && j < 10)
        {
            j++;
            index = (h1 + j * h2) % 10;
        }

        if (j == 10)
            cout << "Hash table is full. ID cannot be inserted.\n";
        else
            table[index] = value;
    }

    cout << "\nSlot\tStudent ID\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << "\n";
    }

    return 0;
}