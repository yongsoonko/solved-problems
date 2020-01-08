// Example program
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int m;

void solution(vector<int>& v2, int round) {
    if(round==m) {
        for(int i: v2) {
            printf("%d ", i);
        }
        printf("\n");
        return;
    }

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
        v2.push_back(*it);
        solution(v2, round+1);
        v2.pop_back();
    }
}

int main()
{
    int n;
    vector<int> v2;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    solution(v2, 0);
}