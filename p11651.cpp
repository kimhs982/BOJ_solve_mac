// 11651번, 좌표 정렬하기2
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <utility>
using std::make_pair;
using std::pair;

#include <algorithm>
using std::sort;

void print_coordinateSorting(pair<int, int> *, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    pair<int, int> *coordinateList = new pair<int, int>[N];
    int x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        coordinateList[i] = make_pair(x, y);
    }
    print_coordinateSorting(coordinateList, N);

    return 0;
}

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void print_coordinateSorting(pair<int, int> *corList, int in_N)
{
    sort(corList, corList + in_N, compare);
    for (int i = 0; i < in_N; i++)
        cout << corList[i].first << ' ' << corList[i].second << '\n';
}