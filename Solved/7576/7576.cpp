#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    // EWSN
    int moveX[4] = {1,-1,0,0};
    int moveY[4] = {0,0,1,-1};
    queue<int> x, y;
    int N, M;
    int **arr;
    int **visit;
    int cnt = 0;

    scanf("%d %d",&M,&N);
    arr = new int*[N];
    visit = new int*[N];
    for(int i = 0; i < N; ++i)
    {
        arr[i] = new int[M];
        visit[i] = new int[M];
        for(int j = 0; j < M; ++j)
        {
            scanf("%d",&arr[i][j]);
            visit[i][j] = -1;
            if(arr[i][j] == 1)
            {
                x.push(i);
                y.push(j);
                visit[i][j] = 0;
            }
        }
    }

    while(!x.empty())
    {
            int r = x.front();
            int s = y.front();
            x.pop(); y.pop();

            for(int j = 0; j < 4; ++j)
            {
                int _r = r + moveX[j];
                int _s = s + moveY[j];

                if(_r<0||_r>=N||_s<0||_s>=M) continue;
                if(arr[_r][_s] == 0 && visit[_r][_s] == -1)
                {
                    visit[_r][_s] = visit[r][s] + 1;
                    x.push(_r);
                    y.push(_s);
                }
            }
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cnt = max(cnt,visit[i][j]);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            if(arr[i][j] == 0 && visit[i][j] == -1)
            {   cnt = -1; }
    printf("%d",cnt);

}



