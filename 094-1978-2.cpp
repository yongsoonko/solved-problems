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

  vector<int> v(1001);
  for(int i=1; i<=1000; i++) {
    v[i] = i;
  }

  v[0] = v[1] = -1;
  for(int i=2; i<=1000/2; i++) {
    if(v[i] == -1) continue;
    for(int j=i*2; j<=1000; j+=i) {
      v[j] = -1;
    }
  }

  // for(int i: v) {
  //   if(i != -1) cout << i << ' ';
  // }
  // cout << '\n';

  int n, cnt = 0;
  cin >> n;
  for(int i=n; i--;) {
    int a;
    cin >> a;
    if(v[a] != -1) cnt++;
  }

  cout << cnt;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
