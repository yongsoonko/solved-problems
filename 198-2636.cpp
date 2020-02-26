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
int N, M, ans, cnt;
int map[101][101];
int chk[101][101];
vector<Pos> v, v2;

void dfs(int ci, int cj) {
  chk[ci][cj] = 1;
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (ni >= 0 && ni < N && nj >= 0 && nj < M && !chk[ni][nj] && map[ni][nj] == 0)
      dfs(ni, nj);
  }
}

void dfs2(int ci, int cj) {
  chk[ci][cj] = 1;
  v2.push_back({ci, cj});
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i];
    if (ni >= 0 && ni < N && nj >= 0 && nj < M && !chk[ni][nj] && map[ni][nj] == 2)
      dfs2(ni, nj);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  //Answer: 0 0 / 1 5 / 1 6 / 1 3 / 3 5 / 1 8
  int tc = 1;
  while (tc--) {
    cin >> N >> M;
    ans = cnt = 0;
    fill(&chk[0][0], &chk[N - 1][M], 0);

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        cin >> map[i][j];

    // 내부의 빈 공간 표시
    dfs(0, 0);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (!chk[i][j] && map[i][j] == 0)
          map[i][j] = 2;

    while (1) {
      int flag = 1;
      for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
          if (map[i][j] == 1) {
            flag = 0;
            int once = 0;
            for (int k = 0; k < 4; k++) {
              int ni = i + di[k], nj = j + dj[k];
              if (ni >= 0 && ni < N && nj >= 0 && nj < M && map[ni][nj] == 0)
                once = 1;
            }
            if (once) {
              v.push_back({i, j});
              for (int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 && ni < N && nj >= 0 && nj < M && map[ni][nj] == 2 && !chk[ni][nj])
                  dfs2(ni, nj);
              }
            }
          }
      if (flag)
        break;
      ans++;
      cnt = v.size();

      while (v.size()) {
        map[v.back().i][v.back().j] = 0;
        v.pop_back();
      }
      while (v2.size()) {
        map[v2.back().i][v2.back().j] = 0;
        v2.pop_back();
      }
    }

    cout << ans << '\n'
         << cnt << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}