#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;

int digitSum(int a, int p) {
  char buf[7] = {
      0x00,
  };
  sprintf(buf, "%d", a);
  string num = buf;
  int sum = 0, len = num.length();
  for (int i = 0; i < len; i++) {
    int digit = num[i] - '0';
    sum += pow(digit, p);
  }
  return sum;
}

void dfs(int now, int p, vector<int> &vertex) {
  vertex[now] = 0;
  int next = digitSum(now, p);

  int cnt = 1;
  while (vertex[next] == -1) {
    vertex[next] = cnt;
    next = digitSum(next, p);
    cnt++;
  }
  cout << vertex[next];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t _start = clock();

  int a, p;
  cin >> a >> p;

  vector<int> vertex(236197, -1);
  dfs(a, p, vertex);

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
