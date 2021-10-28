#include<bits/stdc++.h>
using namespace std;

int a[100000][40][2];
int main()
{
    ios::sync_with_stdio(0);
    int n,q,t;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0][0];
        a[i][0][1]=a[i][0][0];
    }
    for(int l=0;l<20;l++)
    {
        for(int i=0;i+(2<<l)<=n;i++)
        {
            a[i][l+1][0]=min(a[i][l][0],a[i+(1<<l)][l][0]);
            a[i][l+1][1]=max(a[i][l][1],a[i+(1<<l)][l][1]);
            //cout<<a[i][l+1][0]<<","<<a[i][l+1][1]<<" ";
        }
        //cout<<"\n"<<l<<"\n";
    }
    
    auto min2=[&](int l,int r)->int{
        t=r-l+1;
        int mi=INT_MAX,b=0;
        while(t)
        {
            while(!((1<<b)&t))b++;
            mi=min(mi,a[l][b][0]);
            t=t&(t-1);
            l+=1<<b;
        }
        return mi;
    };
    auto max2=[&](int l,int r)->int{
        t=r-l+1;
        if(t<=0)return -1;
        int mi=INT_MIN,b=0;
        while(t)
        {
           while(!((1<<b)&t))b++;
            mi=max(mi,a[l][b][1]);
            t=t&(t-1);
            l+=1<<b;
        }
        return mi;
    };
    cout<<std::fixed<<std::setprecision(1);
        
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        double p=max2(0,l-1),q=max2(r+1,n-1),s=min2(l,r),t=max2(l,r);
        
        cout<<max(max(p,q)+s,(s+t)*0.5)<<"\n";
    }
    
    return 0;
}