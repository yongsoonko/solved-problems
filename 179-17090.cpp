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
int N, M, ans;
string map[501];
int chk[501][501];
int mark[501][501];

int dfs(int ci, int cj) {
  if (ci < 0 || ci >= N || cj < 0 || cj >= M)
    return 1;
  else if (chk[ci][cj])
    return 2;
  else if (mark[ci][cj] == 1 || mark[ci][cj] == 2)
    return mark[ci][cj];
  else {
    char d = map[ci][cj];
    int ni, nj, res;
    if (d == 'U') {
      ni = ci - 1, nj = cj;
      chk[ci][cj] = 1;
      mark[ci][cj] = dfs(ni, nj);
      chk[ci][cj] = 0;
    } else if (d == 'R') {
      ni = ci, nj = cj + 1;
      chk[ci][cj] = 1;
      mark[ni][cj] = dfs(ni, nj);
      chk[ci][cj] = 0;
    } else if (d == 'D') {
      ni = ci + 1, nj = cj;
      chk[ci][cj] = 1;
      mark[ci][cj] = dfs(ni, nj);
      chk[ci][cj] = 0;
    } else {
      ni = ci, nj = cj - 1;
      chk[ci][cj] = 1;
      mark[ci][cj] = dfs(ni, nj);
      chk[ci][cj] = 0;
    }
    return mark[ci][cj];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> map[i];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (dfs(i, j) == 1)
        ans++;

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}