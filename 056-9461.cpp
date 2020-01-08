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

  int n;
  cin >> n;

  vector<long long> v(101, 0);
  v[1] = v[2] = v[3] = 1;
  v[4] = v[5] = 2;
  while (n--) {
    int input;
    cin >> input;

    for (int i = 6; i <= input; i++) {
      v[i] = v[i - 1] + v[i - 5];
    }

    cout << v[input] << '\n';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
