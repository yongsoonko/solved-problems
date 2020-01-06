#include <algorithm>
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

  int n, cnt;
  cin >> n;
  cnt = n;

  vector<vector<int>> v(200001, vector<int>());
  while (cnt--) {
    int input, input2;
    cin >> input >> input2;

    v[input + 100000].push_back(input2);
  }

  for (int i = 0; i < 200001; i++) {
    vector<int> tmp = v[i];
    if (!tmp.empty()) {
      sort(tmp.begin(), tmp.end());
      int size = tmp.size();
      for (int j = 0; j < size; j++) {
        cout << i - 100000 << ' ' << tmp[j] << '\n';
      }
    }
  }
  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
