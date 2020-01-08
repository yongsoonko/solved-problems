#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

struct queue {
  int f = 0, b = 0, _size = 0;
  int _queue[20000] = {
      0,
  };

  void push(int x) {
    _queue[b++] = x;
    _size = b - f;
  }
  void pop() {
    if (_size == 0)
      cout << -1 << '\n';
    else {
      cout << _queue[f++] << '\n';
      _size = b - f;
    }
  }
  void size() {
    cout << _size << '\n';
  }
  void empty() {
    cout << (_size == 0 ? 1 : 0) << '\n';
  }
  void front() {
    if(_size == 0) cout << -1 << '\n';
    else cout << _queue[f] << '\n';
  }
  void back() {
    if(_size == 0) cout << -1 << '\n';
    else cout << _queue[b-1] << '\n';
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;
  queue q;
  for (int i = n; i--;) {
    int a;
    string str;
    cin >> str;
    if (str == "push") {
      cin >> a;
      q.push(a);
    } else if (str == "pop") {
      q.pop();
    } else if (str == "size") {
      q.size();
    } else if (str == "empty") {
      q.empty();
    } else if (str == "front") {
      q.front();
    } else if (str == "back") {
      q.back();
    }
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
