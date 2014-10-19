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

int main () {
  int n, k, a;
  cin >> n; cin >> k;
  vi heights;
  FOR(i, n) {
    cin >> a;
    heights.pb(a);
  }

  int diff, movesUsed = 0;
  // List of Move => number of repetitions
  vector<pair<pii, int> > moves;
  moves.pb(mp(mp(3, 3), 5));

  cout << diff << " " << movesUsed << endl;
  FOREACH(move, moves) {
    FOR(i, move->se) {
      cout << move->fi.fi << " " << move->fi.se << endl;
    }
  }
  return 0;
}
