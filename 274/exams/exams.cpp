#include <iostream>
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

typedef multimap<ll int, ll int> mii;

int main () {
  ll int n, a, b;
  cin >> n;
  // Multimap ai -> bi
  // Maps are sorted on the key
  mii exams;
  FOR(i, n) {
    cin >> a; cin >> b;
    exams.insert(mp(a, b));
  }

  ll int lastDay = 1;
  FOREACH(exam, exams) {
    lastDay = max(lastDay, min(exam->fi, exam->se));
  }

  cout << lastDay << endl;
  return 0;
}
