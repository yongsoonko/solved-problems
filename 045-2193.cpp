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

  int n;
  cin >> n;
  vector<vector<long long>> v(n, vector<long long>(2));
  v[0][0] = 0;
  v[0][1] = 1;

  clock_t start = clock();

  for(int i=1; i<n; i++) {
    v[i][0] = v[i-1][0] + v[i-1][1];
    v[i][1] = v[i-1][0];
  }

  cout << v[n-1][0] + v[n-1][1];
  
  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "time : " << _time;
}
