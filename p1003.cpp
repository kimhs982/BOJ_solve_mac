// 1003번, 피보나치 함수
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <utility>
using std::make_pair;
using std::pair;

#include <memory>
using std::unique_ptr;

pair<int, int> fibonacci_01_count(int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        pair<int, int> list_01 = fibonacci_01_count(N);
        cout << list_01.first << ' ' << list_01.second << '\n';
    }

    return 0;
}

// 연산자(+) 오버로딩, pair 객체
pair<int, int> operator+(pair<int, int> &P1, pair<int, int> &P2)
{
    return make_pair(P1.first + P2.first, P1.second + P2.second);
}

// 피보나치 함수, 0과 1의 호출 횟수 구하기, DP
pair<int, int> fibonacci_01_count(int in_N)
{
    unique_ptr<pair<int, int>[]> F(new pair<int, int>[in_N + 1]);
    // F[0] = {1, 0}, F[1] = {0, 1};
    F[0] = make_pair(1, 0), F[1] = make_pair(0, 1);

    for (int i = 2; i <= in_N; i++)
        F[i] = F[i - 1] + F[i - 2];

    return F[in_N];
}