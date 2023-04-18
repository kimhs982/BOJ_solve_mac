// 10988번, 팰린드롬인지 확인하기
#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <algorithm>
using std::reverse;

int main()
{
    string word;
    cin >> word;

    int wordBegin = 0, wordEnd = word.size() - 1;

    bool isPalindrome = true;

    // 풀이 1
    // while (wordBegin <= wordEnd)
    // {
    //     if (word[wordBegin] != word[wordEnd])
    //     {
    //         isPalindrome = false;
    //         break;
    //     }
    //     wordBegin++, wordEnd--;
    // }

    // 풀이 2
    string revWord = word;
    reverse(revWord.begin(), revWord.end());

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] != revWord[i])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}