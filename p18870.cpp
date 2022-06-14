// 18870번, 좌표 압축
#include <cstdio>

#include <algorithm>
using std::sort;

// 숫자와 처음 위치를 저장하는 구조체
struct coordinateIndex
{
    int num;
    int index;
    coordinateIndex(int in_num = 0, int in_index = 0) : num(in_num), index(in_index) {}
};

void printCompressed_coor(coordinateIndex *, int);

int main()
{
    int N;
    scanf("%d", &N);
    coordinateIndex *coorList = new coordinateIndex[N];

    int num;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &coorList[i].num);
        coorList[i].index = i;
    }

    printCompressed_coor(coorList, N);

    delete[] coorList;
    return 0;
}

// coordinateIndex의 num을 정렬 기준으로 삼음
bool cmp_first(const coordinateIndex &a, const coordinateIndex &b)
{
    return a.num < b.num;
}

// coordinateIndex의 index를 정렬 기준으로 삼음
bool cmp_second(const coordinateIndex &a, const coordinateIndex &b)
{
    return a.index < b.index;
}

// 좌표를 압축하여 출력하는 함수
void printCompressed_coor(coordinateIndex *coordinateList, int in_N)
{
    // <algorithm> 헤더파일의 sort() 함수 사용/coordinateIndex의 num을 기준으로 정렬, quick sort, unstable
    sort(coordinateList, coordinateList + in_N, cmp_first);

    // 좌표 압축
    int temp, comp_num = 0;
    temp = coordinateList[0].num;
    coordinateList[0].num = comp_num;
    for (int i = 1; i < in_N; i++)
    {
        if (coordinateList[i].num > temp)
            comp_num++;
        temp = coordinateList[i].num;
        coordinateList[i].num = comp_num;
    }

    // <algorithm> 헤더파일의 sort() 함수 사용/coordinateIndex의 index를 기준으로 정렬, quick sort, unstable
    sort(coordinateList, coordinateList + in_N, cmp_second);

    // 압축된 좌표 출력
    for (int i = 0; i < in_N; i++)
        printf("%d ", coordinateList[i].num);
    printf("\n");
}