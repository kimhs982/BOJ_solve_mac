// 2563번, 색종이
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool whitePaper[100][100] = {};

    int numberOfPaper;
    cin >> numberOfPaper;

    for (int i = 0; i < numberOfPaper; i++)
    {
        int left, height;
        cin >> left >> height;
        for (int j = height - 1; j < height + 9; j++)
            for (int k = left - 1; k < left + 9; k++)
                whitePaper[j][k] = true;
    }

    int count = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (whitePaper[i][j])
                count++;

    cout << count;

    return 0;
}