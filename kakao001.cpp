#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  int N = board.size();
  vector<int> bu;

  vector<vector<int>> b(board[0].size() + 1);
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] > 0)
        b[j + 1].push_back(board[i][j]);
    }
  }

  // for (int i = 0; i <= N; i++) {
  //   for (int j = 0; j < b[i].size(); j++)
  //     cout << b[i][j];
  //   cout << '\n';
  // }

  for (int i = 0; i < moves.size(); i++) {
    int pos = moves[i];
    if (b[pos].size()) {
      int top = b[pos].back();
      b[pos].pop_back();

      if (bu.size() && bu.back() == top) {
        answer += 2;
        bu.pop_back();
      } else
        bu.push_back(top);
    }
  }

  return answer;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> b(N);
  vector<int> m;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      b[i].push_back(a);
    }

  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    m.push_back(a);
  }

  cout << solution(b, m);
}