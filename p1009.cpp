// 1009번, 분산처리
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

int last_handled_computer1(int, int);
int last_handled_computer2(int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, a, b;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        // cout << last_handled_computer1(a, b) << '\n';
        cout << last_handled_computer2(a, b) << '\n';
    }

    return 0;
}

int last_handled_computer1(int in_a, int in_b)
{
    switch (in_a % 10)
    {
    case 0:
        return 10;
    case 1:
        return 1;
    case 2:
        switch (in_b % 4)
        {
        case 0:
            return 6;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 8;
        }
    case 3:
        switch (in_b % 4)
        {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 9;
        case 3:
            return 7;
        }
    case 4:
        if (in_b % 2 == 0)
            return 6;
        else
            return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        switch (in_b % 4)
        {
        case 0:
            return 1;
        case 1:
            return 7;
        case 2:
            return 9;
        case 3:
            return 3;
        }
    case 8:
        switch (in_b % 4)
        {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 4;
        case 3:
            return 2;
        }
    case 9:
        if (in_b % 2 == 0)
            return 1;
        else
            return 9;
    default:
        return 0;
    }
}

int last_handled_computer2(int in_a, int in_b)
{
    int temp = 1;
    for(int i = 0; i < in_b; i++)
        temp = temp * in_a % 10;

    if(temp == 0)
        return 10;
    else
        return temp;
}