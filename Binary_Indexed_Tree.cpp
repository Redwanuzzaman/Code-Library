#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int arr[mx], tree[mx];
void update(int idx,int val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int read(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int query(int x, int y)
{
    return read(y) - read(x-1);
}
int main()
{
    int t, n, q, cs = 1, type, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &q);
        memset(tree, 0, sizeof tree);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            update(i, arr[i], n);
        }
        printf("Case %d:\n",cs++);
        while(q--)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                scanf("%d", &x);
                x++;
                printf("%d\n", arr[x]);
                update(x, -arr[x], n);
                arr[x] = 0;
            }
            else if(type == 2)
            {
                scanf("%d %d", &x, &y);
                x++;
                update(x, y, n);
                arr[x] += y;
            }
            else
            {
                scanf("%d %d", &x, &y);
                x++, y++;
                printf("%d\n", query(x, y));
            }
        }
    }
}
