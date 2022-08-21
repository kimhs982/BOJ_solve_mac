// 15650번, N과 M(2)
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

int num_arr[8];

void NandM(int, int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    NandM(N, M, 0);

    return 0;
}

// 백트래킹, 재귀함수
void NandM(int in_N, int in_M, int height)
{
    if (height == in_M)
    {
        for (int i = 0; i < in_M; i++)
            cout << num_arr[i] << ' ';
        cout << '\n';
    }
    else
    {
        for (int i = (height - 1 < 0 ? 0 : num_arr[height - 1]); i < in_N; i++)
        {
            num_arr[height] = i + 1;
            NandM(in_N, in_M, height + 1);
        }
    }
}