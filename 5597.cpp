// 5597번, 과제 안 내신 분...?
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool *attendanceNum = new bool[31]();

    for (int i = 0; i < 28; i++)
    {
        int studentNum;

        cin >> studentNum;

        attendanceNum[studentNum] = true;
    }

    for (int i = 1; i <= 30; i++)
    {
        if (!attendanceNum[i])
            cout << i << "\n";
    }

    delete[] attendanceNum;

    return 0;
}