#include<bits/stdc++.h>
using namespace std;

struct query{
    int i,l,r;
    long long a;
    query(){i=0;l=0;r=0;a=-1;}
    query(int i1,int l1,int r1)
    {
        i=i1;
        l=l1-1;
        r=r1-1;
        a=-1;
    }
};
struct comp{
    int block;
    comp(int b){this->block = b;}
    bool operator () (const query a,const query b)
    {
        if(a.l/block==b.l/block)
        return a.r<b.r;
        return a.l<b.l;
    }
};
int main()
{
    int n,m,l,r;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<query> q(m);
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        q[i]=query(i,l,r);
    }
    int block=ceil(sqrt(n));
    sort(q.begin(),q.end(),comp(block));
    for(int i=0;i<m;i++)
    cout<<q[i].l<<q[i].r<<"\n";
    vector<int> c(200001);
    l=0;r=0;
    long long a=v[0];c[v[0]]=1;
    for(int i=0;i<m;i++)
    {
        while(l<q[i].l)
        {
            a-=v[l]*c[v[l]]*c[v[l]];
            c[v[l]]--;
            a+=v[l]*c[v[l]]*c[v[l]];
            l++;
        }
        while(l>q[i].l)
        {
            l--;
            a-=v[l]*c[v[l]]*c[v[l]];
            c[v[l]]++;
            a+=v[l]*c[v[l]]*c[v[l]];
        }
        while(r<q[i].r)
        {
            r++;
            a-=v[r]*c[v[r]]*c[v[r]];
            c[v[r]]++;
            a+=v[r]*c[v[r]]*c[v[r]];
        }
        while(r>q[i].r)
        {
            a-=v[r]*c[v[r]]*c[v[r]];
            c[v[r]]--;
            a+=v[r]*c[v[r]]*c[v[r]];
            r--;
        }
        q[i].a=a;
    }
    sort(q.begin(),q.end(),[](const query a,const query b)-> bool{return a.i<b.i;});
    for(int i=0;i<m;i++)
    cout<<q[i].a<<"\n";
    return 0;
}
