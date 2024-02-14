// 9375번, 패션왕 신해빈
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 나의 풀이(시간 초과)
// int T, N, result;
// string name, type;
// map<string, int> clothes;
// vector<int> clothes_num;

// void combination(vector<int> V, int n, int r, int start = -1)
// {
//     if (V.size() == r)
//     {
//         int temp{1};
//         for (int i : V)
//             temp *= clothes_num[i];
//         result += temp;
//         return;
//     }
//     for (int i{start + 1}; i < n; i++)
//     {
//         V.push_back(i);
//         combination(V, n, r, i);
//         V.pop_back();
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);

//     cin >> T;
//     for (int i{0}; i < T; i++)
//     {
//         clothes.clear(), clothes_num.clear();
//         cin >> N;
//         for (int j{0}; j < N; j++)
//         {
//             cin >> name >> type;
//             if (clothes.find(type) != clothes.end())
//                 clothes[type]++;
//             else
//                 clothes[type] = 1;
//         }
//         for (auto it{clothes.begin()}; it != clothes.end(); it++)
//             clothes_num.emplace_back(it->second);
//         result = 0;
//         for (int j{1}; j <= clothes_num.size(); j++)
//             combination(vector<int>(), clothes_num.size(), j);
//         cout << result << '\n';
//     }
//     return 0;
// }

// 예시 답안(입을 수 있는 전체 경우의 수 - 아무것도 입지 않는 경우의 수(1))
int T, N;
string name, type;

int main()
{
    cin >> T;
    for (int i{0}; i < T; i++)
    {
        map<string, int> clothes;
        cin >> N;
        for (int j{0}; j < N; j++)
        {
            cin >> name >> type;
            clothes[type]++;
        }
        long long result{1};
        for (auto j : clothes)
            result *= (j.second + 1);
        result--;
        cout << result << '\n';
    }
    return 0;
}