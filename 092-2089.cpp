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

  int remain, div;
  string ans;
  if (n == 0)
    ans = '0';
  while (n != 0) {
    if (n < 0 && n % 2 == -1)
      div = n / -2 + 1;
    else
      div = n / -2;
    remain = n - div * -2;
    // cout << "div\t" << div << "\tremain\t" << remain << '\n';
    n = div;
    ans = (char)('0' + remain) + ans;
  }
  cout << ans;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
