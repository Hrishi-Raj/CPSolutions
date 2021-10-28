#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,t,m,c,x,y,b,z;
    string s;
    map<string,int> d;
    d["left"]=0;
    d["right"]=1;
    cin>>c;
    while(c--)
    {
        cin>>t>>m;
        queue<pair<int,int>> v[2];
        vector<int> time(m);
        for(int i=0;i<m;i++)
        {
            cin>>x>>s;
            v[d[s]].push(make_pair(x,i));
        }
        b=0;
        x=0;
        while(!v[0].empty()||!v[1].empty())
        {
            y=0;
            while(!v[b].empty()&&x>=v[b].front().first&&y<n) 
            {
                time[v[b].front().second]=x+t;
                v[b].pop();
                y++;
            }
            if(y==0)
            {
                if(!v[0].empty()&&!v[1].empty())
                {if(v[b].front().first>v[b^1].front().first)
                {
                    x=max(x,v[b^1].front().first)+t;
                    b^=1;
                }
                else
                {
                    x=max(x,v[b].front().first);
                }
                }
                else if(v[b].empty())
                {
                    x=max(x,v[b^1].front().first)+t;
                    b^=1;
                }
                else
                {
                    x=max(x,v[b].front().first);
                }
                
            }
            else
            {
                x+=t;
                b^=1;    
            }     
        }
        for(int i=0;i<m;i++)
        {
            cout<<time[i]<<"\n";
        }
        if(c)
        cout<<"\n";
    }
    return 0;
}