#include <iostream>
#include <string>
#include <time.h>
#include <stack>

using namespace std;

struct stack {
  int _size = 0;
  char _stack[100001] = {
      0x00,
  };
  int _count[100001] = {0, };

  int ans = 0;
  char prev;

  bool empty() {
    return _size == 0;
  }
  void push(char ch) {
    // for(int i=0; i<_size; i++) {
    //   cout << _stack[i];
    // }
    // cout << '\t' << ans << '\n';

    if(_size >= 1) {
      if(prev == '(' && ch == ')') {
        for(int i=0; i<_size-1; i++) {
          _count[i]++;
        }
        _size--;
        prev = '_';
        return;
      } else if(ch == ')') {
        ans += _count[--_size] + 1;
        _count[_size] = 0;
        prev = '_';
        return;
      }
    }
    prev = ch;
    _stack[_size++] = ch;

  }
  void pop() {
    if (_size > 0)
      _size--;
  }
  char top() {
    if (_size > 0)
      return _stack[_size - 1];
    return '_';
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  string str;
  int len;
  stack s;
  cin >> str;
  len = str.length();

  for(int i=0; i<len; i++) {
    s.push(str[i]);
  }

  cout << s.ans;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
