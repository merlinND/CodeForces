#include <iostream>
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

bool isValid(int nMoves, int m) {
  return (nMoves % m) == 0;
}

int main () {
  int n, m;
  cin >> n;
  cin >> m;

  // Maximum number of steps of 2 that could be done
  int twoSteps = (n / 2);
  int oneSteps = 0;
  // Add the necessary number of steps of 1 to reach n
  if(twoSteps * 2 < n) {
    oneSteps = (n - 2 * twoSteps);
  }

  int nMoves = oneSteps + twoSteps;
  while(!isValid(nMoves, m) && twoSteps > 0) {
    oneSteps += 2;
    twoSteps--;
    nMoves++;
  }

  if(!isValid(nMoves, m))
    cout << -1 << endl;
  else
    cout << nMoves << endl;

	return 0;
}
