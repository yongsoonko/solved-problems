#include <cmath>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

vector<bool> v(1000001, true);
vector<int> v2;

int search(int begin, int end, int target) {
  int mid = (begin + end) / 2;
  if (v2[mid] < target && v2[mid + 1] > target) {
    return mid;
  } else if (v2[mid] < target && v2[mid + 1] < target) {
    if(begin == mid) {
      return mid+1;
    }
    return search(mid + 1, end, target);
  } else {
    return search(begin, mid, target);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 테스트 케이스 만들기(doTc를 true로 하세요)
  bool doTc = true;
  vector<int> tc;
  if (doTc) {
    int size = 100000;
    tc.reserve(size+1);
    tc.push_back(0);

    srand(time(NULL));
    for (int i = 1; i <= size; i++) {
      int rd = rand() % 999994 + 6;
      if(rd % 2 == 1) rd -= 1;
      tc.push_back(rd);
    }
  }
  clock_t start = clock();

  v[1] = false;

  for (int i = 2; i <= sqrt(1000000); i++) {
    if(!v[i]) continue;
    for (int j = i + i; j <= 1000000; j += i) {
      v[j] = false;
    }
  }

  // 3부터 100만까지의 소수 리스트
  v2.reserve(80000);
  for (int i = 3; i <= 1000000; i++) {
    if (v[i])
      v2.push_back(i);
  }

  int n;
  if (doTc) {
    n = tc.back();
    tc.pop_back();
  } else {
    cin >> n;
  }

  do {
    for (int i = search(0, v2.size() - 1, n); i >= 0; i--) {
      if (v[n - v2[i]]) {
        cout << n << " = " << n - v2[i] << " + " << v2[i] << '\n';
        break;
      }
    }

    if (doTc) {
      n = tc.back();
      tc.pop_back();
    } else {
      cin >> n;
    }
  } while (n != 0);

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  cout << "\ntime : " << _time;
}
