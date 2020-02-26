#include <algorithm>
#include <array>
#include <cstring>
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
ve<int> chk_fall(2);
ve<pii> movement(2);
ve<string> map(11);
int chk[11][11][11][11];

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // Answer: 1 1 1 0 1 1 0 0
  int tc = 1;
  while (tc--) {
    int chk_success = 0;
    chk_fall.assign(2, 0);
    memset(chk, 0, 4 * 11 * 11 * 11 * 11);
    ai3 r, b;
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

    queue<pair<ai3, ai3>> q;
    chk[r[0]][r[1]][b[0]][b[1]] = 1;
    q.push({r, b});

    // 거리 조정
    for (int p = 0; p < 10; p++) {
      int qs = q.size();
      for (int l = 0; l < qs; l++) {
        pair<ai3, ai3> curr = q.front();
        q.pop();

        r = curr.first, b = curr.second;
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
          if (chk_fall[0] && !chk_fall[1]) {
            cout << 1 << '\n';
            chk_success = 1;
            goto tc;
            // return 0;
          } else if (chk_fall[1])
            chk_fall.assign(2, 0);
          else { // 둘 다 안 떨어진 경우
            ai3 nr = {r[0] + movement[0].fi, r[1] + movement[0].se, 0},
                nb = {b[0] + movement[1].fi, b[1] + movement[1].se, 1};
            if (!chk[nr[0]][nr[1]][nb[0]][nb[1]]) {
              chk[nr[0]][nr[1]][nb[0]][nb[1]] = 1;
              q.push({nr, nb});
            }
          }
        }
      }
    }
  tc:
    if (!chk_success)
      cout << 0 << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}