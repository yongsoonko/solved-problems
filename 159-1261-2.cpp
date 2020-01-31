#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int m, n;

void bfs(ai3 now, vector<string> &map, vector<vector<int>> &accum_map) {
  priority_queue<ai3, vector<ai3>, greater<ai3>> pq;
  pq.push(now);

  while (!pq.empty()) {
    ai3 now = pq.top();
    pq.pop();

    int i = now[1], j = now[2];
    for (int k = 0; k < 4; k++) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && accum_map[ni][nj] > now[0] + map[ni][nj] - '0') {
        accum_map[ni][nj] = now[0] + map[ni][nj] - '0';
        pq.push({accum_map[ni][nj], ni, nj});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int tc = 1;
  for (int i = tc; i--;) {
    cin >> m >> n;

    vector<string> map(n);
    vector<vector<int>> accum_map(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++)
      cin >> map[i];

    accum_map[0][0] = 0;
    bfs({0, 0, 0}, map, accum_map);

    // for (auto a : accum_map) {
    //   for (int i : a)
    //     cout << i << ' ';
    //   cout << '\n';
    // }
    cout << accum_map[n - 1][m - 1] << '\n';
    // cout << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}