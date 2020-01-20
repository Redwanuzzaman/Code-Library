#include <bits/stdc++.h>
using namespace std;
 
#define sft scanf("%d",&t)
#define sfn scanf("%d",&n)
#define MAX 10000000
bool marked[MAX];
vector <int> primes;
 
void sieve()
{
    for(int i = 3; i * i <= MAX; i += 2)
    {
        if(marked[i] == false)
        {
            for(int j = i * i; j <= MAX; j += i+i)
                marked[j] = true;
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= MAX; i += 2)
        if(marked[i] == false) primes.push_back(i);
}
int main()
{
    sieve();
    int t, n, tmp, cs = 1;
    sft;
    while(t--)
    {
        sfn;
        int res = 0;
        for(int i = 0; primes[i] <= n/2; i++)
        {
            if((marked[n-primes[i]] == false) && ((n - primes[i] & 1) || (n - primes[i] == 2))) res++;
        }
        cout << "Case " << cs++ << ": " << res << endl;
    }
}
 
