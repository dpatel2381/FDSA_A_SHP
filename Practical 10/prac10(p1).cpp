#include <iostream>
using namespace std;

int main()
{
    int table[10], n, value;

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter registration number: ";
        cin >> value;

        int index = value % 10;
        int count = 0;

        while (table[index] != -1 && count < 10)
        {
            index = (index + 1) % 10;
            count++;
        }

        if (count == 10)
            cout << "Parking lot is full. Vehicle cannot be parked.\n";
        else
            table[index] = value;
    }

    cout << "\nParking Slot\tRegistration Number\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t\t";
        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];
        cout << "\n";
    }

    return 0;
}
