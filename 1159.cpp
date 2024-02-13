// 1159번, 농구 경기
#include <iostream>
#include <string>
using namespace std;

// 나의 풀이
int N, cnt[30];
string str;
bool giveUp{true};
int main()
{
    cin >> N;
    for (int i{0}; i < N; i++)
    {
        cin >> str;
        cnt[str[0] - 'a']++;
    }
    for (int i{0}; i < 26; i++)
        if (cnt[i] >= 5)
        {
            cout << static_cast<char>(i + 'a');
            giveUp = false;
        }
    if (giveUp)
        cout << "PREDAJA\n";
    else
        cout << '\n';
    return 0;
}

// 예시 답안
int N, cnt[26];
string str, ret;
int main()
{
    cin >> N;
    for (int i{0}; i < N; i++)
    {
        cin >> str;
        cnt[str[0] - 'a']++;
    }
    for (int i{0}; i < 26; i++)
        if (cnt[i] >= 5)
            ret += (i + 'a');
    if (ret.size())
        cout << ret << '\n';
    else
        cout << "PREDAJA\n";
    return 0;
}