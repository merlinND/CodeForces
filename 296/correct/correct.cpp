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

ll trySwap(string a, string b, ll i, ll j, ll distance) {
  swap(a[i], a[j]);
  // Distance can only improve by 0, 1 or 2
  if(a[i] == b[i]) distance--;
  if(a[j] == b[j]) distance--;
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

  // We can't improve using a swap if there are less that 2 wrong letters
  if(initialDistance <= 1) {
    printResults(initialDistance);
    return 0;
  }

  // Try collecting one or two 'wrong' letters which are desired elsewere
  ll pos1 = -1, pos2 = -1;
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
      // Cool, now check if any of these candidates
      // actually are waiting for the letter we have available
      do {
        pos1 = range->second;
        if(second[range->second] == available) {
          // We know there's no way to get better than a -2 improvement
          // with a single swap
          pos2 = it->second;
          printResults(initialDistance - 2, pos1, pos2);
          return 0;
        }

        range++;
      } while(range != rangeEnd);
    }
  }

  // We still found at least one useful letter, swap it with any other
  if(pos1 >= 0) {
    differences_t::iterator it = differences.begin();
    do {
      pos2 = it->second;
      it++;
    } while(pos2 == pos1);

    printResults(initialDistance - 1, pos1, pos2);
    return 0;
  }

  printResults(initialDistance);
  return 0;
}
