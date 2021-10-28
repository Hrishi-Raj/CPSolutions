#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t,k,x;
    unsigned char c;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>k;
        map<char,int> m;
        for(int i=0;i<k;i++)
        {
            cin>>c>>x;
            m[c]=x;
        }
        vector<int> v(550);
        cin>>k;
        getline(cin,s);
        while(k--)
        {
            getline(cin,s);
            
            for(int i=0;i<s.length();i++)
            {
                v[s[i]+130]++;
            }
        }
        double cost=0;
        for(auto i:m)
        {
            cost+=v[i.first+130]*i.second;
        }
        cost/=100;
        cout<<fixed<<setprecision(2)<<cost<<"$\n";
    }
    return 0;
}