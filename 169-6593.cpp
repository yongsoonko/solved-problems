#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

#define ve vector
#define fi first
#define se second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

int di[6] = {-1, 0, 1, 0, 0, 0}, dj[6] = {0, 1, 0, -1, 0, 0}, dk[6] = {0, 0, 0, 0, 1, -1};
int l, r, c, si, sj, sk;
ve<ve<string>> map(31, ve<string>(31));
ve<ve<ve<int>>> dist;
ve<ai3> end_list;

void bfs() {
  queue<ai3> q;
  map[sk][si][sj] = '#';
  q.push({si, sj, sk});

  while (!q.empty()) {
    ai3 curr = q.front();
    q.pop();

    int ci = curr[0], cj = curr[1], ck = curr[2];
    for (int p = 0; p < 6; p++) {
      int ni = ci + di[p], nj = cj + dj[p], nk = ck + dk[p];
      if (ni >= 0 && ni < r && nj >= 0 && nj < c && nk >= 0 && nk < l && map[nk][ni][nj] != '#') {
        map[nk][ni][nj] = '#';
        q.push({ni, nj, nk});
        dist[nk][ni][nj] = dist[ck][ci][cj] + 1;
      }
    }
    for (ai3 end : end_list)
      if (dist[end[2]][end[0]][end[1]] < 1e9) {
        // while (!q.empty())
        //   q.pop();
        break;
      }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
    cin >> l >> r >> c;
    if (l == 0 && r == 0 && c == 0)
      break;

    dist.assign(l, ve<ve<int>>(r, ve<int>(c, 1e9)));
    ve<ai3>().swap(end_list);

    for (int k = 0; k < l; k++)
      for (int i = 0; i < r; i++) {
        cin >> map[k][i];
        for (int j = 0; j < c; j++) {
          if (map[k][i][j] == 'S')
            si = i, sj = j, sk = k;
          else if (map[k][i][j] == 'E')
            end_list.push_back({i, j, k});
        }
      }

    dist[sk][si][sj] = 0;
    bfs();
    int chk_arrive = 0;
    for (ai3 end : end_list)
      if (dist[end[2]][end[0]][end[1]] < 1e9) {
        cout << "Escaped in " << dist[end[2]][end[0]][end[1]] << " minute(s).\n";
        chk_arrive = 1;
        break;
      }
    if (!chk_arrive)
      cout << "Trapped!\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}