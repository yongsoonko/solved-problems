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

  int a, n;
  cin >> a;

  while(a--) {
    cin >> n;
    vector<vector<int>> v;
    for(int i=0; i<=1; i++) {
      vector<int> tmp;
      tmp.reserve(n);
      for(int j=0; j<n; j++) {
        int input;
        cin >> input;
        tmp.push_back(input);
      }
      v.push_back(tmp);
    }
    // for(auto a: v) {
    //   for(int i: a) {
    //     cout << i << ' ';
    //   }
    //   cout << '\n';
    // }
    vector<vector<int>> ans(n, vector<int>(3, 0));
    ans[0][0] = v[0][0];
    ans[0][1] = v[1][0];
    for(int i=1; i<n; i++) {
      ans[i][0] = max(ans[i-1][1] + v[0][i], ans[i-1][2] + v[0][i]);
      ans[i][1] = max(ans[i-1][0] + v[1][i], ans[i-1][2] + v[1][i]);
      ans[i][2] = max(ans[i-1][0], ans[i-1][1]);
    }
    cout << max(max(ans[n-1][0], ans[n-1][1]), ans[n-1][2]) << '\n';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
