#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {

    string ans, str, b;
    cin >> str >> b;

    stack<char> s;
    reverse(b.begin(), b.end());
    for (int i = 0; i < str.size(); i++) {
      s.push(str[i]);
      bool flag = 1;
      string tmp;
      if (s.size() >= b.size()) {
        for (int j = 0; j < b.size(); j++) {
          if (s.top() != b[j]) {
            flag = 0;
            break;
          }
          tmp.push_back(s.top());
          s.pop();
        }
      }
      if (!flag) {
        while (tmp.size()) {
          s.push(tmp.back());
          tmp.pop_back();
        }
      }
    }

    while (s.size()) {
      ans.push_back(s.top());
      s.pop();
    }

    if (ans.size()) {
      for (int i = ans.length() - 1; i >= 0; i--)
        cout << ans[i];
      cout << '\n';
    } else
      cout << "FRULA\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}