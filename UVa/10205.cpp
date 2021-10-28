#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t,n,x;
    char c;
    string a;
    cin>>t;
    vector<string> s(52);
    string suit[]={"Clubs","Diamonds","Hearts","Spades"};
    for(int i=0;i<4;i++)
    {
        for(int j=2;j<10;j++)
        {
            c=char('0'+j);
            //cout<<a;
            s[i*13+j-2]="  of "+suit[i];
            s[i*13+j-2][0]=c;

            //cout<<s[i*13+j-2]<<"\n";
        }
        s[i*13+8]="10 of "+suit[i];
        s[i*13+9]="Jack of "+suit[i];
        s[i*13+10]="Queen of "+suit[i];
        s[i*13+11]="King of "+suit[i];
        s[i*13+12]="Ace of "+suit[i];
    }
    while(t--)
    {
        cin>>n;
        int d[2][52];
        for(int i=0;i<52;i++)
        {
            d[0][i]=i;
        }
        vector<vector<int>> v(n);
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<52;i++)
            {
                cin>>x;
                v[j].push_back(x-1);
            }
        }
        int j=0,k;
        string st;
        getline(cin,st);
        while(cin.peek()!=EOF&&cin.peek()!='\n')
        {
            cin>>k;
            getline(cin,st);
            k--;

            for(int i=0;i<52;i++)
            {
                d[j^1][i]=d[j][v[k][i]];
                //cout<<d[j^1][i]<<" ";
            }
            //cout<<endl;
            j=j^1;
        }
        for(int i=0;i<52;i++)
        {
            cout<<s[d[j][i]]<<"\n";
        }
        if(t)
        cout<<"\n";
    }
    return 0;
}