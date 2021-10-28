#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    fstream cin,cout;
    cin.open("in.txt");
    cout.open("out.txt");
    long n,ma, m;
    while(cin>>n)
    {
        m=1<<n;
        vector<long> v(m),c(m);
        for(int i=0;i<m;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                c[i]+=v[i^(1<<j)];
            }
        }
        ma=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ma=max(ma,c[i^(1<<j)]+c[i]);
            }
        }
        cout<<ma<<"\n";
    }
    return 0;
}