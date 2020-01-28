// Implementation of Disjoint Set

#include <bits/stdc++.h>
using namespace std;
#define Max 101

int parent[Max];

void make_set(int m)
{
    parent[m] = m;
}

int find_root(int representative)
{
    if(parent[representative] == representative)
    {
        return representative;
    }
    return parent[representative] = find_root(parent[representative]);
}

void union_find(int x, int y)
{
    int u = find_root(x);
    int v = find_root(y);

    if(u == v)
    {
        printf("Already Friends\n");
    }
    else
    {
        printf("Not Friends Yet\n");
        parent[u] = v;
    }
}

int main()
{

}
