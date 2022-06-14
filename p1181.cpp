// 1181번, 단어 정렬
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <string>
using std::string;

#include <algorithm>
using std::sort;

void print_wordSorting(string *, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string *string_list = new string[N];
    for (int i = 0; i < N; i++)
        cin >> string_list[i];

    print_wordSorting(string_list, N);

    return 0;
}

bool compare(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    else
        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i])
                return a[i] < b[i];
    return false;
}

void print_wordSorting(string *strList, int in_N)
{
    sort(strList, strList + in_N, compare);

    cout << strList[0] << '\n';
    for (int i = 1; i < in_N; i++)
    {
        if (strList[i - 1] == strList[i])
            continue;
        cout << strList[i] << '\n';
    }
}