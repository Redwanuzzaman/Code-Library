#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll josephus(ll n, ll k)
{
    if (n == 1) return 1;
    else return (josephus(n - 1, k) + k-1) % n + 1;
}
int main()
{
    ll t, cs = 1;
    cin >> t;
    while(t--)
    {
        ll n, k;
        scanf("%lld %lld",&n, &k);
 
        printf("Case %lld: %lld\n",cs++, josephus(n, k));
    }
}
 
