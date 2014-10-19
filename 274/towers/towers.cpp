#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
  vi towers;
  // Note that `lowest` contains negative heights
  priority_queue<int> highest, lowest;
  FOR(i, n) {
    cin >> a;
    towers.pb(a);
    highest.push(a);
    lowest.push(-a);
  }

  int diff, movesUsed = 0;
  vector<pii> moves;

  // @warning Edge case where the minimum difference is 1
  while(moves.size() < k && diff > 0) {
    int top = highest.top();
    int bottom = - lowest.top();
    diff = top - bottom;
    moves.pb(mp(top, bottom)); // Wrong, we should indicate the indices
  }

  cout << diff << " " << moves.size() << endl;
  FOREACH(move, moves) {
    FOR(i, move->se) {
      cout << move->fi << " " << move->fi << endl;
    }
  }
  return 0;
}
