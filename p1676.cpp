// 1676번, 팩토리얼 0의 개수
// 주의 : 0! = 1, 십의 자리수까지 확인!
// 10 = 2 * 5 -> 소인수분해하여 2와 5의 개수를 비교 -> 그 중에 최소가 0의 개수
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <algorithm>
using std::min;

unsigned int count_zero_in_factorial(unsigned int);
unsigned int count_zero_in_factorial_new(unsigned int);

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    unsigned int N, zero_cnt;
    cin >> N;

    // zero_cnt = count_zero_in_factorial(N);
    zero_cnt = count_zero_in_factorial_new(N);

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

unsigned int count_zero_in_factorial_new(unsigned int in_N)
{
    int cnt_2 = 0, cnt_5 = 0;
    if(in_N == 0)
        return 0;
    
    for(unsigned int i = in_N; i > 1; i--)
    {
        bool check = true;
        unsigned int copy = i;
        while(check)
        {
            check = false;
            if (copy % 2 == 0)
            {
                copy /= 2;
                cnt_2++;
                check = true;
            }
            if(copy % 5 == 0)
            {
                copy /= 5;
                cnt_5++;
                check = true;
            }
        }
    }

    return min(cnt_2, cnt_5);
}