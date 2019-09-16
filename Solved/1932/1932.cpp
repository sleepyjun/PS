#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int arr[500][501];
int dp[500][501];
int TreeSum(int current, int select = 0)
{
    if(current == N) return 0;
    int& MAX = dp[current][select];
    if(MAX != -1) return MAX;

    for(int i = select; i <= select + 1; ++i)
    {
        MAX = max(MAX, TreeSum(current+1, i) + arr[current][select]);
    }
    return MAX;
}

int main()
{
    scanf("%d",&N);

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j <= i; ++j)
            scanf("%d",&arr[i][j]);
    }
    memset(dp,-1,sizeof(dp));

    printf("%d",TreeSum(0));
}
