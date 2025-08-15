#include <bits/stdc++.h>
using namespace std;


int main () {
    cout << "hello world" << endl;
    cout << "hey\n";
    vector<int>arr({1,3,4,5,6,7,8,8,8,3,34,5,6,6,6,6});
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    cout << arr.size() << endl;
    for (int val: arr) cout << val << " "; cout << endl;
    return 0;
}