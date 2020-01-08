#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

struct stack {
  int _size = 0;
  int stack[20000] = {
      0,
  };

  void size() {
    cout << _size << '\n';
  }
  void empty() {
    cout << (int)(_size == 0) << '\n';
  }
  void push(int x) {
    stack[_size++] = x;
  }
  void pop() {
    if (_size == 0)
      cout << -1 << '\n';
    else
      cout << stack[--_size] << '\n';
  }
  void top() {
    if (_size == 0)
      cout << -1 << '\n';
    else
      cout << stack[_size - 1] << '\n';
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;

  stack s;
  for (int i = n; i--;) {
    string str;
    int a;
    cin >> str;
    if (str == "push") {
      cin >> a;
      s.push(a);
    } else if (str == "pop") {
      s.pop();
    } else if (str == "size") {
      s.size();
    } else if (str == "empty") {
      s.empty();
    } else if (str == "top") {
      s.top();
    }
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
