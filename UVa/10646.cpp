#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t,k=1;
    cin>>t;
    while(k<=t)
    {
        vector<string> v(52);
        for(int i=0;i<52;i++)
        {
            cin>>v[i];
        }
        int i=26,y=0,j=3,x;
        while(j--)
        {
            if(v[i][0]<='9'&&v[i][0]>='0')
            x=v[i][0]-'0';
            else
            x=10;
            y+=x;
            i-=11-x;
        }
        cout<<"Case "<<k<<": ";
        if(y<=i+1)
        cout<<v[y-1]<<"\n";
        else
        {
            cout<<v[y-i+25]<<"\n";
        }
        k++;
    }
    return 0;
}