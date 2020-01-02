//야구 게임
#include <iostream>
#include <random>
#include <time.h>
#include <vector>

using namespace std;

vector<int> ans(3);

void makeAnswer()
{
    unsigned seed;
    // random_device rd;
    // seed = rd(); //특정 컴파일러에서 random_device를 항상 0으로 리턴함
    seed = clock();
    mt19937_64 rng(seed);
    uniform_int_distribution<__int64> dist1;

    vector<int> v(10);
    int tmp = 0, tmp2;
    for (int &i : v)
    {
        i = tmp;
        tmp++;
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        uniform_int_distribution<__int64>::param_type pt(0, v.size() - 1);
        dist1.param(pt);

        tmp = dist1(rng);
        tmp2 = v[tmp];
        v.erase(v.begin() + tmp);
        ans[ans.size() - 1 - i] = tmp2;
    }

    // printf("정답 : ");
    // for (int i : ans)
    //     printf("%d ", i);
    // printf("\n");
}

void check(vector<int> input)
{
    int b = 0, s = 0, o = 0;
    for (int i = 0; i < input.size(); i++)
        for (int j = 0; j < ans.size(); j++)
        {
            if (input[i] == ans[j])
            {
                if (i == j)
                    s++;
                else
                    b++;
                break;
            }
            else
                //마지막 인덱스 일 때
                if (j == ans.size() - 1)
                    o++;
        }

    if (o == 3)
        printf("아웃\n");
    else
        printf("%dS %dB\n", s, b);
}

int main()
{
    vector<int> input(3);
    makeAnswer();

    while (true)
    {
        for (int &i : input)
            scanf("%d", &i);

        check(input);
    }
}