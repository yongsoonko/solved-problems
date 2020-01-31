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
int m, n;

void dfs(int i, int j, vector<string> &map, vector<vector<bool>> &vertex, vector<vector<int>> &accum_map) {
  if (i == n - 1 && j == m - 1)
    return;

  for (int k = 0; k < 4; k++) {
    int ni = i + di[k], nj = j + dj[k];
    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vertex[ni][nj] && accum_map[ni][nj] > accum_map[i][j] + map[ni][nj] - '0') {
      vertex[ni][nj] = true;
      accum_map[ni][nj] = accum_map[i][j] + map[ni][nj] - '0';
      dfs(ni, nj, map, vertex, accum_map);
      vertex[ni][nj] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int tc = 5;
  for (int i = tc; i--;) {
    cin >> m >> n;

    vector<string> map(n);
    vector<vector<int>> accum_map(n, vector<int>(m, 1e9));
    vector<vector<bool>> vertex(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
      cin >> map[i];

    accum_map[0][0] = 0;
    vertex[0][0] = true;
    dfs(0, 0, map, vertex, accum_map);

    cout << accum_map[n - 1][m - 1] << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}