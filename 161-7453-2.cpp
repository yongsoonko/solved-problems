#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ai3 = array<int, 3>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int n;
  ll ans = 0;
  cin >> n;

  vector<int> a(n), b(n), c(n), d(n);
  vector<int> sum_ab, sum_cd;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
    cin >> c[i];
    cin >> d[i];
  }

  sum_ab.reserve(16000000);
  sum_cd.reserve(16000000);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      sum_ab.push_back(a[i] + b[j]);
      sum_cd.push_back(c[i] + d[j]);
    }

  sort(sum_ab.begin(), sum_ab.end());
  sort(sum_cd.begin(), sum_cd.end());

  int add, cnt_ab, cnt_cd;
  auto it_cd = sum_cd.end();
  pair<vector<int>::iterator, vector<int>::iterator> bounds_ab, bounds_cd;
  for (auto it = sum_ab.begin(); it != sum_ab.end(); advance(it, cnt_ab)) {
    add = *it;
    bounds_ab = equal_range(it, sum_ab.end(), add);
    bounds_cd = equal_range(sum_cd.begin(), it_cd, -add);
    cnt_ab = distance(bounds_ab.first, bounds_ab.second),
    cnt_cd = distance(bounds_cd.first, bounds_cd.second);
    advance(it_cd, -cnt_cd);

    // 자료형이 다른 피연산자의 연산은 적은 쪽은 큰쪽으로 바꿔준 후 계산한다.
    // ll(cnt_ab * cnt_cd)와 전혀 다른 동작을 한다.
    ans += (ll)cnt_ab * cnt_cd;
    // cout << add << ' ' << cnt_ab << ' ' << cnt_cd << ' ' << ans << '\n';
  }
  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}