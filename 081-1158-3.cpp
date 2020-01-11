#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, k, tmp;
  cin >> n >> k;
  tmp = k;

  list<int> l;
  for (int i = 1; i <= n; i++) {
    l.push_back(i);
  }

  // 순차탐색으로 하는 방식
  auto it = l.begin();
  advance(it, k - 1);
  cout << '<' << *it;
  it = l.erase(it);
  while (!l.empty()) {
    k = tmp;
    for (; k > l.size(); k -= l.size())
      advance(it, l.size() + 1);
    if (distance(it, l.end()) <= k - 1)
      advance(it, k);
    else
      advance(it, k - 1);
    cout << ", " << *it;
    it = l.erase(it);
    if (it == l.end()) {
      it = l.begin();
    }
  }
  cout << '>';

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
