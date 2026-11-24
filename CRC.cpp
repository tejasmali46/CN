#include <iostream>
using namespace std;

int main()
{
    int data[20], gen[10], temp[20];
    int n, m;

    cout << "Enter number of data bits: ";
    cin >> n;

    cout << "Enter data bits: ";
    for(int i = 0; i < n; i++)
        cin >> data[i];

    cout << "Enter number of generator bits: ";
    cin >> m;

    cout << "Enter generator bits: ";
    for(int i = 0; i < m; i++)
        cin >> gen[i];


    // Copy data and append zeros
    for(int i = 0; i < n; i++)
        temp[i] = data[i];

    for(int i = n; i < n + m - 1; i++)
        temp[i] = 0;

    // Perform XOR division
    for(int i = 0; i < n; i++)
    {
        if(temp[i] == 1)
        {
            for(int j = 0; j < m; j++)
                temp[i+j] = temp[i+j] ^ gen[j];
        }
    }

    // Display transmitted data
    cout << "\nTransmitted Data: ";

    for(int i = 0; i < n; i++)
        cout << data[i];

    for(int i = n; i < n + m - 1; i++)
        cout << temp[i];

    // Receive data
    cout << "\nEnter received data: ";

    for(int i = 0; i < n + m - 1; i++)
        cin >> temp[i];

    // Check received data
    for(int i = 0; i < n; i++)
    {
        if(temp[i] == 1)
        {
            for(int j = 0; j < m; j++)
                temp[i+j] = temp[i+j] ^ gen[j];
        }
    }

    // Check remainder
    int error = 0;

    for(int i = n; i < n + m - 1; i++)
    {
        if(temp[i] != 0)
            error = 1;
    }

    if(error == 0)
        cout << "No Error Detected";
    else
        cout << "Error Detected";

    return 0;
}

