#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    int n,a[2],s;
    string st;
    char c;
    while(cin.peek()!=EOF)
    {
        s=0;
        cin>>n>>a[0];
        vector<int> v(n-1);
        for(int i=1;i<n;i++)
        {
            cin>>a[i&1];
            v[i-1]=abs(a[1]-a[0]);
        }
        getline(cin,st);
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++)
        {
            if(v[i]!=i+1)
            {
                s=1;
                break;
            }
        }
        if(s)
        {
            cout<<"Not jolly\n";
        }
        else
        {
            cout<<"Jolly\n";
        }
    }
    return 0;
}