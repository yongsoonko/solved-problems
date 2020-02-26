#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  int i;
  int j;
};

class stack {
  char data[100001];
  int idx = 0;

public:
  void push(char ch) {
    data[idx++] = ch;
  }
  char top() {
    return data[idx - 1];
  }
  void pop() {
    idx--;
  }
  bool empty() {
    return idx <= 0;
  }
  int size() const {
    return idx;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    stack s;
    string str;
    char prev;
    int ans = 0;
    cin >> str;
    for (char ch : str) {
      if (ch == '(')
        s.push(ch);
      else if (!s.empty()) {
        if (prev == '(') {
          s.pop();
          ans += s.size();
        } else {
          s.pop();
          ans++;
        }
      }
      prev = ch;
    }
    cout << ans << ' ';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}