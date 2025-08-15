

class Solution {

  dp[100][100];

  int solve(int left, int right, int vector<int>&arr, vector<int>&weights, int ind) {
    int k = weights.size();
    if (ind == k) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    if (left > right) return 0;
    int op1 = solve(left+1, right, arr, weights, ind+1) + arr[left] * weights[ind];
    int op2 = solve(left, right - 1, arr, weights, ind + 1) + arr[right] * weights[ind];
    return dp[left][right] = max(op1, op2);
  }

  public:
  int getMaxValue(vector<int>arr, int k, vector<int>weights) {
    return solve(0, arr.size() -1, arr, weights, k, ind);
  }
}
