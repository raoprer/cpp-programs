#include <iostream>
using namespace std;

void components(int adjm[20][20], int n, int s)
{
    bool visited[20];
    int que[20];
    int f = -1;
    int e = -1;
    int count = 1;
    bool component[20];
    for (int i = 1; i <= 20; i++)
        component[i] = false;
    while (true)
    {
        for (int i = 0; i < 20; i++)
            visited[i] = false;
        bool more = false;
        que[++e] = s;
        component[s]=true;
        visited[s] = true;
        while (e != f)
        {
            int cv = que[++f];
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i] && (adjm[cv][i] == 1 || adjm[i][cv]))
                {
                    component[i] = true;
                    visited[i] = true;
                    que[++e] = i;
                }
            }
        }
        cout << "The vertices of " << count++ << " component:";
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                cout << ">" << i;
            }
            else
            {
                if (!component[i])
                {
                    s = i;
                    more = true;
                }
            }
        }
        if (!more)
        {
            break;
        }
        cout << endl;
    }
}

int main()
{
    int n = 8;
    int adjmat[20][20];
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            adjmat[i][j] = 0;
        }
    }
    adjmat[1][2] = 1;
    adjmat[2][3] = 1;
    adjmat[3][4] = 1;
    adjmat[5][6] = 1;
    adjmat[6][7] = 1;
    adjmat[7][8] = 1;
    components(adjmat, 8, 1);
}
