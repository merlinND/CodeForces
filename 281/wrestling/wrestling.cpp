#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll total1, total2;
int latest1, latest2;

bool breakTie(vector<ll> const & points1, vector<ll> const & points2) {
  int n1 = points1.size();
  int n2 = points2.size();

  if(total1 == total2) {
    // Tie-breaker: lexicographical order of the sequence of points
    if(points1.size() != points2.size()) {
      int i = 0;
      while(i < min(n1, n2)) {
        if(points1[i] == points2[i]) {
          i++;
          continue;
        }
        // Found a lexicographical difference
        return (points1[i] > points2[i]);
      }

      // Different sizes but one is prefix of the other:
      // the lexicographically larger is the longest of the two
      return (n1 > n2);
    }
    // Tie-breaker-breaker: latest move
    return (latest1 > latest2);
  }

  // Standard victory by most points
  return (total1 > total2);
}

int main() {
  int n;
  cin >> n;

  ll score;
  vector<ll> points1, points2;
  for(int i = 0; i < n; ++i) {
    cin >> score;

    // First wrestler
    if(score > 0) {
      points1.push_back(score);
      total1 += score;
      latest1 = i;
    }
    // Second wrestler
    else {
      points2.push_back(score);
      score = - score;
      total2 += score;
      latest2 = i;
    }
  }

  cout << (breakTie(points1, points2) ? "first" : "second") << endl;
  return 0;
}
