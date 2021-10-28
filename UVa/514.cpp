#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    int n,t,c;
    while(cin>>n)
    {
        if(!n)
        break;
        while(true)
        {   
            stack<int> s;
            t=1;
            vector<int> v(n);
            cin>>v[0];
            if(!v[0])
            break;
            for(int i=1;i<n;i++)
            {
                cin>>v[i];
            }
            c=0;
            for(int i=1;i<=n;)
            {
                while(i<=n&&(s.empty()||s.top()!=v[c]))
                {
                    s.push(i);
                    i++;
                }
                while(!s.empty()&&s.top()==v[c])
                {
                    s.pop();
                    c++;
                }    
            }
            if(c<n)
            cout<<"No\n";
            else
            cout<<"Yes\n";
        }
        cout<<"\n";
    }
    return 0;
}