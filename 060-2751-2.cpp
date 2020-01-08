#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

vector<int> v;
vector<int> ans;

void mergeSort(int i, int size) {
  if (size == 1) {
    return;
  }

  int a = size / 2, b = size - a;
  int j = i + a, k = i;
  int iend = j, jend = i + size;
  int tmp = i;
  mergeSort(i, a);
  mergeSort(j, b);

  while (i < iend && j < jend) {
    if (v[i] > v[j]) {
      ans[k++] = v[j++];
    } else if (v[i] < v[j]) {
      ans[k++] = v[i++];
    }
  }

  while (i < iend) {
    ans[k++] = v[i++];
  }
  while (j < jend) {
    ans[k++] = v[j++];
  }

  for(int i=0; i<size; i++) {
    v[tmp+i] = ans[tmp+i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start = clock();

  int n, cnt;
  cin >> n;
  cnt = n;
  v.reserve(n);
  ans.assign(n, 0);

  while (cnt--) {
    int input;
    cin >> input;
    v.push_back(input);
  }

  mergeSort(0, n);

  if(n == 1) {
    cout << v[0];
  } else {
    for(int i: ans) {
      cout << i << '\n';
    }
  }

  float _time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "\ntime : " << _time;
}
