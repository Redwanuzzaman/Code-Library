#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> edges[100];
    vector <int> indegree[100];
    vector <int> outdegree[100];

    int e, n, x, y;
    cin >> n >> e;
    for(int i = 1; i <= e;  i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
        indegree[y].push_back(x);
        outdegree[x].push_back(y);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for(int j = 0; j < edges[i].size(); j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << "Indegree of " << i << " -> ";
        for(int j = 0; j < indegree[i].size(); j++)
        {
            cout << indegree[i][j] << " ";
        }
        cout << endl;
    }
}
