#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    Node* left;
    Node* right;
    ll count;
    Node() {
      count = 1;
      left = nullptr;
      right = nullptr;
    }
};


void solve(int r) {
    int n = r + 1;

    Node* root = new Node();
    
    for (ll i = 0; i < n; ++ i) {
        Node* curr = root;
        for (ll j = 30; j >=0; -- j) {
            if((1LL<<j)&i) {
                if (curr->right == nullptr) {
                    curr->right = new Node();
                }
                curr = curr->right;
            }
            else {
                if (curr->left == nullptr) {
                    curr->left = new Node();
                }
                curr = curr->left;
            }
            curr->count++;
        }
    }

    vector<ll>arr(n,-1);

    for (ll i = r; i >= 0; -- i) {
        Node* curr = root;
        ll val = 0;
        for (ll j = 30; j >= 0; -- j) {
            if((1LL<<j)&i) {
                if (curr->left != nullptr and curr->left->count > 0) {
                    curr = curr->left;
                  }
                  else {
                    val |= (1LL<<j);
                  curr = curr->right;
                }
                if (curr != nullptr) curr->count--;
            }
            else {
                if (curr->right != nullptr and curr->right->count > 0) {
                    curr = curr->right;
                    val |= (1LL<<j);
                }
                else {
                    curr = curr->left;
                }
                if (curr != nullptr) curr->count--;
            }
        }
        // assert(val < n and val >= 0);
        cout << i << " " << val << endl;
        if (val >= 0 && val < n) {
            arr[i] = val;
            arr[val] = i;
        } else {
            cerr << "Error: val = " << val << " is out of bounds [0, " << n << ")" << endl;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++ i) {
        ans += (i^arr[i]);
    }
    // cout << ans << endl;
    for (int i =0 ; i < n; ++ i) cout << i << " "; cout << endl;
    for (int i =0 ; i < n; ++ i) cout << arr[i] << " "; cout << endl;
    cout << ans << endl;
}

int main() {
	// your code goes here
  solve(12);
	return 0;
}
