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

  vector<int> v(2000001, 0);
  while(n--) {
    int input;
    cin >> input;

    v[input+1000000] = 1;
  }

  for(int i=0; i<=2000000; i++) {
    if(v[i] == 1) {
      cout << i-1000000 << '\n';
    }
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
