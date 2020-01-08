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

  int n;
  cin >> n;

  vector<vector<int>> dp(n, vector<int>(3, 0));

  if(n % 2) {
    cout << 0;
  } else {
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for(int i=3; i<n; i+=2) {
      dp[i][0] = dp[i-2][0] + dp[i-2][1] + dp[i-2][2];
      dp[i][1] = dp[i-2][0] + dp[i-2][1] + dp[i-2][2] + dp[i-2][1];
      dp[i][2] = dp[i-2][0] + dp[i-2][1] + dp[i-2][2] + dp[i-2][2];
    }
    cout << dp[n-1][0] + dp[n-1][1] + dp[n-1][2];
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
