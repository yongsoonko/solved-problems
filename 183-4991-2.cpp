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
};

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int N, M;
string map[21];
int dist[11][11];
int chk[11][21][21];
vector<Pos> dirty_list;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  while (1) {
    fill(&dist[0][0], &dist[10][11], 1e9);
    fill(&chk[0][0][0], &chk[10][20][21], 0);
    vector<Pos>().swap(dirty_list);

    cin >> M >> N;
    if (M == 0 && N == 0)
      break;
    for (int i = 0; i < N; i++) {
      cin >> map[i];
      for (int j = 0; j < M; j++)
        if (map[i][j] == 'o') {
          dirty_list.insert(dirty_list.begin(), {i, j});
          map[i][j] = '.';
        } else if (map[i][j] == '*')
          dirty_list.push_back({i, j});
    }

    for (int i = 0; i < dirty_list.size(); i++) {
      Pos curr = dirty_list[i];
      int ci = curr.i, cj = curr.j;
      queue<Pos> q;
      chk[i][ci][cj] = 1;
      dist[i][i] = 0;
      q.push({ci, cj});

      int cnt = 1;
      while (q.size()) {
        for (int qs = q.size(); qs--;) {
          curr = q.front();
          q.pop();

          ci = curr.i, cj = curr.j;
          for (int j = 0; j < 4; j++) {
            int ni = ci + di[j], nj = cj + dj[j];
            if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
              if (map[ni][nj] == '.' && !chk[i][ni][nj]) {
                chk[i][ni][nj] = 1;
                q.push({ni, nj});
              } else if (map[ni][nj] == '*' && !chk[i][ni][nj]) {
                int k = 0;
                for (; k < dirty_list.size(); k++) {
                  if (dirty_list[k].i == ni && dirty_list[k].j == nj)
                    break;
                }
                dist[i][k] = cnt;
                chk[i][ni][nj] = 1;
                q.push({ni, nj});
              }
            }
          }
        }
        cnt++;
      }
    }

    int seq[dirty_list.size()];
    for (int i = 0; i < dirty_list.size() - 1; i++)
      seq[i] = i + 1;

    int ans = 1e9;
    do {
      int sum = dist[0][seq[0]], flag = 0;
      for (int i = 0; i < dirty_list.size() - 2; i++) {
        if (dist[seq[i]][seq[i + 1]] == 1e9) {
          flag = 1;
          break;
        }
        sum += dist[seq[i]][seq[i + 1]];
      }
      if (!flag)
        ans = min(ans, sum);
    } while (next_permutation(seq, seq + dirty_list.size() - 1));
    if (ans == 1e9)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}