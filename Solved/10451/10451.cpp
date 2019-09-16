#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[1001][2]; // 0 순열 1 패턴
bool visit[1001];

void dfs(int node)
{
    if(visit[node]) return;
    visit[node] = true;
    dfs(arr[node][1]);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; ++i)
    {
        int N, cnt = 0;
        memset(visit,0,sizeof(visit));
        scanf("%d",&N);
        for(int j = 1; j <= N; ++j)
        {
            arr[j][0] = j;
            scanf("%d",&arr[j][1]);
        }

        for(int j = 1; j <= N; ++j)
        {
            if(visit[j]) continue;
            else
            {
                dfs(j);
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
