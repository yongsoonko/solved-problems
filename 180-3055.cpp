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
int R, C, ans = 1e9;
string map[51];
int chk_s[51][51], chk_w[51][51];
Pos S, D;
vector<Pos> W;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // Answer: 3 KAKTUS 6 4 14 K 30 33 83 86 44 98 152 1
  int tc = 1;
  while (tc--) {
    ans = 1e9;
    fill(&chk_s[0][0], &chk_s[50][51], 0);
    fill(&chk_w[0][0], &chk_w[50][51], 0);
    vector<Pos>().swap(W);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
      cin >> map[i];
      for (int j = 0; j < C; j++)
        if (map[i][j] == '*')
          W.push_back({i, j});
        else if (map[i][j] == 'S')
          S = {i, j};
        else if (map[i][j] == 'D')
          D = {i, j};
    }

    Pos curr_w;
    queue<Pos> wq;
    for (int i = 0; i < W.size(); i++) {
      curr_w = W[i];
      wq.push(curr_w);
      chk_w[curr_w.i][curr_w.j] = 1;
    }

    Pos curr_s = S;
    queue<Pos> sq;
    sq.push(curr_s);
    chk_s[curr_s.i][curr_s.j] = 1;

    int cnt = 0;
    while (!sq.empty()) {
      int wqs = wq.size();
      for (int i = 0; i < wqs; i++) {
        curr_w = wq.front();
        wq.pop();

        int ci = curr_w.i, cj = curr_w.j;
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < R && nj >= 0 && nj < C && !chk_w[ni][nj] && map[ni][nj] != 'D' && map[ni][nj] != 'X') {
            chk_w[ni][nj] = 1;
            wq.push({ni, nj});
          }
        }
      }
      int sqs = sq.size();
      for (int i = 0; i < sqs; i++) {
        curr_s = sq.front();
        sq.pop();

        int ci = curr_s.i, cj = curr_s.j;
        for (int i = 0; i < 4; i++) {
          int ni = ci + di[i], nj = cj + dj[i];
          if (ni >= 0 && ni < R && nj >= 0 && nj < C && !chk_s[ni][nj] && !chk_w[ni][nj] && map[ni][nj] != 'X') {
            chk_s[ni][nj] = 1;
            sq.push({ni, nj});
          }
        }
      }
      cnt++;
      if (chk_s[D.i][D.j]) {
        ans = min(ans, cnt);
        break;
      }
    }

    if (ans == 1e9)
      cout << "KAKTUS\n";
    else
      cout << ans << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}