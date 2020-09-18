//https://www.acmicpc.net/problem/1260
#include <iostream>
using namespace std;
#include<queue> //BFS

int **arr;
int *visit;
int N,M; //정점,간선

void DFS(int V);
void BFS(int V);

int main()
{
    int V;//시작번호
    int X,Y;//(X,Y)
    cin >> N >> M >> V;

    //인접행렬 (except 0)
    visit = new int[N+1];
    arr = new int*[N+1];
    for(int i = 0; i < N+1; ++i)
    {
        arr[i] = new int[N+1];
        visit[i] = false;
    }
    for(int i = 0; i < M; ++i)
    {
        cin >> X >> Y;
        arr[X][Y] = 1;
        arr[Y][X] = 1;
    }
    //
    DFS(V);
    for(int i = 0; i < N+1; ++i)
        visit[i] = false;
    cout << endl;
    BFS(V);
}

void DFS(int V)
{
    visit[V] = true;
    cout << V <<' ';
    for(int i = 1; i <= N; ++i)
        if(arr[V][i] == 1 && visit[i] == false)
            DFS(i);
}
void BFS(int V)
{
    queue<int> Q;
    Q.push(V);
    visit[V] = true;

    while(!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        cout << temp <<' ';
        for(int i = 1; i <= N; ++i)
        {
            if(arr[temp][i] == 1 && visit[i] == false)
            {
                Q.push(i);
                visit[i] = true;
            }
        }
    }
}
