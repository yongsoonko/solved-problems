#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

#define ve vector
#define fi first
#define se second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

int m, n, k;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
ve<ve<int>> map(101, ve<int>(101));
ve<int> ans;

int bfs(int ci, int cj) {
  int cnt = 1;
  queue<pii> q;
  q.push({ci, cj});
  map[ci][cj] = 1;

  while (!q.empty()) {
    pii curr = q.front();
    q.pop();

    ci = curr.fi, cj = curr.se;
    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] == 0) {
        map[ni][nj] = 1;
        q.push({ni, nj});
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> m >> n >> k;

  for (int s = 0; s < k; s++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i < c; i++)
      for (int j = b; j < d; j++)
        map[i][j] = 1;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (map[i][j] == 0)
        ans.push_back(bfs(i, j));

  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int i : ans)
    cout << i << ' ';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}