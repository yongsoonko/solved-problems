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

  int a;
  cin >> a;
  vector<int> nums;
  nums.reserve(a);
  for (int i = 0; i < a; i++) {
    nums.push_back(i);
  }
  // for(int i: nums) {
  //   cout << i << ' ';
  // }

  // clock_t start = clock();

  for (int i = 0; i < a - 1; i++) {
    nums[i + 1] = min(nums[i] + 1, nums[i + 1]);
    if (i + 1 <= a / 3) {
      nums[(i + 1) * 3 - 1] = min(nums[i] + 1, nums[(i + 1) * 3 - 1]);
    }
    if (i + 1 <= a / 2) {
      nums[(i + 1) * 2 - 1] = min(nums[i] + 1, nums[(i + 1) * 2 - 1]);
    }
  }
  cout << nums[a - 1] << '\n';

  // float time = (float)(clock() - start) / CLOCKS_PER_SEC;
  // cout << "time : " << time;
}
