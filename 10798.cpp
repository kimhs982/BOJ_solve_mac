// 10798번, 세로읽기
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<char>> blackBoard;
    blackBoard.reserve(5);

    // 칠판에 자석 붙이기
    for (int i = 0; i < 5; i++)
    {
        vector<char> magnetWord(15);

        for (int j = 0; j < 16; j++)
        {
            char temp = cin.get();

            if (temp == '\n')
                break;
            else
                magnetWord[j] = temp;
        }
        blackBoard.emplace_back(magnetWord);
    }

    vector<char> verticalRead;

    // 칠판에 붙여진 단어들 세로 읽기
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 5; j++)
            if (blackBoard[j][i] == NULL)
                continue;
            else
                verticalRead.emplace_back(blackBoard[j][i]);

    for (int i = 0; i < verticalRead.size(); i++)
        cout << verticalRead[i];

    return 0;
}