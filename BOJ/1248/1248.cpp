// https://www.acmicpc.net/problem/1248
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int ans[11][11];
int n;
int res[11];

void solve(int curr, int currSum=0)
{
	if(curr == n)
	{
		for(int i = 0; i < n; ++i)
		{
			cout << res[i] << ' ';
		}
		cout << '\n';
		exit(0);
	}
	int currSign = ans[curr][curr];

	if(currSign == 1)
	{
		for(int i = 1; i <= 10; ++i)
		{
			bool flag = true;
			int r = i;
			int sum = r;
			for(int j = curr-1; flag && j >= 0; --j)
			{
				sum += res[j];
				if(ans[j][curr] == 0 && sum == 0);
				else if(ans[j][curr] == 1 && sum >= 1);
				else if(ans[j][curr] == -1 && sum <= -1);
				else flag = false;
			}
			if(flag == false) continue;
			res[curr] = r;
			solve(curr+1, currSum + r);
		}
	}
	else if(currSign == -1)
	{
		for(int i = 1; i <= 10; ++i)
		{
			bool flag = true;
			int r = -1 * i;
			int sum = r;
			for(int j = curr-1; flag && j >= 0; --j)
			{
				sum += res[j];
				if(ans[j][curr] == 0 && sum == 0);
				else if(ans[j][curr] == 1 && sum >= 1);
				else if(ans[j][curr] == -1 && sum <= -1);
				else flag = false;
			}
			if(flag == false) continue;
			res[curr] = r;
			solve(curr+1, currSum + r);
		}
	}
	else
	{
		res[curr] = 0;
		solve(curr+1, currSum);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			char x; cin >> x;
			if(x == '0') ans[i][j] = 0;
			else if(x == '+') ans[i][j] = 1;
			else if(x == '-') ans[i][j] = -1;
		}
	}
	solve(0);
}//g++ -o a -std=c++17 *.cpp