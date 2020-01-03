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
  vector<vector<int>> v(n, vector<int>(10, 0));
  for(int& i: v[0]) {
    i = 1;
  }
  for(int i=1; i<n; i++) {
    for(int j=0; j<=9; j++) {
      for(int k=0; k<=j; k++) {
        v[i][j] = (v[i][j] + v[i-1][k]) % 10007;
      }
    }
  }
  // for(auto a: v) {
  //   for(int b: a) {
  //     cout << b << ' ';
  //   }
  //   cout << '\n';
  // }
  int sum = 0;
  for(int i: v[n-1]) {
    sum = (sum + i) % 10007;
  }
  cout << sum;
  
  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "time : " << _time;
}
