#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int bfs(vector<vector<int>> &map, vector<vector<bool>> &vertex) {
  queue<pll> q;
  int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
  int h = map.size(), w = map[0].size();
  vertex[0][0] = true;
  q.push({0, 0});

  while (!q.empty()) {
    pll now = q.front();
    q.pop();

    int i = now.first, j = now.second;
    for (int k = 0; k < 4; k++) {
      int pi = i + di[k], pj = j + dj[k];
      if (pi >= 0 && pi <= h - 1 && pj >= 0 && pj <= w - 1 && !vertex[pi][pj]) {
        vertex[pi][pj] = true;
        q.push({pi, pj});
        map[pi][pj] = map[i][j] + 1;
      }
    }
  }
  return map[h-1][w-1];
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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<bool>> vertex(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      for (int j = 0; j < m; j++) {
        map[i][j] = str[j] - '0';
        if (str[j] == '0')
          vertex[i][j] = true;
      }
    }

    cout << bfs(map, vertex) << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}