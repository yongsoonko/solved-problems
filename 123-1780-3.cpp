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

int N;
int map[3000][3000];
int ans_cnt[3];

int dfs(int ci, int cj, int size) {
  if (size == 1) {
    return map[ci][cj];
  } else {
    int cnt[3] = {0};
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        int sub_res = dfs(ci + i * size / 3, cj + j * size / 3, size / 3);
        if (sub_res == 1e9)
          continue;
        else if (sub_res == -1)
          sub_res = 2;
        cnt[sub_res]++;
      }

    int res;
    if (cnt[res = 0] == 9 || cnt[res = 1] == 9 || cnt[res = 2] == 9) {
      if (size == N)
        ans_cnt[res]++;
      if (res == 2)
        res = -1;
      return res;
    } else {
      ans_cnt[0] += cnt[0], ans_cnt[1] += cnt[1], ans_cnt[2] += cnt[2];
      return 1e9;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> map[i][j];

  dfs(0, 0, N);

  cout << ans_cnt[2] << '\n'
       << ans_cnt[0] << '\n'
       << ans_cnt[1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}