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
  int k;
};

int di[6] = {-1, 0, 1, 0, 0, 0},
    dj[6] = {0, 1, 0, -1, 0, 0},
    dk[6] = {0, 0, 0, 0, -1, 1};

int N, M, H;
int map[101][101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    cin >> M >> N >> H;
    queue<Pos> q;

    for (int k = 0; k < H; k++)
      for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
          cin >> map[k][i][j];
          if (map[k][i][j] == 1)
            q.push({i, j, k});
        }

    int ans = -1;
    while (q.size()) {
      for (int qs = q.size(); qs--;) {
        Pos curr = q.front();
        q.pop();
        int ci = curr.i, cj = curr.j, ck = curr.k;
        for (int i = 0; i < 6; i++) {
          int ni = ci + di[i], nj = cj + dj[i], nk = ck + dk[i];
          if (ni >= 0 && ni < N && nj >= 0 && nj < M && nk >= 0 && nk < H && map[nk][ni][nj] == 0) {
            map[nk][ni][nj] = 1;
            q.push({ni, nj, nk});
          }
        }
      }
      ans++;
    }

    int flag = 0;
    for (int k = 0; k < H; k++)
      for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
          if (map[k][i][j] == 0) {
            flag = 1;
            goto out;
          }
  out:

    if (flag)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}