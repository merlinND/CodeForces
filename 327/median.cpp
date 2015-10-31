#include <iostream>
#include <vector>

using namespace std;
using ll = long long int;

/** Value table:
 * 0 0 0 => 0
 * 0 1 0 => 0  (and all equivalents)
 * 0 1 1 => 1  (and all equivalents)
 * 1 1 1 => 1
 */
bool median(bool b1, bool b2, bool b3) {
  char sum = static_cast<char>(b1) + static_cast<char>(b2) + static_cast<char>(b3);
  return sum >= 2;
}

int main() {
  ll n;
  cin >> n;
  vector<bool> b(n);
  bool tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    b[i] = tmp;
  }

  // TODO: early exit if there is a cycle
  ll iterations = 0;
  // Compute median for inner terms
  bool hasChanged;
  vector<bool> previous;
  do {
    iterations++;
    previous = b;
    hasChanged = false;
    for (int i = 1; i < n - 1; ++i) {
      bool m = median(previous[i-1], previous[i], previous[i+1]);
      hasChanged = hasChanged || (m != previous[i]);
      b[i] = m;
    }
  } while(hasChanged);

  cout << iterations - 1 << endl;
  if (iterations >= 0) {
    for (const bool bb : b) {
      cout << bb << " ";
    }
  }
  cout << endl;

  return 0;
}