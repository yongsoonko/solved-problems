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

  string str;
  cin >> str;

  int len = str.length();
  int idx = len % 3;
  int ans;
  if (idx == 1) {
    cout << str[0] - '0';
  } else if (idx == 2) {
    cout << (str[0] - '0') * 2 + (str[1] - '0');
  }
  for (int i = idx; i < len; i++) {
    if (i % 3 == idx) {
      ans = str[i] - '0';
    } else {
      ans = ans * 2 + (str[i] - '0');
    }
    if (i % 3 == (idx + 2) % 3)
      cout << ans;
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
