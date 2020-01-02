#include <iostream>
#include <vector>

using namespace std;
int cnt;

void solution(vector<int> &v, vector<int> &result, int round)
{
    if (round == cnt)
    {
        for (int i : result)
        {
            printf("%d ", i);
        }
        printf("\n");
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        int temp = *it;
        vector<int>::iterator temp2 = v.erase(it);
        result.push_back(temp);
        solution(v, result, round + 1);
        result.pop_back();
        v.insert(temp2, temp);
    }
}

int main()
{

    int a, b;
    cin >> a >> b;

    vector<int> v(a, 1);
    vector<int> result;

    for (int i = 0; i < a; i++)
    {
        v[i] += i;
    }

    cnt = b;

    solution(v, result, 0);
}