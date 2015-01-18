#include <iostream>
using namespace std;

bool isPalindrome(string const & s) {
  for(int i = 0; i < (s.length() / 2); ++i) {
    if(s[i] != s[s.length() - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string input;
  cin >> input;
  int n = input.length();
  string output1(n + 1, 'z');
  string output2(n + 1, 'z');

  if(isPalindrome(input)) {
    // If already a palindrome: insert a letter in the middle
    for(int i = 0; i < (n / 2) + 1; ++i) {
      output1[i] = input[n - 1 - i];
      output1[n - i] = output1[i];
    }
    output1[(n + 1) / 2] = output1[(n / 2) + 1];

    cout << output1 << endl;
    return 0;
  }

  int d1 = 0, d2 = 0;
  for(int i = 0; i < (n / 2) + 1; ++i) {
    // Search for the first mismatching letter
    // Try both directions at the same time

    if(input[i] != input[n - 1 - (i-d1)]) {
      d1++;
    }
    output1[i] = input[i];
    output1[n - i] = output1[i];

    if(input[i] != input[n - 1 - (i+d2)]) {
      d2++;
    }
    output2[i+d2-1] = input[n - 1 - i];
    output2[n - i] = output2[i];
  }


  if(d1 == 1) {
    cout << output1 << endl;
  }
  else if(d2 == 1) {
    cout << output2 << endl;
  }
  else {
    // Fail
    cout << "NA" << endl;
  }
  return 0;
}
