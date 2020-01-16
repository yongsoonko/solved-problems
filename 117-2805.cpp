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
int search(int left, int right, int target) {
  int mid = (left + right) / 2, size = v.size();
  ll sum = 0, sumRight = 0;
  for (int i = 0; i < size; i++) {
    if (v[i] > mid)
      sum += v[i] - mid;
    if (v[i] > mid + 1)
      sumRight += v[i] - (mid + 1);
  }
  if (mid == right)
    return mid;
  if (sum < target)
    return search(left, mid - 1, target);
  else if (sumRight >= target)
    return search(mid + 1, right, target);
  else
    return mid;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int n, m;
  cin >> n >> m;

  int max = 0;
  v.reserve(n);
  for (int i = n; i--;) {
    int a;
    cin >> a;
    if (max < a)
      max = a;
    v.push_back(a);
  }

  cout << search(0, max, m);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}