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
using pss = pair<short, short>;

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
vector<short> root(1001);
vector<vector<short>> map(1001, vector<short>(1001, 0));
vector<vector<bool>> vertex(1001, vector<bool>(1001, false));

int find(int x) {
  if (x == root[x])
    return x;
  else
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  root[y] = x;
}

void bfs(pss now) {
  queue<pss> q;
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    int i = now.first, j = now.second, uid = find(map[i][j]);
    for (int k = 0; k < 4; k++) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni >= 0 && ni <= 1000 && nj >= 0 && nj <= 1000 && uid == find(map[ni][nj]) && !vertex[ni][nj]) {
        vertex[ni][nj] = true;
        q.push({ni, nj});
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
    int n, ans = 1, cnt = 1;
    cin >> n;

    for (int i = 1; i <= 1000; i++)
      root[i] = i;

    int a, b, c, d;
    for (int i = 1; i <= n; i++) {
      cin >> a >> b >> c >> d;
      for (int j = a; j <= c; j++) {
        if (j == 0 && (b == 0 || d == 0))
          ans = 0;
        short &pa = map[j + 500][b + 500], &pb = map[j + 500][d + 500];
        if (!pa)
          pa = i;
        else
          merge(pa, i);
        if (!pb)
          pb = i;
        else
          merge(pb, i);
      }
      for (int j = b; j <= d; j++) {
        if (j == 0 && (a == 0 || c == 0))
          ans = 0;
        short &pc = map[a + 500][j + 500], &pd = map[c + 500][j + 500];
        if (!pc)
          pc = i;
        else
          merge(pc, i);
        if (!pd)
          pd = i;
        else
          merge(pd, i);
      }
    }

    for (int i = 0; i <= 1000; i++)
      for (int j = 0; j <= 1000; j++)
        if (map[i][j] > 0 && !vertex[i][j]) {
          vertex[i][j] = true;
          bfs({i, j});
          cnt++;
        }

    cout << ans + cnt - 2;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}