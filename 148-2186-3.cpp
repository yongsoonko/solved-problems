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

string map[100];
vector<vector<vector<int>>> cache(100, vector<vector<int>>(100, vector<int>(80, -1)));
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int n, m, k, len;
string arrival;

int dfs(int i, int j, int str_idx) {
  if (str_idx < 0)
    return 1;
  if (cache[i][j][str_idx] != -1)
    return cache[i][j][str_idx];

  cache[i][j][str_idx] = 0;
  for (int a = 1; a <= k; a++)
    for (int b = 0; b < 4; b++) {
      int ni = i + a * di[b], nj = j + a * dj[b];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] == arrival[str_idx])
        cache[i][j][str_idx] += dfs(ni, nj, str_idx - 1);
    }
  return cache[i][j][str_idx];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
      cin >> map[i];
    cin >> arrival;
    len = arrival.length();

    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (map[i][j] == arrival.back())
          ans += dfs(i, j, len - 2);

    // Answer: 5378880
    cout << ans;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}