#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class deque {
  int data[20002];
  int head, tail;

public:
  deque() : head(10000), tail(10000) {}
  void push_front(int a) {
    data[--head] = a;
  }
  void push_back(int a) {
    data[tail++] = a;
  }
  void pop_front() {
    if (tail - head > 0) {
      cout << data[head] << '\n';
      head++;
    } else
      cout << -1 << '\n';
  }
  void pop_back() {
    if (tail - head > 0) {
      cout << data[tail - 1] << '\n';
      tail--;
    } else
      cout << -1 << '\n';
  }
  void size() {
    cout << tail - head << '\n';
  }
  void empty() {
    cout << (tail - head > 0 ? 0 : 1) << '\n';
  }
  void front() {
    if (tail - head > 0)
      cout << data[head] << '\n';
    else
      cout << -1 << '\n';
  }
  void back() {
    if (tail - head > 0)
      cout << data[tail - 1] << '\n';
    else
      cout << -1 << '\n';
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int N;
  cin >> N;
  deque dq;
  while (N--) {
    int a;
    string str;
    cin >> str;
    if (str == "push_front") {
      cin >> a;
      dq.push_front(a);
    } else if (str == "push_back") {
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
