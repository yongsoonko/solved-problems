#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int s;
  int d;
  int z;
};

int di[5] = {0, -1, 1, 0, 0},
    dj[5] = {0, 0, 0, 1, -1};
int R, C, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // Answer: 22 0 22 4
  int tc = 1;
  while (tc--) {
    cin >> R >> C >> M;
    vector<vector<Pos>> init(R + 1, vector<Pos>(C + 1, {0, 0, 0}));
    vector<vector<Pos>> map = init, map2 = init;

    int r2 = 2 * R - 2, c2 = 2 * C - 2;
    for (int i = 0; i < M; i++) {
      int r, c, s, d, z;
      cin >> r >> c >> s >> d >> z;
      if (d <= 2)
        map[r][c] = {s %= r2, d, z};
      else
        map[r][c] = {s %= c2, d, z};
    }

    int ans = 0;
    for (int j = 1; j <= C; j++) {

      for (int i = 1; i <= R; i++)
        if (map[i][j].z) {
          ans += map[i][j].z;
          map[i][j].z = 0;
          break;
        }

      for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
          if (map[i][j].z) {
            Pos p = map[i][j];
            int ci = i, cj = j, ni, nj, s;
            for (int k = 0; k < p.s; k++) {
              ni = ci + di[p.d], nj = cj + dj[p.d];
              if (ni < 1) {
                ni = 2;
                p.d = 2;
              } else if (ni > R) {
                ni = R - 1;
                p.d = 1;
              }
              if (nj < 1) {
                nj = 2;
                p.d = 3;
              } else if (nj > C) {
                nj = C - 1;
                p.d = 4;
              }
              ci = ni, cj = nj;
            }
            if (map2[ci][cj].z < map[i][j].z)
              map2[ci][cj] = p;
          }
        }

      map = map2;
      map2 = init;
    }
    cout << ans << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}