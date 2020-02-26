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
int N, M;
int map[301][301], diff[301][301];
int chk[301][301];

bool chk_range(int ci, int cj) {
  return ci >= 0 && ci < N && cj >= 0 && cj < M;
}

void dfs(int ci, int cj) {
  chk[ci][cj] = 1;
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (chk_range(ni, nj) && map[ni][nj] > 0 && !chk[ni][nj])
      dfs(ni, nj);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> map[i][j];

  int ans = 0, ans_flag = 0;
  while (1) {
    int min_year = 1e9;
    int out_flag = 1, once = 1;

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (map[i][j] > 0) {
          out_flag = 0;
          int water = 0;
          for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (chk_range(ni, nj) && map[ni][nj] == 0)
              water++;
          }
          if (water == 0)
            continue;
          if (map[i][j] < water) {
            diff[i][j] = map[i][j];
            min_year = 1;
          } else {
            diff[i][j] = water;
            min_year = min(min_year, map[i][j] / water);
          }
        }

    if (out_flag)
      break;

    // for (int i = 0; i < N; i++) {
    //   for (int j = 0; j < M; j++)
    //     cout << map[i][j] << ' ';
    //   cout << '\n';
    // }
    // cout << '\n';

    fill(&chk[0][0], &chk[N - 1][M], 0);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (map[i][j] > 0 && !chk[i][j]) {
          if (once) {
            dfs(i, j);
            once = 0;
          } else
            ans_flag = 1;
        }
    if (ans_flag)
      break;

    ans += min_year;
    // ans++;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (diff[i][j] > 0) {
          map[i][j] -= min_year * diff[i][j];
          diff[i][j] = 0;
        }
  }

  if (ans_flag)
    cout << ans << '\n';
  else
    cout << 0 << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}