#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
/** Multimap (a wrong letter -> its position) */
typedef multimap<char, ll> differences_t;
/** Multimap ((a wrong letter, the expected letter) -> position the wrong letter) */
typedef multimap<pair<char, char>, ll> expectations_t;

differences_t differences;
expectations_t expectations;

void precompute(string a, string b) {
  for(size_t i = 0; i < a.length(); ++i) {
    if(a[i] != b[i]) {
      differences.insert(make_pair<>(a[i], i));
      expectations.insert(make_pair<>(make_pair<>(a[i], b[i]), i));
    }
  }
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
  precompute(first, second);

  differences_t::iterator it, other;
  expectations_t::iterator back;

  for(it = differences.begin(); it != differences.end(); ++it) {
    // At this position, what we have VS what we would like
    char available = it->first;
    char desired = second[it->second];

    // See if this desired letter is available among the other candidates
    other = differences.find(desired);

    if(other != differences.end()) {
      minDistance = initialDistance - 1;
      pos1 = it->second;
      pos2 = other->second;

      // Cool, now check if any of these candidates
      // actually are waiting for the letter we have available
      back = expectations.find(make_pair<>(desired, available));
      if(back != expectations.end()) {
        // We know there's no way to get better than a -2 improvement
        // with a single swap
        pos2 = back->second;
        printResults(initialDistance - 2, pos1, pos2);
        return 0;
      }
    }
  }

  // We still found at least one useful letter
  printResults(minDistance, pos1, pos2);
  return 0;
}
