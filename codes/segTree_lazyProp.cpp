#incldue <bits/stdc++.h>
using namespace std;



class SegmentTree {
  int n;
  vector<int>tree;
  vector<int>lazy;

  void merge(int a, int b) { return max(a, b); }

  void build(int v, int start, int end, vector<int>&arr) {

    if (start == end) {
      tree[v] = arr[start];

    } else {
      int mid = (start + end)/2;
      build(2*v+1, start, mid, arr);
      build(2*v+2, mid+1, end, arr);
      tree[v] = merge(tree[2*v+1], tree[2*v+2]);
    }
  }

  void propagate(int v, int start, int end) {
    if (lazy[v] == 0) return ;
    tree[v] += lazy[v];
    if (start != end) {
      lazy[2*v+1] += lazy[v];
      lazy[2*v+2] += lazy[v];
    }
    lazy[v] = 0;
  }

  void update(int v, int start, int end, int l, int r, int val) {
    propagate(v, start, end);
    if (end < l or r < start or start > end) return ;

    if (l <= start and end <= r) {
      tree[v] += val;
      if (start != end) {
        lazy[2*v+1] += val;
        lazy[2*v+2] += val;
      }
      return ;
    }

    int mid = (start + end) / 2;
    update(2*v+1, start, mid, l, r, val);
    update(2*v+2, mid+1, end, l, r, val);
    tree[v] = merge(tree[2*v+1], tree[2*v+2]);
  }


  int query(int v, int start, int end, int l, int r) {
    propagate(v, start, end);
    if (start > end or end < l or r < start) return 0;
    if (start == end) {
      return tree[v];
    }
    int mid = (start+end)/2;
    return merge(
      query(2*v+1, start, mid, l, r),
      query(2*v+2, mid+1, end, l, r)
    );
  }


  public:
  SegmentTree(vector<int>&arr) {
    n = arr.size();
    tree.resize(4*n);
    lazy.resize(4*n);
    fill_n(lazy, 4*n, 0);
    build(0, 0, n-1, arr);
  }

  void rangeUpdate(int l, int r, int val) {
    update(0, 0, n-1, l, r, val);
  }

  void rangeQuery(int l, int r) {
    query(0, 0, n-1, l, r);
  }
};