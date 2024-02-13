// 10808번, 알파벳 개수
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 나의 풀이
int main()
{
    string S;
    vector<int> alphabetCount(26);

    cin >> S;
    for (int i{0}; i < S.size(); i++)
        alphabetCount[static_cast<int>(S[i]) - 97]++;
    for (int i{0}; i < 26; i++)
        cout << alphabetCount[i] << ' ';
    cout << '\n';
}

// 예시 답안(Counting Start -> 맵(map) 또는 배열(Array))
// string S;
// int cnt[26];

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);

//     cin >> S;
//     for (char c : S)
//         cnt[c - 'a']++;
//     for (int i{0}; i < 26; i++)
//         cout << cnt[i] << ' ';

//     return 0;
// }