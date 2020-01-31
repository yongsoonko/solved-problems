#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

bool solve(int begin, vector<pii> &blank, vector<vector<int>> &map) {
  if (begin == blank.size())
    return true;

  pii now = blank[begin];
  for (int num = 1; num <= 9; num++) {
    int i = 0, j = 0, k = 0;
    for (; i < 9; i++)
      if (map[i][now.second] == num)
        break;
    for (; j < 9; j++)
      if (map[now.first][j] == num)
        break;
    for (; k < 9; k++)
      if (map[(now.first) / 3 * 3 + k / 3][(now.second) / 3 * 3 + k % 3] == num)
        break;
    if (i == 9 && j == 9 && k == 9) {
      map[now.first][now.second] = num;
      if (solve(begin + 1, blank, map))
        return true;
      map[now.first][now.second] = 0;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  for (int i = tc; i--;) {
    vector<pii> blank;
    vector<vector<int>> map(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++) {
        cin >> map[i][j];
        if (map[i][j] == 0)
          blank.push_back({i, j});
      }

    solve(0, blank, map);

    for (auto a : map) {
      for (int i : a)
        cout << i << ' ';
      cout << '\n';
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}