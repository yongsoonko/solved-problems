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

int N, L;
int map[101][101];
int chk[200][101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  // Answer: 3 7 3 11 11 6 4 6 4 11 10 11 10 3 5 1 8 5 10 7 5 4 10
  int tc = 1;
  while (tc--) {
    cin >> N >> L;
    fill(&chk[0][0][0], &chk[11][100][101], 0);

    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cin >> map[i][j];

    int ans = 0;
    for (int i = 0; i < N; i++) {
      int flag = 1, flag2 = 1;
      for (int j = 0; j < N - 1; j++) {
        if (map[i][j] - map[i][j + 1] == 1) {
          flag = 0;
          for (int k = 0; k < L; k++)
            if (j + 1 + k >= N || map[i][j + 1 + k] != map[i][j + 1] || chk[i][i][j + 1 + k]) {
              flag2 = 0;
              break;
            }
          if (flag2)
            for (int k = 0; k < L; k++) 
                chk[i][i][j + 1 + k] = 1;
            
          else
            break;
        } else if (map[i][j] - map[i][j + 1] == -1) {
          flag = 0;
          for (int k = 0; k < L; k++)
            if (j - k < 0 || map[i][j - k] != map[i][j] || chk[i][i][j - k]) {
              flag2 = 0;
              break;
            }
          if (flag2)
            for (int k = 0; k < L; k++) 
                chk[i][i][j - k] = 1;
            
          else
            break;
        } else if (abs(map[i][j] - map[i][j + 1]) > 1)
          flag = 0, flag2 = 0;
      }
      if (flag)
        ans++;
      else if (flag2)
        ans++;
    }

    for (int j = 0; j < N; j++) {
      int flag = 1, flag2 = 1;
      for (int i = 0; i < N - 1; i++) {
        if (map[i][j] - map[i + 1][j] == 1) {
          flag = 0;
          for (int k = 0; k < L; k++)
            if (i + 1 + k >= N || map[i + 1 + k][j] != map[i + 1][j] || chk[N + j][i + 1 + k][j]) {
              flag2 = 0;
              break;
            }
          if (flag2)
            for (int k = 0; k < L; k++) 
                chk[N + j][i + 1 + k][j] = 1;
            
          else
            break;
        } else if (map[i][j] - map[i + 1][j] == -1) {
          flag = 0;
          for (int k = 0; k < L; k++)
            if (i - k < 0 || map[i - k][j] != map[i][j] || chk[N + j][i - k][j]) {
              flag2 = 0;
              break;
            }
          if (flag2)
            for (int k = 0; k < L; k++) 
                chk[N + j][i - k][j] = 1;
            
          else
            break;
        } else if (abs(map[i][j] - map[i + 1][j]) > 1)
          flag = 0, flag2 = 0;
      }
      if (flag)
        ans++;
      else if (flag2)
        ans++;
    }

    cout << ans << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}