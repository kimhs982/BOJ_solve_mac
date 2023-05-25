// 2566번, 최댓값
#include <iostream>
using std::cin;
using std::cout;

#include <limits.h>

int main()
{
    int maxValue = INT_MIN;
    int row = 0, column = 0;

    // 9 x 9 격자판 숫자 입력
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            int temp;
            cin >> temp;
            if (temp > maxValue)
            {
                maxValue = temp;
                row = i, column = j;
            }
        }

    // 최댓값, 최댓값이 존재하는 행 & 열 번호 출력
    cout << maxValue << '\n'
         << row << ' ' << column;

    return 0;
}