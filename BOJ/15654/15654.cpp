#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int dest[10];
int src[10];
bool visit[10];
void dfs(int cnt)
{
	if(cnt == m)
	{
		for(int i = 0; i < m; ++i)
			cout << dest[i] << ' ';
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < n; ++i)
	{
		if(visit[i] == false)
		{
			dest[cnt] = src[i];
			visit[i] = true;
			dfs(cnt+1);
			visit[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0 ; i < n; ++i)
		cin >> src[i];
	sort(src, src+n);
	dfs(0);
}