#include <iostream>
using namespace std;

using ll = long long int;

int cmp(char aa, char bb) {
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
  ll currentSum = 0;
  int begin, end;

  // Build initial sum
  begin = cmp(a[0], b[0]);
  for (ll i = 0; i < a.length(); ++i) {
    end = cmp(a[i], b[i]);
    currentSum += end;
  }
  s += currentSum;

  // Add up the following partial sums incrementally
  for (ll offset = 1; offset + a.length() <= b.length(); ++offset) {
    end = cmp(a.back(), b[offset + a.length() - 1]);
    currentSum -= begin;
    currentSum += end;
    begin = cmp(a[0], b[offset]);

    s += currentSum;
  }

  cout << s << endl;
  return 0;
}