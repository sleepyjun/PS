// https://www.acmicpc.net/problem/2150
// 코사라주 알고리즘
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

const int MAX = 10001;
std::vector<std::vector<int> > adj, rAdj, scc;
std::stack<int> st;
bool visited[MAX];
int v,e,cnt; 
void dfs(int curr)
{
	visited[curr] = true;
	for(int next : adj[curr])
		if(false == visited[next]) dfs(next);
	st.push(curr);
}
void func(int curr)
{
	visited[curr] = true;
	scc[cnt-1].push_back(curr);
	for(int next : rAdj[curr])
		if(false == visited[next]) func(next);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> v >> e;
    adj.resize(v+1); rAdj.resize(v+1);
    for(int i = 0; i < e; ++i)
    {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        rAdj[b].push_back(a);
    }
	for(int i = 1; i <= v; ++i)
		if(false == visited[i]) dfs(i);

	std::fill(visited,visited+MAX,false);
	while(false == st.empty())
	{
		int curr = st.top(); st.pop();
		if(true == visited[curr]) continue;
		scc.resize(++cnt);
		func(curr);
	}
	for(int i = 0; i < cnt; ++i)
		std::sort(scc[i].begin(), scc[i].end());
	std::sort(scc.begin(), scc.end());

	cout << cnt << '\n';
	for(int i = 0; i < cnt; ++i)
	{
		for(int x : scc[i]) cout << x << ' ';
		cout << "-1\n";
	}
}//g++ -o a -std=c++11 *.cpp