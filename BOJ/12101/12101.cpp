// https://www.acmicpc.net/problem/12101
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n, k;
int arr[15];
int d;
void run(int sum, int cnt)
{
	if(sum > n) return;
	if(sum == n)
	{
		d++;
		if(d==k)
		{
			for(int i = 0; i < cnt; ++i)
				cout << arr[i] << (i==cnt-1 ? '\n' : '+');
			exit(0);
		}
		return;
	}

	for(int i = 1; i <= 3; ++i)
	{
		arr[cnt] = i;
		run(sum+i, cnt+1);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	run(0,0);
	cout << -1 << '\n';
}//g++ -o a -std=c++17 *.cpp