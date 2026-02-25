// q2
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>weights, vector<int>values, int maxWeightLimit) {
  
  int n = values.size();
  int MW = *max_element(weights.begin(), weights.end());
  
  vector<vector<int>>dp(n, vector<int>(MW+1, -1));

  dp[0][0] = 0;

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j <= MW; ++ j) {

      int w = weights[i];
      if (j <= maxWeightLimit) {
        int choice1 = i == 0 ? 0 : dp[i-1][j];
        int choice2 = (j-w >= 0 ? dp[i-1][j-w] : 0) + values[i]; 
        dp[i][j] = max(choice1, choice2);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++ i) {
    ans = max(ans, dp[i][MW]);
  }
  cout << ans << endl;
}


int main() {
  vector<int>values = {10,40, 30, 50};
  vector<int>weights = {5,4,6,3};
  int maxWeightLimit = 10;
  solve(weights, values, maxWeightLimit);
  return 0;
}