// 9996번, 한국이 그리울 땐 서버에 접속하지
#include <iostream>
#include <string>
using namespace std;

// 내 풀이
// int N;
// string pat, str;
// int main()
// {
//     cin >> N;
//     cin >> pat;
//     for (int i{0}; i < N; i++)
//     {
//         cin >> str;
//         // 반례: 패턴의 길이(별표(*)를 제외한 길이)가 파일 이름의 길이보다 긴 경우
//         if (pat.size() - 1 > str.size())
//             cout << "NE\n";
//         else
//         {
//             bool isSame{true};
//             int j{0};
//             while (pat[j] != '*')
//             {
//                 if (pat[j] != str[j])
//                 {
//                     isSame = false;
//                     break;
//                 }
//                 j++;
//             }
//             if (isSame)
//             {
//                 j = 0;
//                 while (pat[pat.size() - (j + 1)] != '*')
//                 {
//                     if (pat[pat.size() - (j + 1)] != str[str.size() - (j + 1)])
//                     {
//                         isSame = false;
//                         break;
//                     }
//                     j++;
//                 }
//             }
//             if (isSame)
//                 cout << "DA\n";
//             else
//                 cout << "NE\n";
//         }
//     }
//     return 0;
// }

// 예시 답안
int N;
string pat, str, pre, suf;
int main()
{
    cin >> N;
    cin >> pat;
    int pos{static_cast<int>(pat.find('*'))};
    pre = pat.substr(0, pos);
    suf = pat.substr(pos + 1);
    for (int i{0}; i < N; i++)
    {
        cin >> str;
        if (pre.size() + suf.size() > str.size())
            cout << "NE\n";
        else
        {
            if (pre == str.substr(0, pre.size()) && suf == str.substr(str.size() - suf.size()))
                cout << "DA\n";
            else
                cout << "NE\n";
        }
    }
    return 0;
}