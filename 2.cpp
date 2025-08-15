


/*


str = "aab"
break above string to get palindromic subarray. Get all possible combinations

[['a', 'a', 'b'], ['aa', 'b']]
aabsdf|adsf f

arr
dp[i] = all the possible plaindromic subarrays
arr[0..i]

dp[i+1] =

dp[j]

for
  // checking the suffix is palindrome n^2(n+)

  //
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome (string &str, int begin, int end) {
  while (begin < end) {
    if (str[begin] != str[end]) return false;
    ++ begin, -- end;
  }
  return true;
}

vector<vector<vector<int>>> solve(string str) {
  int n = str.size();
  // vector<vector<int>>ans;
  vector<vector<vector<vector<int>>>>dp(n);
  // [b, e]
  vector<int> strPnts({0,0});
  vector<vector<int>>allAns({ strPnts });
  dp[0].push_back(allAns);

  for (int i = 1; i < n; ++ i) {
    vector<vector<vector<int>>>newAns;
    if (isPalindrome(str, 0, i)) {
        newAns.push_back({{0,i}});
    }
    for (int j = i-1; j >= 0; -- j) {
      if (isPalindrome(str, j+1, i)) {
        auto oldAns = dp[j];
        for (auto prvAns: oldAns) {
          vector<int>segment({j+1, i});
          prvAns.push_back(segment);
          newAns.push_back(prvAns);
        }
      }
    }
    dp[i]=newAns;
  }
// */
  return dp[n-1];
  // return makeAnswer(dp[n-1]);
}

int main() {
  string str = "aab";
  vector<vector<vector<int>>> ans = solve(str);
  for (vector<vector<int>>&subString: ans) {
    for (auto p2: subString) cout << "[" << p2[0] << "," << p2[1] << "] ";
    cout << endl;
  }

  return 0;
}