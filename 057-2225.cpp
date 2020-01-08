#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, k;
  cin >> n >> k;

  vector<vector<int>> v(n+1, vector<int>(k+1, 1));

  for(int i=1; i<=n; i++) {
    for(int j=2; j<=k; j++) {
      v[i][j] = (v[i-1][j] + v[i][j-1]) % 1000000000;
    }
  }

  // for(auto a: v) {
  //   for(int i: a) {
  //     cout << i << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << v[n][k];

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
