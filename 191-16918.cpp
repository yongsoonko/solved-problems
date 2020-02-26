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
int R, C, N;
string map[201], map2[201], map3[201];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
      map2[i].clear();
      map3[i].clear();
    }

    for (int i = 0; i < R; i++) {
      cin >> map[i];
      for (int j = 0; j < C; j++) {
        map2[i].push_back('O');
        map3[i].push_back('O');
      }
    }

    if (N % 2 == 0) {
      for (int i = 0; i < R; i++)
        cout << map3[i] << '\n';
      cout << '\n';
    } else {
      N--;
      while ((N -= 2) >= 0) {
        for (int i = 0; i < R; i++)
          for (int j = 0; j < C; j++)
            if (map[i][j] == 'O') {
              map2[i][j] = '.';
              for (int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 && ni < R && nj >= 0 && nj < C)
                  map2[ni][nj] = '.';
              }
            }
        for (int i = 0; i < R; i++) {
          map[i] = map2[i];
          map2[i] = map3[i];
        }
      }
      for (int i = 0; i < R; i++)
        cout << map[i] << '\n';
      cout << '\n';
    }
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}