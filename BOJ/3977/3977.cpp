// https://www.acmicpc.net/problem/3977
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <stack>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::stack<int> st;
std::vector<std::vector<int> > adj, rAdj, scc;
bool visited[100001];
int indegree[100001], group[100001], cnt;

void dfs(int curr)
{
	visited[curr] = true;
	for(int next: adj[curr])
		if(false == visited[next])
			dfs(next);
	st.push(curr);
}

void sfd(int curr, std::vector<int> &currVec)
{
	visited[curr] = true;
	group[curr] = cnt;
	currVec.push_back(curr);

	for(int next: rAdj[curr])
		if(false == visited[next])
			sfd(next, currVec);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int res = 0; cnt = 1;
		int n, m; cin >> n >> m;
		adj.resize(n+1); rAdj.resize(n+1);

		for(int i = 0; i < m; ++i)
		{
			int s,e; cin >> s >> e;
			adj[s].push_back(e);
			rAdj[e].push_back(s);
		}

		for(int i = 0; i < n; ++i)
			if(false == visited[i]) dfs(i);
		std::fill(visited, visited+100001, false);
		while(!st.empty())
		{
			int curr = st.top(); st.pop();
			if(true == visited[curr]) continue;
			
			std::vector<int> currVec;
			sfd(curr, currVec);
			
			scc.push_back(currVec);
			cnt++;	
		}

		for(int i = 0; i < n; ++i)
			for(int j: adj[i])
				if(group[i] != group[j]) indegree[group[j]]++;

		int idx;
		for(int i = 1; i < cnt; ++i)
			if(indegree[i] == 0) idx = i, res++;

		if(res != 1) cout << "Confused\n";
		else
		{
			std::sort(scc[idx-1].begin(), scc[idx-1].end());

			for(int node : scc[idx-1])
				cout << node << '\n';
		}
		cout << '\n';
		
		adj.clear(); rAdj.clear(); scc.clear();
		std::fill(visited, visited+100001, false);
		std::fill(group, group+100001, 0);
		std::fill(indegree, indegree+100001, 0);
	}
}//g++ -o a -std=c++17 *.cpp