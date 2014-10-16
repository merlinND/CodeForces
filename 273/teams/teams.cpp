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
  ll int uniformTeamSize = (n / m);
  ll int excess = n - m * uniformTeamSize;
  minFriendships = (m - 1) * friendshipsCreated(uniformTeamSize);
  minFriendships += friendshipsCreated(uniformTeamSize + excess);

  cout << minFriendships << " " << maxFriendships << endl;
  return 0;
}
