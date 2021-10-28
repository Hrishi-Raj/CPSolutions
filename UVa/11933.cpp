#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long n,a,c;int m;bool b;
    
    while(1)
    {
        cin>>n;
        if(n==0)break;
        m=log2(n)+1;b=true;a=0;c=0;
        for(int i=0;i<=m;i++)
        {
            if(n&(1<<i))
            {
                if(b)
                {
                    a=a|(1<<i);
                }
                else
                {
                    c=c|(1<<i);
                }
                b=!b;
            }
            //cout<<a<<" "<<c<<"\n";
        }
        cout<<a<<" "<<c<<"\n";
    }
}