// 1620번, 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 나의 풀이(string 클래스의 stoi() 함수 사용)
// int M, N;
// string temp;
// map<string, int> pocketmonDict1;
// vector<string> pocketmonDict2(1);

// int main()
// {
//     // 시간초과 주의!
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> M >> N;
//     for (int i{0}; i < M; i++)
//     {
//         cin >> temp;
//         pocketmonDict1[temp] = i + 1;
//         pocketmonDict2.push_back(temp);
//     }
//     for (int i{0}; i < N; i++)
//     {
//         cin >> temp;
//         if (temp[0] >= 65) // cctype의 isdigit() 함수 사용 가능. 10진수 숫자로 변경 가능 -> 0이 아닌 숫자(true), 10진수 숫자로 변경 불가능 -> 0(false)
//             cout << pocketmonDict1[temp] << '\n';
//         else
//             cout << pocketmonDict2[stoi(temp)] << '\n';
//     }
//     return 0;
// }

// 예시 답안(cstdlib의 atoi() 함수 사용, 정수(int)로 변경할 수 없는 경우 -> 0)
#include <cstdlib>

int N, M;
string temp;
map<string, int> pocketmonDict1;
string pocketmonDict2[100004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int i{0}; i < N; i++)
    {
        cin >> temp;
        pocketmonDict1[temp] = i + 1;
        pocketmonDict2[i + 1] = temp;
    }
    for (int i{0}; i < M; i++)
    {
        cin >> temp;
        if (atoi(temp.c_str()) == 0)
            cout << pocketmonDict1[temp] << '\n';
        else
            cout << pocketmonDict2[atoi(temp.c_str())] << '\n';
    }
    return 0;
}