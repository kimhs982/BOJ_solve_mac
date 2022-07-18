// 2004번, 조합 0의 개수
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <algorithm>
using std::min;

int count_zero_BinomialCoefficient(long long, long long);
int count_zero_BinomialCoefficient_fail(unsigned int, unsigned int);
int BinomialCoefficient(int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;
    cin >> n >> m;

    cout << count_zero_BinomialCoefficient(n, m) << '\n';

    return 0;
}

// unsigned 사용 X -> long long 사용
/*예) 10!에서 곱해진 2, 5의 개수
2가 1번 곱해져 있는 수 : 2, 6, 10
2가 2번 곱해져 있는 수 : 4
2가 3번 곱해져 있는 수 : 8
10 / 2 = 5 -> 2, 4, 6, 8, 10
10 / 4 = 2 -> 4, 8
10 / 8 = 1 -> 8

5가 1번 곱해져 있는 수 : 5, 10;
10 / 5 = 2 -> 5, 10
*/
int count_zero_BinomialCoefficient(long long in_n, long long in_m)
{
    int cnt_2 = 0, cnt_5 = 0;

    // 소인수분해 -> 2의 개수
    for (long long i = 2; i <= in_n; i *= 2)
        cnt_2 += in_n / i;
    for (long long i = 2; i <= in_n - in_m; i *= 2)
        cnt_2 -= (in_n - in_m) / i;
    for (long long i = 2; i <= in_m; i *= 2)
        cnt_2 -= in_m / i;

    // 소인소분해 -> 5의 개수
    for (long long i = 5; i <= in_n; i *= 5)
        cnt_5 += in_n / i;
    for (long long i = 5; i <= in_n - in_m; i *= 5)
        cnt_5 -= (in_n - in_m) / i;
    for (long long i = 5; i <= in_m; i *= 5)
        cnt_5 -= in_m / i;

    return min(cnt_2, cnt_5);
}

// nCk = n! / k! * (n - k)! -> 분자의 0의 개수 - 분모의 0의 개수 = 이항계수(계산값)의 0의 개수
// 정확한 값을 얻지 못함!
int count_zero_BinomialCoefficient_fail(unsigned int in_n, unsigned int in_m)
{
    int cnt = 0;
    if (in_n == in_m || in_m == 0)
        return cnt;
    else
    {
        in_m = min(in_m, in_n - in_m);
        // 분자의 0의 갯수 계산
        unsigned int numerator_cal = in_n;
        for (int i = 1; i < in_m; i++)
        {
            numerator_cal *= (in_n - i);
            while (numerator_cal >= 100)
                if (numerator_cal % 10 == 0)
                {
                    cnt++;
                    numerator_cal /= 10;
                }
                else
                    numerator_cal %= 100;
        }
        cout << "분자 나머지 출력" << numerator_cal << '\n';

        // 분모의 0의 갯수 계산
        unsigned int denominator_cal = in_m;
        for (int i = in_m - 1; i > 1; i--)
        {
            denominator_cal *= i;
            while (denominator_cal >= 100)
                if (denominator_cal % 10 == 0)
                {
                    cnt--;
                    denominator_cal /= 10;
                }
                else
                    denominator_cal %= 100;
        }
        cout << "분모 나머지 출력" << denominator_cal << '\n';
    }

    return cnt;
}

// 이항 계수(Binomial Coefficient) - 동적 계획법, DP -> 메모리 초과
// N_C_K
int BinomialCoefficient(int N, int K)
{
    int result;
    int **BC = new int *[N + 1];
    for (int i = 0; i < N + 1; i++)
        *(BC + i) = new int[K + 1];

    for (int n = 1; n <= N; n++)
        for (int k = 0; k <= min(n, K); k++)
            if ((k == 0) || (k == n))
                BC[n][k] = 1;
            else
                BC[n][k] = BC[n - 1][k - 1] + BC[n - 1][k];

    result = BC[N][K];

    for (int i = 0; i < N + 1; i++)
        delete[] BC[i];
    delete[] BC;

    return result;
}