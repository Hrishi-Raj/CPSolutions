#include<iostream>
#include<utility>
#include<vector>
#include<map>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t,c,q,p;
    char r;
    string s;
    cin>>t;
    getline(cin,s);
    while(t--)
    {
        map<int,int> m;
        vector<pair<int,pair<int,int>>> v;
        getline(cin,s);
        while(cin.peek()!='\n'&&cin.peek()!=EOF)
        {
            cin>>c>>q>>p>>r;
            getline(cin,s);
            if(r=='I')
            {
                if(m.find(c*10+q)!=m.end())
                {
                    if(m[c*10+q]>=0)
                    m[c*10+q]+=20;
                }
                else
                m[c*10+q]=20;
            }
            else if(r=='C')
            {
                if(m.find(c*10+q)!=m.end())
                {
                    if(m[c*10+q]>=0)
                    m[c*10+q]=-p-m[c*10+q];
                }
                else
                m[c*10+q]=-p;
            }
            else
            { 
                if(m.find(c*10+q)==m.end())
                m[c*10+q]=0;
            }
            
            //cout<<c<<r<<"in\n";
        }
        int x=(*m.begin()).first/10;p=0;q=0;
        for(auto i:m)
        {
            //cout<<x<<"t";
            if(x==i.first/10)
            {
                if(i.second<0)
                {
                    p+=i.second;
                    q++;
                }                
            }
            else
            {
                v.push_back(make_pair(q,make_pair(p,-x)));
                x=i.first/10;
                p=0;q=0;
                if(i.second<0)
                {
                    p+=i.second;
                    q++;
                }
            }
        }
        if(m.size())
        v.push_back(make_pair(q,make_pair(p,-x)));
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(auto i:v)
        {
            cout<<-i.second.second<<" "<<i.first<<" "<<-i.second.first<<"\n";
        }
        if(t)
        cout<<"\n";
    }
    return 0;
}