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

  string n;
  int b;
  cin >> n >> b;

  int ans;
  if(n[0] >= 'A')
    ans = 10 + n[0] - 'A';
  else
    ans = n[0] - '0';
  
  int len = n.length();
  for(int i=1; i<len; i++) {
    int tmp;
    if(n[i] >= 'A')
      tmp = 10 + n[i] - 'A';
    else
      tmp = n[i] - '0';
    
    ans = ans * b + tmp;
  }

  cout << ans;

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
