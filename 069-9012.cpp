#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stack {
  int _size = 0;
  char _stack[100] = {0x00, };

  void isVps() {
    cout << (empty()? "YES": "NO") << '\n';
  }
  bool empty() {
    return _size == 0;
  }
  void push(char ch) {
    if(this->top() == '(' && ch == ')')
      this->pop();
    else
      _stack[_size++] = ch;
  }
  void pop() {
    if(_size > 0) _size--; 
  }
  char top() {
    if(_size > 0) return _stack[_size-1];
    return '_';
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;

  for(int i=n; i--;) {
    stack s;
    string str;
    cin >> str;
    int len = str.length();
    for(int i=0; i<len; i++) {
      s.push(str[i]);
    }
    s.isVps();
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
