#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[10];

void dfs(int cnt)
{
	if(cnt == M)
	{
		for(int i = 0; i < cnt; ++i)
			cout << arr[i] << ' ';
		cout << endl;
		return;
	}
	for(int i = 1; i <= N; ++i)
	{
		if(cnt-1 >= 0 && arr[cnt-1] >= i) continue;
		arr[cnt] = i;
		dfs(cnt+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	dfs(0);
}