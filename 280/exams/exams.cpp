#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
  ll n, maxGrade, targetAverage;
  cin >> n >> maxGrade >> targetAverage;

  // We multiply by the target rather than to divide the mean
  // in order to avoid floating point manipulation.
  // This gives the total required amount of points
  ll target = targetAverage * n;

  // Each exam has (cost of improving grade by one, current grade)
  vector<pii> exams;
  ll cost, grade;
  ll currentPoints = 0;
  ll totalCost = 0;
  for(int i = 0; i < n; ++i) {
    cin >> grade >> cost;
    exams.push_back(make_pair(cost, grade));
    currentPoints += grade;
  }

  // Sort exams by the least cost of improving the grade
  sort(exams.begin(), exams.end());

  ll diff = target - currentPoints;
  // Index of the cheapest available exam
  ll i = 0;
  while(diff > 0 && i < n) {

    // We can improve at this cost until we reach the maximum grade
    ll essaysToWrite = min(diff, maxGrade - exams[i].second);
    ll cost = exams[i].first * essaysToWrite;
    currentPoints += essaysToWrite;
    totalCost += cost;

    // cout << target << " vs " << currentPoints << endl;
    // cout << "Will write " << essaysToWrite << " for exam " << i << " at cost " << cost << endl;

    // We have maxed out this exam
    i++;

    diff = target - currentPoints;
  }


  cout << totalCost << endl;
  return 0;
}
