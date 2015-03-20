#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
/** Multimap (a wrong letter -> its position) */
typedef multimap<char, ll> differences_t;


differences_t getDifferences(string a, string b) {
  differences_t differences;
  for(size_t i = 0; i < a.length(); ++i) {
    if(a[i] != b[i]) {
      differences.insert(make_pair<>(a[i], i));
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

void printResults(ll finalDistance, ll pos1 = -2, ll pos2 = -2) {
  cout << finalDistance << endl << (pos1+1) << " " << (pos2+1) << endl;
}

int main() {
  ll length;
  string first, second;
  cin >> length;
  cin >> first >> second;

  // Objective: find the single swap in `first`
  // which minimizes its hamming distance to `second`
  ll initialDistance = hammingDistance(first, second);
  ll minDistance = initialDistance;

  // We can't improve using a swap if there are less that 2 wrong letters
  if(minDistance <= 1) {
    printResults(minDistance);
    return 0;
  }

  // Try collecting one or two 'wrong' letters which are desired elsewere
  ll pos1 = -2, pos2 = -2;
  differences_t differences = getDifferences(first, second);

  differences_t::iterator it, range, rangeEnd;
  pair<differences_t::iterator, differences_t::iterator> pIt;
  for(it = differences.begin(); it != differences.end(); ++it) {
    // At this position, what we have VS what we would like
    char available = it->first;
    char desired = second[it->second];

    // See if this desired letter is available among the other candidates
    pIt = differences.equal_range(desired);
    range = pIt.first;
    rangeEnd = pIt.second;

    if(range != rangeEnd) {
      minDistance = initialDistance - 1;
      // Cool, now check if any of these candidates
      // actually are waiting for the letter we have available
      do {
        pos1 = range->second;
        pos2 = it->second;

        char desiredThere = second[range->second];
        if(desiredThere == available) {
          // We know there's no way to get better than a -2 improvement
          // with a single swap
          printResults(initialDistance - 2, pos1, pos2);
          return 0;
        }

        range++;
      } while(range != rangeEnd);
    }
  }

  // We still found at least one useful letter
  printResults(minDistance, pos1, pos2);
  return 0;
}
