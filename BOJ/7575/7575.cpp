// https://www.acmicpc.net/problem/7575
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> codes[1001];
int fail[1001];
int n, k; 

void getFail(const std::vector<int> &virus)
{
	for(int i = 1, j = 0; i < k; ++i)
	{
		while(j > 0 && virus[i] != virus[j]) j = fail[j-1];
		if(virus[i] == virus[j]) fail[i] = ++j;
	}
}

bool comp(const std::vector<int> &virus)
{
	getFail(virus);
	for(int idx = 1; idx < n; ++idx)
	{
		bool flag = true;

		int size = codes[idx].size();
		for(int i = 0, j = 0; i < size; ++i)
		{
			while(j > 0 && codes[idx][i] != virus[j]) j = fail[j-1];
			if(codes[idx][i] == virus[j])
			{
				if(j == virus.size()-1)
				{
					flag = false;
					break;
				}
				else j++;
			}
		}
		if(flag) return false;
	}
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	std::vector<int> src;

	for(int i = 0; i < n; ++i)
	{
		int m; cin >> m;
		for(int j = 0; j < m; ++j)
		{
			int x; cin >> x;
			if(i==0) src.push_back(x);
			codes[i].push_back(x);
		}
		codes[i].push_back(-1);
		for(int j = m-1; j >= 0; --j)
			codes[i].push_back(codes[i][j]);
	}

	bool flag = false;
	int size = src.size();
	if(size >= k)
	{
		for(int i = 0; i <= size-k; ++i)
		{
			std::vector<int> virus;
			for(int j = i; j < i+k; ++j)
				virus.push_back(src[j]);

			if(true == comp(virus))
			{
				flag = true;
				break;
			}
		}
	}

	if(true == flag) cout << "YES";
	else cout << "NO";
	cout << '\n';
}//g++ -o a -std=c++17 *.cpp