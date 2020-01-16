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
// 특정 조건을 충족하는 최적 타겟을 이분 탐색
int search(ll left, ll right, int target) {
  ll mid = (left + right) / 2;
  // sumRight는 mid+1일 때의 sum을 계산한 변수
  int sum = 0, sumRight = 0, size = v.size();
  for (int i = 0; i < size; i++) {
    sum += v[i] / mid;
    sumRight += v[i] / (mid + 1);
  }

  if (mid == right)
    return mid;

  if (sum < target)
    return search(left, mid - 1, target);
  else {
    // 현재 요소가 조건을 충족하더라도 똑같이 조건을 충족하는
    // 최적 요소(현재 요소보다 더 큰 값)를 검색해나간다.
    if (sumRight >= target)
      return search(mid + 1, right, target);
    // 현재 요소의 오른쪽 요소가 조건을 충족시키지 못하는 경우
    // 현재 요소가 조건을 충족하는 가장 나은 최적 요소이다.
    else
      return mid;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  clock_t _start = clock();

  int k, n;
  cin >> k >> n;

  v.reserve(k);
  int max = 0;
  for (int i = k; i--;) {
    int a;
    cin >> a;
    if (max < a)
      max = a;
    v.push_back(a);
  }

  cout << search(1, max, n);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}