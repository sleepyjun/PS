#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, cnt = 0;
vector<int> temp[1001];
bool visit[1001];
void dfs(int i)
{
    visit[i] = true;
    for(int j = 0; j < temp[i].size(); ++j)
    {
        if(!visit[temp[i].at(j)])
            dfs(temp[i].at(j));
    }
}
int main()
{
    scanf("%d %d",&N,&M);

    for(int i = 0; i < M; ++i)
    {
        int u, v;
        scanf("%d %d",&u,&v);
        temp[u].push_back(v);
        temp[v].push_back(u);
    }
    for(int i = 1; i <= N; ++i)
    {
        if(!visit[i])
        {
            cnt++;
            dfs(i);
        }
    }
    printf("%d",cnt);
}
