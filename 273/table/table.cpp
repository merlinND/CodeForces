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

inline bool shouldContinue(ll int r, ll int g, ll int b) {
  // cout << r << ", " << g << ", " << b << endl;
  return !(r == g && g == b)
      && (r >= 0 && g >= 0 && g >= 0)
      && (r + g + b >= 3)
      && (r >= 2 || g >= 2 || b >= 2);
}

// Get the index of the max value
inline unsigned int iMax3(ll int * arr) {
  unsigned int index = 0;
  if(arr[1] > arr[index]) {
    index = 1;
  }
  if(arr[2] > arr[index]) {
    index = 2;
  }
  return index;
}

int main () {
  ll int t = 0;
  ll int b[3];
  cin >> b[0];
  cin >> b[1];
  cin >> b[2];

  // Greedy strategy: use the excess balloons in priority
  while(shouldContinue(b[0], b[1], b[2])) {
    unsigned int i = iMax3(b);
    unsigned int i2 = (i + 1) % 3;
    unsigned int i3 = (i + 2) % 3;
    b[i] -= 2;
    if(b[i2] >= b[i3])
      b[i2]--;
    else
      b[i3]--;

    t++;
  }

  // We have the same quantity of each balloon left
  // we can just decorate all tables the same way.
  if(b[0] == b[1] && b[1] == b[2])
    t += b[0];

  cout << t << endl;
  return 0;
}
