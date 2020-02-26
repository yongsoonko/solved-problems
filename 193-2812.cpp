#include <algorithm>
#include <deque>
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
int N, K;
string str;
stack<char> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  int tc = 1;
  while (tc--) {
    cin >> N >> K >> str;

    for (char ch : str) {
      while (K && s.size() && s.top() < ch) {
        s.pop();
        K--;
      }
      s.push(ch);
    }

    string ans;
    while (s.size()) {
      ans.push_back(s.top());
      s.pop();
    }

    for (int i = ans.length() - 1; i >= K; i--)
      cout << ans[i];
    cout << '\n';
  }

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}