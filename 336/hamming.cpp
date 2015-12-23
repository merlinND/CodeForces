#include <iostream>
using namespace std;

using ll = long long int;

inline int cmp(char aa, char bb) {
  return (aa == bb ? 0 : 1);
}

int main() {
  string a, b;
  cin >> a; cin >> b;

  if (b.length() < a.length()) {
    cout << 0 << endl;
    return 0;
  }

  ll s = 0;

  // Add up the partial sums incrementally
  for (ll offset = 0; offset + a.length() <= b.length(); ++offset) {
    for (ll i = 0; i < a.length(); ++i) {
      s += cmp(a[i], b[offset + i]);
    }
  }

  cout << s << endl;
  return 0;
}