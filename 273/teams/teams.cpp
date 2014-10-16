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

ll int friendshipsCreated(ll int teamSize) {
  return (teamSize * (teamSize - 1) / 2);
}

int main () {
  ll int minFriendships, maxFriendships;
  ll int n, m;
  cin >> n;
  cin >> m;

  // One huge team with most players, (m - 1) teams of 1 creating zero friendships
  maxFriendships = friendshipsCreated(n - m + 1);

  // All teams of size (n / m)  (integer division)
  // (and maybe one last team to take the excess players)

  // Forms teams of one until we can make make teams of more players
  // The players in teams of 1 become useless
  float r;
  do {
    r = (n / (float)m);
    if(r < 2.f) {
      n--;
      m--;
    }
  } while(r < 2.f);

  ll int uniformTeamSize = ceil(r);
  ll int excess = n - (m - 1) * uniformTeamSize;
  minFriendships = (m - 1) * friendshipsCreated(uniformTeamSize) + friendshipsCreated(excess);

  cout << minFriendships << " " << maxFriendships << endl;
  return 0;
}
