// 1010번, 다리 놓기
#include <cstdio>

int buildBridge(int, int);

int main()
{
    int rep, N, M;
    scanf("%d", &rep);

    for (int i = 0; i < rep; i++)
    {
        scanf("%d%d", &N, &M);
        printf("%d\n", buildBridge(N, M));
    }

    return 0;
}

// 점화식 : B[i+1][j]=sum_i<=k<=j-1(B[i][k])
int buildBridge(int in_N, int in_M)
{
    int result = 0;
    int **B = new int *[in_N];
    for (int i = 0; i < in_N; i++)
        *(B + i) = new int[in_M]();

    for (int i = 0; i < in_N; i++)
        for (int j = i; j < in_M - (in_N - (i + 1)); j++)
        {
            if (i == 0)
                B[i][j] = 1;
            else
                for (int k = 0; k < j; k++)
                    B[i][j] += B[i - 1][k];
        }

    for (int i = in_N - 1; i < in_M; i++)
        result += B[in_N - 1][i];

    for (int i = 0; i < in_N; i++)
        delete[] B[i];
    delete[] B;

    return result;
}