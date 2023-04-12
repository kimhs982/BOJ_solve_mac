// 27866번, 문자와 문자열
#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

int main()
{
    string S;
    int i;

    cin >> S >> i;

    cout << S[i - 1] << '\n';

    return 0;
}