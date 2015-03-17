#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

void printArea(pll const & vertical, pll const & horizontal) {
  cerr << "Best rectangle: "
       << vertical.first << " ... " << vertical.second
       << " x "
       << horizontal.first << " ... " << horizontal.second
       << " --> ";

  cout << (vertical.second - vertical.first)
        * (horizontal.second - horizontal.first) << endl;
}

void updateLargestInterval(vector<ll> & cuts, pll & bestInterval) {
  ll best = 0;
  sort(cuts.begin(), cuts.end());

  for(size_t i = 1; i < cuts.size(); ++i) {
    cerr << "Proposed interval: " << cuts[i-1] << " ... " << cuts[i] << endl;
    if(cuts[i] - cuts[i-1] > best) {
      bestInterval.first = cuts[i-1];
      bestInterval.second = cuts[i];
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
  vector<ll> vCuts, hCuts;
  vCuts.push_back(vBest.first);
  vCuts.push_back(vBest.second);
  hCuts.push_back(hBest.first);
  hCuts.push_back(hBest.second);
  for(ll i = 0; i < n; ++i) {
    // For each new cut, update the best area
    cin >> type >> point;
    if(type == 'V') {
      vCuts.push_back(point);
      cerr << "New V cut at " << point << endl;
      // Affected our best area
      if(point > vBest.first && point < vBest.second) {
        // Need to find the new best vertical interval
        cerr << "Spoiled " << vBest.first << " ... " << vBest.second << endl;
        updateLargestInterval(vCuts, vBest);
      }
    }
    else {
      hCuts.push_back(point);
      cerr << "New H cut at " << point << endl;
      // Affected our best area
      if(point > hBest.first && point < hBest.second) {
        // Need to find the new best vertical interval
        cerr << "Spoiled " << hBest.first << " ... " << hBest.second << endl;
        updateLargestInterval(hCuts, hBest);
      }
    }

    printArea(vBest, hBest);
  }
  return 0;
}
