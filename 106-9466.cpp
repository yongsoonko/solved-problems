#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

int dfs(int now, vector<int> &vertex, vector<int> &edge) {
  stack<int> s;
  int cnt = 1;
  vertex[now] = cnt;
  s.push(now);
  int next = edge[now];

  // -1: 이번 단계서 방문하지 않은 수열
  // -2: 이전 단계서 방문했던 수열
  // 종료상태: 반복수열 발생 시 or 이전 단계서 방문한 수열 진입 시
  while (vertex[next] == -1 && vertex[next] != -2) {
    vertex[next] = ++cnt;
    s.push(next);
    next = edge[next];
  }

  // 반복수열의 맨 처음은 제외해야 하므로 1을 빼준다.
  int result = vertex[next] == -2 ? cnt : vertex[next] - 1;

  // 이번 단계서 방문한 수열을 모두 -2로 바꿔준다.
  while (!s.empty()) {
    vertex[s.top()] = -2;
    s.pop();
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int tc;
  cin >> tc;

  for (int i = tc; i--;) {
    int n;
    cin >> n;
    vector<int> vertex(n + 1, -1);
    vector<int> edge(n + 1);
    for (int j = 1; j <= n; j++) {
      cin >> edge[j];
    }
    int sum = 0;
    for (int k = 1; k <= n; k++)
      if (vertex[k] == -1)
        sum += dfs(k, vertex, edge);
    cout << sum << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}