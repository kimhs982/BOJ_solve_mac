// 2444번, 별 찍기 - 7
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 첫 번째 풀이
    // int blankNum = N - 1;
    // int starNum = 1;

    // while (blankNum >= 0)
    // {
    //     for (int j = 0; j < blankNum; j++)
    //         cout << ' ';

    //     for (int j = 0; j < starNum; j++)
    //         cout << '*';
    //     cout << '\n';

    //     blankNum--;
    //     starNum += 2;
    // }

    // blankNum = 1;
    // starNum = 2 * N - 3;
    // while (starNum >= 1)
    // {
    //     for (int j = 0; j < blankNum; j++)
    //         cout << ' ';

    //     for (int j = 0; j < starNum; j++)
    //         cout << '*';
    //     cout << '\n';

    //     blankNum++;
    //     starNum -= 2;
    // }

    // 두 번째 풀이(다른 사람 풀이 참고)
    for (int line = 1; line <= 2 * N - 1; line++)
    {
        if (line <= N)
        {
            for (int i = N - line; i > 0; i--)
                cout << ' ';

            for (int i = 2 * line - 1; i > 0; i--)
                cout << '*';

            cout << '\n';
        }
        else
        {
            for (int i = 0; i < line - N; i++)
                cout << ' ';

            for (int i = 0; i < 4 * N - 2 * line - 1; i++)
                cout << '*';

            cout << '\n';
        }
    }

    return 0;
}