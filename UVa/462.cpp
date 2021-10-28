#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string x;
    // fstream cout;
    // cout.open("output.txt");
    while(cin>>x)
    {
        vector<bool> v(53),st(4);
        vector<int> s(4);
        int sts=0,p=0,j=-1;
        switch(x[1])
        {
            case 'S':s[0]++;j=0;break;
            case 'H':s[1]++;j=1;break;
            case 'D':s[2]++;j=2;break;
            case 'C':s[3]++;j=3;break;
        }
        switch(x[0])
        {
            case 'A':p+=4;v[13*j+1]=1;break;
            case 'K':p+=3;v[13*j+13]=1;break;
            case 'Q':p+=2;v[13*j+12]=1;break;
            case 'J':p+=1;v[13*j+11]=1;break;
            case 'T':v[13*j+10]=1;break;
            default: v[13*j+x[0]-'0']=1;
        }
        for(int i=1;i<13;i++)
        {
            cin>>x;
            switch(x[1])
            {
                case 'S':s[0]++;j=0;break;
                case 'H':s[1]++;j=1;break;
                case 'D':s[2]++;j=2;break;
                case 'C':s[3]++;j=3;break;
            }
            switch(x[0])
            {
                case 'A':p+=4;v[13*j+1]=1;break;
                case 'K':p+=3;v[13*j+13]=1;break;
                case 'Q':p+=2;v[13*j+12]=1;break;
                case 'J':p+=1;v[13*j+11]=1;break;
                case 'T':v[13*j+10]=1;break;
                default: v[13*j+x[0]-'0']=1;
            }
        }
        // for(int i=1;i<53;i++)
        // {
        //     cout<<v[i]<<" ";
        //     if(i%13==0)
        //     cout<<"\n";
        // }
        for(int i=0,t=0;i<4;i++)
        {
            if(v[13*i+13])
            {if(s[i]==1)
                p--;
            else
            {   st[i]=1;t=1; }}
            if(v[13*i+12])
            {if(s[i]<=2)
                p--;
            else
            {   st[i]=1;t=1;}}       
            if(v[13*i+11]&&s[i]<=3)
                p--;
            if(v[13*i+1])
            {   st[i]=1;t=1;}
            sts+=t;
            t=0;
            
        }
        //cout<<sts<<p;
        if(sts==4&&p>=16)
        {
            cout<<"BID NO-TRUMP\n";continue;
        }
        for(int i=0;i<4;i++)
        {
            if(s[i]<=1)
            p+=2;
            if(s[i]==2)
            p+=1;
        }
        if(p>=14)
        {
            int m=0,in=-1;
            for(int i=0;i<4;i++)
            {
                if(m<s[i])
                {
                    m=s[i];
                    in=i;
                }
            }
            cout<<"BID ";
            switch(in)
            {
                case 0:cout<<"S\n";break;
                case 1:cout<<"H\n";break;
                case 2:cout<<"D\n";break;
                case 3:cout<<"C\n";break;
            }
        }
        else
        {
            cout<<"PASS\n";
        }
        
    }
    return 0;
}