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

  clock_t start = clock();

  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(10));
  v[0][0] = 0;
  for(int i=1; i<=9; i++) {
    v[0][i] = 1;
  }
  for(int i=1; i<n; i++) {
    v[i][0] = v[i-1][1];
    v[i][9] = v[i-1][8];
    for(int j=1; j<=8; j++) {
      v[i][j] = (v[i-1][j-1] + v[i-1][j+1]) % 1000000000;
    }
  }
  // for(vector<int> tmp: v) {
  //   for(int i: tmp) {
  //     cout << i << ' ';
  //   }
  //   cout << '\n';
  // }
  int sum = 0;
  for(int i: v[n-1]) {
    sum = (sum + i) % 1000000000;
  }
  cout << sum;
  
  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "time : " << _time;
}
