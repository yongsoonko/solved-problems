#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>
#include <cstring>

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

bool chk_out(int ci, int cj) {
  return ci >= 1 && ci <= N && cj >= 1 && cj <= N;
}

bool bfs(int ci, int cj) {
  chk[ci][cj] = 1;
  queue<Pos> q, qq;
  q.push({ci, cj});
  qq.push({ci, cj});
  int sum = 0, cnt = 0, avg, flag = 0;

  while (q.size()) {
    ci = q.front().i, cj = q.front().j;
    q.pop();
    sum += map[ci][cj];
    cnt++;

    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      int diff;
      if (chk_out(ni, nj) && !chk[ni][nj] && (diff = abs(map[ci][cj] - map[ni][nj])) >= L && diff <= R) {
        flag = 1;
        chk[ni][nj] = 1;
        q.push({ni, nj});
        qq.push({ni, nj});
      }
    }
  }
  avg = sum / cnt;
  while (qq.size()) {
    ci = qq.front().i, cj = qq.front().j;
    qq.pop();
    map[ci][cj] = avg;
  }
  return flag;
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
    int cnt = 0;
    for (; cnt <= 2000; cnt++) {
      int flag = 0;
      fill(&chk[1][1], &chk[N][N + 1], 0);
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
          if (!chk[i][j]) {
            if (bfs(i, j))
              flag = 1;
          }
      if (!flag)
        break;
    }
    cout << cnt << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}