#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        cout<<"Case "<< i<<": ";
        if(c%__gcd(a,b))
        cout<<"No\n";
        else
        cout<<"Yes\n";

    }
    return 0;
}