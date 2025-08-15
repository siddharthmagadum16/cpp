#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define M 1000000
#define fastio    ios_base::sync_with_stdio(false);


void yes(){ cout<<"YES"<<nl; return ;}
void no(){ cout<<"NO"<<nl; return ;}
template<typename T> void p(T a){ cout<<a<<" "; return;}
template<typename T> void pnl(T a){ cout<<a<<nl; return;}

#define f(i, a) for (int i=0; i<(a); i++)
#define ff(i, a) for (int i=1; i<=(a); i++)
#define fr(i, a) for (int i=(a-1);i>=0;i--)
#define ffr(i, a) for (int i=(a);i>0;i--)

#define trav(a,x) for (auto& a : x)
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define scf(a) scanf("%d",&a)
#define scfll(a) scanf("%lld",&a)

const int ten4=1e4;
const int ten5=1e5;
const int ten6=1e6;
const int ten7=1e7;
const int ten9=1e9;
const int mod = 1e9+7;

/*
friend bool operator<(Node const &a, Node const &b) {
  return a.height < b.height;
}
*/

struct pair_hash {  //  unordered_set<pair<int,int>,pair_hash>st;    // pair doesn't support hashing, so modify this function for unordered_set pair hash function
  inline std::size_t operator()(const std::pair<int,int> & v) const {
    return v.first*31+v.second;
  }
};

ll bin_to_integer(string strin){
  ll r=1,sum=0;
  for(ll i=strin.length()-1;i>=0;i--){
    if(strin[i]=='1')    sum+=r;
    r*=2;
  }   return sum;
}
string to_binary(int n){
  string strng;
  while(n>0){
    if(n&1) strng+='1'; else    strng+='0';  n>>=1;
  }
  reverse(strng.begin(),strng.end());
  // int len=66-s.length(); string sn; for(int i=0;i<len;i++){     if(i<len) sn+='0'; } sn+=s;
  return strng;
  // return sn;   // this returns the binary string with length 66 irrespective of n
}

int compare(const void *a, const void *b){
  const ll* x=(ll*) a;
  const ll* y=(ll*) b;
  if(*x>*y) return 1;         // (a,n,sizeof(ll),compare);
  else if(*x<*y) return -1;
  return 0;
}

// _________________________________________________________________________________________________
int power(int a,int n){
  int res=1;
  while(n){
    if(n&1) res=(res*1LL*a)%mod;
    n/=2;
    a=(a*1LL*a)%mod;
  }
  return res;
}
const int Nc=200001;  //
int F[Nc]; // don't use this to get the factorial without using nCr functions first !!!
bool Fcomputed=false;
int nCr(int n,int r){
    if(!Fcomputed){ F[0]=1, Fcomputed=true;     for(int i=1;i<Nc;i++) F[i]=(F[i-1]*1LL*i)%mod;  }
    if(n<r) return 0;
    int res =F[n];
    res= res*1LL*power(F[r],mod-2)%mod;
    res=res*1LL*power(F[n-r],mod-2)%mod;
    return res;
}
// _________________________________________________________________________________________________

int getAbyB (int a, int b) {
  int bInv = power(b, mod - 2);
  return (a*bInv)%mod;
}

struct unionfind{
	vector<int> p;
	unionfind(int N){
		p = vector<int>(N, -1);
	}
	int root(int x){
		if (p[x] < 0){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}
	bool same(int x, int y){
		return root(x) == root(y);
	}
	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x != y){
			if (p[x] < p[y]){
				swap(x, y);
			}
			p[y] += p[x];
			p[x] = y;
		}
	}
};


void testcase(int test){ // testcases


  // cout << "Case #" << test << ": " << ans << endl;  cout << fixed << setprecision(2) << result << endl;
  return;
}
int main(){
  fastio;
  int test=1,z=1;
  cin>>test;
  while(z<=test){
      testcase(z); z++;
  }
  return 0;
}
/*
for std::lcm use -std=c++17 to compile locally


*/