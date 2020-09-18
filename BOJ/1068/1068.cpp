// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[51];
const int NONE = -9;
int n, res = 0;
void dfs(int node)
{
	if(arr[node] == NONE) return;
	bool flag = false;
	for(int i = 0; i < n; ++i)
	{
		if(node == i) continue;
		if(arr[i] == node)
		{
			flag = true;
			dfs(i);
		}
	}
	if(flag == false) res++;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(arr,arr+51,NONE);
	int root; cin >> n;
	for(int i = 0; i < n; ++i) 
	{
		cin >> arr[i];
		if(arr[i] == -1)
			root = i;
	}
	int del; cin >> del;
	arr[del] = NONE;
	dfs(root);
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;