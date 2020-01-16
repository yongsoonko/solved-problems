#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll> genConn(int i, int j, vector<vector<int>> &map) {
  int h = map.size(), w = map[0].size();
  vector<pll> result;
  int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
  for (int k = 0; k < 4; k++) {
    int pi = i + di[k], pj = j + dj[k];
    if (pi >= 0 && pi <= h - 1 && pj >= 0 && pj <= w - 1 && map[pi][pj] == 0)
      result.push_back({pi, pj});
  }
  return result;
}

int bfs(vector<vector<int>> &map, vector<vector<bool>> &vertex, vector<vector<vector<pll>>> &edge) {
  int day = 0, quotaOfDay = 0, quotaOfTomorrow = 0, remain = 0;
  queue<pll> q;
  for (int i = 0; i < map.size(); i++)
    for (int j = 0; j < map[0].size(); j++) {
      if (map[i][j] == 1) {
        vertex[i][j] = true;
        q.push({i, j});
        quotaOfDay++;
      } else if (map[i][j] == 0)
        remain++;
    }

  while (!q.empty()) {
    pll now = q.front();
    q.pop();

    vector<pll> conn = edge[now.first][now.second];
    for (int i = 0; i < conn.size(); i++) {
      pll next = conn[i];
      if (!vertex[next.first][next.second]) {
        vertex[next.first][next.second] = true;
        q.push(next);
        quotaOfTomorrow++;
        remain--;
      }
    }

    if (--quotaOfDay == 0) {
      quotaOfDay = quotaOfTomorrow;
      quotaOfTomorrow = 0;
      day++;
    }
  }
  if (remain == 0)
    // 마지막 날은 포함하지 않는다.
    return day - 1;
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int tc;
  // cin >> tc;
  tc = 1;

  for (int i = tc; i--;) {
    // m: 가로, n: 세로
    int m, n;
    cin >> m >> n;

    // 1: 익은토마토, 0: 익지않은토마토, -1:들어있지 않은 칸
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<bool>> vertex(n, vector<bool>(m, false));
    vector<vector<vector<pll>>> edge(n, vector<vector<pll>>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> map[i][j];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        edge[i][j] = genConn(i, j, map);

    int day = bfs(map, vertex, edge);
    cout << day << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
