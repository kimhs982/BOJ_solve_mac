// 2720번, 세탁소 사장 동혁
#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int T; // 테스트 케이스의 개수
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int C; // 거스름 돈
        cin >> C;

        cout << C / 25 << ' '; // 쿼터
        C %= 25;
        cout << C / 10 << ' '; // 다임
        C %= 10;
        cout << C / 5 << ' '; // 니켈
        C %= 5;
        cout << C << '\n'; // 페니
    }

    return 0;
}