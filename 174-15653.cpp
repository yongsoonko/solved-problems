#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

#define fi first
#define se second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

struct Ball {
  int i;
  int j;
  int k;

  Ball operator+(const Ball &other) {
    return Ball{i + other.i, j + other.j, k};
  }
};

int N, M;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
string map[11];
int chk[10000];
int chk_fall[2];

Ball move_ball(Ball b, int d) {
  Ball res = {0, 0};
  while (map[b.i + di[d]][b.j + dj[d]] == '.') {
    b.i += di[d], b.j += dj[d];
    res.i += di[d], res.j += dj[d];
  }

  if (map[b.i + di[d]][b.j + dj[d]] == 'O') {
    b.i += di[d], b.j += dj[d];
    res.i += di[d], res.j += dj[d];
    chk_fall[b.k] = 1;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    fill(chk_fall, chk_fall + 2, 0);
    fill(chk, chk + 10000, 0);

    Ball cr, cb;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      cin >> map[i];
      for (int j = 0; j < M; j++) {
        if (map[i][j] == 'R') {
          cr.i = i, cr.j = j, cr.k = 0;
          map[i][j] = '.';
        } else if (map[i][j] == 'B') {
          cb.i = i, cb.j = j, cb.k = 1;
          map[i][j] = '.';
        }
      }
    }

    int curr = cr.i * 1000 + cr.j * 100 + cb.i * 10 + cb.j;
    chk[curr] = 1;
    queue<int> q;
    q.push(curr);

    int prev_lv = 1, next_lv = 0, cnt = 1, flag = 0;
    while (!q.empty()) {
      curr = q.front();
      q.pop();
      prev_lv--;

      cr = {curr / 1000, curr % 1000 / 100, 0}, cb = {curr % 100 / 10, curr % 10, 1};
      for (int i = 0; i < 4; i++) {
        Ball mr = move_ball(cr, i);
        Ball mb = move_ball(cb, i);

        Ball nr = cr + mr, nb = cb + mb;
        if (chk_fall[0] && !chk_fall[1]) {
          flag = 1;
          goto out;
        } else if (chk_fall[1]) {
          chk_fall[0] = chk_fall[1] = 0;
          continue;
        } else {
          if (nr.i == nb.i && nr.j == nb.j) {
            if (i == 0) {
              if (cr.i < cb.i)
                nb.i++;
              else
                nr.i++;
            } else if (i == 1) {
              if (cr.j < cb.j)
                nr.j--;
              else
                nb.j--;
            } else if (i == 2) {
              if (cr.i < cb.i)
                nr.i--;
              else
                nb.i--;
            } else {
              if (cr.j < cb.j)
                nb.j++;
              else
                nr.j++;
            }
          }
        }
        int next = nr.i * 1000 + nr.j * 100 + nb.i * 10 + nb.j;
        if (!chk[next]) {
          chk[next] = 1;
          q.push(next);
          next_lv++;
        }
      }
      if (!prev_lv) {
        prev_lv = next_lv;
        next_lv = 0;
        cnt++;
      }
    }

  out:
    if (flag)
      cout << cnt << '\n';
    else
      cout << -1 << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}