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

void search(int left, int right, int target) {
  if (left > right) {
    cout << "0 ";
    return;
  }
  int mid = (left + right) / 2;

  if (v[mid] == target) {
    cout << "1 ";
    return;
  }
  if (v[mid] > target)
    search(left, mid - 1, target);
  if (v[mid] < target)
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

  cin >> m;
  for (int i = m; i--;) {
    int a;
    cin >> a;
    search(0, n - 1, a);
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}