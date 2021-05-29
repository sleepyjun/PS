// https://www.acmicpc.net/problem/15658
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int NINF = std::numeric_limits<int>::min();

int n; 
int arr[11];
int op[4];

int min = INF;
int max = NINF;

void calc(int &res, int idx, int cond)
{
	switch(cond)
	{
		case 0:
			res += arr[idx];
			break;
		case 1:
			res -= arr[idx];
			break;
		case 2:
			res *= arr[idx];
			break;
		case 3:
			res /= arr[idx];
			break;
	}
}
void dfs(int idx, int res = arr[0])
{
	if(idx == n)
	{
		min = std::min(min, res);
		max = std::max(max, res);
		return;
	}

	int temp = res;
	for(int i = 0; i < 4; ++i)
	{
		res = temp;
		if(op[i] != 0)
		{
			op[i]--;
			calc(res, idx, i);
			dfs(idx+1, res);
			op[i]++;
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	for(int i = 0; i < 4; ++i) cin >> op[i];
	dfs(1);

	cout << max << '\n' << min << '\n';
}//g++ -o a -std=c++17 *.cpp