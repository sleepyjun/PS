// https://www.acmicpc.net/problem/15681
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
std::vector<int> child[100001];
int parent[100001];
int size[100001];
void makeTree(int curr, int prev = -1)
{
	for(int next: adj[curr])
	{
		if(next != prev)
		{
			child[curr].push_back(next);
			parent[curr] = prev;
			makeTree(next, curr);
		}
	}
}
void countSubnode(int curr)
{
	size[curr] = 1;
	for(int next: child[curr])
	{
		countSubnode(next);
		size[curr] += size[next];
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,r,q; cin >> n >> r >> q;

	for(int i = 1; i < n; ++i)
	{
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	makeTree(r);
	countSubnode(r);
	while(q--)
	{
		int u; cin >> u;
		cout << size[u] << '\n';
	}
}//g++ -o a -std=c++11 *.cpp