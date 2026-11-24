
#include <iostream>
using namespace std;

int main()
{
    int n, cost[10][10], dist[10], visited[10];
    int source, min, u;

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "Enter cost matrix (999 for no connection):\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    cout << "Enter source router: ";
    cin >> source;
    source--;

    for(int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int i = 0; i < n; i++)
    {
        min = 999;
        u = -1;

        for(int j = 0; j < n; j++)
        {
            if(visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(int j = 0; j < n; j++)
        {
            if(visited[j] == 0 &&
               dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    cout << "\nShortest Distance from Router "
         << source + 1 << ":\n";

    for(int i = 0; i < n; i++)
    {
        cout << "Router " << i + 1
             << " = " << dist[i] << endl;
    }

    return 0;
}

