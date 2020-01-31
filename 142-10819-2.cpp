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

bool next_permute(vector<int>::iterator _begin, vector<int>::iterator _end) {
  int idx = -1;
  for (auto it = _begin; it != _end - 1; it++)
    if (*it < *(it + 1))
      idx = it - _begin;
  if (idx == -1)
    return false;
  for (auto it = _end - 1; it != _begin; it--)
    if (*it > *(_begin + idx)) {
      swap(*it, *(_begin + idx));
      break;
    }
  reverse(_begin + idx + 1, _end);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    int n, ans = 0;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    sort(v.begin(), v.end());
    while (next_permute(v.begin(), v.end())) {
      int sum = 0;
      for (auto it = v.begin(); it != v.end() - 1; it++)
        sum += abs(*it - *(it + 1));
      ans = max(ans, sum);
    }
    cout << ans;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}