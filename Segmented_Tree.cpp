#include <bits/stdc++.h>
using namespace std;
 
#define sft scanf("%d",&t)
#define sfone scanf("%d",&one)
#define sfqt scanf("%d",&qt)
#define sfl2 scanf("%d%d",&n,&q)
#define sfxy scanf("%d%d",&x,&y)
#define sflr scanf("%d%d",&l,&r)
#define sfarr scanf("%d",&arr[i])
#define Max 100005
int arr[Max];
int tree[Max*4];
 
void init(int node, int beg, int endd)
{
    if(beg == endd)
    {
        tree[node] = arr[beg];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (beg + endd)/2;
 
    init(left, beg, mid);
    init(right, mid+1, endd);
 
    tree[node] = tree[left] + tree[right];
}
 
int query(int node, int beg, int endd, int x, int y)
{
    if(x > y) return 0;
    if(beg == x && endd == y) return tree[node];
 
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (beg + endd)/2;
 
    int l = query(left, beg, mid, x, min(y, mid));
    int r = query(right, mid+1, endd, max(x, mid+1), y);
 
    return l + r;
}
 
void update(int node, int beg, int endd, int x, int val)
{
    if(beg == x && endd == x)
    {
        tree[node] = val;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (beg + endd)/2;
 
    if(x <= mid) update(left, beg, mid, x, val);
    else update(right, mid+1, endd, x, val);
 
    tree[node] = tree[left] + tree[right];
}
 
int main()
{
    int t, n, q, qt, x, y, cs = 1, one;
    sft;
    while(t--)
    {
        sfl2;
        for(int i = 1; i <= n; i++) sfarr;
 
        init(1, 1, n);
        printf("Case %d:\n", cs++);
 
        while(q--)
        {
            sfqt;
            if(qt == 1)
            {
                sfone;
                printf("%d\n", arr[one+1]);
                arr[one+1] = 0;
                update(1, 1, n, one+1, 0);
            }
            else if(qt == 2)
            {
                sfxy;
                arr[x+1] += y;
                update(1, 1, n, x+1, arr[x+1]);
            }
            else
            {
                int l, r;
                sflr;
                int res = query(1, 1, n, l+1, r+1);
                printf("%d\n", res);
            }
        }
    }
}
