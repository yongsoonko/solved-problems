#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;

  int cnt = 0;
  for(int i=1; i<=n; i++) {
    if(i % 5 == 0) cnt++;
    if(i % 25 == 0) cnt++;
    if(i % 125 == 0) cnt++;
  }

  cout << cnt;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
