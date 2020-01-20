#include <bits/stdc++.h>
using namespace std;

#define sft scanf("%d",&t)
#define sfn scanf("%d",&n)
#define sfxy scanf("%d%d",&x,&y)
#define sfnm scanf("%d%d",&n,&m)
#define sfarr scanf("%d",&arr[i])
#define sftll scanf("%lld",&t)
#define sfnll scanf("%lld",&n)
#define sfnmll scanf("%lld%lld",&n,&m)
#define sfxyll scanf("%lld%lld",&x,&y)
#define sfarrll scanf("%lld",&arr[i])
#define sf2d scanf("%d%d",&arr[i][j])
#define pi acos(-1)
#define MAX 100000000
typedef long long ll;

bool marked[20000003];
vector <int> prime;

bool isPrime(int n)
{
    if(n == 2) return true;
    if(n < 2 || (n % 2 == 0)) return false;
    return marked[n] == false;
}

// SIEVE
void sieve(int n)
{
    for(int i = 3; i * i <= n; i += 2)
    {
        if(marked[i] == false)
        {
            for(int j = i * i; j <= n; j += i+i)
                marked[j] = true;
        }
    }
}

//PRIME STORING WITH SIEVE
void sieve()
{
    int root = sqrt(MAX);
    for(int i = 3; i <= root; i += 2)
    {
        if(marked[i] == false)
        {
            for(int j = i * i; j <= MAX; j += i)
                marked[j] = true;
        }
    }
    prime.push_back(1);
    prime.push_back(2);
    for(int i = 3; i <= MAX; i += 2)
    {
        if(marked[i] == false) prime.push_back(i);
    }
}
// EULER TOTIENT FUNCTION
int eulerTotient(int n)
{
    int result = n;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
            }
            result -= (result/ i);
        }
    }
    if(n > 1) result -= (result / n);
    return result;
}

// DIVISOR COUNT OF A NUMBER
int countDivisor(int n) {
  int divisor = 0;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      divisor += 1;
    } else if (n % i == 0) {
      divisor += 2;
    }
  }
  return divisor;
}
int main()
{

    return 0;
}
