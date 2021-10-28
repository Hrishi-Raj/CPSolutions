#include <bits/stdc++.h>
using namespace std;

void f(deque<string> &a,deque<string> &b,deque<string> &t,int &turn)
{
    int c=1;
    if(a.front()[1]=='A')
    {
        c=4; 
    }
    else if(a.front()[1]=='K')
    {
        c=3;
    }
    else if(a.front()[1]=='Q')
    {
        c=2;
    }
    //cout<<a.front()<<"c";
    t.push_front(a.front());
    a.pop_front();
    
    while(!b.empty()&&c--)
    {
        if((b.front()[1]<='9'&&b.front()[1]>'1')||b.front()[1]=='T')
        {
            //cout<<b.front()<<"r ";
            t.push_front(b.front());
            b.pop_front();
        }
        else
        {
            turn=1^turn;
            f(b,a,t,turn);
            return;
        }
    }
    if(c<=0)
    {
        turn=1-turn;
        while(!t.empty())
            {
                a.push_back(t.back());
                t.pop_back();
            }
    }

}

int main() {
    ios::sync_with_stdio(false);
    // fstream fout;
    // fout.open("output.txt");
    string x="!",y;
    while(true)
    {
        
    deque<string> a,b,t;
    cin >> x;
        if(x=="#")
        break;
    cin>>y;
    a.push_front(x);b.push_front(y);
    for(int i=1;i<26;i++)
    {
        cin>>x>>y;
        a.push_front(x);b.push_front(y);
    }
    //cout<<a.size();
    int turn=1;
    while(true)
    {
        // for(auto i:a)
        // cout<<i<<" ";
        // cout<<endl;
        // for(auto i:b)
        // cout<<i<<" ";
        // cout<<endl;

        
        if(turn==1)
        {   if(a.empty())
            {
                break;
            }
            if((a.front()[1]<='9'&&a.front()[1]>'1')||a.front()[1]=='T')
            {
                t.push_front(a.front());
                a.pop_front();
                turn=0;
            }
            else
            {
                turn=0;
                f(a,b,t,turn);
            }
        }
        else
        {
            if(b.empty())
            {
                //winner=2;
                break;
            }
            if(((b.front()[1]<='9'&&b.front()[1]>'1')||b.front()[1]=='T'))
            {
                t.push_front(b.front());
                b.pop_front();
                turn=1;
            }
            else
            {
                turn=1;
                f(b,a,t,turn);
            }
        }
        
    }
    
    // for(auto i:a)
    //     cout<<i<<" ";
    //     cout<<endl;
    // for(auto i:b)
    //     cout<<i<<" ";
    //     cout<<endl;
    if(a.empty())
    {
        cout<<"1 ";
        if(b.size()<10)
        cout<<" ";
        cout<<b.size()<<endl;
    }
    else
    {
        cout<<"2 ";
        if(a.size()<10)
        cout<<" ";
        cout<<a.size()<<endl;
    }
    }
    
	return 0;
}

