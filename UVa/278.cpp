#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t,n,m;
    char c;
    cin>>t;
    while(t--)
    {
        cin>>c>>n>>m;
        if(c=='r'||c=='Q')
        {
            cout<<min(n,m)<<"\n";
        }
        else if(c=='K')
        {
            cout<<((n+1)/2)*((m+1)/2)<<"\n";
        }
        else
        {
            cout<<(n/2)*(m/2)+((n+1)/2)*((m+1)/2)<<"\n";
        }
        
    }
    return 0;
}