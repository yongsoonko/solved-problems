#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  string a, b, c, d;
  cin >> a >> b >> c >> d;

  string _a = a + b, _b = c + d;
  long long ans = _a[0] - '0', ans2 = _b[0] - '0';
  for(int i=1; i<_a.length(); i++) {
    ans = ans * 10 + (_a[i] - '0');
  }
  for(int i=1; i<_b.length(); i++) {
    ans2 = ans2 * 10 + (_b[i] - '0');
  }
  cout << ans + ans2;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
