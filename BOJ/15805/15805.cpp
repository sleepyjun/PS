#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N;

    scanf("%d",&N);
    int cnt = 1;
    int path[N];
    int parent[N];
    fill(parent,parent+N+1,-999);

    for(int i = 0; i < N; ++i)
    {
        scanf("%d",&path[i]);
        if(i == 0)
            parent[path[i]] = -1;
        else if(parent[path[i]] == -999)
        {
            parent[path[i]] = path[i-1];
            cnt++;
        }
    }
    printf("%d\n",cnt);
    for(int i = 0; i < cnt; ++i)
    {
        printf("%d ",parent[i]);
    }
}
