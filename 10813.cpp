// 10813번, 공 바꾸기
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

void swap(int &, int &);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // N개의 바구니, M번 공을 바꿈
    cin >> N >> M;

    // basket 생성 & 초기화
    int *basket = new int[N];
    for (int i = 0; i < N; i++)
    {
        *(basket + i) = i + 1;
    }

    // 바구니의 공 M번 교환
    for (int k = 0; k < M; k++)
    {
        int i, j; // i번 바구니와 j번 바구니의 공을 교환
        cin >> i >> j;

        swap(basket[i - 1], basket[j - 1]);
    }

    // 바구니의 공 출력
    for (int i = 0; i < N; i++)
    {
        cout << basket[i] << ' ';
    }
    cout << '\n';

    delete[] basket;

    return 0;
}

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}