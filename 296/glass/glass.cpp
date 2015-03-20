#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef ll interval_t;
typedef map<ll, interval_t> cuts_t;

// Map (position of the cut) => (length of the following interval)
cuts_t vCuts, hCuts;
// Multisets of all available intervals
multiset<interval_t> vIntervals, hIntervals;

void printArea() {
  multiset<interval_t>::iterator vIt = vIntervals.end(),
                                 hIt = hIntervals.end();
  vIt--;
  hIt--;

  cout << (*vIt) * (*hIt) << endl;
}

void insertCut(cuts_t & cuts, multiset<interval_t> & intervals, ll position) {
  // The interval being intersected becomes shorter
  cuts_t::iterator bottom = cuts.lower_bound(position);
  bottom--;

  interval_t updatedInterval = (position - bottom->first);
  interval_t newInterval = (bottom->second - updatedInterval);

  // Maintain the set of available intervals
  intervals.erase(intervals.find(bottom->second));
  intervals.insert(updatedInterval);
  intervals.insert(newInterval);

  // Register this new cut
  bottom->second = updatedInterval;
  cuts[position] = newInterval;
}

int main() {
  ll width, height, n;
  cin >> width >> height >> n;

  pll vBest(0, width);
  pll hBest(0, height);

  vCuts[vBest.first] = vBest.second;
  hCuts[hBest.first] = hBest.second;
  vIntervals.insert(vBest.second);
  hIntervals.insert(hBest.second);

  char type;
  ll point;
  for(ll i = 0; i < n; ++i) {
    // For each new cut, update the best area
    cin >> type >> point;

    cuts_t * cuts = (type == 'V' ? &vCuts : &hCuts);
    multiset<interval_t> * intervals = (type == 'V' ? &vIntervals : &hIntervals);

    insertCut(*cuts, *intervals, point);
    printArea();
  }
  return 0;
}
