// 25206번, 너의 평점은
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <unordered_map>
using std::unordered_map;

double getGrade(const string &);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double totalCredit = 0, totalGrade = 0;

    // 풀이 1
    // for (int i = 0; i < 20; i++)
    // {
    //     string input;
    //     getline(cin, input);

    //     stringstream inputProcess(input);
    //     string subject, gradeString;
    //     double gradeDouble, credit;
    //     inputProcess >> subject >> credit >> gradeString;

    //     if (gradeString == "P")
    //         continue;

    //     gradeDouble = getGrade(gradeString);
    //     totalGrade += (credit * gradeDouble);
    //     totalCredit += credit;
    // }

    // 풀이 2
    unordered_map<string, double> Grade =
        {
            {"A+", 4.5},
            {"A0", 4.0},
            {"B+", 3.5},
            {"B0", 3.0},
            {"C+", 2.5},
            {"C0", 2.0},
            {"D+", 1.5},
            {"D0", 1.0},
            {"F", 0.0}};

    string input;
    double credit;
    while (cin >> input)
    {
        cin >> credit;
        cin >> input;
        if (input != "P")
        {
            totalCredit += credit;
            totalGrade += (credit * Grade[input]);
        }
    }

    cout << totalGrade / totalCredit << '\n';

    return 0;
}

double getGrade(const string &gradeString)
{
    if (gradeString == "A+")
        return 4.5;
    else if (gradeString == "A0")
        return 4.0;
    else if (gradeString == "B+")
        return 3.5;
    else if (gradeString == "B0")
        return 3.0;
    else if (gradeString == "C+")
        return 2.5;
    else if (gradeString == "C0")
        return 2.0;
    else if (gradeString == "D+")
        return 1.5;
    else if (gradeString == "D0")
        return 1.0;
    else
        return 0.0;
}