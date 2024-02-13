// 11655번, ROT13
#include <iostream>
#include <string>
using namespace std;

string S;
int main()
{
    getline(cin, S);
    for (int i{0}; i < S.size(); i++)
    {
        if (S[i] >= 65 && S[i] <= 90)
        {
            int temp{S[i] + 13};
            // ROT13을 적용하였을 때, 97 이상이 되는 경우 고려
            if (temp > 90)
                temp -= 26;
            S[i] = temp;
        }
        else if (S[i] >= 97 && S[i] <= 122)
        {
            // 아스키 코드의 마지막 번호(127)를 넘어가면 에러 발생
            int temp{S[i] + 13};
            if (temp > 122)
                temp -= 26;
            S[i] = temp;
        }
    }
    cout << S << '\n';
    return 0;
}