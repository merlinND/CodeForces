#include <iostream>
#include <string>
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

const int INITIAL_POSITION = 0;

int main () {
  string originalDirections, directions;
  cin >> originalDirections;
  cin >> directions;

  int desiredPosition = INITIAL_POSITION;
  FOR(i, originalDirections.length()) {
    if(originalDirections.at(i) == '+') desiredPosition++;
    else desiredPosition--;
  }

  vi potentialPositions;
  potentialPositions.pb(INITIAL_POSITION);
  // For each received instruction
  FOR(i, directions.size()) {
    char instruction = directions.at(i);
    vi added;

    // Update all potential positions
    FOR(j, potentialPositions.size()) {
      if(instruction == '+')
        potentialPositions[j]++;
      else if(instruction == '-')
        potentialPositions[j]--;
      else {
        added.pb(potentialPositions[j] + 1);
        potentialPositions[j]--;
      }
    }

    potentialPositions.insert(potentialPositions.end(), added.begin(), added.end());
  }

  // When done, count the number of occurences of the correct position
  unsigned int correct = 0;
  FOR(i, potentialPositions.size()) {
    if(potentialPositions[i] == desiredPosition)
      correct++;
  }

  cout << correct / (float)potentialPositions.size() << endl;

	return 0;
}
