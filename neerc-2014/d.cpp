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
  int myMoney, alone1, alone2;
  cin >> myMoney >> alone1 >> alone2;

  int nFriends;
  cin >> nFriends;
  // Friends = (max rent, bonus)
  int maxRent, bonus;
  vector<pii> friends;
  FOR(i, nFriends) {
    cin >> maxRent >> bonus;
    friends.pb(mp(maxRent, bonus));
  }

  int nApartments;
  cin >> nApartments;
  // Appartments (1B or 2B) = (index, (cost, bonus))
  int beds, cost;
  vector<pair<int, pii> > ap1, ap2;
  FOR(i, nApartments) {
    cin >> beds >> cost >> bonus;
    if(beds == 1)
      ap1.pb(mp(i+1, mp(cost, bonus)));
    else
      ap2.pb(mp(i+1, mp(cost, bonus)));
  }

  // Solution = (appartment, friend)
  pii best(-1, -1);
  int utility, bestUtility = -1;

  // Alone in a 1 bedroom appartment
  FOREACH(it, ap1) {
    if(it->se.fi <= myMoney) {
      utility = alone1 + it->se.se;
      if(utility > bestUtility) {
        bestUtility = utility;
        best.fi = it->fi;
        best.se = -1;
      }
    }
  }

  // Alone in a 2 bedrooms appartment
  FOREACH(it, ap2) {
    if(it->se.fi <= myMoney) {
      utility = alone2 + it->se.se;
      if(utility > bestUtility) {
        bestUtility = utility;
        best.fi = it->fi;
        best.se = -1;
      }
    }

    // With a friend in a 2 bedrooms appartment
    FOR(k, friends.size()) {
      pii & f = friends[(unsigned int)k];
      float halfRent = it->se.fi / 2.0f;

      if(myMoney >= halfRent && f.fi >= halfRent) {
        utility = it->se.se + f.se;
        if(utility > bestUtility) {
          bestUtility = utility;
          best.fi = it->fi;
          best.se = k+1;
        }
      }
    }
  }

  // Output
  if(best.fi < 0)
    cout << "Forget about apartments. Live in the dormitory." << endl;
  else if(best.se < 0)
    cout << "You should rent the apartment #" << best.fi << " alone." << endl;
  else
    cout << "You should rent the apartment #" << best.fi << " with the friend #" << best.se << "." << endl;
}
