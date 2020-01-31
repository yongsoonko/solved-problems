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

void dfs(vector<int> v, vector<int> ans) {
  if (6 == ans.size()) {
    for (int i : ans)
      cout << i << ' ';
    cout << '\n';
    return;
  }
  int size = v.size(), cnt = ans.size();
  for (int i = 0; i <= size - (6 - cnt); i++) {
    ans.push_back(v[i]);
    dfs(vector<int>(v.begin() + i + 1, v.end()), ans);
    ans.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int k;
  cin >> k;
  while (k != 0) {
    vector<int> v(k);
    for (int i = 0; i < k; i++)
      cin >> v[i];

    dfs(v, vector<int>());

    cout << '\n';
    cin >> k;
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}