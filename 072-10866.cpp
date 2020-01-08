#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct deque {
  int f = 15000, b = 15000, _size = 0;
  int _deque[30000] = {0,};

  void push_front(int x) {
    _deque[--f] = x;
    _size = b - f;
  }
  void push_back(int x) {
    _deque[b++] = x;
    _size = b - f;
  }
  void pop_front() {
    if(_size == 0) cout << -1 << '\n';
    else {
      cout << _deque[f++] << '\n';
      _size = b - f;
    }
  }
  void pop_back() {
    if(_size == 0) cout << -1 << '\n';
    else {
      cout << _deque[--b] << '\n';
      _size = b - f;
    }
  }
  void size() {
    cout << _size << '\n';
  }
  void empty() {
    cout << (_size == 0? 1: 0) << '\n';
  }
  void front() {
    if(_size == 0) cout << -1 << '\n';
    else cout << _deque[f] << '\n';
  }
  void back() {
    if(_size == 0) cout << -1 << '\n';
    else cout << _deque[b-1] << '\n';
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;
  deque dq;
  for (int i = n; i--;) {
    int a;
    string str;
    cin >> str;
    if (str == "push_front") {
      cin >> a;
      dq.push_front(a);
    } else if(str == "push_back") {
      cin >> a;
      dq.push_back(a);
    } else if (str == "pop_front") {
      dq.pop_front();
    } else if (str == "pop_back") {
      dq.pop_back();
    } else if (str == "size") {
      dq.size();
    } else if (str == "empty") {
      dq.empty();
    } else if (str == "front") {
      dq.front();
    } else if (str == "back") {
      dq.back();
    }
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
