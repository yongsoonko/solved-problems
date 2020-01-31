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

int ans = 0, n;
void permute(vector<int> &v, vector<int> &v2) {
  if (v2.size() == n) {
    int sum = 0;
    for (int i = 0; i < v2.size() - 1; i++)
      sum += abs(v2[i] - v2[i + 1]);
    ans = max(ans, sum);
  }

  for (int i = 0; i < v.size(); i++) {
    int tmp = v[i];
    auto it = v.erase(v.begin() + i);
    v2.push_back(tmp);
    permute(v, v2);
    v.insert(it, tmp);
    v2.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int _tc = 1;
  for (int _i = _tc; _i--;) {
    cin >> n;
    vector<int> v(n), v2;
    for (int i = 0; i < n; i++)
      cin >> v[i];

    permute(v, v2);
    cout << ans;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}