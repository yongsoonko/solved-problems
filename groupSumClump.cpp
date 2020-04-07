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

vector<int> v;
int N, sum;

bool f(int curr, int add) {
  if (curr == N) {
    if (add == sum)
      return 1;
    return 0;
  }
  if (add == sum)
    return 1;
  int adj_sum = v[curr], i = curr;
  for (; i < N - 1; i++)
    if (v[i] == v[i + 1])
      adj_sum += v[i];
    else
      break;
  cout << adj_sum << '\n';
  if (f(i + 1, add))
    return 1;
  if (f(i + 1, add + adj_sum))
    return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    vector<int>().swap(v);
    cin >> N;
    for (int i = 0; i < N; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    cin >> sum;

    if (f(0, 0))
      cout << "true\n";
    else
      cout << "false\n";
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}