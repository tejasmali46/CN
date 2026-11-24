#include <iostream>
using namespace std;

int main()
{
    int a[8], p1, p2, p4, error;

    cout<<"Enter 4 data bits: ";
    cin>>a[3]>>a[5]>>a[6]>>a[7];

    // Calculate parity bits
    a[1] = a[3] ^ a[5] ^ a[7];
    a[2] = a[3] ^ a[6] ^ a[7];
    a[4] = a[5] ^ a[6] ^ a[7];

    cout<<"\nGenerated Hamming Code: ";
    for(int i=1;i<=7;i++)
        cout<<a[i];

    // Receiver side
    cout<<"\nEnter received 7 bits: ";
    for(int i=1;i<=7;i++)
        cin>>a[i];

    // Calculate syndrome bits
    p1 = a[1] ^ a[3] ^ a[5] ^ a[7];
    p2 = a[2] ^ a[3] ^ a[6] ^ a[7];
    p4 = a[4] ^ a[5] ^ a[6] ^ a[7];

    error = p4*4 + p2*2 + p1;

    if(error == 0)
    {
        cout<<"No error detected";
    }
    else
    {
        cout<<"\nError detected at position: "<<error;

        // Correct the error
        a[error] = a[error] ^ 1;

        cout<<"\nCorrected Hamming Code: ";
        for(int i=1;i<=7;i++)
            cout<<a[i];
    }

    return 0;
}

