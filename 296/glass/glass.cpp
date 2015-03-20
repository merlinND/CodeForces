#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

void printArea(pll const & vertical, pll const & horizontal) {
  cout << (vertical.second - vertical.first)
        * (horizontal.second - horizontal.first) << endl;
}

void updateLargestInterval(set<ll> & cuts, pll & bestInterval) {
  ll best = 0;
  // Set elements are traversed in sorted order
  set<ll>::const_iterator it = cuts.begin(), it2 = it;
  it2++;
  for(; it2 != cuts.end(); ++it, ++it2) {
    if((*it2) - (*it) >= best) {
      bestInterval.first = (*it);
      bestInterval.second = (*it2);
      best = (bestInterval.second - bestInterval.first);
    }
  }
}

int main() {
  ll width, height, n;
  cin >> width >> height >> n;

  pll vBest(0, width);
  pll hBest(0, height);

  char type;
  ll point;
  set<ll> vCuts, hCuts;
  vCuts.insert(vBest.first);
  vCuts.insert(vBest.second);
  hCuts.insert(hBest.first);
  hCuts.insert(hBest.second);
  for(ll i = 0; i < n; ++i) {
    // For each new cut, update the best area
    cin >> type >> point;
    if(type == 'V') {
      vCuts.insert(point);
      // Affected our best area
      if(point > vBest.first && point < vBest.second) {
        // Need to find the new best vertical interval
        updateLargestInterval(vCuts, vBest);
      }
    }
    else {
      hCuts.insert(point);
      // Affected our best area
      if(point > hBest.first && point < hBest.second) {
        // Need to find the new best vertical interval
        updateLargestInterval(hCuts, hBest);
      }
    }

    printArea(vBest, hBest);
  }
  return 0;
}
