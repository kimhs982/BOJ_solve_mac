// 2108번, 통계학
#include <cstdio>
#include <cmath>

#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, median, mode, range;
    double mean;

    scanf("%d", &N);
    int *arr = new int[N];

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i]; // 모든 입력 값의 합
    }
    // 산술 평균
    mean = double(sum) / N;
    if ((mean > -1) && (mean < 0))
        mean = -(mean);

    // 정렬(algorithm)
    sort(arr, arr + N);

    // 중간값
    median = arr[N / 2];

    // 최빈값
    int max_count = 0;
    vector<pair<int, int> > arr_freq;
    for (int i = 0; i < N;)
    {
        int count = 1, j;
        for (j = i + 1; j < N; j++)
            if (arr[i] == arr[j])
                count++;
            else
                break;
        arr_freq.__emplace_back(make_pair(arr[i], count));
        i = j;
        if (max_count < count)
            max_count = count;
    }

    vector<int> max_freq;
    for (int i = 0; i < int(arr_freq.size()); i++)
        if (arr_freq[i].second == max_count)
            max_freq.__emplace_back(arr_freq[i].first);

    if (max_freq.size() > 1)
        mode = max_freq[1];
    else
        mode = max_freq[0];

    // 범위
    range = arr[N - 1] - arr[0];

    printf("%.0lf\n%d\n%d\n%d\n", mean, median, mode, range);

    delete[] arr;
    return 0;
}