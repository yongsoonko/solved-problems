#include <time.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;

  vector<int> v(10001, 0);
  for(int i=0; i<n; i++) {
    int input;
    cin >> input;

    v[input]++;
  }

  for(int i=1; i<=10000; i++) {
    int size = v[i];
    for(int j=0; j<size; j++) {
      cout << i << '\n';
    }
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
