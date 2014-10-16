#include <iostream>
#include <math.h>
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

bool shouldContinue(ll int r, ll int g, ll int b) {
  return !(r == g && g == b)
      && (r >= 0 && g >= 0 && g >= 0)
      && (r + g + b >= 3);
}

int main () {
  ll int t = 0;
  ll int b[3];
  cin >> b[0];
  cin >> b[1];
  cin >> b[2];

  // Greedy strategy: use the excess balloons in priority
  while(shouldContinue(b[0], b[1], b[2])) {
    // WARNING: edge cases r < 0
    // TODO
  }

  // We have the same quantity of each balloon left, we can just decorate all tables
  // the same way.
  t += b[0];

  cout << t << endl;
  return 0;
}
