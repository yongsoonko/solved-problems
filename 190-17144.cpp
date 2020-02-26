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

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};
int R, C, T;
int map[51][51];
int add[51][51];
Pos air;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    // Answer: 188 188 186 178 172 71 52 46
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++) {
        cin >> map[i][j];
        if (map[i][j] == -1 && air.i == 0)
          air = {i, j};
      }

    while (T--) {

      for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
          if (map[i][j] >= 0)
            add[i][j] = map[i][j] / 5;

      for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
          int ci = i, cj = j;
          for (int k = 0; k < 4; k++) {
            int ni = ci + di[k], nj = cj + dj[k];
            if (ni >= 0 && ni < R && nj >= 0 && nj < C && map[ni][nj] != -1) {
              map[i][j] -= add[i][j];
              map[ni][nj] += add[i][j];
            }
          }
        }

      for (int i = air.i - 1; i >= 1; i--)
        map[i][0] = map[i - 1][0];
      for (int j = 0; j <= C - 2; j++)
        map[0][j] = map[0][j + 1];
      for (int i = 0; i <= air.i - 1; i++)
        map[i][C - 1] = map[i + 1][C - 1];
      for (int j = C - 1; j >= 2; j--)
        map[air.i][j] = map[air.i][j - 1];
      map[air.i][1] = 0;

      for (int i = air.i + 2; i <= R - 2; i++)
        map[i][0] = map[i + 1][0];
      for (int j = 0; j <= C - 2; j++)
        map[R - 1][j] = map[R - 1][j + 1];
      for (int i = R - 1; i >= air.i + 2; i--)
        map[i][C - 1] = map[i - 1][C - 1];
      for (int j = C - 1; j >= 2; j--)
        map[air.i + 1][j] = map[air.i + 1][j - 1];
      map[air.i + 1][1] = 0;
    }

    int ans = 0;
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        if (map[i][j] > 0)
          ans += map[i][j];

    cout << ans << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}