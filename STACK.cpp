#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t, i = 1;
    string s, s2;
    cin >> t;
    while(t--)
    {
        stack <string> bck, frd;
        bck.push("http://www.lightoj.com/");
        cout << "Case " << i++ << ":" << endl;
 
        while(cin >> s)
        {
            if(s == "QUIT") break;
            else if(s == "VISIT")
            {
                cin >> s2;
                cout << s2 << endl;
                bck.push(s2);
                if(!frd.empty())
                {
                    while(!frd.empty()) frd.pop();
                }
            }
            else if(s == "BACK")
            {
                frd.push(bck.top());
                bck.pop();
                if(bck.empty())
                {
                    cout << "Ignored" << endl;
                    bck.push(frd.top());
                    frd.pop();
                }
                else cout << bck.top() << endl;
            }
            else
            {
                if(frd.empty())
                    cout << "Ignored" << endl;
                else
                {
                    cout << frd.top() << endl;
                    bck.push(frd.top());
                    frd.pop();
                }
            }
        }
    }
}
