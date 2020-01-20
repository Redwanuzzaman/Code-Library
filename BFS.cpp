#include <bits/stdc++.h>
using namespace std;
#define sft scanf("%d",&t)
#define sfne scanf("%d%d",&n,&e)
#define sfab scanf("%d%d",&a,&b)
#define MAX 1005

vector <int> adj[MAX];
int level[MAX];
bool vis[MAX];

void connection(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void initialize()
{
    for(int i = 0; i <= MAX; i++)
    {
        adj[i].clear();
        level[i] = -1;
        vis[i] = false;
    }
}

void bfs(int n)
{
    queue <int> q;
    q.push(n);
    level[n] = 0; // source node level 0
    vis[n] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < adj[cur].size(); i++)
        {
            int x = adj[cur][i];
            if(vis[x] == false)
            {
                level[x] = level[cur] + 6;
                q.push(x);
                vis[x] = true;
            }
        }
    }
}
int main()
{
    int t, n, e, a, b, source;
    sft;
    while(t--)
    {
        sfne;
        initialize();
        for(int i = 0; i < e; i++)
        {
            sfab;
            connection(a, b);
        }
        scanf("%d", &source);
        bfs(source);
        for(int i = 1; i <= n; i++)
        {
            if(i == source)
            {
                continue;
            }
            else if(i == n)
            {
                printf("%d\n", level[i]);
            }
            else
            {
                printf("%d ", level[i]);
            }
        }
    }
}
