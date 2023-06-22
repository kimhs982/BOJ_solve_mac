// 2745번, 진법 변환
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <string>
using std::string;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N; // B진법 수 N
    int B;    // B진법

    cin >> N >> B;

    int transformedNumber = 0; // 10진법으로 변환된 숫자
    for (int i = N.size() - 1; i >= 0; i--)
    {
        int char_to_int_minus;
        if (N[i] >= 65)
            char_to_int_minus = 55;
        else
            char_to_int_minus = 48;

        int involutionNumber = 1;
        for (int j = 1; j < N.size() - i; j++)
            involutionNumber *= B;
        transformedNumber += (N[i] - char_to_int_minus) * involutionNumber;
    }

    cout << transformedNumber << '\n';

    return 0;
}