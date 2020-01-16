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
vector<pair<int, int>> vp;

void search(int left, int right, int target) {
  if (left > right) {
    cout << "0 ";
    return;
  }
  int mid = (left + right) / 2;
  int first = vp[mid].first;
  if (first == target) {
    cout << vp[mid].second << ' ';
    return;
  }
  if (first > target)
    search(left, mid - 1, target);
  if (first < target)
    search(mid + 1, right, target);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n, m;
  cin >> n;

  v.reserve(n);
  for (int i = n; i--;) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());

  int size = v.size();
  vp.push_back({v[0], 1});
  for (int i = 1; i < size; i++) {
    if (vp.back().first == v[i])
      vp.back().second++;
    else
      vp.push_back({v[i], 1});
  }

  size = vp.size();
  cin >> m;
  for (int i = m; i--;) {
    int a;
    cin >> a;
    search(0, size - 1, a);
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}