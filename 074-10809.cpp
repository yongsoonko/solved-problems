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

  string str;
  cin >> str;
  vector<int> cnt(26, -1);

  for(int i=0; i<str.length(); i++) {
    int idx = str[i] - 'a';
    if(cnt[idx] == -1) cnt[idx] = i;
  }

  for(int i: cnt) {
    cout << i << ' ';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
