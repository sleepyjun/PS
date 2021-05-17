// https://www.acmicpc.net/problem/14890
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n, l; 
std::vector<int> arr[101];
bool slope[101];

int solve()
{
	int ret = 0;

	for(int y = 0; y < n; ++y)
	{
		std::fill(slope,slope+101,false);

		int prev = arr[y][0];
		int cnt = 1;
		bool ok = true;
		//++
		for(int x = 1; x < n; ++x)
		{
			bool fail = false;
			int curr = arr[y][x];

			if(prev == curr)
			{
				cnt++;
			}
			else if(prev+1 == curr)
			{
				if(cnt >= l)
				{
					for(int j = 1; j <= l; ++j)
					{
						if(slope[x-j] == false)
						{
							slope[x-j] = true;
						}
						else
						{
							fail = true;
							break;
						}
					}

					if(false == fail)
					{
						prev = curr;
						cnt = 1;
					}
				}
				else fail = true;
			}
			else if(prev-1 == curr)
			{
				prev = curr;
				cnt = 1;
			}
			else fail = true;

			if(true == fail)
			{
				ok = false;
				break;
			}
		}

		if(false == ok) continue;

		prev = arr[y][n-1];
		cnt = 1;
		ok = true;
		//--
		for(int x = n-2; x >= 0; --x)
		{
			bool fail = false;
			int curr = arr[y][x];

			if(prev == curr)
			{
				cnt++;
			}
			else if(prev+1 == curr)
			{
				if(cnt >= l)
				{
					for(int j = 1; j <= l; ++j)
					{
						if(slope[x+j] == false)
						{
							slope[x+j] = true;
						}
						else
						{
							fail = true;
							break;
						}
					}

					if(false == fail)
					{
						prev = curr;
						cnt = 1;
					}
				}
				else fail = true;
			}
			else if(prev-1 == curr)
			{
				prev = curr;
				cnt = 1;
			}
			else fail = true;

			if(true == fail)
			{
				ok = false;
				break;
			}
		}

		if(false == ok) continue;
		ret++;
	}

	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> l;
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			int d; cin >> d;
			arr[y].push_back(d);
		}
	}

	int res = 0;
	//row
	res += solve();
	//column
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			std::swap(arr[i][j], arr[j][i]);
	res += solve();

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp