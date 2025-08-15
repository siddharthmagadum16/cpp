#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
// lps = longest proper prefix which is also a suffix
// remember: lps[i] stores the index which doesnt match, i.e, pat[i] will be matched, but it gives next index of the matched index

class KMPAlgo {

  string txt, pat;
  int M, N;
  vector<int>lps;

  void computeLPSArray() {
    int len = 0;
    for(int i = 1; i < M; ) {
      if (pat[i] == pat[len]) {
        lps[i++] = ++len;
      }
      else if (len != 0) {
        len = lps[len - 1];
      }
      else {
        lps[i++] = 0;
      }
    }
  }
public:
  KMPAlgo(string txt, string pat) {
    this->txt = txt;
    this->pat = pat;
    N = txt.length();
    M = pat.length();
    lps = vector<int>(M, 0);
  }
  vector<int> KMPsearch() {
    vector<int>ans;
    computeLPSArray();
    for (int i = 0; i < M; ++ i) cout << lps[i] << " "; cout << endl;
    for (int i = 0, j = 0; i < N; ) {

      if (txt[i] == pat[j]) {
        ++ i;
        ++ j;
      }

      if (j == M) {
        ans.push_back(i - M) // +1 for 1-indexed
        j = lps[j - 1];
      }
      else if (i < N and txt[i] != pat[j]) {
        j ? (j = lps[j - 1]) : ++ i;
      }
    }
    return ans;
  }
};

int main () {
  string txt = "isawsquirrelnearmysquirrelhouseohmy";
  string pat = "my";
  KMPAlgo kmp(txt, pat);
  auto ans = kmp.KMPsearch();
  for (int u: ans) {
    cout << u << " ";
  }
  cout << endl;
  return 0;
}

// isawsquirrelnearmysquirrelhouseohmy
/*
class KMPAlgo2 {

  string txt, pat;
  vector<int>lps;

  void computeLPSArray () {
    int len = 0;
    lps = vector<int>(pat.size(),0);
    for (int i = 1; i < pat.size(); ) {
      if (pat[i] == pat[len]) {
        lps[i++] = ++len;
      }
      else if (len > 0) len = lps[len - 1];
      else ++ i;
    }
  }

  public:

  KMPAlgo2(string text, string pattern) {
    txt = text;
    pat = pattern;
    computeLPSArray();
  }

  vector<int> getMatchingPositions() {

    vector<int>ans;
    int j = 0;
    for (int i = 0; i < txt.size(); ++ i) {
      if (txt[i] == pat[j]) {
        ++ i; ++ j;
      }

      if (j == pat.size()) {
        ans.push_back(j-pat.size());
        j = lps[j - 1];
      }
      else if (i < txt.size() and i != j) {
        j ? (j = lps[j-1]) : ++ i;
      }
    }
    return ans;
  }

};

*/