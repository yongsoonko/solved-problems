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

int di[5] = {0, 0, 0, 1, -1}, dj[5] = {0, 1, -1, 0, 0};
int M, N, si, sj, sd, ei, ej, ed;
int map[101][101];
int chk[101][101][5];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> M >> N;
  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= N; j++)
      cin >> map[i][j];

  cin >> si >> sj >> sd >> ei >> ej >> ed;

  queue<Pos> q;
  chk[si][sj][sd] = 1;
  q.push({si, sj, sd});

  int ans = 0;
  while (!q.empty()) {
    if (chk[ei][ej][ed])
      break;
    int qs = q.size();
    for (int i = 0; i < qs; i++) {
      Pos curr = q.front();
      q.pop();

      int ci = curr.i, cj = curr.j, dir = curr.k, len = 0;
      if (dir == 1 || dir == 2) {
        if (!chk[ci][cj][3]) {
          chk[ci][cj][3] = 1;
          q.push({ci, cj, 3});
        }
        if (!chk[ci][cj][4]) {
          chk[ci][cj][4] = 1;
          q.push({ci, cj, 4});
        }
      } else if (dir == 3 || dir == 4) {
        if (!chk[ci][cj][1]) {
          chk[ci][cj][1] = 1;
          q.push({ci, cj, 1});
        }
        if (!chk[ci][cj][2]) {
          chk[ci][cj][2] = 1;
          q.push({ci, cj, 2});
        }
      }
      for (int i = 1; i <= 3; i++) {
        int ni = ci + di[dir] * i, nj = cj + dj[dir] * i;
        if (ni >= 1 && ni <= M && nj >= 1 && nj <= N)
          if (map[ni][nj] == 0)
            len = i;
          else
            break;
      }
      for (int i = 1; i <= len; i++) {
        int ni = ci + di[dir] * i, nj = cj + dj[dir] * i;
        if (!chk[ni][nj][dir]) {
          chk[ni][nj][dir] = 1;
          q.push({ni, nj, dir});
        }
      }
    }
    ans++;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}