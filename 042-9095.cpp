#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution() {
  int ans = 0;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, n;
  cin >> a;
  vector<int> v(11, 0);
  v[0] = 1;
  v[1] = 2;
  v[2] = 4;
  for(int i=3; i<11; i++) {
    for(int j=1; j<=3; j++) {
      v[i] += v[i - j]; 
    }
  }
  clock_t start = clock();
  
  while(a--) {
   int n;
   cin >> n;
   cout << v[n-1] << '\n'; 
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "time : " << _time;
}
