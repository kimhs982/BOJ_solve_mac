// 2979번, 트럭 주차
#include <iostream>
using namespace std;

// 나의 풀이
int A, B, C, in, out, costs;
int cnt[100];
int main()
{
    cin >> A >> B >> C;
    for (int i{0}; i < 3; i++)
    {
        cin >> in >> out;
        for (int j{in}; j < out; j++)
            cnt[j]++;
    }
    for (int i{1}; i < 100; i++)
        switch (cnt[i])
        {
        case 1:
            costs += A;
            break;
        case 2:
            costs += B * 2;
            break;
        case 3:
            costs += C * 3;
            break;
        default:
            break;
        }
    cout << costs << '\n';
}

// 예시 답안(시간 -> 시작(이상) ~ 끝(미만))
// #include <iostream>
// using namespace std;

// int A, B, C, in, out, cnt[104], costs;
// int main()
// {
//     cin >> A >> B >> C;
//     for (int i{0}; i < 3; i++)
//     {
//         cin >> in >> out;
//         for (int j{in}; j < out; j++)
//             cnt[j]++;
//     }
//     for (int i{1}; i < 100; i++)
//         if (cnt[i])
//         {
//             if (cnt[i] == 1)
//                 costs += A;
//             else if (cnt[i] == 2)
//                 costs += B * 2;
//             else if (cnt[i] == 3)
//                 costs += C * 3;
//         }
//     cout << costs << '\n';
//     return 0;
// }