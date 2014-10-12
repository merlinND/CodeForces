#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

const ll int P = 1000000007;

inline bool isValid(ll int k, ll int limit) {
  return (k <= limit) && (k > 0);
}

int main () {
  ll int a, b;
  cin >> a;
  cin >> b;

  vi nice;
  ll int x = 0;
  FORI(k, a) {
    FORI(beta, b - 1) {
      x = ((k * beta) * b) % P + beta;
      if(x > 0)
        nice.pb(x);
    }
  }

  ll int answer = 0;
  FOR(i, nice.size()) {
    answer += (nice[i] % P);
  }

  cout << answer % P << endl;
	return 0;
}
