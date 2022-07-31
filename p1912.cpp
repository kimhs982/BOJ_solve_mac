// 1912번, 연속합
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <memory>
using std::unique_ptr;

#include <algorithm>
using std::max;

// INT_MIN
#include <climits>

int continuous_sum_max(const unique_ptr<int[]> &, int);
int continuous_sum_max1(const unique_ptr<int[]> &, int, int);
int continuous_sum_max2(const unique_ptr<int[]> &, int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    unique_ptr<int[]> numList(new int[n]);

    for (int i = 0; i < n; i++)
        cin >> numList[i];

    cout << continuous_sum_max(numList, n) << '\n';

    return 0;
}

// i번째까지의 연속합의 최대값은 [i - 1번째까지의 최대값 + i번째 값] 또는 [i번째 값] 중 큰 값
// M[i] = max(M[i - 1] + arr[i], arr[i])
int continuous_sum_max(const unique_ptr<int[]> &numList, int size)
{
    int max_sum = numList[0], temp = numList[0];
    for(int i = 1; i < size; i++)
    {
       temp = max(temp + numList[i], numList[i]);
       max_sum = max(max_sum, temp);
    }

    return max_sum;
}

// 메모리 초과, 모든 경우의 수만큼의 배열 공간 생성
int continuous_sum_max1(const unique_ptr<int[]> &numList, int size, int max_sum)
{
    // 1 <= i <= n인 경우, N[i] = i
    // n + 1 <= i <= 2n - 1인 경우, N[i] = N[i - n] + N[i - n + 1]
    for (int i = size; i < 2 * size - 1; i++)
    {
        numList[i] = numList[i - size] + numList[i - size + 1];
        max_sum = max(max_sum, numList[i]);
    }
    
    // i >= 2n - 1 & j = 1, 2, ... , n - 2인 경우, N[i] = N[i - (n - j)] + N[i - (n - j) + 1] + N[i - 2(n - j)]
    int temp = 2 * size - 1;
    for(int i = 1; i < size - 1; i++)
    {
        int j;
        for(j = temp; j < temp + (size - (i + 1)); j++)
        {
            numList[j] = numList[j - (size - i)] + numList[j - (size - i) + 1] - numList[j - 2 * (size - i)];
            max_sum = max(max_sum, numList[j]);
        }
        temp = j;
    }

    return max_sum;
}

// 시간 초과, 2n - 1개의 배열 재활용
int continuous_sum_max2(const unique_ptr<int[]> &numList, int size, int max_sum)
{
    for (int i = size; i < 2 * size - 1; i++)
    {
        numList[i] = numList[i - size] + numList[i - size + 1];
        max_sum = max(max_sum, numList[i]);
    }
    
    bool check = true;
    int j;
    for(int i = 2; i < size - 1; i++)
        if(check)
        {
            for(j = 0; j < size - i; j++)
            {
                numList[j] = numList[size - (i - 2) + j] + numList[size - (i - 2) + j + 1] - numList[j + 1];
                max_sum = max(max_sum, numList[j]);
            }

            check = false;
        }
        else
        {
            for(int k = j; k < j + (size - i); k++)
            {
                numList[k] = numList[k - j] + numList[k - j + 1] - numList[size + (k - j) - (i - 3) + 1];
                max_sum = max(max_sum, numList[k]);
            }
            check = true;
        }

    return max_sum;
}