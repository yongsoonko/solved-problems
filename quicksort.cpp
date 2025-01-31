#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void qs(vector<int> &v, int left, int right) {
  if (left >= right)
    return;

  int i = left + 1, j = right, pivot = v[left];
  while (i <= j) {
    // 피벗과 같은 수를 어느 영역에 둘지를 정해야 한다.
    // 피벗 기준, 왼쪽은 피벗 보다 작거나 같은 수
    // 오른쪽은 피벗 보다 큰 수
    while (i <= right && v[i] <= pivot && i++);
    while (j >= left + 1 && v[j] > pivot && j--);
    if(i < j) 
      swap(v[i++], v[j--]);
  } 

  swap(v[left], v[j]);
  qs(v, left, j - 1);
  qs(v, j + 1, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  for (int i : v)
    cout << i << ' ';
  cout << '\n';

  qs(v, 0, v.size() - 1);
  // sort(v.begin(), v.end());
  for (int i : v)
    cout << i << ' ';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}