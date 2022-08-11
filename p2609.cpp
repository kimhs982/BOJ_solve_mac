// 2609번, 최대공약수와 최소공배수
#include <algorithm>
using std::swap;

#include <cstdio>

int getGCD(int, int);

int main()
{
    int first, second;
    scanf("%d%d", &first, &second);

    int GCD, LCM;
    GCD = getGCD(first, second);
    LCM = first * second / GCD;

    printf("%d\n%d\n", GCD, LCM);
    return 0;
}

// 유클리드 호제법
int getGCD(int num1, int num2)
{
    int low = (num1 < num2 ? num1 : num2);
    int high = (num1 > num2 ? num1 : num2);

    while (1)
    {
        if ((high % low == 0) || (low == 1))
            break;
        high -= low;
        if (low > high)
            swap(low, high);
    }
    return low;
}