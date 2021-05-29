// https://www.acmicpc.net/problem/14225
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::map<int, bool> check;
int n;
int arr[20];
void init(int idx, int sum = 0)
{
	if(idx == n)
	{
		check[sum] = true;
		return;
	}

	sum += arr[idx];
	init(idx+1, sum);
	sum -= arr[idx];
	init(idx+1, sum);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	init(0);
	for(int i = 1; ; ++i)
	{
		if(check[i] == false)
		{
			cout << i << '\n';
			break;
		}
	}
}//g++ -o a -std=c++17 *.cpp