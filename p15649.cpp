// 1549번, N과 M(1)
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

int num_arr[8];
bool isUsed[8];
void NandM_DFS(int, int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    NandM_DFS(N, M, 0);

    return 0;
}

// 백트래킹
void NandM_DFS(int in_N, int in_M, int depth)
{
    if(depth == in_M)
    {
        for(int i = 0; i < in_M; i++)
            cout << num_arr[i] << ' ';
        cout << '\n';
    }
    else
    {
        for(int i = 0; i < in_N; i++)
        {
            if(!isUsed[i])
            {
                num_arr[depth] = i + 1;
                isUsed[i] = true;
                NandM_DFS(in_N, in_M, depth + 1);
                isUsed[i] = false;
            }
        }
    }
}