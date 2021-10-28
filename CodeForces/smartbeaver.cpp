#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include<fstream>
#include <algorithm>
#include <map>
using namespace std;

void red(vector<pair<int,long>> &v,int i,int m,int h)
{
    if(v[i].first==-1)
    {
        v[i].first=(i+m)%v.size();
        v[i].second=1;
        return;
    }
    cout<<i<<"red"<<endl;
    red(v,v[i].first,m,h);
    if(v[v[i].first].first!=i)
    {
        v[i].first=v[v[i].first].first;
        v[i].second=v[v[i].first].second+1;
    }

}
void res(vector<pair<int,long>> &v,int i,int p,int m)
{
    if(i==p)
    return;
    if(v[i].first==p)
    {
        v[i].first=v[(i+m)%v.size()].first;
        v[i].second=v[(i+m)%v.size()].second+1;
        cout<<i-m<<"res"<<endl;
        res(v,abs(i-m)%v.size(),p,m);
    }
}
int main()
{
    long h,m,n,x,y,j;
    cin>>h>>m>>n;
    char c;
    vector<pair<int,long>> v(h);
    for(int i=0;i<h;i++)
    v[i].first=-1;
    map<int,int> f;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        cout<<c<<endl;
        if(c=='+')
        {
            cin>>x>>y;
            red(v,y,m,h);
            f[x]=((v[y].first-m)%h+m)%h;
            cout<<f[x]<<endl;
            j+=(v[y].second);
        }
        else
        {
            cin>>x;
            v[f[x]].first=-1;
            v[f[x]].second=0;
            res(v,((f[x]-m)%h+m)%h,v[f[x]].first,m);
            f.erase(x);
        }
        for(int i=0;i<h;i++)
        cout<<v[i].first<<" ";
        cout<<endl;
    }
    cout<<j;
    return 0;
}