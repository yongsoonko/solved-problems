#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  int tc = 1;
  for (int i = tc; i--;) {
    string n;
    cin >> n;

    vector<int> cnt(10, 0);
    int sum = 0;

    for (char ch : n) {
      int num = ch - '0';
      cnt[num]++;
      sum += num;
    }

    if (cnt[0] == 0 || sum % 3 != 0)
      cout << -1;
    else
      for (int i = 9; i >= 0; i--)
        for (int j = cnt[i]; j--;)
          cout << i;
    cout << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}