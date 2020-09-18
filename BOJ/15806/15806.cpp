#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, K, t;
int **Map;
int **ca;

queue<int> qx;
queue<int> qy;
const int Xpos[] = {1,2,2,1,-1,-2,-2,-1};
const int Ypos[] = {-2,-1,1,2,2,1,-1,-2};
void bfs()
{
    for(int time = 0; time < t; ++time)
    {
        int qSize = qx.size();
        for(int i = 0; i < qSize; ++i)
        {
            int x = qx.front();
            int y = qy.front();
            qx.pop(); qy.pop();
            Map[x][y]--;
            for(int j = 0; j < 8; ++j)
            {
                int dx = x + Xpos[j];
                int dy = y + Ypos[j];
                if(dx>=1 && dx<=N && dy>=1 && dy<=N)
                {
                    Map[dx][dy]++;
                    qx.push(dx);
                    qy.push(dy);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d %d",&N, &M, &K, &t);
    Map = new int*[N+1];
    ca = new int*[K+1];

    for(int i = 0; i <= N; ++i)
        Map[i] = new int[N+1];

    for(int i = 0; i < M; ++i)
    {
        int x,y;
        scanf("%d %d",&x, &y);
        qx.push(x); qy.push(y);
        Map[x][y] = 1;
    }
    for(int i = 0; i < K; ++i)
    {
        ca[i] = new int[2];

        int x,y;
        scanf("%d %d",&x, &y);
        ca[i][0] = x;
        ca[i][1] = y;
    }

    bfs();
    for(int i = 0; i < K; ++i)
    {
        if(Map[ca[i][0]][ca[i][1]] > 0)//exist
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
