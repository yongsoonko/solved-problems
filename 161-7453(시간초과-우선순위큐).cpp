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

  int n, ans = 0;
  cin >> n;

  vector<int> a(n), b(n), c(n), d(n);
  priority_queue<int> pq;
  priority_queue<int, vector<int>, greater<int>> pq2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
    cin >> c[i];
    cin >> d[i];
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      pq.push(a[i] + b[j]);
      pq2.push(c[i] + d[j]);
    }

  while (!pq.empty() && !pq.empty()) {
    int p1 = pq.top(), p2 = pq2.top();
    cout << p1 << ' ' << p2 << ' ' << ans << '\n';
    if (p1 + p2 > 0)
      pq.pop();
    else if (p1 + p2 < 0)
      pq2.pop();
    else {
      pq.pop();
      pq2.pop();
      ans++;
    }
  }

  cout << ans;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}