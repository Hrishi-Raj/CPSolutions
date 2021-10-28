#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> v(n+1),p(n+1);v[0]=0;
        for(int i=0;i<=n;i++)
        v[i]=i;
        int x=n;
        for(int i=2,j=0;i<n+2;i++)
        {
            int y=j,z=0;
            while(y)
            {
                z+=v[y];
                y=y&(y-1);
            }
            if(x-z<i)
            i-=x-z;
            i%=x;
            int l=0,r=n,m;
            while(l<r)
            {
                m=(l+r)/2;
                if(v[m]<i)
                l=m+1;
                else if(v[m]>i)
                r=m-1;
                else if(v[m-1]==v[m])
                r=m-1;
                else{
                    x--;
                    v[m]--;
                }
                
            }

        }
    }
}