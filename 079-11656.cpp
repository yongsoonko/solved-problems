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

  string str;
  cin >> str;
  vector<string> v;
  v.reserve(str.length());

  for(int i=0; i<str.length(); i++) {
    v.push_back(str.substr(i));
  }

  sort(v.begin(), v.end());
  for(string s: v) {
    cout << s << '\n';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
