// Example program
#include <iostream>
#include <vector>

using namespace std;

int m;

void solution(vector<int> &v, vector<int> &v2, int round)
{
    if (round == m)
    {
        for (int i : v2)
        {
            printf("%d ", i);
        }
        printf("\n");
        return;
    }

    vector<int> temp;

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {

        if (v.end() - it < m - round)
        {
            //printf("--%d %d--\n", v.end()-it, m-round);
            return;
        }

        vector<int>().swap(temp);

        v2.push_back(*it);
        temp.insert(temp.begin(), v.begin(), it + 1);
        v.erase(v.begin(), it + 1);

        solution(v, v2, round + 1);

        v.insert(v.begin(), temp.begin(), temp.end());
        v2.pop_back();
    }
}

int main()
{
    int n;
    vector<int> v;
    vector<int> v2;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    solution(v, v2, 0);
}
