#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, b;
  cin >> n >> b;

  int remain;
  string str = "";
  do {
    char ch;
    remain = n % b;
    n /= b;
    if (remain < 10)
      ch = '0' + remain;
    else
      ch = 'A' + (remain - 10);
    str = ch + str;
  } while (n != 0);

  cout << str;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
