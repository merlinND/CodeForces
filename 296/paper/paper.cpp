#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll length, width;
  cin >> length >> width;

  ll result = 0;
  // int oldWidth = width;
  while(length > 0 && width > 0) {
    if(width > length) {
      swap(width, length);
    }

    ll k = (length / width);
    length -= k * width;
    result += k;
  }

  cout << result << endl;
  return 0;
}
