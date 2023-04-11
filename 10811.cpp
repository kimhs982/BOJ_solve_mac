// 10811번, 바구니 뒤집기
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <vector>
using std::vector;

#include <algorithm>
using std::reverse;

void reverseBasketOrder(vector<int> &, int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // N개의 바구니, M번 역순 만들기

    cin >> N >> M;

    vector<int> basket;
    basket.reserve(N);
    for (int i = 0; i < N; i++)
        basket.push_back(i + 1);

    for (int k = 0; k < M; k++)
    {
        int i, j;
        cin >> i >> j;

        // reverseBasketOrder(basket, i, j);
        reverse(basket.begin() + i - 1, basket.begin() + j);
    }

    for (int i = 0; i < N; i++)
        cout << basket[i] << ' ';
    cout << '\n';

    return 0;
}

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void reverseBasketOrder(vector<int> &B, int I, int J)
{
    while (I < J)
    {
        swap(B[I - 1], B[J - 1]);
        I++, J--;
    }
}