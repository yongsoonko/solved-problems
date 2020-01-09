#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

struct elem {
  char ch;
  elem *prev, *next;
  elem(char _ch, elem *_prev, elem *_next) : ch(_ch), prev(_prev), next(_next){};
};

struct editor {
  elem *cursor;
  elem const * const firstElem;
  editor(string str) :firstElem(new elem('^', NULL, NULL)) {
    cursor = const_cast<elem*>(firstElem);
    for (int i = 0; i < str.length(); i++) {
      elem *newElem = new elem(str[i], NULL, NULL);
      cursor->next = newElem;
      newElem->prev = cursor;
      cursor = newElem;
    }
  };

  void L() {
    if (cursor->prev != NULL)
      cursor = cursor->prev;
  }
  void D() {
    if (cursor->next != NULL)
      cursor = cursor->next;
  }
  void B() {
    if (cursor->prev != NULL) {
      cursor->prev->next = cursor->next;
      if (cursor->next != NULL) 
        cursor->next->prev = cursor->prev;
      elem *delElem = cursor;
      cursor = cursor->prev;
      delete delElem;
    }
  }
  void P(char ch) {
    elem *newElem = new elem(ch, NULL, NULL);
    if (cursor->next != NULL) {
      cursor->next->prev = newElem;
      newElem->next = cursor->next;
    }
    cursor->next = newElem;
    newElem->prev = cursor;
    cursor = newElem;
  }
  void print() {
    elem* p = firstElem->next;
    while(p != NULL) {
      cout << p->ch;
      p = p->next;
    } 
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  string str;
  int n;
  cin >> str >> n;
  editor e(str);

  for (int i = n; i--;) {
    char op;
    cin >> op;

    switch (op) {
    case 'L':
      e.L();
      break;
    case 'D':
      e.D();
      break;
    case 'B':
      e.B();
      break;
    case 'P':
      char ch;
      cin >> ch;
      e.P(ch);
      break;
    }
  }

  e.print();

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
