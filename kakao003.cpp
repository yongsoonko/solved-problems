#include <string>
#include <vector>

#include <iostream>

using namespace std;

int chk[11111112];
int chk2[8];
int answer;

void dfs(vector<string> &user_id, vector<string> &banned_id, int curr) {
  int N = banned_id.size(), M = user_id.size();
  if (curr == N) {
    int num = 0;
    for (int i = 0; i < M; i++)
      num = num * 10 + chk2[i];
    if (chk[num] == 0) {
      answer++;
      // cout << num << '\n';
    }
    chk[num] = 1;
    return;
  }

  for (int j = 0; j < M; j++) {
    if (!chk2[j] && banned_id[curr].size() == user_id[j].size()) {
      int flag = 1;
      for (int k = 0; k < banned_id[curr].size(); k++) {
        if (banned_id[curr][k] != '*' && banned_id[curr][k] != user_id[j][k]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        chk2[j] = 1;
        dfs(user_id, banned_id, curr + 1);
        chk2[j] = 0;
      }
    }
  }
}

int solution(vector<string> user_id, vector<string> banned_id) {
  dfs(user_id, banned_id, 0);
  return answer;
}

int main() {
  int tc = 3;
  while (tc--) {
    fill(chk, chk + 11111112, 0);
    fill(chk2, chk2 + 8, 0);
    answer = 0;

    int N, M;
    cin >> N >> M;

    vector<string> u, b;
    for (int i = 0; i < N; i++) {
      string str;
      cin >> str;
      u.push_back(str);
    }

    for (int i = 0; i < M; i++) {
      string str;
      cin >> str;
      b.push_back(str);
    }

    cout << solution(u, b) << "\n\n";
  }
}