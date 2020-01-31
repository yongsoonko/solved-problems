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

int z, m, n, ans = 0;
void solve(int len, int begin, int add, vector<int> &v, vector<int> &sum) {
  int size = v.size();
  if (len == size - 1) {
    sum[add + v[begin]] = 1;
    return;
  }

  sum[add + v[begin]]++;
  int next = (begin + 1) % size;
  solve(len + 1, next, add + v[begin], v, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> z >> m >> n;

  vector<int> a(m), b(n);
  vector<int> sum_a(1000001, 0), sum_b(1000001, 0);
  for (int i = 0; i < m; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < m; i++)
    solve(0, i, 0, a, sum_a);
  for (int i = 0; i < n; i++)
    solve(0, i, 0, b, sum_b);

  if (z <= 1000000)
    ans += sum_a[z] + sum_b[z];
  for (int i = 0; i <= 1000000; i++) {
    int ni = z - i;
    if (ni >= 0 && ni <= 1000000)
      ans += sum_a[i] * sum_b[ni];
  }

  cout << ans;
  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}