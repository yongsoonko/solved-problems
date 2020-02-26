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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    int r, c, chk = 1;
    cin >> r >> c;

    ve<string> map(r);
    for (int i = 0; i < r; i++)
      cin >> map[i];

    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        if (map[i][j] == 'S') {
          for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
              if (map[ni][nj] == '.')
                map[ni][nj] = 'D';
              else if (map[ni][nj] == 'W')
                chk = 0;
            }
          }
        }

    if (chk) {
      cout << 1 << '\n';
      for (int i = 0; i < r; i++)
        cout << map[i] << '\n';
    } else
      cout << 0 << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}