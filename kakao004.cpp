#include <deque>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
  vector<long long> answer;
  deque<long long> dq;

  dq.push_back(room_number.front());
  for (int i = 1; i < room_number.size(); i++) {
    if (room_number[i] < dq.front()) {
      dq.push_front(room_number[i]);
      answer.push_back(room_number[i]);
    } else if (room_number[i] > dq.back()) {
      dq.push_back(room_number[i]);
      answer.push_back(room_number[i]);
    } else {
      long long target = room_number[i];
      int left = 0, right = dq.size() - 1;
      int least = right;
      while (1) {
        int mid = (right + left) / 2;
        if (mid == left)
          break;
        if (dq[mid] < target) {
          right = mid - 1;
          least = right;
        } else if (dq[mid] >= target)
          left = mid + 1;
      }
      dq.insert(dq[least]);
    }
  }

  return answer;
}

int main() {
  int k = 10;
  vector<long long> v{1, 3, 4, 1, 3, 1};
  vector<long long> res = solution(k, v);
  for (long long ll : res)
    cout << ll << ' ';
}