// problem 1
#include <bits/stdc++.h>
using namespace std;

// arr of uniq integers
// print all permutations of given array.

void solve(int indx, vector<int> &arr, vector<vector<int>>&ans) {
  if (indx == arr.size()  - 1) {
    ans.push_back(arr);
  }

  for (int l = indx; l < arr.size(); ++ l) {
    swap(arr[indx], arr[l]);
    solve(indx + 1, arr, ans);
    swap(arr[indx], arr[l]);
  }
}


int main () {
  vector<int>arr ={2,3,1, 4};
  vector<vector<int>>ans;
  solve(0, arr, ans);

  for (auto &result: ans) {
    for (int i = 0; i < result.size(); ++ i) {
      cout << result[i] <<" ";
    }
    cout << endl;
  }
  return 0;
}


// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
// n^3log(n)
// n*(n-1)
// n*(n+1)/2



// 3*4/2 = 6