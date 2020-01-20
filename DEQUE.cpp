#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t, sz, cmd, num;
    string str;
    cin >> t;
 
    for(int i = 1; i <= t; i++)
    {
        cin >> sz >> cmd;
 
        deque <int> dq;
 
        cout << "Case " << i << ":" << endl;
 
        for(int j = 0; j < cmd; j++)
        {
            cin >> str;
            if(str == "pushLeft" || str == "pushRight") cin >> num;
 
            if((str == "pushLeft" || str == "pushRight") && dq.size() == sz) cout << "The queue is full" << endl;
            else if((str == "popLeft" || str == "popRight") && dq.size() == 0) cout << "The queue is empty" << endl;
 
            else if(str == "pushLeft")
            {
                cout << "Pushed in left: " << num << endl;
                dq.push_front(num);
            }
            else if(str == "pushRight")
            {
                cout << "Pushed in right: " << num << endl;
                dq.push_back(num);
            }
            else if(str == "popLeft")
            {
                cout << "Popped from left: " << dq.front() << endl;
                dq.pop_front();
            }
            else if(str == "popRight")
            {
                cout << "Popped from right: " << dq.back() << endl;
                dq.pop_back();
            }
        }
    }
    return 0;
}
