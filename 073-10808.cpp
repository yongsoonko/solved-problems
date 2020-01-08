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

  int cnt[26] = {
      0,
  };
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    cnt[str[i] - 'a']++;
  }

  for (int i : cnt) {
    cout << i << ' ';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
