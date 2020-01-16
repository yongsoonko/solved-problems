#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
string ans[3];

void dfs(char now, vector<bool> &vertex, vector<vector<char>> &edge) {
  // 전위 순회
  ans[0] += now;

  for (int i = 0; i < 2; i++) {
    char next = edge[now - 'A'][i];
    if (next != '.') {
      dfs(next, vertex, edge);
    }
    if (i == 0)
      // 중위 순회
      ans[1] += now;
    else if (i == 1)
      // 후위 순회
      ans[2] += now;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<bool> vertex(n, false);
  vector<vector<char>> edge(n, vector<char>(2));
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    for (int j = 0; j < 2; j++) {
      cin >> edge[ch - 'A'][j];
    }
  }

  // for (auto a : edge) {
  //   for (char ch : a)
  //     cout << ch << ' ';
  //   cout << '\n';
  // }

  dfs('A', vertex, edge);
  for (string str : ans)
    cout << str << '\n';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}