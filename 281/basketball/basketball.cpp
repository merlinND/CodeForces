#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
  int n, m;
  vector<ll> teamA, teamB;
  // min1, min2: score if d is set to the max distance any team shot from
  ll score, totalA = 0, totalB = 0;

  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> score;
    teamA.push_back(score);
    totalA += 2;
  }

  cin >> m;
  for(int i = 0; i < m; ++i) {
    cin >> score;
    teamB.push_back(score);
    totalB += 2;
  }

  sort(teamA.begin(), teamA.end());
  sort(teamB.begin(), teamB.end());

  ll bestA = totalA,
     bestB = totalB,
     bestDifference = bestA - bestB;
  int i = n - 1,
      j = m - 1;
  // First reachable distance
  ll d = max(teamA[i], teamB[j]) - 1;
  ll difference;
  // For all meaningful values of d
  while(i >= 0) {
    // cout << "Trying distance d = " << d << endl;

    // And add points to both teams
    while(i >= 0 && teamA[i] > d) {
      totalA++;
      i--;
    }
    while(j >= 0 && teamB[j] > d) {
      totalB++;
      j--;
    }

    // Update best difference
    difference = totalA - totalB;
    if(difference > bestDifference || (difference == bestDifference && totalA > bestA)) {
      bestA = totalA;
      bestB = totalB;
      bestDifference = difference;
    }

    // Move d closer
    if(i >= 0 && j >= 0)
      d = max(teamA[i], teamB[j]) - 1;
    else if(i >= 0)
      d = teamA[i] - 1;
    else
      d = teamB[j] - 1;
  }

  cout << bestA << ":" << bestB << endl;
  return 0;
}
