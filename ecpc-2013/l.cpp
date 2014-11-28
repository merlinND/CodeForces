#include "bits/stdc++.h"
#include <cstdio>
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

char getChar(char * previous, ll i, ll * maxI, ll multiplier, ll adder) {
  if(i <= (*maxI)) {
    return previous[i];
  }

  char a = ((previous[i-1] - 'a') * multiplier) % 26;
  char b = (i * adder) % 26;
  char c = (a + b) % 26 + 'a';

  previous[i] = c;
  (*maxI)++;
  return c;
}

int main() {
  freopen("mahdi.in", "r", stdin);

  int T;
  scanf("%d\n", &T);

  FOR(t, T) {
    printf("Case %d:\n", (t+1));

    // Expected result
    char init;
    ll length, multiplier, adder;
    scanf("%c %lld %lld %lld\n", &init, &length, &multiplier, &adder);
    char reference[length];
    reference[0] = init;
    // Maximum position evaluated in `reference` (inclusive)
    ll maxPos = 0;

    ll n;
    scanf("%lld\n", &n);
    // For each word proposed
    FOR(k, n) {
      char first;
      ll l, m, a;
      scanf("%c %lld %lld %lld\n", &first, &l, &m, &a);
      char proposal[l];
      proposal[0] = first;
      // Maximum position evaluated in `proposal` (inclusive)
      ll maxI = 0;

      // For each char of this word
      ll i = 0; // Iterator on the proposed word
      ll j = 0; // Iterator on the expected result
      while(i < l) {
        char c = getChar(proposal, i, &maxI, m, a);
        while(j < length &&
              c != getChar(reference, j, &maxPos, multiplier, adder)) {
          j++;
        }

        if(j >= length) {
          printf("REPEAT\n");
          break;
        }

        i++;
      }

      if(i >= l) {
        printf("BRAVO\n");
      }
    }
  }
}
