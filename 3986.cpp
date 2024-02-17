// 3986번, 좋은 단어
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N, cnt;
string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i{0}; i < N; i++)
    {
        cin >> str;
        stack<char> wordList;
        for (char c : str)
        {
            if (wordList.size() && c == wordList.top())
                wordList.pop();
            else
                wordList.push(c);
        }
        if (wordList.empty())
            cnt++;
    }
    cout << cnt << '\n';
}