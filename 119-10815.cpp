#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<bool> v(20000001, 0);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int n, m;
  cin >> n;
  
  for(int i=n; i--;) {
    int a;
    cin >> a;
    v[a + 10000000] = 1;
  }
  
  cin >> m;
  for(int i=m; i--;) {
    int a;
    cin >> a;
    cout << v[a + 10000000] << ' ';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}