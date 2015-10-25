#include <iostream>

using namespace std;

int main() {
  int n, m;
  string name;
  cin >> n; cin >> m; cin >> name;

  char x, y;
  for (int i = 0; i < m; ++i) {  // Designer's transformations
    cin >> x; cin >> y;
    for (int j = 0; j < name.length(); ++j) {
      if (name[j] == x) name[j] = y;
      else if (name[j] == y) name[j] = x;
    }
  }

  cout << name << endl;
  return 0;
}