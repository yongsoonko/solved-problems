#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

void dfs(int now, vector<bool> &vertex, vector<int> &edge) {
  vertex[now] = true;
  int next = edge[now];

  while(!vertex[next]) {
    vertex[next] = true;
    next = edge[next];
  }
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
    vector<bool> vertex(n + 1, false);
    vector<int> edge(n + 1);
    for (int j = 1; j <= n; j++) {
      int a;
      cin >> a;
      edge[j] = a;
    }

    int cnt = 0;
    for (int k = 1; k <= n; k++)
      if (!vertex[k]) {
        cnt++;
        dfs(k, vertex, edge);
        // for (int i = 1; i < vertex.size(); i++)
        //   cout << vertex[i] << ' ';
        // cout << '\n';
      }
    cout << cnt << '\n';
  }

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
