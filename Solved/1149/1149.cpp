#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int cost[1000][3], temp[1001][4];
//R - 0, G - 1, B - 2
int RGB(int current, int prevColor = 3)
{
    int &MIN = temp[current][prevColor];
    if(MIN != -1) return MIN;
    if(current == N) return 0;


    MIN = 100000000;

    for(int i = 0; i < 3; ++i)
        if(prevColor != i)
            MIN = min(MIN, RGB(current + 1, i) + cost[current][i]);
    return MIN;
}
int main()
{
    scanf("%d",&N);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < 3; ++j)
            scanf("%d",&cost[i][j]);
    memset(temp,-1,sizeof(temp));
    printf("%d",RGB(0));
}
