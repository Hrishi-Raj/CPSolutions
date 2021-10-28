#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    char d,x,y;
    
    string s="SWNE";
    map<char,int> m;
    map<int,char> r,ri;
    m['C']=0;m['D']=1;m['S']=2;m['H']=3;
    r[0]='C';r[1]='D';r[2]='S';r[3]='H';
    m['T']=10;m['J']=11;m['Q']=12;m['K']=13;m['A']=14;
    ri[10]='T';ri[11]='J';ri[12]='Q';ri[13]='K';ri[14]='A';
    for(int i=2;i<10;i++)
    {
        m[char('0'+i)]=i;
        ri[i]=char('0'+i);
    }
    while(true)
    {
        map<char,int> dir;
        cin>>d;
        if(d=='#')
        break;
        dir[d]=3;
        int j=0;
        while(s[j]!=d)
        j++;
        j++;
        int k=0;
        while(s[j%4]!=d)
        {
            dir[s[j%4]]=k++;
            j++;
        }
        
        vector<int> v[4];
        for(int i=0;i<13;i++)
        {
            for(int j=0;j<4;j++)
            {
                cin>>x>>y;
                v[j].push_back(m[x]*100+m[y]);
            }
        }
        for(int i=0;i<4;i++)
        {
            sort(v[i].begin(),v[i].end());
        }
        
        
        cout<<"S:";
        for(int i:v[dir['S']])
        cout<<" "<<r[i/100]<<ri[i%100];
        cout<<"\nW:";
        for(int i:v[dir['W']])
        cout<<" "<<r[i/100]<<ri[i%100];
        cout<<"\nN:";
        for(int i:v[dir['N']])
        cout<<" "<<r[i/100]<<ri[i%100];
        cout<<"\nE:";
        for(int i:v[dir['E']])
        cout<<" "<<r[i/100]<<ri[i%100];
        cout<<"\n";
    }
    return 0;
}