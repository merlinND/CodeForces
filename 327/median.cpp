#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> a(n);
  bool tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    a[i] = tmp;
  }

  long long int iterations = -1;
  vector<bool> b(n);
  b[0] = a[0];
  b[n - 1] = a[n - 1];

  cout << iterations << endl;
  if (iterations >= 0) {
    for (const bool bb : b) {
      cout << bb << " ";
    }
  }
  cout << endl;

  return 0;
}