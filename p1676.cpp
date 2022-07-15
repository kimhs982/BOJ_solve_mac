// 1676번, 팩토리얼 0의 개수
// 주의 : 0! = 1, 십의 자리수까지 확인!
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

unsigned int count_zero_in_factorial(unsigned int);

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    unsigned int N, zero_cnt;
    cin >> N;

    zero_cnt = count_zero_in_factorial(N);

    cout << zero_cnt << '\n';

    return 0;
}

unsigned int count_zero_in_factorial(unsigned int in_N)
{
    unsigned int zero_cnt = 0, cal = in_N;
    for (int i = in_N - 1; i > 0; i--)
    {
        cal *= i;
        while (cal >= 100)
            if (cal % 10 == 0)
            {
                zero_cnt++;
                cal /= 10;
            }
            else
                cal %= 100;
    }

    return zero_cnt;
}