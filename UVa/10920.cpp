#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n,p,x,o,l,c,y,r;
    
    while(true)
    {
        cin>>n>>p;
        if(!n)
        break;
        o=n/2+1;
        x=sqrt(p);
        x-=(x&1)^1;
        l=o+x/2;
        c=o+x/2;
        y=x*x;
        if(y!=p)
        {
            l++;c++;
            r=(p-y-1)/(x+1);
            switch(r)
            {
                case 0:c-=p-y;break;
                case 1:c-=x+1;l-=p-y-x-1;break;
                case 2:l-=x+1;c-=x+1;c+=p-y-2*(x+1);break;
                case 3:l-=x+1;l+=p-y-3*(x+1);
            }
            
        }
        cout<<"Line = "<<l<<", column = "<<c<<".\n";
    }

    return 0;
}