// 2903번, 중앙 이동 알고리즘
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 반복 횟수
    cin >> N;

    int squareNum = 1;     // 정사각형 개수
    int dotNum = 4;        // 점의 개수
    int twoInvolution = 1; // 2의 거듭제곱
    for (int i = 1; i <= N; i++)
    {
        dotNum += squareNum * 5 - 2 * twoInvolution * (twoInvolution - 1);
        squareNum *= 4;
        twoInvolution *= 2;
    }
    cout << dotNum << '\n';

    // 다른 풀이
    /*
    int N;      // 반복 횟수
    cin >> N;

    int squareNum = 2;
    for(int i = 0; i < N; i ++)
    {
        squareNum *= 2;
        squareNum--;
    }
    squareNum *= squareNum;

    cout << squareNum << '\n';
    */

    return 0;
}