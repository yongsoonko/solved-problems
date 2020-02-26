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

  bool operator<(const Pos &p) const {
    if (j == p.j)
      return i < p.i;
    return j < p.j;
  }
};

int r, c, k, rsize, csize;
int map[100][100];
Pos cnt_num[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    rsize = 3, csize = 3;

    for (int i = 1; i <= 100; i++)
      cnt_num[i].i = i;

    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        cin >> map[i][j];

    int ans = 0;
    while (1) {
      if (map[r - 1][c - 1] == k) {
        cout << ans << '\n';
        break;
      }
      if (rsize >= csize) {
        int len = 0;
        for (int i = 0; i < rsize; i++) {
          for (int j = 0; j < csize; j++)
            cnt_num[map[i][j]].j++;
          sort(cnt_num + 1, cnt_num + 101);
          int k = 0;
          for (int j = 1; j <= 100; j++)
            if (cnt_num[j].j && k < 100) {
              map[i][k] = cnt_num[j].i;
              map[i][k + 1] = cnt_num[j].j;
              k += 2;
              if (len < k)
                len = k;
            }
          for (int l = k; l < 100; l++)
            map[i][l] = 0;
          for (int l = 1; l <= 100; l++) {
            cnt_num[l].i = l;
            cnt_num[l].j = 0;
          }
        }
        csize = len;
        ans++;
        if (ans > 100) {
          cout << -1 << '\n';
          break;
        }
      } else {
        int len = 0;
        for (int j = 0; j < csize; j++) {
          for (int i = 0; i < rsize; i++)
            cnt_num[map[i][j]].j++;
          sort(cnt_num + 1, cnt_num + 101);
          int k = 0;
          for (int i = 1; i <= 100; i++)
            if (cnt_num[i].j && k < 100) {
              map[k][j] = cnt_num[i].i;
              map[k + 1][j] = cnt_num[i].j;
              k += 2;
              if (len < k)
                len = k;
            }
          for (int l = k; l < 100; l++)
            map[l][j] = 0;
          for (int l = 1; l <= 100; l++) {
            cnt_num[l].i = l;
            cnt_num[l].j = 0;
          }
        }
        rsize = len;
        ans++;
        if (ans > 100) {
          cout << -1 << '\n';
          break;
        }
      }
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}