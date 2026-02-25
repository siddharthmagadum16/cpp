#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr, int k) {
  int n = arr.size();
  if (n == 0) {
    return 0;
  }


  int slowPtr = -1, fastPtr = 0;
  int currNumZeros =  0; 

  int ans = 0;

  while (fastPtr < n) {

    int currVal = arr[fastPtr];
    currNumZeros += (currVal == 0 ? 1 : 0);
    
    if (currNumZeros > k) {
      while (slowPtr+1 < n and arr[slowPtr+1] != 0) {
        ++slowPtr;
      }
      ++slowPtr;
      -- currNumZeros;
    }

    int result = fastPtr - slowPtr;
    ans = max(ans, result);

    ++ fastPtr;
  }
  return ans;
}


int main () {

  vector<int>arr = vector<int>({1,1,1,0,0,0,1,1,1,1,0});

  int ans = solve(arr, 2);
  cout << ans << endl;
  return 0;
}

/*


*/