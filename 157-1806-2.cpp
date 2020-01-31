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

int n, s, ans = 1e9;

int search(int left, int right, int target, vector<int> &v) {
  int mid = (left + right) / 2 + 1, midLeft = mid - 1;
  if (left == right) {
    if (left == n) {
      if (v[left] >= target)
        return midLeft;
      return -1;
    }
    return midLeft;
  }

  if (v[mid] >= target && v[midLeft] < target)
    return mid;
  else {
    if (v[mid] >= target && v[midLeft] >= target)
      return search(left, mid - 1, target, v);
    else
      return search(mid, right, target, v);
  }
}

void solve(vector<int> &v) {
  for (int i = 1; i <= n; i++) {
    int idx = search(i, n, s + v[i - 1], v);
    if (idx == -1)
      break;
    ans = min(ans, idx - i + 1);
  }
  if (ans == 1e9)
    ans = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  cin >> n >> s;
  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    v[i] = v[i - 1] + a;
  }
  solve(v);
  cout << ans;

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}