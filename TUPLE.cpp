#include<bits/stdc++.h>
using namespace std;

bool sortdesc(const tuple<int, int, string> &a, const tuple<int, int, string> &b)
{
    if(get<0>(a) > get<0>(b)){
        return (get<0>(a) > get<0>(b));
    }
    if(get<0>(a) == get<0>(b)){
        return (get<1>(a) < get<1>(b));
    }
    return (get<0>(a) > get<0>(b));
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<tuple <int, int, string> >vct;
    vector<tuple <int, int, string> > :: const_iterator it;
    for(int i = 0; i < n; i++)
    {
        int num;
        int roll_num;
        string name;
        scanf("%d",&roll_num);
        getchar();
        getline(cin, name);
        scanf("%d", &num);
        vct.push_back(make_tuple(num,roll_num,name));
    }
    sort(vct.begin(),vct.end(), sortdesc);
    printf("Roll | Name       | Marks\n");
    printf("-------------------------\n");

    for(it = vct.begin(); it != vct.end(); it++)
    {
        cout << setw(4) << get<1>(*it) << " | " ;
        string s = get<2>(*it);
        cout << s;
        for(int i = 0; i < 10-s.size(); i++) cout << " ";
        cout << " | " << get<0>(*it) << "\n";
    }
}
