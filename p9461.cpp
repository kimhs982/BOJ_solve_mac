// 9461번, 파도반 수열
#include <cstdio>

#include <memory>
using std::unique_ptr;

// unsigned (int) 사용 X -> 범위 초과
unsigned long long get_P(int);

int main()
{
    int T, N;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        printf("%llu\n", get_P(N));
    }

    return 0;
}

unsigned long long get_P(int in_N)
{
    if (in_N < 4)
        return 1;

    unique_ptr<unsigned long long[]> P(new unsigned long long[in_N]);

    // N이 1, 2, 3인 경우 -> 1
    P[0] = P[1] = P[2] = 1;
    // 점화식 : P[N] = P[N - 2] + P[N - 3]
    for (int i = 3; i < in_N; i++)
        P[i] = P[i - 2] + P[i - 3];

    return P[in_N - 1];
}