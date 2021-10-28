#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    long x,m;
    priority_queue<long> m1;
    priority_queue<long,vector<long>,greater<long>> m2;
    cin>>x;
    m2.push(x);
    cout<<x<<"\n";
    while(cin>>x)
    {
        
        if(m1.size()<m2.size())
        {
            if(x>m2.top())
            {
                m1.push(m2.top());
                m2.pop();
                m2.push(x);
                
            }
            else
            {
                m1.push(x);
            }
            m=(m1.top()+m2.top())/2;
        }
        else if(m1.size()>m2.size())
        {
            if(x<m1.top())
            {
                m2.push(m1.top());
                m1.pop();
                m1.push(x);
            }
            else
            {
                m2.push(x);
            }
            m=(m1.top()+m2.top())/2;
        }
        else
        {
            if(x>m2.top())
            {
                m2.push(x);
                m=m2.top();
            }
            else
            {
                m1.push(x);
                m=m1.top();
            }
        }
        cout<<m<<"\n";
    }
    return 0;
}