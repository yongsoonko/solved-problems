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
int r, c, ans = 1;
char map[20][20];
bool vertex[26];

void dfs(int i, int j, int from, int cnt) {
  for (int k = 0; k < 4; k++) {
    if (k == from)
      continue;
    if (ans == 26)
      return;
    int ni = i + di[k], nj = j + dj[k];
    if (ni >= 0 && ni < r && nj >= 0 && nj < c && !vertex[map[ni][nj]]) {
      vertex[map[ni][nj]] = true;
      ans = max(ans, cnt + 1);
      dfs(ni, nj, (k + 2) % 4, cnt + 1);
      vertex[map[ni][nj]] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
      string str;
      cin >> str;
      for (int j = 0; j < c; j++)
        map[i][j] = str[j] - 'A';
    }

    vertex[map[0][0]] = true;
    dfs(0, 0, 0, 1);
    cout << ans;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}