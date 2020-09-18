#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int moveX[4] = {1,-1,0,0};
int moveY[4] = {0,0,1,-1};
int moveZ[2] = {1,-1};
int main()
{
    queue<int> x,y,z;
    int ***box;
    int ***check;
    int M, N, H;
    int result = -1;
    scanf("%d %d %d", &M, &N, &H);

    box = new int**[H];
    check = new int**[H];

    for(int i = 0; i < H; ++i)
    {
        box[i] = new int*[N];
        check[i] = new int*[N];

        for(int j = 0; j < N; ++j)
        {
            box[i][j] = new int[M];
            check[i][j] = new int[M];

            for(int k = 0; k < M; ++k)
            {
                check[i][j][k] = -1;
                scanf("%d",&box[i][j][k]);
                if(box[i][j][k] == 1)
                {
                    check[i][j][k] = 0;
                    z.push(i);
                    y.push(j);
                    x.push(k);
                }
            }
        }
    }


    while(!x.empty())
    {
        int p = x.front(); //5
        int q = y.front(); //3
        int r = z.front(); //0
        x.pop(); y.pop(); z.pop();

        for(int j = 0; j < 4; ++j)
        {
            int _p = p + moveX[j];
            int _q = q + moveY[j];
            if(_p<0||_p>=M||_q<0||_q>=N) continue;
            if(box[r][_q][_p] == 0 && check[r][_q][_p] == -1)
            {
                check[r][_q][_p] = check[r][q][p] + 1;
                x.push(_p);
                y.push(_q);
                z.push(r);
            }
        }
        if(H>1)
        {
            for(int k = 0; k < 2; ++k)
            {
                int _r = r + moveZ[k];
                if(_r<0||_r>=H) continue;
                if(box[_r][q][p] == 0 && check[_r][q][p] == -1)
                {
                    check[_r][q][p] = check[r][q][p] + 1;
                    x.push(p);
                    y.push(q);
                    z.push(_r);
                }
            }
        }
    }

    for(int i = 0; i < H; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < M; ++k)
            {
                if(box[i][j][k] == 0 && check[i][j][k] == -1)
                {
                    printf("-1"); return 0;
                }
                result = max(result,check[i][j][k]);
            }
    printf("%d\n",result);
    return 0;
}
