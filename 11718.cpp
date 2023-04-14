// 11718번, 그대로 출력하기
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <string>
using std::string;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    // for (int i = 0; i < 100; i++)
    // {
    //     getline(cin, str);
    //     cout << str << '\n';
    // }

    // EOF(End Of File, control(ctrl) + z)
    while (getline(cin, str))
        cout << str << '\n';

    return 0;
}