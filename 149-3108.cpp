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
vector<vector<int>> map(2001, vector<int>(2001, -1));
int cnt = 1;

void bfs(pii now) {
  queue<pii> q;
  q.push(now);

  while (!q.empty()) {
    now = q.front();
    q.pop();

    int i = now.first, j = now.second;
    for (int k = 0; k < 4; k++) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni >= 0 && ni <= 2000 && nj >= 0 && nj <= 2000 && map[ni][nj] == 0) {
        map[ni][nj] = cnt;
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
    int n, ans = 1;
    cin >> n;

    int a, b, c, d;
    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c >> d;
      for (int j = a * 2; j <= c * 2; j++) {
        if (j == 0 && (b == 0 || d == 0))
          ans = 0;
        map[j + 1000][b * 2 + 1000] = 0;
        map[j + 1000][d * 2 + 1000] = 0;
      }
      for (int j = b * 2; j <= d * 2; j++) {
        if (j == 0 && (a == 0 || c == 0))
          ans = 0;
        map[a * 2 + 1000][j + 1000] = 0;
        map[c * 2 + 1000][j + 1000] = 0;
      }
    }

    for (int i = 0; i <= 2000; i++)
      for (int j = 0; j <= 2000; j++)
        if (map[i][j] == 0) {
          map[i][j] = cnt;
          bfs({i, j});
          cnt++;
        }

    // for (auto a : map) {
    //   for (int i : a) {
    //     if (i == -1)
    //       cout << "■";
    //     else
    //       cout << i;
    //   }
    //   cout << '\n';
    // }

    cout << ans + cnt - 2;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}