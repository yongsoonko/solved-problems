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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int N, M, si, sj, ei, ej;
int map[1001][1001];
int chk[1001][1001][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M >> si >> sj >> ei >> ej;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      cin >> map[i][j];

  queue<Pos> q;
  chk[si][sj][0] = 1;
  q.push({si, sj, 0});

  int cnt = 0, flag = 0;
  while (!q.empty()) {
    int qs = q.size();
    for (int i = 0; i < qs; i++) {
      Pos curr = q.front();
      q.pop();

      int ci = curr.i, cj = curr.j;
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 1 && ni <= N && nj >= 1 && nj <= M) {
          if (curr.k == 1) {
            if (map[ni][nj] == 1 || chk[ni][nj][1] || chk[ni][nj][0])
              continue;
            else {
              chk[ni][nj][1] = 1;
              q.push({ni, nj, 1});
            }
          } else {
            Pos p;
            if (!chk[ni][nj][0]) {
              p.i = ni, p.j = nj, p.k = 0;
              if (map[ni][nj] == 1)
                p.k = 1;
              chk[ni][nj][p.k] = 1;
              q.push(p);
            }
          }
        }
      }
    }
    cnt++;
    if (chk[ei][ej][0] || chk[ei][ej][1]) {
      flag = 1;
      break;
    }
  }

  if (flag)
    cout << cnt;
  else
    cout << -1;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}