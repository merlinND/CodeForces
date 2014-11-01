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
  map<string, int> boxes;
  boxes["Alice"] = 0;
  boxes["Ariel"] = 0;
  boxes["Aurora"] = 0;
  boxes["Phil"] = 0;
  boxes["Peter"] = 0;
  boxes["Olaf"] = 0;
  boxes["Phoebus"] = 0;
  boxes["Ralph"] = 0;
  boxes["Robin"] = 0;
  boxes["Bambi"] = 1;
  boxes["Belle"] = 1;
  boxes["Bolt"] = 1;
  boxes["Mulan"] = 1;
  boxes["Mowgli"] = 1;
  boxes["Mickey"] = 1;
  boxes["Silver"] = 1;
  boxes["Simba"] = 1;
  boxes["Stitch"] = 1;
  boxes["Dumbo"] = 2;
  boxes["Genie"] = 2;
  boxes["Jiminy"] = 2;
  boxes["Kuzko"] = 2;
  boxes["Kida"] = 2;
  boxes["Kenai"] = 2;
  boxes["Tarzan"] = 2;
  boxes["Tiana"] = 2;
  boxes["Winnie"] = 2;

  ll int n, pos = 0, steps = 0;
  cin >> n;
  string name;
  FOR(i, n) {
    cin >> name;
    steps += std::abs(pos - boxes[name]);
    pos = boxes[name];
  }

  cout << steps << endl;
}
