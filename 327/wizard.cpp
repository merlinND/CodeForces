#include <iostream>

using namespace std;

int main() {
  int l, p, q;
  cin >> l; cin >> p; cin >> q;

  cout << p * l / static_cast<float>(p + q);
  return 0;
}