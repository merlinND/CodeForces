#include <iostream>
using namespace std;

#define ISLANDS 30001
#define SHORTER 0
#define SAME 1
#define LONGER 2

int hasGem[ISLANDS];

int makeJumps(int current, int previousJump, int collected) {
  int jump1 = 0, jump2 = 0, jump3 = 0;

  if(current < 0 || current > ISLANDS) {
    return collected;
  }

  collected += hasGem[current];

  // TODO: complexity is way too high, need to use DP!
  if(previousJump > 1 && current + previousJump - 1 < ISLANDS) {
    jump1 = makeJumps(current + previousJump - 1, previousJump - 1, collected);
  }
  if(current + previousJump < ISLANDS) {
    jump2 = makeJumps(current + previousJump, previousJump, collected);
  }
  if(current + previousJump + 1 < ISLANDS) {
    jump3 = makeJumps(current + previousJump + 1, previousJump + 1, collected);
  }

  return max(collected, max(jump1, max(jump2, jump3)));
}

int main() {
  int n, firstJump;
  cin >> n >> firstJump;

  // Input: gem positions
  for(int i = 0; i < ISLANDS; ++i) {
    hasGem[i] = 0;
  }
  int x;
  for(int i = 0; i < n; ++i) {
    cin >> x;
    hasGem[x]++;
  }

  // Make jumps
  int best = makeJumps(firstJump, firstJump, 0);
  cout << best << endl;
  return 0;
}
