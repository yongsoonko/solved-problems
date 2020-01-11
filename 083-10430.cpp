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

  int a, b, c;
  cin >> a >> b >> c;

  cout << (a + b) % c << '\n';
  cout << (a % c + b % c) % c << '\n';
  cout << (a * b) % c << '\n';
  cout << (a % c * b % c) % c << '\n';

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
