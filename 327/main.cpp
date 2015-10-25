#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> data;
  int x = 0;
  while (cin >> x) {
    data.push_back(x);
  }

  for (int y : data) {
    cout << y << endl;
  }
  return 0;
}