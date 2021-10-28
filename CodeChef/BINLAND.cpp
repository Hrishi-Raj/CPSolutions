#include<bits/stdc++.h>
using namespace std;
const int qm=300000,nm=20;
string s[2][qm];
int dp[2][qm][nm][nm],l[2]={0,0};
int main()
{
    ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    auto push2 = [&](int x) -> void{
        int t=l[x]-1;
        if(t==0) for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        dp[x][t][i][j]=(i==j);
        else{               
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[x][t][i][j]=0;
                if(s[x][0][i]!=s[x][t][j])
                {//cout<<dp[x][t][i][j]<<" ";
                continue;}
                for(int k=j-1;k<j+2;k++)
                {
                    if(k<0||k>=n) continue;
                    dp[x][t][i][j]+=dp[x][t-1][i][k];
                    if(dp[x][t][i][j]>=1000000007) dp[x][t][i][j]-=1000000007;
                }
                //cout<<dp[x][t][i][j]<<" ";
            }
            //cout<<"\n";
        }}
        //cout<<x<<" "<<t<<"\n";
    };
    while(q--)
    {
        string sq;
        cin>>sq;
        if(sq[0]=='a')
        {
            cin>>sq;
            s[0][l[0]++]=sq;
            push2(0);
        }
        else if(sq[0]=='r'){
            if(l[1]) l[1]--;
            else{
                while(l[0])
                {
                    s[1][l[1]++]=s[0][--l[0]];
                    push2(1);
                }
                l[1]--;
            }
        }else{
            int x,y;
            cin>>x>>y;x--;y--;
            long long ans=0;
            if(!l[1])ans=dp[0][l[0]-1][x][y];
            else if(!l[0])ans=dp[1][l[1]-1][y][x];
            else
            {
                long long r;
                for(int j=0;j<n;j++)
                {
                    r=0;
                    for(int k=j-1;k<j+2;k++)
                    {
                        if(k<0||k>=n) continue;
                        if(s[0][0][j]!=s[1][0][k]) continue;
                        r+=dp[1][l[1]-1][k][x];
                        if(r>=1000000007) r-=1000000007;
                    }
                    ans+=(r*dp[0][l[0]-1][j][y])%1000000007;
                }
                //cout<<"\n";
            }
            if(ans>=1000000007)ans%=1000000007;
            cout<<ans<<"\n";
        }
    }
    return 0;
}