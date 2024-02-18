// 1629번, 곱셈
#include <iostream>
using namespace std;

// 예시 답안(거듭 제곱 -> 분할 정복)
int A, B, C;

long long abc_mod(int a, int b)
{
    if (b == 1)
        return a % C;
    long long result{abc_mod(a, b / 2)};
    result = (result * result) % C;
    if (b & 1)
        result = (result * a) % C;
    return result;
}

int main()
{
    cin >> A >> B >> C;
    cout << abc_mod(A, B) << '\n';
}