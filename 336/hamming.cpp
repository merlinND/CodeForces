#include <iostream>
#include <map>
#include <vector>
#include <deque>

using namespace std;

using ll = long long int;

namespace {
  map<deque<bool>, ll> sums;
}

inline ll cmp(const vector<bool> & aa, const deque<bool> & window) {
  if (sums.count(window) <= 0) {
    ll sum = 0;
    size_t i = 0;
    for (const bool & w : window) {
      sum += (aa[i] == w ? 0 : 1);
      ++i;
    }
    sums[window] = sum;
    return sum;
  }
  return sums[window];
}

int main() {
  string aa, bb;
  cin >> aa; cin >> bb;
  size_t n = aa.length(), nb = bb.length();

  vector<bool> a(n);
  deque<bool> w;
  // Prepare initial window
  for (size_t i = 0; i < n; ++i) {
    a[i] = (aa[i] == '1');
    w.push_back(bb[i] == '1');
  }

  ll s = cmp(a, w);
  // Add up the partial sums incrementally
  for (ll offset = 1; offset + n <= nb; ++offset) {
    w.pop_front();
    w.push_back(bb[offset + n - 1] == '1');

    s += cmp(a, w);
  }

  cout << s << endl;
  return 0;
}