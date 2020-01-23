#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<int> v;
void dq(int h, int from, int tmp, int to) {
  if (h == 1) {
    v.push_back(from);
    v.push_back(to);
    return;
  }
  dq(h - 1, from, to, tmp);
  dq(1, from, tmp, to);
  dq(h - 1, tmp, from, to);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;
  dq(n, 1, 2, 3);

  cout << v.size() / 2 << '\n';
  for (int i = 0; i < v.size(); i += 2)
    cout << v[i] << ' ' << v[i + 1] << '\n';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}