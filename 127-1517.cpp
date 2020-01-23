#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

// 버블 소트는 O(N^2)의 시간 복잡도를 가지므로
// 50만개의 요소의 모든 비교횟수가 2500억번이 된다.
// 그러므로 ll 자료형을 반환한다.
ll dq(vector<int> &v, int left, int right) {
  if (left >= right)
    return 0;

  ll result = 0;
  int mid = (left + right) / 2, size = right - left + 1;
  vector<int> tmp(size);
  result += dq(v, left, mid);
  result += dq(v, mid + 1, right);

  // 부분 문제에서 정렬되어 나온 배열을 사용한다.
  int i = left, j = mid + 1, k = 0;
  while (i <= mid && j <= right) {
    if (v[i] <= v[j])
      tmp[k++] = v[i++];
    else {
      tmp[k++] = v[j++];
      // 앞의 서브 배열의 한 요소가 뒤 서브 배열의 요소보다
      // 값이 크다면 그 차이만큼 뒤 서브 배열의 요소가 앞으로
      // 이동해야 한다.
      result += (mid + 1) - i;
    }
  }
  while (i <= mid)
    tmp[k++] = v[i++];
  while (j <= right)
    tmp[k++] = v[j++];

  for (int i = 0; i < size; i++)
    v[left + i] = tmp[i];

  return result;
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

  cout << dq(v, 0, v.size() - 1);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}