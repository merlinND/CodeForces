#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, m;
  string name;
  cin >> n; cin >> m; cin >> name;

  unordered_map<char, char> transformations;

  char x, y;
  for (int i = 0; i < m; ++i) {  // Designer's transformations
    cin >> x; cin >> y;

    // Letters that were transformed to `x` will now become `y` (and inversely)
    for (const auto p : transformations) {
      if (p.second == x) {
        transformations[p.first] = y;
      }
      if (p.second == y) {
        transformations[p.first] = x;
      }
    }
    // Letters `x` that are still there from the original name should become `y` (and inversely)
    if (transformations.count(x) <= 0) {
      transformations[x] = y;
    }
    if (transformations.count(y) <= 0) {
      transformations[y] = x;
    }
  }

  for (int j = 0; j < name.length(); ++j) {
    const auto y = transformations.find(name[j]);
    if (y != transformations.end()) {
      name[j] = y->second;
    }
  }

  cout << name << endl;
  return 0;
}