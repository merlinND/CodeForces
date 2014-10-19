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
  int maxResult;
  int a, b, c;
  cin >> a; cin >> b; cin >> c;

  if(1 / (float)a + 1 / (float)b > 1) {
    maxResult = a + b;
  }
  else {
    maxResult = a * b;
  }

  if(1 / (float)maxResult + 1 / (float)c > 1) {
    maxResult = maxResult + c;
  }
  else {
    maxResult = maxResult * c;
  }

  cout << maxResult << endl;
  return 0;
}
