#include <algorithm>
#include <cmath>
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
int N, M;
string map[21];
int chk[21][21][1024];
Pos vac;
vector<Pos> dirty_list;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
    fill(&chk[0][0][0], &chk[20][20][1024], 0);
    vector<Pos>().swap(dirty_list);

    cin >> M >> N;
    if (M == 0 && N == 0)
      break;
    for (int i = 0; i < N; i++) {
      cin >> map[i];
      for (int j = 0; j < M; j++)
        if (map[i][j] == 'o') {
          vac = {i, j, 0};
          map[i][j] = '.';
        } else if (map[i][j] == '*')
          dirty_list.push_back({i, j});
    }

    queue<Pos> q;
    chk[vac.i][vac.j][vac.k] = 1;
    q.push(vac);

    int end = pow(2, dirty_list.size()) - 1;
    int ans = 0, flag = 0;

    while (q.size()) {
      if (dirty_list.size() == 0 || flag)
        break;
      int qs = q.size();
      for (int i = 0; i < qs; i++) {
        Pos curr = q.front();
        q.pop();

        int ci = curr.i, cj = curr.j, ck = curr.k;
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
            if (map[ni][nj] == '.') {
              if (!chk[ni][nj][ck]) {
                chk[ni][nj][ck] = 1;
                q.push({ni, nj, ck});
              }
            } else if (map[ni][nj] == '*') {
              int j = 0;
              for (; j < dirty_list.size(); j++) {
                if (dirty_list[j].i == ni && dirty_list[j].j == nj)
                  break;
              }
              if (!((1 << j) & ck)) {
                int nk = ck + (1 << j);
                if (nk == end)
                  flag = 1;
                chk[ni][nj][nk] = 1;
                q.push({ni, nj, nk});
              } else if (!chk[ni][nj][ck]) {
                chk[ni][nj][ck] = 1;
                q.push({ni, nj, ck});
              }
            }
          }
        }
      }
      ans++;
    }
    if (dirty_list.size() == 0)
      cout << 0 << '\n';
    else if (flag)
      cout << ans << '\n';
    else
      cout << -1 << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}