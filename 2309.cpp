// 2309번, 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 내가 푼 방법, 조합(재귀)
void dwarfs_combination(const vector<int> &V, vector<int> T, int start = -1)
{
    if (T.size() == 7)
    {
        int tempSum{0};
        for (int i : T)
            tempSum += V[i];
        if (tempSum == 100)
        {
            for (int i : T)
                cout << V[i] << '\n';
            exit(0);
        }
        return;
    }
    for (int i{start + 1}; i < V.size(); i++)
    {
        T.push_back(i);
        dwarfs_combination(V, T, i);
        T.pop_back();
    }
}

int main()
{
    vector<int> dwarfs(9);
    for (int i{0}; i < 9; i++)
        cin >> dwarfs[i];
    sort(dwarfs.begin(), dwarfs.end());
    dwarfs_combination(dwarfs, vector<int>());
    return 0;
}

// 순열(next_permutation)
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);

//     int dwarfs[9];
//     for (int i{0}; i < 9; i++)
//         cin >> dwarfs[i];
//     sort(dwarfs, dwarfs + 9);
//     do
//     {
//         int sum{0};
//         for (int i{0}; i < 7; i++)
//             sum += dwarfs[i];
//         if (sum == 100)
//             break;
//     } while (next_permutation(dwarfs, dwarfs + 9));
//     for (int i{0}; i < 7; i++)
//         cout << dwarfs[i] << '\n';
//     return 0;
// }

// 조합(중첩 for문)
// void dwarfs_combination(const vector<int> &V)
// {
//     int sum{0}, A, B;
//     for (int i : V)
//         sum += i;
//     for (int i{0}; i < V.size(); i++)
//         for (int j{0}; j < i; j++)
//             if (sum - V[i] - V[j] == 100)
//             {
//                 A = i, B = j;
//                 break;
//             }
//     for (int i{0}; i < V.size(); i++)
//     {
//         if (i == A || i == B)
//             continue;
//         cout << V[i] << '\n';
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);

//     vector<int> dwarfs(9);
//     for (int i{0}; i < 9; i++)
//         cin >> dwarfs[i];
//     sort(dwarfs.begin(), dwarfs.end());
//     dwarfs_combination(dwarfs);
//     return 0;
// }

// 순열(재귀)
// void dwarfs_permutation(vector<int> &V, int r, int depth = 0)
// {
//     if (r == depth)
//     {
//         int sum{0};
//         for (int i{0}; i < r; i++)
//             sum += V[i];
//         if (sum == 100)
//         {
//             sort(V.begin(), V.begin() + 7);
//             for (int i{0}; i < r; i++)
//                 cout << V[i] << '\n';
//             exit(0);
//         }
//     }
//     for (int i{depth}; i < V.size(); i++)
//     {
//         swap(V[i], V[depth]);
//         dwarfs_permutation(V, r, depth + 1);
//         swap(V[i], V[depth]);
//     }
// }

// int main()
// {
//     vector<int> dwarfs(9);
//     for (int i{0}; i < 9; i++)
//         cin >> dwarfs[i];
//     dwarfs_permutation(dwarfs, 7);
//     return 0;
// }