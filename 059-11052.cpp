#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;

  vector<int> v(n+1, 0);
  for(int i=1; i<=n; i++) {
    int input;
    cin >> input;
    v[i] = input;
  }
  
  for(int i=2; i<=n; i++) {
    for(int j=i-1; j>=i/2; j--) {
      v[i] = max(v[i], v[j] + v[i-j]);
    }
  }
  
  // for(int i: v) {
  //   cout << i << ' ';
  // }
  // cout << '\n';

  cout << v[n];

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
