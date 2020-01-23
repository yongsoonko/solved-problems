#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

// key 값을 갖거나 key 값보다 큰 값을 가지는
// 요소의 인덱스
int _lowerbound(int left, int right, int key, vector<int> &v) {
  if (left == right) {
    if (left == v.size() - 1 && v[left] < key)
      return left + 1;
    return left;
  }

  int mid = (left + right) / 2 + 1;
  if (v[mid] >= key) {
    if (v[mid - 1] >= key)
      return _lowerbound(left, mid - 1, key, v);
    else
      return mid;
  } else
    return _lowerbound(mid + 1, right, key, v);
}

int lowerbound(int key, vector<int> &v) {
  return _lowerbound(0, v.size() - 1, key, v);
}

// key 값보다 큰 값을 가지는 요소의 인덱스
int _upperbound(int left, int right, int key, vector<int> &v) {
  if (left == right) {
    if (left == v.size() - 1 && v[left] <= key)
      return left + 1;
    return left;
  }

  int mid = (left + right) / 2 + 1;
  if (v[mid] > key) {
    if (v[mid - 1] > key)
      return _upperbound(left, mid - 1, key, v);
    else
      return mid;
  } else
    return _upperbound(mid + 1, right, key, v);
}

int upperbound(int key, vector<int> &v) {
  return _upperbound(0, v.size() - 1, key, v);
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

  cout << lowerbound(3, v) << '\n';
  cout << lowerbound(7, v) << '\n';
  cout << lowerbound(8, v) << '\n';
  cout << lowerbound(9, v) << '\n';

  cout << "-----" << '\n';

  cout << lower_bound(v.begin(), v.end(), 3) - v.begin() << '\n';
  cout << lower_bound(v.begin(), v.end(), 7) - v.begin() << '\n';
  cout << lower_bound(v.begin(), v.end(), 8) - v.begin() << '\n';
  cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << '\n';

  cout << "-----" << '\n';

  cout << upperbound(3, v) << '\n';
  cout << upperbound(7, v) << '\n';
  cout << upperbound(8, v) << '\n';
  cout << upperbound(9, v) << '\n';

  cout << "-----" << '\n';

  cout << upper_bound(v.begin(), v.end(), 3) - v.begin() << '\n';
  cout << upper_bound(v.begin(), v.end(), 7) - v.begin() << '\n';
  cout << upper_bound(v.begin(), v.end(), 8) - v.begin() << '\n';
  cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << '\n';
  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}