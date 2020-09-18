#include <iostream>
using namespace std;
#include<queue>
#include<algorithm>
int N;
char **arr;
int cnt[315];
void dfs(int x,int y,int num)
{
    arr[x][y] = '0';
    cnt[num]++;
    if (x+1 <N && (arr[x+1][y] == '1') && x<N) dfs(x + 1, y,num);
	if (x-1 >=0 && (arr[x-1][y] == '1') && x<N) dfs(x - 1, y,num);
	if (y+1 <N && (arr[x][y+1] == '1') && y<N) dfs(x, y+1,num);
	if (y-1 >=0 && (arr[x][y-1] == '1') &&  y<N) dfs(x, y-1,num);
}
int main()
{
    int total = 0;
    cin >> N;
    arr = new char*[N];
    for(int i = 0; i < N; ++i)
    {
        arr[i] = new char [N];
        for(int j = 0; j < N; ++j)
            cin >> arr[i][j];
    }
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(arr[i][j] == '0')
                continue;
            dfs(i,j,total);
            total++;
        }
    }
    sort(cnt,cnt+total);
    cout <<total<< endl;
    for(int i = 0; i <total; ++i)
        cout<<cnt[i]<<endl;
    return 0;
}
