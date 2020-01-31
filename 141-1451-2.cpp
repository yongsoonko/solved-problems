#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  // answer: 3806599216
  for (int _i = _tc; _i--;) {
    ll sum = 0, ans = 0;
    int n, m;
    cin >> n >> m;

    vector<string> vs(n + 1);
    vector<vector<int>> sub_sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      cin >> vs[i];
      for (int j = 1; j <= m; j++)
        sub_sum[i][j] = sub_sum[i - 1][j] + sub_sum[i][j - 1] - sub_sum[i - 1][j - 1] + (vs[i][j - 1] - '0');
    }

    //case 1: 가로 -> 세로(ㅜ)
    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++) {
        ll a = sub_sum[i][m];
        ll b = sub_sum[n][j] - sub_sum[i][j];
        ll c = sub_sum[n][m] - a - b;
        ans = max(ans, a * b * c);
      }

    //case 2: 세로 -> 가로(ㅗ)
    for (int i = n; i > 1; i--)
      for (int j = 1; j < m; j++) {
        ll a = sub_sum[i - 1][j];
        ll b = sub_sum[i - 1][m] - a;
        ll c = sub_sum[n][m] - a - b;
        ans = max(ans, a * b * c);
      }

    //case 3: 가로 -> 세로(ㅓ)
    for (int i = m; i > 1; i--)
      for (int j = 1; j < n; j++) {
        ll a = sub_sum[j][i - 1];
        ll b = sub_sum[n][i - 1] - a;
        ll c = sub_sum[n][m] - a - b;
        ans = max(ans, a * b * c);
      }

    //case 4: 세로 -> 가로(ㅏ)
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++) {
        ll a = sub_sum[n][i];
        ll b = sub_sum[j][m] - sub_sum[j][i];
        ll c = sub_sum[n][m] - a - b;
        ans = max(ans, a * b * c);
      }

    //case 5: 가로 -> 가로(=)
    for (int i = 1; i < n - 1; i++)
      for (int j = i + 1; j < n; j++) {
        ll a = sub_sum[i][m];
        ll b = sub_sum[j][m] - a;
        ll c = sub_sum[n][m] - a - b;
        ans = max(ans, a * b * c);
      }

    //case 6: 세로 -> 세로(||)
    for (int i = 1; i < m - 1; i++)
      for (int j = i + 1; j < m; j++) {
        ll a = sub_sum[n][i];
        ll b = sub_sum[n][j] - a;
        ll c = sub_sum[n][m] - a - b;
        ans = max(ans, a * b * c);
      }

    cout << ans << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}