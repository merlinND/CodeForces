#include <iostream>
#include <vector>

using namespace std;

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
  int n;
  cin >> n;
  vector<bool> b(n);
  bool tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    b[i] = tmp;
  }

  // TODO: early exit if there is a cycle
  long long int iterations = -1;
  // Compute median for inner terms
  bool hasChanged;
  do {
    iterations++;
    hasChanged = false;
    for (int i = 1; i < n - 1; ++i) {
      bool m = median(b[i-1], b[i], b[i+1]);
      hasChanged = hasChanged || (m != b[i]);
      b[i] = m;
    }
  } while(hasChanged);

  // Particular case for the number of iterations: the sequence was stable from the start
  cout << (iterations > 0 ? iterations + 1 : iterations) << endl;
  if (iterations >= 0) {
    for (const bool bb : b) {
      cout << bb << " ";
    }
  }
  cout << endl;

  return 0;
}