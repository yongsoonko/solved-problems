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

void dfs(int now, vector<pair<char, char>> &edge) {
  pair<char, char> child = edge[now];
  ans[0] += 'A' + now;
  if (child.first != '.')
    dfs(child.first - 'A', edge);
  ans[1] += 'A' + now;
  if (child.second != '.')
    dfs(child.second - 'A', edge);
  ans[2] += 'A' + now;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int n;
  cin >> n;

  vector<pair<char, char>> edge(n);
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    cin >> edge[ch - 'A'].first >> edge[ch - 'A'].second;
  }

  // for (auto a : edge)
  //   cout << a.first << ' ' << a.second << '\n';

  dfs(0, edge);
  for (string str : ans)
    cout << str << '\n';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}