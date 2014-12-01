#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int rest = n;
  int i = 0;
  int currentLevel = 0;

  while(rest > 0) {
    i++;
    currentLevel += i;
    rest -= currentLevel;
  }

  if(rest < 0) {
    i--;
  }

  cout << i << endl;

  return 0;
}
