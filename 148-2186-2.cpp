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

int dfs(pii now, int str_idx, vector<string> &map, vector<vector<vector<int>>> &cache) {
  int i = now.first, j = now.second, ans = 0;
  if (str_idx == arrival.length())
    return 1;
  if (cache[i][j][str_idx] != -1)
    return cache[i][j][str_idx];

  for (int a = 1; a <= k; a++)
    for (int b = 0; b < 4; b++) {
      int pi = i + a * di[b], pj = j + a * dj[b];
      if (pi >= 0 && pi < n && pj >= 0 && pj < m && map[pi][pj] == arrival[str_idx])
        ans += dfs({pi, pj}, str_idx + 1, map, cache);
    }
  cache[i][j][str_idx] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    cin >> n >> m >> k;

    vector<string> map(n);
    vector<vector<vector<int>>> cache(n, vector<vector<int>>(m, vector<int>(81, -1)));
    for (int i = 0; i < n; i++)
      cin >> map[i];
    cin >> arrival;

    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (map[i][j] == arrival.front())
          ans += dfs({i, j}, 1, map, cache);

    cout << ans;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}