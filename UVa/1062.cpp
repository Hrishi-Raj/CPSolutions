#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    int in,t=1;
    while(1)
    {
        cin>>s;
        if(s=="end")
        break;
        vector<char> v;
        v.push_back(s[0]);
        for(int i=1;i<s.size();i++)
        {
            in=lower_bound(v.begin(),v.end(),s[i])-v.begin();
            if(in==v.size())
            {
                v.push_back(s[i]);
            }
            else
            {
                v[in]=s[i];
            }
        }
        cout<<"Case "<<t<<": "<<v.size()<<"\n";
        t++;
    }
    return 0;
}