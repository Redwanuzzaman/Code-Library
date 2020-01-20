## PRIME Numbers upto 10^8
===================================================


#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000
#define sft scanf("%d",&t)
#define sfn scanf("%d",&n)

bool isPrime[MAX+1];
vector <int> vct;

void sieve()
{
    int root = sqrt(MAX);
    for(int i = 3; i <= root; i += 2)
    {
        if(isPrime[i] == false)
        {
            for(int j = i * i; j <= MAX; j += i)
                isPrime[j] = true;
        }
    }
    vct.push_back(1);
    vct.push_back(2);
    for(int i = 3; i <= MAX; i += 2)
    {
        if(isPrime[i] == false) vct.push_back(i);
    }
}

int main()
{
    sieve();
    int t, n;
    sft;
    while(t--)
    {
        sfn;
        printf("%d\n", vct[n]);
    }
}
