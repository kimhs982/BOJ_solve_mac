// 1213번, 팰린드롬 만들기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 나의 풀이(시간 초과)
// string str, temp;
// int diffCharNum{1};
// bool isPossible;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);

//     cin >> str;
//     sort(str.begin(), str.end());
//     for (int i{1}; i < str.size(); i++)
//         if (str[i - 1] != str[i])
//             diffCharNum++;
//     if (diffCharNum > (str.size() + 1) / 2)
//         cout << "I'm Sorry Hansoo\n";
//     else
//     {
//         do
//         {
//             temp = str;
//             reverse(temp.begin(), temp.end());
//             if (str == temp)
//                 isPossible = true;
//         } while (!isPossible && next_permutation(str.begin(), str.end()));
//         if (isPossible)
//             cout << str << '\n';
//         else
//             cout << "I'm Sorry Hansoo\n";
//     }

//     return 0;
// }

// 예시 답안
/*
팰린드롬이 안되는 경우 - 홀수개인 알파벳의 개수가 2개 이상
사전순(오름차순) - 알파벳을 Z -> A 순서로 배치
*/
string str, result;
int cnt[100], flag;
char mid;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> str;
    for (char c : str)
        cnt[c]++;
    for (int i{'Z'}; i >= 'A'; i--)
        if (cnt[i])
        {
            if (cnt[i] & 1) // 비스마스킹(홀수 & 1 -> 1, 짝수 & 1 -> 0)
            {
                mid = static_cast<char>(i);
                flag++;
                cnt[i]--;
            }
            if (flag == 2)
                break;
            for (int j{0}; j < cnt[i]; j += 2)
            {
                result = static_cast<char>(i) + result;
                result += static_cast<char>(i);
            }
        }
    if (mid)
        result.insert(result.begin() + result.size() / 2, mid);
    if (flag == 2)
        cout << "I'm Sorry Hansoo\n";
    else
        cout << result << '\n';

    return 0;
}