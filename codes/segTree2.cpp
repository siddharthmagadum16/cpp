#include <bits/stdc++.h>
using namespace std;

class SegTree {
  vector<int>t;
  int merge(int a, int b) { return a + b; }
  int n;

  void build (vector<int> arr, int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = arr[tl];
    } else {
      int tm = (tl + tr)/2;
      build(arr, 2*v, tl, tm);
      build(arr, 2*v+1, tm+1, tr);
      t[v] = merge(t[2*v], t[2*v+1]);
    }
  }

public:
  void SegTree(vector<int>&arr): n(arr.size()), t(vector<int>(n*4)) {
    build(arr, 0, 0, n);
  }

  int query(int v, int tl, int tr, int l, int r) {
    if (l > r)  return 0;
    if (l == tl and  r == tr)  return t[v];

    int tm = (tl + tr)/2;
    t[v] = merge(
      query(2*v, tl, tm, l, min(tm, r)),
      query(2*v+1, tm+1, tr, max(tm+1, l), r)
    );
  }

  void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      t[v] = val;
    }
    else {
      int tm = (tl + tr)/2;
      if (pos <= tm) {
        update(2*v, tl, tm, pos, val);
      }
      else {
        update(2*v+1, tm+1, tr, pos, val);
      }
      t[v] = merge(t[2*v], t[2*v+1]);
    }
  }
};


int main () {
  int n = 10;
  vector<int>arr(n, 0);
  arr = {1,1,1,1,1,1,1,1,1,1 };
  segTree sg(arr);

  sg.update(0, 3, 3);
  sg.update(3, 4, 2);
  sg.update(5, 6, 4);
  // sg.update(4, 4, -1);

  cout << sg.query(2, 5) << endl;
  cout << sg.query(2, 7) << endl;

  for (int i = 1; i <= n; ++ i)
    cout << sg.query(i-1, i-1) << " "; cout << endl;

  return 0;
}