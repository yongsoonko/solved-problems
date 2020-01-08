#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct elem {
  int data;
  elem *prev, *next;
  elem(int _data, elem* _prev, elem* _next) {
    data = _data;
    prev = _prev;
    next = _next;
  }
};

struct deque {
  elem* f = NULL, *b = NULL;
  int _size = 0;

  void push_front(int x) {
    elem* newElem = new elem(x, NULL, NULL);;
    if(f == NULL) {
      f = b = newElem;
    } else {
      newElem->next = f;
      f->prev = newElem;
      f = newElem;
    }
    _size++;
  }
  void push_back(int x) {
    elem* newElem = new elem(x, NULL, NULL);;
    if(b == NULL) {
      f = b = newElem;
    } else {
      newElem->prev = b;
      b->next = newElem;
      b = newElem;
    }
    _size++;
  }
  void pop_front() {
    if(_size == 0) cout << -1 << '\n';
    else {
      elem* delElem = f;
      if(_size == 1) {
        f = b = NULL;
      }
      else {
        f = f->next;
        f->prev = NULL;
      }
      cout << delElem->data << '\n';
      _size--;
      delete delElem;
    }
  }
  void pop_back() {
    if(_size == 0) cout << -1 << '\n';
    else {
      elem* delElem = b;
      if(_size == 1) {
        f = b = NULL;
      }
      else {
        b = b->prev;
        b->next = NULL;
      }
      cout << delElem->data << '\n';
      _size--;
      delete delElem;
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
    else cout << f->data << '\n';
  }
  void back() {
    if(_size == 0) cout << -1 << '\n';
    else cout << b->data << '\n';
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
