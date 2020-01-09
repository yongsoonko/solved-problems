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

  string a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << atoll((a + b).c_str()) + atoll((c + d).c_str());

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
