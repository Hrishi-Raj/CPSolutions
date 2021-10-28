#include <bits/stdc++.h>
using namespace std;

int main()
{
    //fstream cout;cout.open("out.txt");
    ios::sync_with_stdio(false);
    int t,n,m;
    char c;
    bool b;
    string s;
    vector<vector<vector<bool>>> v(2,vector<vector<bool>> (5,vector<bool> (5,0)));
    cin>>t;
    //getline(cin,s);getline(cin,s);
    while(t--)
    {
        for(int i=1;i<4;i++)
        {
            cin>>s;
            for(int j=1;j<4;j++)
            {
                v[0][i][j]=0;
                if(s[j-1]=='1')
                {v[0][i][j]=true;b=true;}
                //cout<<v[0][i][j];
            }
            //cout<<"\n";
        }
        
        n=-1;
        while(b)
        {
            b=false;
            n++;
            for(int i=1;i<4;i++)
            {
                for(int j=1;j<4;j++)
                {
                    v[(n&1)^1][i][j]=v[n&1][i][j-1]^v[n&1][i-1][j]^v[n&1][i+1][j]^v[n&1][i][j+1];
                    if(v[(n&1)^1][i][j])
                    {b=true;}
                    //cout<<v[(n&1)^1][i][j];
                }
                //cout<<"\n";
            }
        }
        cout<<n<<"\n";
    }
    return 0;
}