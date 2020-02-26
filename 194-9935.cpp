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

char chain[62];
char last_ch;

int get_idx(char ch) {
  int res;
  if (ch >= 'a' && ch <= 'z')
    res = ch - 'a';
  else if (ch >= 'A' && ch <= 'Z')
    res = ch - 'A' + 26;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0' + 52;
  return res;
}

void gen_chain(char curr, char prev) {
  chain[get_idx(curr)] = prev;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    string str, bomb;
    cin >> str >> bomb;

    char ch = bomb[0];
    gen_chain(ch, '^');

    if (bomb.size() == 1)
      last_ch = bomb[0];
    for (int i = 1; i < bomb.length(); i++) {
      gen_chain(bomb[i], bomb[i - 1]);
      if (i == bomb.length() - 1)
        last_ch = bomb[i];
    }

    stack<char> s;
    for (char ch : str) {
      s.push(ch);
      if (s.top() == last_ch) {
        string tmp;
        do {
          tmp.push_back(s.top());
          s.pop();
        } while (s.size() && s.top() == chain[get_idx(tmp.back())]);
        if (chain[get_idx(tmp.back())] != '^')
          while (tmp.size()) {
            s.push(tmp.back());
            tmp.pop_back();
          }
      }
    }

    string ans;
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