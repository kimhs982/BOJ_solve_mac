// 1940번, 주몽
#include <iostream>
#include <vector>
using namespace std;

// 나의 풀이1(시간 초과)
int N, M, cnt;
int costs[15004];

void combination(vector<int> V, int start = -1)
{
    if (V.size() == 2)
    {
        int sum{0};
        for (int i : V)
            sum += costs[i];
        if (sum == M)
            cnt++;
        return;
    }
    for (int i{start + 1}; i < N; i++)
    {
        V.push_back(i);
        combination(V, i);
        V.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int i{0}; i < N; i++)
        cin >> costs[i];
    combination(vector<int>());
    cout << cnt << '\n';
}

// 나의 풀이2(시간 초과)
// int N, M, temp, cnt;
// vector<int> costs;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);
//     cin >> N;
//     cin >> M;
//     for (int i{0}; i < N; i++)
//     {
//         cin >> temp;
//         if (temp >= M)
//             continue;
//         costs.emplace_back(temp);
//     }
//     for (int i{0}; i < costs.size() - 1; i++)
//         for (int j{i + 1}; j < costs.size(); j++)
//         {
//             if (costs[i] + costs[j] == M)
//             {
//                 cnt++;
//                 costs.erase(costs.begin() + j);
//                 costs.erase(costs.begin() + i);
//                 j = i;
//             }
//         }
//     cout << cnt << '\n';

//     return 0;
// }

// 예시 답안
int N, M, cnt, costs[15004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M;
    for (int i{0}; i < N; i++)
        cin >> costs[i];
    if (M >= 200000)
        cout << 0 << '\n';
    else
    {
        for (int i{0}; i < N; i++)
            for (int j{i + 1}; j < N; j++)
                if (costs[i] + costs[j] == M)
                    cnt++;
        // for (int i{0}; i < N; i++)
        //     for (int j{0}; j < i; j++)
        //         if (costs[i] + costs[j] == M)
        //             cnt++;
        cout << cnt << '\n';
    }
}