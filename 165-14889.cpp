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

int n, ans = 1e9;
ve<ve<int>> v(21, ve<int>(21));
ve<int> chk(21);

void dfs(int curr, int cnt) {
  if (cnt == n / 2) {
    ve<int> s, l;
    int sum_s = 0, sum_l = 0;
    for (int i = 1; i <= n; i++) {
      if (chk[i])
        s.push_back(i);
      else
        l.push_back(i);
    }

    for (int i = 0; i < cnt; i++)
      for (int j = 0; j < cnt; j++) {
        sum_s += v[s[i]][s[j]];
        sum_l += v[l[i]][l[j]];
      }
    ans = min(ans, abs(sum_s - sum_l));
    return;
  }
  for (int i = curr; i <= n; i++) {
    chk[i] = 1;
    dfs(i + 1, cnt + 1);
    chk[i] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> v[i][j];

  chk[1] = 1;
  dfs(2, 1);

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}