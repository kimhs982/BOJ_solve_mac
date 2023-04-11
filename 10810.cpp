// 10810번, 공 넣기
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 바구니 N개, 공을 넣는 횟수 M번

    cin >> N >> M;

    int *basket = new int[N]();

    for (int l = 0; l < M; l++)
    {
        int i, j, k;
        cin >> i >> j >> k;

        for (int m = i - 1; m < j; m++)
        {
            basket[m] = k;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << basket[i] << " ";
    }
    cout << '\n';

    delete[] basket;
    return 0;
}