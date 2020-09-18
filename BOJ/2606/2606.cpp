#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int cnt;
vector<int> ve[101];
bool visited[101];

void dfs(int start)
{
    cnt++;
    visited[start] = true;
    for(int i = 0; i < ve[start].size(); ++i)
    {
        int next = ve[start][i];
        if(visited[next] == false)
        {
            visited[next] = true;
            dfs(next);
        }
    }
}
int main()
{
    int u, v;
    scanf("%d",&N);
    scanf("%d",&M);

    for(int i = 0; i < M; ++i)
    {
        scanf("%d %d",&u, &v);
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dfs(1);
    printf("%d",cnt-1);
    return 0;
}
