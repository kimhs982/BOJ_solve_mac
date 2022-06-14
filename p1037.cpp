// 1037번, 약수
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <cmath>

int getMultipleNum(int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int factor_num;
    cin >> factor_num;

    cout << getMultipleNum(factor_num) << '\n';

    return 0;
}

// 입력받은 약수 중에서 가장 큰 수와 가장 작은 수를 곱함
int getMultipleNum(int factorNum)
{
    int A, min, max;

    cin >> A;
    min = max = A;
    for (int i = 1; i < factorNum; i++)
    {
        cin >> A;
        if (A > max)
            max = A;
        if (A < min)
            min = A;
    }
    return min * max;
}