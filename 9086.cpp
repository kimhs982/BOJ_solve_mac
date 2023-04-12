// 9086번, 문자열
#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string testCase;
        cin >> testCase;

        cout << testCase.front() << testCase.back() << '\n';
    }

    return 0;
}