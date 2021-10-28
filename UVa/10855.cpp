#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    
    while(true)
    {
        cin>>n>>m;
        if(!n)
        break;
        vector<string> s(n),p(m),p1(m),p2(m),p3(m);
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>p[i];
        }
        int r=0,r1=0,r2=0,r3=0;
        for(int i=0;i<=n-m;i++)
        {
            for(int j=0;j<=n-m;j++)
            {
                bool in=1;
                for(int k=0;k<m;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        if(s[i+k][j+l]!=p[k][l])
                        {in=0;break;}
                    }
                }
                if(in)
                r++;
                in=1;
                for(int k=0;k<m;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        if(s[i+k][j+l]!=p[m-1-l][k])
                        {in=0;break;}
                    }
                }
                if(in)
                r1++;
                in=1;
                for(int k=0;k<m;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        if(s[i+k][j+l]!=p[m-1-k][m-1-l])
                        {in=0;break;}
                    }
                }
                if(in)
                r2++;
                in=1;
                for(int k=0;k<m;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        if(s[i+k][j+l]!=p[l][m-1-k])
                        {in=0;break;}
                    }
                }
                if(in)
                r3++;
                
            }
        }
        cout<<r<<" "<<r1<<" "<<r2<<" "<<r3<<"\n";
    }
    return 0;
}