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
  // 일단 맨 처음 집에 공유기가 설치된 것으로 초기화(그리디하게 접근)
  int spot = v[0] + mid, spotRight = v[0] + mid + 1;
  int sum = 1, sumRight = 1; 

  // 반복문에 int i를 삽입하면 O(N^2) 일 수 있다
  // ∵ mid 가 1일 때 while에서 N번, for에서 N번 수행하기 때문에
  // 이 때문에 시간 초과가 발생헀는데, 아래와 같이 기존의 위치를
  // 저장해서 O(N)으로 통과하였다.
  int i = 0;
  while (spot <= v[size - 1]) {
    for (; i < size; i++) {
      if (v[i] >= spot) {
        sum++;
        spot = v[i] + mid;
        break;
      }
    }
  }
  i = 0;
  while (spotRight <= v[size - 1]) {
    for (; i < size; i++) {
      if (v[i] >= spotRight) {
        sumRight++;
        spotRight = v[i] + mid + 1;
        break;
      }
    }
  }

  // mid == right가 참이 되는 2가지 경우
  // 직전 search 호출에서,
  // case 1: mid = 0, left = 1이고 left 역시 조건을 충족
  // case 2: mid = max-min-1, left = max-min이고 left 역시 조건을 충족
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

  int n, c;
  cin >> n >> c;

  v.reserve(n);
  int min = 1000000001, max = 0;
  for (int i = n; i--;) {
    int a;
    cin >> a;
    if (max < a)
      max = a;
    if (min > a)
      min = a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  // for(int i: v)
  //   cout << i << ' ';

  // 간격이 0인 경우 무한루프에 빠지는 문제가 발생했었음
  cout << search(1, max - min, c);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}