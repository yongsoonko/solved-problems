#include <algorithm>
#include <cstring>
#include <deque>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start = clock();

  string A, T;
  cin >> A >> T;

  int lo = 0, hi = T.size() - 1;
  deque<char> lt, rt;
  while (lo <= hi) {
    while (lo <= hi) {
      bool flag = false;
      lt.push_back(T[lo++]);
      if (lt.size() >= A.size()) {
        flag = true;
        for (int i = 0; i < A.size(); i++)
          if (lt[lt.size() - A.size() + i] != A[i]) {
            flag = false;
            break;
          }
      }
      if (flag) {
        for (int i = 0; i < A.size(); i++)
          lt.pop_back();
        break;
      }
    }
    while (lo <= hi) {
      bool flag = false;
      rt.push_front(T[hi--]);
      if (rt.size() >= A.size()) {
        flag = true;
        for (int i = 0; i < A.size(); i++)
          if (rt[i] != A[i]) {
            flag = false;
            break;
          }
      }
      if (flag) {
        for (int i = 0; i < A.size(); i++)
          rt.pop_front();
        break;
      }
    }
  }

  string ans;
  for (char ch : lt)
    ans += ch;
  for (char ch : rt)
    ans += ch;

  int pos = 0;
  while ((pos = ans.find(A, pos)) != string::npos) {
    ans.erase(pos, A.size());
    pos = 0;
  }

  cout << ans << '\n';

  float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << time;
}