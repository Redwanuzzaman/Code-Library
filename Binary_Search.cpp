#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int value)
{
    int beg = 0, endd = n-1, mid, ans = -1;
    while(beg <= endd)
    {
        mid = (beg + endd)/2;
        if(arr[mid] == value)
        {
            endd = mid-1;
            ans = mid;
        }
        else if(arr[mid] > value)
        {
            endd = mid-1;
        }
        else
        {
            beg = mid+1;
        }
    }
    return ans;
}
int main()
{
    int n, q, value;
    scanf("%d %d", &n, &q);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while(q--)
    {
        scanf("%d", &value);
        int idx = binarySearch(arr, n, value);
        printf("%d\n", idx);
    }
}
