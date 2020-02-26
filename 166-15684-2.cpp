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

int n, m, h, add_cnt = 1;
ve<ve<int>> map(31, ve<int>(11));

bool down_ladder() {
  int pos = 1;
  for (; pos <= n; pos++) {
    int j = pos;
    for (int i = 1; i <= h; i++) {
      if (j - 1 >= 1 && map[i][j - 1])
        j--;
      else if (j <= n - 1 && map[i][j])
        j++;
    }
    if (pos != j)
      break;
  }
  if (pos > n)
    return true;
  else
    return false;
}

bool dfs(int ci, int cj, int cnt) {
  if (cnt == add_cnt) {
    return down_ladder();
  } else {
    int do_once = 1, j;
    for (int i = ci; i <= h; i++) {
      if (do_once)
        j = cj, do_once = 0;
      else
        j = 1;
      for (; j < n; j++)
        if (!map[i][j] && ((j - 1 < 1) || !map[i][j - 1]) && ((j + 1 >= n) || !map[i][j + 1])) {
          map[i][j] = 1;
          int ni, nj;
          if (j == n - 1)
            ni = i + 1, nj = 1;
          else
            ni = i, nj = j + 1;
          if (dfs(ni, nj, cnt + 1))
            return true;
          map[i][j] = 0;
        }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // Answer: 3 0 1 3 3 -1 -1 2
  int tc = 8;
  for (; tc--;) {
    map.assign(31, ve<int>(11));
    add_cnt = 1;

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      map[a][b] = 1;
    }

    int candi_cnt = 0;
    for (int i = 1; i <= h; i++)
      for (int j = 1; j < n; j++)
        if (!map[i][j] && ((j - 1 < 1) || !map[i][j - 1]) && ((j + 1 >= n) || !map[i][j + 1]))
          candi_cnt++;

    if (m == 0 || down_ladder()) {
      cout << 0;
    } else if (candi_cnt == 0)
      cout << -1;
    else {
      for (; add_cnt <= 3; add_cnt++) {
        if (dfs(1, 1, 0))
          break;
      }
      if (add_cnt == 4)
        cout << -1;
      else
        cout << add_cnt;
    }
    cout << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}