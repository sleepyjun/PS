#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

// E W S N
//100*r+c
int main()
{

    queue<int> x;
    queue<int> y;
    bool visit[100][100] = {false};
    bool maze[100][100];
    int N,M;
    int moveX[4] = {1,-1,0,0};
    int moveY[4] = {0,0,1,-1};
    int cnt = 1;
    bool success;

    visit[0][0] = true;
    x.push(0);
    y.push(0);

    scanf("%d %d",&N, &M);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%1d",&maze[i][j]);

    while(1)
    {
        int Size = x.size();
        for(int i = 0; i < Size; ++i)
        {
            int r = x.front();
            int s = y.front();
            x.pop();
            y.pop();
            if(r == N-1 && s == M-1)
            {
                printf("%d",cnt);
                return 0;
            }

            for(int j = 0; j < 4; ++j)
            {
                int _r = r + moveX[j];
                int _s = s + moveY[j];

                if(_r<0||_r>=N||_s<0||_s>=M) continue;
                if(visit[_r][_s]) continue;
                if(!maze[_r][_s]) continue;

                    visit[_r][_s] = true;
                    x.push(_r);
                    y.push(_s);
            }
        }
        ++cnt;
    }
}
