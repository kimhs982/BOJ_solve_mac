// 5086번, 배수와 약수
#include <cstdio>

void relationOfTwo(int, int);

int main()
{
    int num1, num2;

    while (1)
    {
        scanf("%d%d", &num1, &num2);
        if ((num1 == 0) && (num2 == 0))
            break;
        relationOfTwo(num1, num2);
    }

    return 0;
}

void relationOfTwo(int first, int second)
{
    if (second % first == 0)
        printf("factor\n");
    else if (first % second == 0)
        printf("multiple\n");
    else
        printf("neither\n");
}