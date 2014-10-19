#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

typedef multimap<int, int> mii;

int main () {
  int n, k, a;
  cin >> n; cin >> k;
  // Multimap height -> index of the tower
  // Maps are sorted on the key
  mii heights;
  FOR(i, n) {
    cin >> a;
    heights.insert(mp(a, i + 1));
  }

  int diff = 1, diff2, nMoves = 0;
  // List of moves (from -> to) -> number of repetitions
  vector<pair<pii, int> > moves;

  // TODO: edge case where the minimum difference is 1
  // TODO: edge case where we have only 1 tower
  while(nMoves < k && diff > 0) {
    mii::iterator top = heights.end(),
                  top2 = heights.end()--,
                  bottom = heights.begin(),
                  bottom2 = heights.begin()++;

    diff = abs(top->fi - bottom->fi);
    diff2 = 0;
    if(top2 != bottom && bottom2 != top) {
      diff2 = abs(top2->fi - bottom2->fi);
    }

    int repetitions = min(diff - diff2 + 1, k - nMoves);
    nMoves += repetitions;
    moves.pb(mp(mp(top->se, bottom->se), repetitions));

    // Update the heights
    heights.insert(mp(top->fi - repetitions, top->se));
    heights.insert(mp(bottom->fi + repetitions, bottom->se));
    heights.erase(top);
    heights.erase(bottom);
    diff -= repetitions;
  }

  cout << diff << " " << moves.size() << endl;
  FOREACH(move, moves) {
    FOR(i, move->se) {
      cout << move->fi.fi << " " << move->fi.se << endl;
    }
  }
  return 0;
}
