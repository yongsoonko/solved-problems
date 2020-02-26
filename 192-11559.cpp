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
string map[12], map2[12];
int chk[12][6];

bool has_color(char ch) {
  return ch == 'R' || ch == 'G' || ch == 'B' || ch == 'P' || ch == 'Y';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  for (int i = 0; i < 12; i++)
    cin >> map[i];

  int ans = 0;
  while (1) {
    // for (int i = 0; i < 12; i++)
    //   cout << map[i] << '\n';
    // cout << '\n';

    int flag = 0;
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 6; j++)
        if (has_color(map[i][j]) && !chk[i][j]) {
          char ch = map[i][j];
          int cnt = 0;

          queue<Pos> q;
          chk[i][j] = 1;
          q.push({i, j});
          while (q.size()) {
            int ci = q.front().i, cj = q.front().j;
            q.pop();
            cnt++;
            for (int i = 0; i < 4; i++) {
              int ni = ci + di[i], nj = cj + dj[i];
              if (ni >= 0 && ni < 12 && nj >= 0 && nj < 6 && map[ni][nj] == ch && !chk[ni][nj]) {
                chk[ni][nj] = 1;
                q.push({ni, nj});
              }
            }
          }
          if (cnt >= 4) {
            flag = 1;
            q.push({i, j});
            map[i][j] = '.';
            while (q.size()) {
              int ci = q.front().i, cj = q.front().j;
              q.pop();
              for (int i = 0; i < 4; i++) {
                int ni = ci + di[i], nj = cj + dj[i];
                if (ni >= 0 && ni < 12 && nj >= 0 && nj < 6 && map[ni][nj] == ch) {
                  map[ni][nj] = '.';
                  q.push({ni, nj});
                }
              }
            }
          }
        }

    fill(&chk[0][0], &chk[11][6], 0);

    string col = "";
    for (int j = 0; j < 6; j++) {
      int i;
      for (i = 11; i >= 0; i--)
        if (map[i][j] != '.')
          col.push_back(map[i][j]);
      for (i = 0; i < col.length(); i++)
        map[11 - i][j] = col[i];
      for (; i <= 11; i++)
        map[11 - i][j] = '.';
      // col = "";
      col.clear();
    }

    if (flag)
      ans++;
    else
      break;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}