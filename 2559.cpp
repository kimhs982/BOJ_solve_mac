// 2559번, 수열
#include <iostream>
#include <climits>
using namespace std;

// int N, K, sum[100004], max_temp{INT_MIN};
// int main()
// {
//     cin >> N >> K;
//     for (int i{1}; i <= N; i++)
//     {
//         int temp;
//         cin >> temp;
//         sum[i] = sum[i - 1] + temp;
//         if (i >= K && (sum[i] - sum[i - K] > max_temp))
//             max_temp = sum[i] - sum[i - K];
//     }
//     cout << max_temp << '\n';
//     return 0;
// }

typedef long long ll;
int N, K, temp, sum[100004], max_temp{-10000004};
int main()
{
    cin >> N >> K;
    for (int i{1}; i <= N; i++)
    {
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    for (int i{K}; i <= N; i++)
        max_temp = max(max_temp, sum[i] - sum[i - K]);
    cout << max_temp << '\n';
    return 0;
}