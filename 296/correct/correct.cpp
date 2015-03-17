#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> getDifferences(string a, string b) {
  vector<ll> differences;
  for(size_t i = 0; i < a.length(); ++i) {
    if(a[i] != b[i]) {
      differences.push_back(i);
    }
  }
  return differences;
}

ll hammingDistance(string a, string b) {
  ll distance = 0;
  for(size_t i = 0; i < a.length(); ++i) {
    if(a[i] != b[i]) {
      distance++;
    }
  }
  return distance;
}

ll trySwap(string a, string b, ll i, ll j) {
  swap(a[i], a[j]);
  return hammingDistance(a, b);
}

void printResults(ll finalDistance, ll pos1 = -2, ll pos2 = -2) {
  cout << finalDistance << endl << (pos1+1) << " " << (pos2+1) << endl;
}

int main() {
  ll length;
  string first, second;
  cin >> length;
  cin >> first >> second;

  // Find the single swap in `first`
  // which minimizes its hamming distance to `second`
  vector<ll> differences = getDifferences(first, second);
  ll initialDistance = hammingDistance(first, second);
  ll minDistance = initialDistance;
  ll pos1 = -2, pos2 = -2;

  if(minDistance <= 1) {
    printResults(minDistance);
    return 0;
  }


  // Try each swap among the differences
  // (there's no sense swapping letters which are in place)
  vector<ll>::iterator diff1, diff2;
  for(diff1 = differences.begin(); diff1 != differences.end(); ++diff1) {
    for(diff2 = diff1; diff2 != differences.end(); ++diff2) {
      ll i = (*diff1);
      ll j = (*diff2);
      ll d = trySwap(first, second, i, j);
      // cout << d << ", " << i << " " << j << endl;
      if(first[i] != first[j] && d < minDistance) {
        minDistance = d;
        pos1 = i;
        pos2 = j;
      }

      // We know there's no way to get better than a -2 improvement
      // with a single swap
      if(minDistance <= initialDistance - 2) {
        printResults(minDistance, pos1, pos2);
        return 0;
      }
    }
  }

  printResults(minDistance, pos1, pos2);
  return 0;
}
