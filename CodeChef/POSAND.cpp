#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    vector<int> v(100001);
    v[1]=2,v[2]=1,v[3]=3,v[4]=5,v[5]=4;
    
    for(int i=6;i<100001;i++)
    {
        v[i]=i;
    }
    for(int i=8;i<=100001;i=i<<1)
    {
        v[i]=i+1;
        v[i+1]=i;
    }
    while(t--)
    {
        cin>>n;
        if(n==1)cout<<"1 ";
        if(n&(n-1))
        {
            for(int i=1;i<=n;i++)
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}