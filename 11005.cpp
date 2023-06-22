// 11005번, 진법 변환 2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, B; // 10진법 수, 변환할 진법 B
    cin >> N >> B;

    int quotient = N;             // 몫
    char remainder;               // 나머지
    vector<char> convertedNumber; // B진법으로 변환된 숫자
    while (quotient != 0)
    {
        // 나머지 계산
        int temp = quotient % B;
        if (temp >= 10)
            remainder = char(temp + 55);
        else
            remainder = char(temp + 48);
        convertedNumber.emplace_back(remainder);

        // 몫 계산
        quotient /= B;
    }

    for (int i = convertedNumber.size() - 1; i >= 0; i--)
        cout << convertedNumber[i];
    cout << '\n';

    return 0;
}