#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n;
  cin >> n;

  vector<pair<int, int>> v(n);
  vector<string> v2(n);

  for(int i=0; i<n; i++) {
    int input;
    string input2;
    cin >> input >> input2;
    v[i] = make_pair(input, i);
    v2[i] = input2;
  }

  sort(v.begin(), v.end());

  for(int i=0; i<n; i++) {
    cout << v[i].first << ' ' << v2[v[i].second] << '\n';
  }  

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
