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
int h[500001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> h[i];

  stack<int> s;
  for (int i = 0; i < N; i++) {
    while (s.size() && h[s.top()] < h[i])
      s.pop();
    if (s.size())
      cout << s.top() + 1 << ' ';
    else
      cout << 0 << ' ';
    s.push(i);
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}