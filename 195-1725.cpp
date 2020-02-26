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

int N;
ll ans;
int h[100010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> h[i];

  stack<int> s;
  s.push(0);
  for (int i = 1; i <= N + 1; i++) {
    while (s.size() && h[s.top()] > h[i]) {
      ll height = h[s.top()];
      s.pop();
      ll width = i - s.top() - 1;

      // cout << width << ' ' << height << '\n';
      ans = max(ans, width * height);
    }
    s.push(i);
  }

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}