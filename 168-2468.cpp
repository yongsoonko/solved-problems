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

int n, ans = -1;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
ve<ve<int>> map(101, ve<int>(101));
ve<ve<int>> chk(101, ve<int>(101));

void bfs(int ci, int cj) {
  queue<pii> q;
  q.push({ci, cj});

  while (!q.empty()) {
    pii curr = q.front();
    q.pop();

    ci = curr.first, cj = curr.second;
    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < n && nj >= 0 & nj < n && chk[ni][nj]) {
        chk[ni][nj] = 0;
        q.push({ni, nj});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> n;
  int min_height = 101, max_height = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      min_height = min(min_height, map[i][j]);
      max_height = max(max_height, map[i][j]);
    }

  for (int k = min_height - 1; k <= max_height; k++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (map[i][j] > k)
          chk[i][j] = 1;

    int cnt = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (chk[i][j]) {
          chk[i][j] = 0;
          bfs(i, j);
          cnt++;
        }
    ans = max(ans, cnt);
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}