#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int bs(int left, int right, int target, vector<int> &v) {
  int mid = (left + right) / 2;
  if (v[mid] > target)
    bs(left, mid - 1, target, v);
  else if (v[mid] < target)
    bs(mid + 1, right, target, v);
  else
    return mid;
}

int qs(int left, int right, vector<int> &v, vector<int> &sv) {
  if (left >= right)
    return 0;

  int mid = (left + right) / 2, idx = -1;
  bool isSwap = false;
  swap(v[left], v[mid]);
  int i = left + 1, j = right;
  while (i <= j) {
    while (i <= right && v[i] <= v[left] && i++);
    while (j >= left + 1 && v[j] > v[left] && j--);
    if (i < j) {
      swap(v[i++], v[j--]);
      isSwap = true;
    }
  }
  mid = j;
  swap(v[left], v[mid]);
  int lmid = qs(left, mid-1, v, sv);
  int rmid = qs(mid+1, right, v, sv);

  if(isSwap)
    idx = max(bs(0, sv.size()-1, v[lmid], sv), idx);
  else {
    mid = idx;
    idx = max(bs(0, sv.size()-1, v[rmid], sv), idx);
  }

  return idx; 
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

  vector<int> sv(v.begin(), v.end());
  stable_sort(sv.begin(), sv.end());

  cout << qs(0, v.size() - 1, v, sv) + 1;

  // cout << '\n';
  // for(int i: v)
  //   cout << i << ' ';
  // cout << '\n';
  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}