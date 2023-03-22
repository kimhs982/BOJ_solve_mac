#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, v;
    vector<int> numList(N);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> numList[i];
    cin >> v;

    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (numList[i] == v)
            cnt++;

    cout << cnt << '\n';

    return 0;
}