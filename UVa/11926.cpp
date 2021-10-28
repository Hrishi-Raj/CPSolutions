#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    int n,m,s,e,in;bool c;
    while(true)
    {
        cin>>n>>m;
        if(!(n||m))break;
        bitset<1000005> b;
        c=true;
        while(n--)
        {
            cin>>s>>e;
            e=min(e,1000001);
            if(c)
            for(int i=s;i<e;i++)
            {
                if(b[i]){c=false;break;}
                b.set(i);
            }
        }
        while(m--)
        {
            cin>>s>>e>>in;
            while(c&&s<1000001)
            {
                for(int i=s;i<e;i++)
                {
                    if(b[i]){c=false;break;}
                    b.set(i);
                }
                s+=in;e+=in;
                e=min(e,1000001);
            }
        }
        if(c)
        cout<<"NO CONFLICT\n";
        else
        {
            cout<<"CONFLICT\n";
        }
        
        
    }
    return 0;
}