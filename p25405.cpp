// 25305번, 커트라인
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

int cutLine(vector<int> &, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k;
    cin >> N >> k;

    vector<int> studentsGrade;
    studentsGrade.reserve(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        studentsGrade.__emplace_back(temp);
    }
    cout << cutLine(studentsGrade, k) << '\n';

    return 0;
}

int cutLine(vector<int> &GL, int in_k)
{
    sort(GL.begin(), GL.end(), std::greater<int>());

    return GL[in_k - 1];
}