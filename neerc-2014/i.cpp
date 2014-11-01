#include "bits/stdc++.h"
using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp nake_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for(__typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int main() {
  string south, north;
  cin >> south >> north;

  unsigned long n1 = south.length(), n2 = north.length();
  unsigned int i = 0, j = 0, seconds = 0;
  while(i < n1 || j < n2) {
    if(i >= n1) {
      // South is clear
      seconds += n2 - j;
      break;
    }
    if(j >= n2) {
      // North is clear
      seconds += n1 - i;
      break;
    }

    // Cars on both sides
    seconds++;
    if(south[i] == 'L' && north[j]== 'L') {
      i++;
      j++;
    }
    else {
      if(south[i] != 'L')
        i++;
      if(north[j] != 'L')
        j++;
    }
  }

  cout << seconds << endl;
}
