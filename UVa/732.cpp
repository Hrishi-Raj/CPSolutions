#include<bits/stdc++.h>
using namespace std;

void rec(string &str,string io,stack<char> s1,stack<char> s2,vector<int> v,int p,vector<string> &a)
{
    if(!s1.empty()&&s1.top()==str[p-1])
    {
        s1.pop();
        io.push_back('o');
    }
    if(p==str.size())
    {
        if(s1.empty()&&s2.empty())
        {
            //cout<<"acc"<<io<<" ";
            a.push_back(io);
        }
        return;
    }
    string re="";
    while(v[str[p]])
    {
        if(s1.empty())
        {
            if(s2.empty())return;
            v[s2.top()]--;
            s1.push(s2.top());
            s2.pop();
            io.push_back('i');
        }
        while(!s2.empty()&&s1.top()!=str[p])
        {
            v[s2.top()]--;
            s1.push(s2.top());
            s2.pop();
            io.push_back('i');
        }
        if(s1.top()==str[p])
        {
            //cout<<p<<io<<" ";
            re=io;
            rec(str,io,s1,s2,v,p+1,a);
            //cout<<p<<" ";
            if(!s2.empty())
            {
                //cout<<s2.top()<<"\n";
                v[s2.top()]--;
                s1.push(s2.top());
                s2.pop();
                io.push_back('i');
            }
        }
        else if(s2.empty())
        return;
    }
    if(!v[str[p]]&&!s1.empty()&&s1.top()==str[p])
    {
        
        //cout<<p<<io<<"tt ";
        if(re!=io)
        rec(str,io,s1,s2,v,p+1,a);
        //cout<<p<<" ";
    }
}

int main()
{
    string s1,s2,io;
    int p;
    while(cin>>s1)
    {
        cin>>s2;
        stack<char> s,p;
        vector<int> v(130);
        for(int i=s1.size()-1;i>=0;i--)
        {
            v[s1[i]]++;
            s.push(s1[i]);
        }
        io="";
        vector<string> a;
        rec(s2,io,p,s,v,0,a);
        cout<<"[\n";
        for(int i=a.size()-1;i>=0;i--)
        {
            for(int j=0;j<a[i].size()-1;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<a[i][a[i].size()-1]<<"\n";
        }
        cout<<"]\n";
    }

    return 0;
}