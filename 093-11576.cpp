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

  int a, b, m;
  cin >> a >> b >> m;

  vector<int> v;
  v.reserve(m);
  for(int i=m; i--;) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  int size = v.size();
  int dec = v[0];
  for(int i=1; i<size; i++) {
    dec = dec * a + v[i];
  }

  vector<int> ans;
  int remain;
  do {
    remain = dec % b;
    dec /= b; 
    ans.push_back(remain);
  } while(dec != 0);

  for(auto it = ans.rbegin(); it!=ans.rend(); it++) {
    cout << *it << ' ';
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
