#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t,c,d,b,j,x,a;
    bool ba=false,em;
    string s;
    cin>>c;
    while(c--)
    {
        cin>>d>>b;
        a=0;
        queue<int> l,r;
        j=0;
        while(j<b)
        {
            cin>>x>>s;
            if(s[0]=='l')
            l.push(x);
            else
            r.push(x);
            j++;
        }
        ba=false;
        while(!(l.empty()&&r.empty()))
        {
            t=d*100;
            if(ba)
            {
                while(!r.empty()&&t>=r.front())
                {
                    t-=r.front();
                    r.pop();
                }
            }
            else
            {
                while(!l.empty()&&t>=l.front())
                {
                    t-=l.front();
                    l.pop();
                }
            }
            a++;
            ba=!ba;
            
        }
        cout<<a<<"\n";
    }
    return 0;
}