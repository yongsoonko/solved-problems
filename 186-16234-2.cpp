#include <algorithm>
#include <cstring>
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
int N, L, R;
int map[51][51];
int chk[51][51];
int chk2[51][51];
int open[51][51][4];
int sum, cnt, flag;

bool chk_out(int ci, int cj) {
  return ci >= 1 && ci <= N && cj >= 1 && cj <= N;
}

void dfs(int ci, int cj) {
  chk[ci][cj] = 1;
  sum += map[ci][cj];
  cnt++;
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (chk_out(ni, nj) && open[ci][cj][i] && !chk[ni][nj])
      dfs(ni, nj);
  }
}

void dfs2(int ci, int cj, int avg) {
  chk2[ci][cj] = 1;
  if (map[ci][cj] != avg)
    flag = 1;
  map[ci][cj] = avg;
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (chk_out(ni, nj) && open[ci][cj][i] && !chk2[ni][nj])
      dfs2(ni, nj, avg);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        cin >> map[i][j];
    int ans = 0;
    for (; ans <= 2000; ans++) {
      fill(&open[1][1][0], &open[N][N][4], 0);
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
          for (int k = 1; k <= 2; k++) {
            int ni = i + di[k], nj = j + dj[k], diff;
            if (ni <= N && nj <= N && (diff = abs(map[i][j] - map[ni][nj])) >= L && diff <= R)
              open[i][j][k] = open[ni][nj][(k + 2) % 4] = 1;
          }
      fill(&chk[1][1], &chk[N][N + 1], 0);
      fill(&chk2[1][1], &chk2[N][N + 1], 0);
      flag = 0;
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
          if (!chk[i][j]) {
            sum = 0, cnt = 0;
            dfs(i, j);
            dfs2(i, j, sum / cnt);
          }
        }
      if (!flag)
        break;
    }
    cout << ans << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}