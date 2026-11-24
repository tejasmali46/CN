
#include <iostream>
using namespace std;

int main()
{
    int n;
    int cost[10][10], dist[10][10];

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "Enter cost matrix (Enter 999 for no connection):\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            dist[i][j] = cost[i][j];
        }
    }

    // Distance Vector Algorithm
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "\nShortest Distance Table:\n";

    for(int i = 0; i < n; i++)
    {
        cout << "Router " << i + 1 << ":\n";

        for(int j = 0; j < n; j++)
        {
            cout << "To Router " << j + 1
                 << " = " << dist[i][j] << endl;
        }

        cout << endl;
    }

    return 0;
}

