```cpp
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, cidr;
    int m1, m2, m3, m4;
    int n1, n2, n3, n4;
    int br1, br2, br3, br4;

    cout << "Enter IP Address (four octets): ";
    cin >> a >> b >> c >> d;

    cout << "Enter CIDR Prefix: ";
    cin >> cidr;

    if (a < 0 || a > 255 || b < 0 || b > 255 ||
        c < 0 || c > 255 || d < 0 || d > 255 ||
        cidr < 1 || cidr > 30)
    {
        cout << "Invalid IP Address or Prefix!";
        return 0;
    }

    // Generate subnet mask
    int mask[4];

    for (int i = 0; i < 4; i++)
    {
        int remaining = cidr - (i * 8);

        if (remaining >= 8)
            mask[i] = 255;
        else if (remaining <= 0)
            mask[i] = 0;
        else
            mask[i] = (255 << (8 - remaining)) & 255;
    }

    m1 = mask[0];
    m2 = mask[1];
    m3 = mask[2];
    m4 = mask[3];

    // Calculate network address
    n1 = a & m1;
    n2 = b & m2;
    n3 = c & m3;
    n4 = d & m4;

    // Calculate broadcast address
    br1 = n1 | (255 - m1);
    br2 = n2 | (255 - m2);
    br3 = n3 | (255 - m3);
    br4 = n4 | (255 - m4);

    // Calculate host information
    int hostBits = 32 - cidr;
    int totalHosts = (1 << hostBits);
    int usableHosts = totalHosts - 2;

    cout << "\n----- SUBNET CALCULATOR -----\n";

    cout << "Subnet Mask: "
         << m1 << "." << m2 << "." << m3 << "." << m4;

    cout << "\nNetwork Address: "
         << n1 << "." << n2 << "." << n3 << "." << n4;

    cout << "\nBroadcast Address: "
         << br1 << "." << br2 << "." << br3 << "." << br4;

    cout << "\nFirst Usable IP: "
         << n1 << "." << n2 << "." << n3 << "." << n4 + 1;

    cout << "\nLast Usable IP: "
         << br1 << "." << br2 << "." << br3 << "." << br4 - 1;

    cout << "\nHost Bits: " << hostBits;
    cout << "\nTotal IP Addresses: " << totalHosts;
    cout << "\nUsable Hosts: " << usableHosts;

    return 0;
}
```
