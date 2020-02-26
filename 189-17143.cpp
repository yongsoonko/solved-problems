#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int s;
  int d;
  int z;
  int chk;

  bool operator<(const Pos &p) const {
    return z > p.z;
  }
};

int di[5] = {0, -1, 1, 0, 0},
    dj[5] = {0, 0, 0, 1, -1};
vector<Pos> map[102][102];
int R, C, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // Answer: 22 0 22 4
  int tc = 4;
  while (tc--) {
    cin >> R >> C >> M;
    for (int i = 1; i <= R; i++)
      for (int j = 1; j <= C; j++)
        vector<Pos>().swap(map[i][j]);

    for (int i = 0; i < M; i++) {
      int r, c, s, d, z;
      cin >> r >> c >> s >> d >> z;
      map[r][c].push_back({s, d, z});
    }

    int ans = 0;
    for (int j = 1; j <= C; j++) {

      for (int i = 1; i <= R; i++)
        if (map[i][j].size()) {
          // cout << j << ' ' << map[i][j].back().z << '\n';
          ans += map[i][j].back().z;
          map[i][j].pop_back();
          break;
        }

      for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
          if (map[i][j].size()) {
            auto it = map[i][j].begin();
            for (int k = 0; k < map[i][j].size();) {
              Pos p = map[i][j][k];
              if (p.chk) {
                k++;
                continue;
              }
              int ci = i, cj = j, ni, nj, s;
              if (p.d == 1 || p.d == 2)
                s = p.s % (2 * R - 2);
              else
                s = p.s % (2 * C - 2);
              for (int k = 0; k < s; k++) {
                ni = ci + di[p.d], nj = cj + dj[p.d];
                if (ni < 1) {
                  ni = 2;
                  p.d = 2;
                } else if (ni > R) {
                  ni = R - 1;
                  p.d = 1;
                }
                if (nj < 1) {
                  nj = 2;
                  p.d = 3;
                } else if (nj > C) {
                  nj = C - 1;
                  p.d = 4;
                }
                ci = ni, cj = nj;
              }
              p.chk = 1;
              if (i == ci && j == cj) {
                map[i][j][k] = p;
                k++;
              } else {
                map[ci][cj].push_back(p);
                map[i][j].erase(it + k);
              }
            }
          }
        }
      for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
          if (map[i][j].size()) {
            sort(map[i][j].begin(), map[i][j].end());
            map[i][j].erase(map[i][j].begin() + 1, map[i][j].end());
            map[i][j][0].chk = 0;
          }
    }
    cout << ans << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}