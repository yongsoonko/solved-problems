#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

struct Pos {
  Pos *node[10];
  bool is_leaf;
  bool has_next;

  Pos() {
    fill(node, node + 10, nullptr);
    is_leaf = 0, has_next = 0;
  }

  bool insert(const char *ch) {
    if (*ch == '\0') {
      is_leaf = 1;
      return !has_next;
    }

    if (!node[*ch - '0']) {
      node[*ch - '0'] = new Pos;
      has_next = 1;
    }

    return !is_leaf && node[*ch - '0']->insert(ch + 1);
  }

  void print(string str = "") {
    int flag = 1;
    for (int i = 0; i < 10; i++)
      if (node[i]) {
        flag = 0;
        str.push_back(i + '0');
        node[i]->print(str);
        str.pop_back();
      }
    if (flag)
      cout << str << '\n';
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc;
  cin >> tc;
  while (tc--) {
    Pos trie;
    int N, ans = 1;
    cin >> N;
    while (N--) {
      string str;
      cin >> str;

      ans &= trie.insert(str.c_str());
    }
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}