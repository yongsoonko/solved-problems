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

int N;
int map[129][129];
int ans[2];

int solve(int ci, int cj, int size) {
  if (size == 1)
    return map[ci][cj];

  int cnt[2] = {0, 0};
  for (int i = 0; i < size; i += size / 2)
    for (int j = 0; j < size; j += size / 2) {
      int tmp = solve(ci + i, cj + j, size / 2);
      if (tmp >= 0)
        cnt[tmp]++;
    }

  int res;
  if (cnt[res = 0] == 4 || cnt[res = 1] == 4) {
    if (size == N)
      ans[res]++;
    return res;
  } else {
    ans[0] += cnt[0], ans[1] += cnt[1];
    return -1;
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

  solve(0, 0, N);

  cout << ans[0] << '\n'
       << ans[1];

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}