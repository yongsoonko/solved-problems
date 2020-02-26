#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

#define fi first
#define se second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

struct Pos {
  int i;
  int j;
};

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int N, M, ans;
int map[8][8];
int chk[8][8];
vector<Pos> emp, vir;
Pos wall[3];

void dfs(int cnt, int curr) {
  if (cnt == 3) {
    for (int i = 0; i < 3; i++) {
      Pos p = wall[i];
      map[p.i][p.j] = 1;
    }

    int emp_size = emp.size() - 3;
    int spread = 0;
    fill(&chk[0][0], &chk[N - 1][M], 0);
    for (int i = 0; i < vir.size(); i++) {
      queue<Pos> q;
      Pos curr = vir[i];
      chk[curr.i][curr.j] = 1;
      q.push(curr);

      while (!q.empty()) {
        curr = q.front();
        q.pop();

        int ci = curr.i, cj = curr.j;
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < N && nj >= 0 && nj < M && !chk[ni][nj] && map[ni][nj] == 0) {
            spread++;
            if (ans >= emp_size - spread)
              goto out;
            chk[ni][nj] = 1;
            q.push({ni, nj});
          }
        }
      }
    }
    ans = max(ans, emp_size - spread);
  out:

    for (int i = 0; i < 3; i++) {
      Pos p = wall[i];
      map[p.i][p.j] = 0;
    }
    return;
  } else {
    for (int i = curr; i < emp.size(); i++) {
      wall[cnt] = emp[i];
      dfs(cnt + 1, i + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
      if (map[i][j] == 0)
        emp.push_back({i, j});
      else if (map[i][j] == 2)
        vir.push_back({i, j});
    }

  dfs(0, 0);
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}