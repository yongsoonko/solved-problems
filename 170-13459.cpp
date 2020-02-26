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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int n, m;
ai3 r, b;
ve<int> chk_fall(2);
ve<pii> movement(2);
ve<string> map(11);

void move(ai3 fi_move, ai3 se_move, int d) {
  int ci = fi_move[0], cj = fi_move[1], k = fi_move[2];
  while (map[ci + di[d]][cj + dj[d]] == '.')
    ci += di[d], cj += dj[d];

  if (map[ci + di[d]][cj + dj[d]] == 'O') {
    ci += di[d], cj += dj[d];
    chk_fall[k] = 1;
  }

  movement[k] = {ci - fi_move[0], cj - fi_move[1]};

  int gi = se_move[0], gj = se_move[1];
  k = se_move[2];
  while (map[gi + di[d]][gj + dj[d]] == '.') {
    if (gi + di[d] == ci && gj + dj[d] == cj)
      break;
    gi += di[d], gj += dj[d];
  }

  if (map[gi + di[d]][gj + dj[d]] == 'O')
    chk_fall[k] = 1;

  movement[k] = {gi - se_move[0], gj - se_move[1]};
}

bool dfs(int cnt) {
  if (cnt == 10)
    return false;
  else {
    ai3 sr = r, sb = b;
    for (int i = 0; i < 4; i++) {
      if (i == 0)
        if (r[0] < b[0])
          move(r, b, i);
        else
          move(b, r, i);
      else if (i == 1)
        if (r[1] > b[1])
          move(r, b, i);
        else
          move(b, r, i);
      else if (i == 2)
        if (r[0] > b[0])
          move(r, b, i);
        else
          move(b, r, i);
      else if (i == 3)
        if (r[1] < b[1])
          move(r, b, i);
        else
          move(b, r, i);
      if (chk_fall[0] && !chk_fall[1])
        return true;
      else if (chk_fall[1])
        chk_fall.assign(2, 0);
      else { // 둘 다 안 떨어진 경우
        r[0] += movement[0].fi, r[1] += movement[0].se;
        b[0] += movement[1].fi, b[1] += movement[1].se;
        if (dfs(cnt + 1))
          return true;
        r = sr, b = sb;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // Answer: 1 1 1 0 1 1 0 0
  int tc = 1;
  while (tc--) {
    chk_fall.assign(2, 0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> map[i];
      for (int j = 0; j < m; j++) {
        if (map[i][j] == 'R') {
          r = {i, j, 0};
          map[i][j] = '.';
        } else if (map[i][j] == 'B') {
          b = {i, j, 1};
          map[i][j] = '.';
        }
      }
    }

    if (dfs(0))
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}