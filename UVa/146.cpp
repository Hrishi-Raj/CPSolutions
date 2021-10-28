#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,k;
    
    while(1)
    {
        cin>>s;
        if(s[0]=='#')break;
        if(next_permutation(s.begin(),s.end()))
        cout<<s<<"\n";
        else
        cout<<"No Successor\n";
    }
    return 0;
}