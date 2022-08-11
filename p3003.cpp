// 3003번, 킹, 퀸, 룩, 비숍, 나이트, 폰
#include <cstdio>

#include <vector>
using std::vector;

void whiteChessPiece(vector<int> &);

int main()
{
    vector<int> pieceList;
    pieceList.reserve(6);

    for (int i = 0; i < 6; i++)
    {   
        int temp;
        scanf("%d", &temp);
        pieceList.__emplace_back(temp);
    }

    whiteChessPiece(pieceList);

    for (int i = 0; i < 6; i++)
        printf("%d ", pieceList[i]);
    printf("\n");

    return 0;
}

void whiteChessPiece(vector<int> &PL)
{
    vector<int> originalPiece;
    originalPiece.reserve(6);
    for(int i = 0; i < 2; i++)
        originalPiece.__emplace_back(1);
    for(int i = 0; i < 3; i++)
        originalPiece.__emplace_back(2);
        originalPiece.__emplace_back(8);

    for (int i = 0; i < 6; i++)
        PL[i] = originalPiece[i] - PL[i];
}