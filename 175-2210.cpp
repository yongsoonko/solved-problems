#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

#define fi first
#define se second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int map[5][5];
int chk[1000000];
char num[6];
int ans;

void dfs(int curr, int ci, int cj) {
  if (curr == 6) {
    int sum = 0;
    for (int i = 0; i < 6; i++)
      sum = sum * 10 + num[i];
    if (!chk[sum]) {
      chk[sum] = 1;
      ans++;
    }
  } else {
    for (int i = 0; i < 4; i++) {
      int ni = ci + di[i], nj = cj + dj[i];
      if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5) {
        num[curr] = map[ni][nj];
        dfs(curr + 1, ni, nj);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> map[i][j];

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      dfs(0, i, j);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}