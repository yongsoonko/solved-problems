#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int N, M, ci, cj, cd, ni, nj, nd, ans;
int map[51][51];
int chk[51][51];

bool chk_out(int ci, int cj) {
  return ci >= 0 && ci < N && cj >= 0 && cj < M;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> ci >> cj >> cd;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> map[i][j];

  while (1) {
  out:
    if (!chk[ci][cj]) {
      chk[ci][cj] = 1;
      ans++;
    }
    for (int i = 0; i < 4; i++) {
      nd = (cd + 4 - 1) % 4;
      ni = ci + di[nd], nj = cj + dj[nd];
      if (chk_out(ni, nj) && map[ni][nj] == 0 && !chk[ni][nj]) {
        ci = ni, cj = nj, cd = nd;
        goto out;
      } else
        cd = nd;
    }
    ni = ci - di[cd], nj = cj - dj[cd];
    if (chk_out(ni, nj) && map[ni][nj] == 0)
      ci = ni, cj = nj;
    else {
      cout << ans << '\n';
      return 0;
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}