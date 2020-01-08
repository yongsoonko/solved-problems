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

  int n, cnt;
  cin >> n;
  cnt = n;
  
  vector<int> v, t(n, 0);
  v.reserve(n);
  
  while(cnt--) {
    int input;
    cin >> input;
    v.push_back(input);
  }

  t[0] = v[0];
  for(int i=1; i<n; i++) {
      t[i] = max(t[i-1] + v[i], v[i]);
  }
  
  int max = -1001;
  for(int i: t) {
      if(max < i) {
          max = i;
      }
    //   cout << i << ' ';
  }
  cout << max;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
//   cout << "\ntime : " << _time;
}
