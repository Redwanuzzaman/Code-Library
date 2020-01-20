#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define Mod 1000003
#define mx 1000001
ll fact[mx];
 
ll bigmod(ll base, ll power)
{
    ll res = 1;
    while(power)
    {
        if(power & 1) res = (res * base) % Mod;
        base = (base * base) % Mod;
        power >>= 1;
    }
    return res;
}
void storeFact()
{
    fact[0] = 1;
    for(ll i = 1; i <= mx; i++)
    {
        fact[i] = ((fact[i-1] % Mod) * (i % Mod)) % Mod;
    }
}
int main()
{
 
    ll test, cs = 1, n, k;
    storeFact();
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&k);
        ll tmp = ((fact[n-k] % Mod) * (fact[k] % Mod)) % Mod;
        ll tmp2 = bigmod(tmp, Mod-2);
        ll res = (fact[n] * tmp2) % Mod;
        printf("Case %lld: %lld\n", cs++, res);
    }
}
