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

void qsort(int left, int right, vector<int> &v) {
  if (left >= right)
    return;

  int i = left + 1, j = right, pivot = v[left];
  while (i <= j) {
    while (i <= right && v[i] <= pivot && i++);
    while (j >= left + 1 && v[j] > pivot && j--);
    if (i < j)
      swap(v[i++], v[j--]);
  }
  swap(v[left], v[j]);
  qsort(left, j - 1, v);
  qsort(j + 1, right, v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  for (int i : v)
    cout << i << ' ';
  cout << '\n';

  qsort(0, n - 1, v);

  for (int i : v)
    cout << i << ' ';
  cout << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}