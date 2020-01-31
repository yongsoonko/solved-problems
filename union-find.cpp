#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

vector<int> root(11), height(11);

// 어떤 값의 루트 노드(집합 ID)를 구한다.
int find(int x) {
  if (x == root[x])
    return x;
  else
    return root[x] = find(root[x]);
}

// 어떤 값의 루트 노드(집합 ID)를 구해 더 낮은 높이를 가지는
// 집합을 반대 트리(집합)에 포함시킨다.
void merge(int x, int y) {
  x = find(x), x = find(y);

  if (x != y) {
    if (height[x] < height[y])
      root[x] = y;
    else {
      root[y] = x;
      if (height[x] == height[y])
        height[x]++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t _start = clock();

  for (int i = 1; i <= 10; i++) {
    root[i] = i;
    height[i] = 0;
  }

  merge(2, 3);
  merge(3, 4);
  cout << find(4) << '\n';

  float _time = (float)(clock() - _start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}