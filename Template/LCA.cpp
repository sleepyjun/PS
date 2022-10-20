// https://www.acmicpc.net/problem/11438
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

std::vector<int> adj[100001];
int parent[100001][21];
int depth[100001];

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
    std::fill(&parent[0][0], &parent[100000][21], -1);
    std::fill(depth, depth+100001, -1);
    depth[1] = 0;
    makeTree(1);
    for(int k = 0; k < 21; ++k)
        for(int i = 0; i <= n; ++i)
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
            for(int i = 20; i >= 0; --i)
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
}
// [출처] 최소 공통 조상(Lowest Common Ancestor) (수정: 2019-08-31)|작성자 라이

/*======================================*/

//!응용문제 최소 최대 간선 찾기
// https://www.acmicpc.net/problem/3176
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 17;
int parent[100001][MAX];
int max[100001][MAX];
int min[100001][MAX];
int depth[100001];
std::vector<pii> adj[100001];

void make(int curr)
{
	
	for(const auto& next: adj[curr])
	{
		int nNode = next.first;
		int nCost = next.second;
		if(depth[nNode] == -1)
		{
			min[nNode][0] = max[nNode][0] = nCost;
			parent[nNode][0] = curr;
			depth[nNode] = depth[curr] + 1;
			make(nNode);
		}
	}
}

int getLCA(int u, int v)
{
	if(depth[u] < depth[v]) std::swap(u, v);
	int diff = depth[u] - depth[v];
	
	for(int i = 0; diff; ++i)
	{
		if(diff % 2) u = parent[u][i];
		diff /= 2;
	}
	
	if(u != v)
	{
		for(int i = MAX-1; i >= 0; --i)
		{
			if(parent[u][i] != -1 && parent[u][i] != parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	
	return u;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&parent[0][0], &parent[100000][MAX], -1);
	std::fill(&max[0][0], &max[100000][MAX], -1);
	std::fill(&min[0][0], &min[100000][MAX], INF);
	std::fill(depth, depth+100001, -1);
	
	int n; cin >> n;
	
	for(int i = 0; i < n-1; ++i)
	{
		int u,v,w; cin >> u >> v >> w;
		
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	depth[1] = 0;
	make(1);
	
	for(int j = 0; j < MAX-1; ++j)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(parent[i][j] != -1)
			{
				min[i][j+1] = std::min(min[i][j], min[parent[i][j]][j]);
				max[i][j+1] = std::max(max[i][j], max[parent[i][j]][j]);
				parent[i][j+1] = parent[parent[i][j]][j];
			}
		}
	}
		
	int t; cin >> t;
	while(t--)
	{
		int s, e; cin >> s >> e;
		int mid = getLCA(s, e);
	
		int leftDiff = depth[s] -  depth[mid];
		int rightDiff = depth[e] - depth[mid];
		int leftMax = -1, rightMax = -1;
		int leftMin = INF, rightMin = INF;
		
		for(int i = 0; leftDiff; ++i)
		{
			if(leftDiff % 2)
			{
				leftMax = std::max(leftMax, max[s][i]);
				leftMin = std::min(leftMin, min[s][i]);
				s = parent[s][i];
			}
			leftDiff /= 2;
		}
		
		for(int i = 0; rightDiff; ++i)
		{
			if(rightDiff % 2)
			{
				rightMax = std::max(rightMax, max[e][i]);
				rightMin = std::min(rightMin, min[e][i]);
				e = parent[e][i];
			}
			rightDiff /= 2;
		}
		
		cout << std::min(leftMin, rightMin) << ' ' << std::max(leftMax, rightMax) << '\n';
	}
}//g++ -o a -std=c++17 *.cpp

