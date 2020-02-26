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
int N, M, ans = 1e9;
int map[51][51];
int chk[51][51];
Pos spot[11];
vector<Pos> emp, vir;

void dfs(int cnt, int curr) {
  if (cnt == M) {
    fill(&chk[0][0], &chk[N - 1][N], 0);
    int emp_size = emp.size();
    queue<Pos> q;
    Pos curr;
    for (int i = 0; i < M; i++) {
      curr = spot[i];
      chk[curr.i][curr.j] = 1;
      q.push(curr);
    }

    int sec = 0, spread = 0;
    if (emp_size == spread) {
      ans = min(ans, sec);
      return;
    }
    while (!q.empty()) {
      int qs = q.size();
      for (int i = 0; i < qs; i++) {
        curr = q.front();
        q.pop();

        int ci = curr.i, cj = curr.j;
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < N && nj >= 0 && nj < N && !chk[ni][nj] && (map[ni][nj] == 0 || map[ni][nj] == 2)) {
            if (map[ni][nj] == 0)
              spread++;
            chk[ni][nj] = 1;
            q.push({ni, nj});
          }
        }
      }
      sec++;
      if (emp_size == spread) {
        ans = min(ans, sec);
        break;
      }
    }
  } else {
    for (int i = curr; i < vir.size(); i++) {
      spot[cnt] = vir[i];
      dfs(cnt + 1, i + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // Answer: 2 2 2 3 1 0 4 4 4 3 7 -1 0
  int tc = 1;
  while (tc--) {
    vector<Pos>().swap(emp);
    vector<Pos>().swap(vir);
    ans = 1e9;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        cin >> map[i][j];
        if (map[i][j] == 0)
          emp.push_back({i, j});
        else if (map[i][j] == 2)
          vir.push_back({i, j});
      }

    dfs(0, 0);

    if (ans == 1e9)
      cout << -1 << ' ';
    else
      cout << ans << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}