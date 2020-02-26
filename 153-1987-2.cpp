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

int r, c, ans = 1;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
ve<string> map(21);
ve<bool> chk('Z' + 1);

void dfs(int ci, int cj, int cnt) {
  for (int i = 0; i < 4; i++) {
    int ni = ci + di[i], nj = cj + dj[i], next;
    if (ni >= 0 && ni < r && nj >= 0 && nj < c && !chk[(next = map[ni][nj])]) {
      chk[next] = 1;
      ans = max(ans, cnt + 1);
      dfs(ni, nj, cnt + 1);
      chk[next] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> r >> c;

  for (int i = 0; i < r; i++)
    cin >> map[i];

  chk[map[0][0]] = 1;
  dfs(0, 0, 1);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}