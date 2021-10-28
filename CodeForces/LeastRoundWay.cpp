#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int w, const vector<int> &v) {
  
  int current_weight = 0;
  int dp[2][w+1];
  for(int i=0;i<=w;i++)
  {
    dp[1][i]=0;
  }
  dp[0][0]=0;
  for(int i=0;i<v.size();i++)
  {
    for(int j=1;j<=w;j++)
    {
      if(j>=v[i]&&dp[(i&1)^1][j]<dp[(i&1)^1][j-v[i]]+v[i])
      {
        dp[i&1][j]=dp[(i&1)^1][j-v[i]]+v[i];
      }
      else
      {
        dp[i&1][j]=dp[(i&1)^1][j];
      }
      //std::cout<<dp[i&1][j]<<" ";
    }
    //std::cout<<std::endl;
  }
  return dp[(v.size()-1)&1][w];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(n);
        for(int j=0;j<n;j++)
        cin >> v[i][j];
    }
    
    return 0;
}