// 25304번, 영수증
#include <cstdio>

int main()
{
    int X, N, a, b;
    int sum = 0;

    scanf("%d%d", &X, &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        sum += (a * b);
    }

    if (X == sum)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}