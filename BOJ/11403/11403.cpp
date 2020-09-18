#include <iostream>
#include <ios>
#include <algorithm>
#include <queue>

using std::cout;
using std::cin;

int arr[101][101];
int res[101][101];
bool visited[101];
int n; 

void bfs(int start)
{
    std::queue<int> q;
    // for(int i = 0; i < n; ++i)
    // {
    //     if(arr[start][i] == 1)
    //     {
    //         res[start][i] = 1;
    //         q.push(i);
    //     }
    // }
    
    q.push(start);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        if(visited[current] == true) continue;
        visited[current] = true;
        
        for(int i = 0; i < n; ++i)
        {
            if(arr[current][i] == 1)
            {
                res[start][i] = 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        std::fill(visited, visited+n, false);
        bfs(i);
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}