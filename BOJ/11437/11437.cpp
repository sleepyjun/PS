// https://www.acmicpc.net/problem/11437
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> adj[50001];
int parent[50001][17];
int depth[50001];

void makeTree(int curr)
{
    for(int n : adj[curr])
    {
        if(depth[n] == -1)
        {
            parent[n][0] = curr;
            depth[n] = depth[curr]+1;
            makeTree(n);
        }
    }
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    std::fill(&parent[0][0], &parent[50000][17], -1);
    std::fill(depth, depth+50001, -1);
    depth[1] = 0;
    makeTree(1);
    for(int k = 0; k < 16; ++k)
        for(int i = 2; i <= n; ++i)
            if(parent[i][k] != -1)
                parent[i][k+1] = parent[parent[i][k]][k];
    
    int m; cin >> m;
    while(m--)
    {
        int a,b; cin >> a >> b;
        if(depth[a] < depth[b]) std::swap(a,b);
        int diff = depth[a] - depth[b];

        for(int i = 0; diff; ++i)
        {
            if(diff % 2) a = parent[a][i];
            diff /= 2;
        }
        if(a != b)
        {
            for(int i = 16; i >= 0; --i)
            {
                if(parent[a][i] != -1 && parent[a][i] != parent[b][i])
                {
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            a = parent[a][0];
        }
        cout << a << '\n';
    }
}//g++ -o a -std=c++11 *.cpp