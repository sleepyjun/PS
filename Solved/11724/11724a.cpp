#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[1001];
queue<int> q;
bool visit[1001];

void BFS(int start)
{
    visit[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int i = 0; i < adj[curr].size(); ++i)
        {
            int next = adj[curr][i];

            if(visit[next] == false)
            {
                visit[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int N, M;
    int u, v;
    int cnt = 0;
    scanf("%d %d",&N, &M);
    for(int i = 0; i < M; ++i)
    {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v); adj[v].push_back(u);
    }

    for(int i = 1; i <= N; ++i)
    {
        if(visit[i] == false)
        {
            BFS(i);
            cnt++;
        }
    }
    printf("%d",cnt);
}
