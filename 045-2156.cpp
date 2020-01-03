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
  vector<int> v;
  v.reserve(n);
  while(cnt--) {
    int input;
    cin >> input;
    v.push_back(input);
  } 

  vector<vector<int>> ans(n, vector<int>(3, 0));
  ans[0][0] = ans[0][1] = v[0];
  for(int i=1; i<n; i++) {
    ans[i][0] = ans[i-1][1] + v[i];
    ans[i][1] = ans[i-1][2] + v[i];
    ans[i][2] = max(max(ans[i-1][0], ans[i-1][1]), ans[i-1][2]);
  }
  cout << max(max(ans[n-1][0], ans[n-1][1]), ans[n-1][2]);

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
