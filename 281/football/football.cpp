#include <iostream>
#include <map>
using namespace std;

int getValue(map<int, int> const & fouls, int player) {
  map<int, int>::const_iterator it = fouls.find(player);
  return (it == fouls.end()) ? 0 : it->second;
}

bool addFoul(map<int, int> & fouls, int player, char color) {
  int penalty = (color == 'r' ? 2 : 1);
  int previousValue = getValue(fouls, player);
  fouls[player] = previousValue + penalty;

  return (previousValue < 2 && fouls[player] >= 2);
}

int main() {
  string team1, team2;
  cin >> team1 >> team2;

  int n;
  cin >> n;

  map<int, int> fouls1, fouls2;
  int minute, player;
  char team, color;
  for(int i = 0; i < n; ++i) {
    cin >> minute;
    cin >> team;
    cin >> player;
    cin >> color;

    if(team == 'h' && addFoul(fouls1, player, color)) {
      cout << team1 << " " << player << " " << minute << endl;
    }
    else if(team == 'a' && addFoul(fouls2, player, color)) {
      cout << team2 << " " << player << " " << minute << endl;
    }
  }

  return 0;
}
