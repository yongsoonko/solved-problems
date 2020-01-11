#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, cnt = 0;
  cin >> n;
  for(int i=n; i--;) {
    int a, j;
    cin >> a;
    for(j=2; j<=sqrt(a); j++) {
      if(a % j == 0) break;
    }
    if(a > 1 && j>sqrt(a)) {
      cnt++;
    }
  }

  cout << cnt;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
