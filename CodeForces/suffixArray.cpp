#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ll co;
    int n;
    string s;
    cin>>s;
    s+="$";
    n=s.size();
    vector<pair<ll,int>> v(n);
    vector<ll> c(n);
    for(int i=0;i<n;i++)
    v[i]={s[i],i};
    sort(v.begin(),v.end());
    co=0;
    c[v[0].second]=0;
    for(int i=1;i<n;i++)
    {if(v[i].first!=v[i-1].first)co++;
    c[v[i].second]=co;}
    int k=0;
    while((1<<k)<n)
    {
        for(int i=0;i<n;i++)
        {
            v[i]={100000*c[i]+c[(i+(1<<k))%n],i};
        }
        sort(v.begin(),v.end());
        co=0;
        c[v[0].second]=0;
        for(int i=1;i<n;i++)
        {if(v[i].first!=v[i-1].first)co++;
        c[v[i].second]=co;}
        if(co==n-1)break;
        k++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i].second<<" ";
    }
}