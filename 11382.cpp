#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long A, B, C;

    cin >> A >> B >> C;
    cout << A + B + C << endl;

    return 0;
}