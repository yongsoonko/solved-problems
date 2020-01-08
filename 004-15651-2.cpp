// Example program
#include <iostream>

using namespace std;

int main()
{
    int n, m, round = 0;
    scanf("%d %d", &n, &m);

    for (int a = 1; a <= n; a++)
    {
        round = 1;
        if (m == round)
        {
            printf("%d\n", a);
            continue;
        }
        for (int b = 1; b <= n; b++)
        {
            round = 2;
            if (m == round)
            {
                printf("%d %d\n", a, b);
                continue;
            }
            for (int c = 1; c <= n; c++)
            {
                round = 3;
                if (m == round)
                {
                    printf("%d %d %d\n", a, b, c);
                    continue;
                }
                for (int d = 1; d <= n; d++)
                {
                    round = 4;
                    if (m == round)
                    {
                        printf("%d %d %d %d\n", a, b, c, d);
                        continue;
                    }
                    for (int e = 1; e <= n; e++)
                    {
                        round = 5;
                        if (m == round)
                        {
                            printf("%d %d %d %d %d\n", a, b, c, d, e);
                            continue;
                        }
                        for (int f = 1; f <= n; f++)
                        {
                            round = 6;
                            if (m == round)
                            {
                                printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
                                continue;
                            }
                            for (int g = 1; g <= n; g++)
                            {
                                round = 7;
                                if (m == round)
                                {
                                    printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}