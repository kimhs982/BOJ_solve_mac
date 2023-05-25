// 2738번, 행렬 덧셈
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // N(행), M(열)
    cin >> N >> M;

    // 2차원 배열 동적할당
    int **matrix = new int *[N];
    for (int i = 0; i < N; i++)
        matrix[i] = new int[M]();

    // 두 행렬(A, B)에 값 넣기 & 더하기
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                int temp;
                cin >> temp;
                matrix[j][k] += temp;
            }

    // 행렬 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << matrix[i][j] << ' ';
        cout << '\n';
    }

    // 2차원 배열 할당 해제
    for (int i = 0; i < N; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}