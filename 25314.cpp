#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#include <string>
using std::string;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 4 <= N <= 1000, 4의 배수
    cin >> N;

    for (int i = 0; i < N / 4; i++)
    {
        cout << "long ";
    }
    cout << "int" << endl;
}