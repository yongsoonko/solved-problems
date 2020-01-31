#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int n, m, k;
string arrival;

int bfs(vector<string> &map, vector<vector<int>> &accum_cnt) {
  queue<pii> q;
  int str_idx = 1, ans = 0;
  int prev_allot = 0, next_allot = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (map[i][j] == arrival.front()) {
        q.push({i, j});
        accum_cnt[i][j] = 1;
        prev_allot++;
      }

  if (m == 1)
    return prev_allot;
  else {
    while (!q.empty()) {
      pii now = q.front();
      q.pop();
      prev_allot--;

      int i = now.first, j = now.second;
      for (int a = 1; a <= k; a++)
        for (int b = 0; b < 4; b++) {
          int pi = i + a * di[b], pj = j + a * dj[b];
          if (pi >= 0 && pi < n && pj >= 0 && pj < m && map[pi][pj] == arrival[str_idx]) {
            if (str_idx <= arrival.length() - 1) {
              q.push({pi, pj});
              next_allot++;
            }
          }
        }
      if (!prev_allot) {
        if (str_idx == arrival.length() - 1)
          return next_allot;
        prev_allot = next_allot;
        next_allot = 0;
        str_idx++;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    cin >> n >> m >> k;

    vector<string> map(n);
    vector<vector<int>> accum_cnt(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      cin >> map[i];
    cin >> arrival;

    cout << bfs(map, accum_cnt);
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}