#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int res = s.length();

  for (int i = 1; i <= s.length() / 2; i++) {
    int cnt = 1;
    string prev = s.substr(0, i), str;
    for (int j = i; j < s.length(); j += i) {
      string sub = s.substr(j, i);
      if (sub == prev)
        cnt++;
      else {
        str += (cnt > 1 ? to_string(cnt) : "") + prev;
        prev = sub;
        cnt = 1;
      }
      if (j + sub.length() == s.length())
        str += (cnt > 1 ? to_string(cnt) : "") + sub;
    }
    if (res > str.length())
      res = str.length();
  }
  return res;
}

int main() {
  int tc = 5;
  while (tc--) {
    string str;
    cin >> str;

    cout << solution(str) << '\n';
  }
}