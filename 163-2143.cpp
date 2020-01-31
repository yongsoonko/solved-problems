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

int t, n, m;
ll ans;

void solve(int begin, int add, vector<int> &v, vector<int> &sum) {
  if (begin == v.size())
    return;

  sum.push_back(add + v[begin]);
  solve(begin + 1, add + v[begin], v, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> t >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];

  vector<int> sum_a, sum_b;
  sum_a.reserve(n * (n - 1) / 2);
  sum_b.reserve(m * (m - 1) / 2);

  for (int i = 0; i < n; i++)
    solve(i, 0, a, sum_a);

  for (int i = 0; i < m; i++)
    solve(i, 0, b, sum_b);

  sort(sum_a.begin(), sum_a.end());
  sort(sum_b.begin(), sum_b.end());

  int add, cnt_a, cnt_b;
  pair<vector<int>::iterator, vector<int>::iterator> bounds_a, bounds_b;
  for (auto it_a = sum_a.begin(); it_a != sum_a.end(); advance(it_a, cnt_a)) {
    add = *it_a;
    bounds_a = equal_range(it_a, sum_a.end(), add);
    bounds_b = equal_range(sum_b.begin(), sum_b.end(), t - add);
    cnt_a = distance(bounds_a.first, bounds_a.second);
    cnt_b = distance(bounds_b.first, bounds_b.second);

    ans += (ll)cnt_a * cnt_b;
  }

  cout << ans;

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}