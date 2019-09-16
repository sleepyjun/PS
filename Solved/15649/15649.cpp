#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[10];
int func(int pivot)
{
	if(pivot == m)
	{
		for(int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return 0;
	}
	for(int i = 1; i <= n; ++i)
	{
		bool flag = true;
		for(int j = 0; j < pivot; ++j)
			if(i==arr[j]) flag = false;
		if(flag)
		{
			arr[pivot] = i;
			func(pivot+1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	func(0);
}
/*
for(int i=1;i<=N;i++){
    if( visit[i] == false ){
        visit[i] = true;
        arr[cnt] = i;
        dfs(cnt+1);
        visit[i] = false; 
    }
}
*/