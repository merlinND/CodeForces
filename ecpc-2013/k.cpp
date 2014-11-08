#include "bits/stdc++.h"
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
#define FOREACH(i,t) for(__typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int main() {
  freopen("cubes.in", "r", stdin);

  int T;
  cin >> T;

  FOR(t, T) {
    printf("Case %d:\n", (t+1));

    int n;
    scanf("%d\n", &n);
    ll face;
    vector<ll> cubes;
    FOR(i, n-1) {
      scanf("%lld ", &face);
      cubes.pb(face);
    }
    scanf("%lld\n", &face);
    cubes.pb(face);

    sort(cubes.begin(), cubes.end());

    ll solution[n];
    int center = (n / 2);
    solution[center] = cubes[0];
    int j, direction = -1;
    FORI(i, n-1) {
      j = center + direction * ((i+1) / 2);
      direction *= -1;
      solution[j] = cubes.at((unsigned long)i);
    }

    printf("%lld", solution[0]);
    FORI(i, n-1) {
      printf(" %lld", solution[i]);
    }
    printf("\n");
  }
}
