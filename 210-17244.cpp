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
string map[51];
int dist[51][51][51][51];
int chk[51][51];
Pos S, E;
vector<Pos> X;

void bfs(int si, int sj) {
  fill(&chk[0][0], &chk[N - 1][M], 0);
  chk[si][sj] = 1;
  queue<Pos> q;
  q.push({si, sj});

  int cnt = 1, chk_cnt = 0;
  while (q.size()) {
    for (int qs = q.size(); qs--;) {
      Pos curr = q.front();
      q.pop();

      int ci = curr.i, cj = curr.j;
      for (int i = 0; i < 4; i++) {
        int ni = ci + di[i], nj = cj + dj[i];
        if (ni >= 0 && ni < N && nj >= 0 && nj < M && !chk[ni][nj] && map[ni][nj] != '#') {
          chk[ni][nj] = 1;
          if (map[ni][nj] == 'S' || map[ni][nj] == 'X' || map[ni][nj] == 'E') {
            dist[si][sj][ni][nj] = min(dist[si][sj][ni][nj], cnt);
            chk_cnt++;
            if (chk_cnt == X.size() + 1)
              return;
          }
          q.push({ni, nj});
        }
      }
    }
    cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  fill(&dist[0][0][0][0], &dist[50][50][50][51], 1e9);

  int cnt = 0;
  cin >> M >> N;
  for (int i = 0; i < N; i++) {
    cin >> map[i];
    for (int j = 0; j < M; j++) {
      if (map[i][j] == 'S' || map[i][j] == 'X' || map[i][j] == 'E') {
        dist[i][j][i][j] = 0;
        if (map[i][j] == 'S')
          S = {i, j};
        else if (map[i][j] == 'E')
          E = {i, j};
        else
          X.push_back({i, j});
      }
    }
  }

  bfs(S.i, S.j);
  if (X.size() == 0) {
    cout << dist[S.i][S.j][E.i][E.j] << '\n';
    return 0;
  }

  for (Pos p : X)
    bfs(p.i, p.j);

  int seq[10];
  for (int i = 0; i < X.size(); i++)
    seq[i] = i;

  int ans = 1e9;
  do {
    int add = dist[S.i][S.j][X[seq[0]].i][X[seq[0]].j], i;
    for (i = 0; i < X.size() - 1; i++)
      add += dist[X[seq[i]].i][X[seq[i]].j][X[seq[i + 1]].i][X[seq[i + 1]].j];
    add += dist[X[seq[i]].i][X[seq[i]].j][E.i][E.j];
    ans = min(ans, add);
  } while (next_permutation(seq, seq + X.size()));

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}