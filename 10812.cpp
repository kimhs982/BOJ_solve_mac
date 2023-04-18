// 10812번, 바구니 순서 바꾸기
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <vector>
using std::vector;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 바구니 수 N개, 순서 회전 횟수 M
    cin >> N >> M;

    vector<int> basket;
    basket.reserve(N);
    for (int i = 0; i < N; i++)
        basket.emplace_back(i + 1);

    for (int cnt1 = 0; cnt1 < M; cnt1++)
    {
        int i, j, k; // i(begin), j(end), k(standard)
        cin >> i >> j >> k;

        for (int cnt2 = i - 1; cnt2 < k - 1; cnt2++)
        {
            basket.emplace(basket.begin() + j, basket[i - 1]);
            basket.erase(basket.begin() + i - 1);
        }
    }

    for (int i = 0; i < N; i++)
        cout << basket[i] << ' ';
    cout << '\n';

    return 0;
}