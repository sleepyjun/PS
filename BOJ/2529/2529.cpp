// https://www.acmicpc.net/problem/2529
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool find = false;
int n; 
char eq[10];
int visited[10];
void downDFS(int curr, int op = 0)
{
	if(find == true) return;
	if(op == n)
	{
		for(int i = 0; i <= n; ++i)
		{
			for(int j = 0; j <= 9; ++j)
			{
				if(visited[j] == i) cout << j;
			}
		}
		find = true;
		return;
	}
	for(int i = 9; i >= 0; --i)
	{
		if(visited[i] == -1)
		{
			if(eq[op] == '>')
			{
				if(curr > i)
				{
					visited[i] = op+1;
					downDFS(i,op+1);
					visited[i] = -1;
				}
			}
			else if(eq[op] == '<')
			{
				if(curr < i)
				{
					visited[i] = op+1;
					downDFS(i,op+1);
					visited[i] = -1;
				}
			}
		}
	}
}
void upDFS(int curr, int op = 0)
{
	if(find == true) return;
	if(op == n)
	{
		for(int i = 0; i <= n; ++i)
		{
			for(int j = 0; j <= 9; ++j)
			{
				if(visited[j] == i) cout << j;
			}
		}
		find = true;
		return;
	}
	for(int i = 0; i <= 9; ++i)
	{
		if(visited[i] == -1)
		{
			if(eq[op] == '>')
			{
				if(curr > i)
				{
					visited[i] = op+1;
					upDFS(i,op+1);
					visited[i] = -1;
				}
			}
			else if(eq[op] == '<')
			{
				if(curr < i)
				{
					visited[i] = op+1;
					upDFS(i,op+1);
					visited[i] = -1;
				}
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	for(int i = 0; i < n; ++i) cin >> eq[i];

	for(int i = 9; i >= 0; --i)
	{
		std::fill(visited, visited+10, -1);
		visited[i] = 0;
		downDFS(i);
	}
	cout << '\n'; find = false;
	for(int i = 0; i <= 9; ++i)
	{
		std::fill(visited, visited+10, -1);
		visited[i] = 0;
		upDFS(i);
	}
}//g++ -o a -std=c++11 *.cpp