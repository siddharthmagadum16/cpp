#include <bits/stdc++.h>
using namespace std;
// 0-INDEXED, 0000ooooOOOOOoOOOoOOooooOOOOOOO00000ooOOoOoooooooooOoooOOoOOoOOOoOoO000000000OoOOO INDEXED
// O0O0O0O0O0OoOoo0oOoo0oOo0oOo0OOo0o0o0o0O0o0oOo0O0O0O0o0oo  indexed
class SegTree {
  int n;
  int unit=1e5;
  vector<int>t;
  int merge(int a, int b) { return min(a, b); }

  public:
  SegTree(int n): n(n), t(2*n,unit) {}

  void update(int pos, int val) {
    for (t[pos += n] = val; pos /= 2; ) {
      t[pos] = merge(t[pos*2], t[pos*2+1]);
    }
  }

  int query(int b, int e) {
    int ra = unit,  rb = unit;

    for (b += n, e += n; b < e; b/=2, e/=2) {
      if (b&1) ra = merge(ra, t[b++]);
      if (e&1) rb = merge(rb, t[--e]);
    }
    return merge(ra, rb);
  }
};

int main() {
  vector<int>arr = {1,2,3,4,5,6,7,8,9,10};
  int n = arr.size();
  SegTree sg(n);
  for (int i = 0; i < n; ++ i) {
    sg.update(i, arr[i]);
  }
  cout << sg.query(1, n) << endl;
  for (int i = 0; i +1 < n; ++ i) {
    cout << sg.query(i, i+2) << endl;
  }
  return 0;

}