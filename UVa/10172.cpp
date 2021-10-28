#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t,n,s,q,qi,x,m,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>s>>q;
        m=-2;
        c=0;
        vector<queue<int>> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>qi;
            while(qi--)
            {
                cin>>x;
                v[i].push(x);
                c++;
            }
        }
        stack<int> car;
        while(c)
        {
            for(int i=0;i<n;i++)
            {
                m+=2;
                while(!(car.empty()||v[i].size()==q))
                {
                    if(car.top()!=i+1)
                    v[i].push(car.top());
                    else
                    c--;
                    car.pop();
                    m++;
                }
                while(!car.empty()&&car.top()==i+1)
                {
                    car.pop();
                    c--;
                    m++;
                }
                while(!(car.size()==s||v[i].empty()))
                {
                    car.push(v[i].front());
                    v[i].pop();
                    m++;
                }
                if(c==0)
                {
                    break;
                }
            }
        }
        cout<<m<<"\n";

    }

    return 0;
}