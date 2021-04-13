// https://www.acmicpc.net/problem/17425
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

ull arr[1000001];
ull sArr[1000001];

void sumInit()
{
	sArr[1] = arr[1];
	for(int i = 2; i <= 1000000; ++i)
	{
		sArr[i] = sArr[i-1] + arr[i];
	}
}
void init()
{
	for(int i = 1; i <= 1000000; ++i)
		for(int j = 1; j <= 1000000/i; ++j)
			arr[i*j] += i;
	sumInit();
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	init();

	int t; cin >> t;
	while(t--)
	{
		int x; cin >> x;
		cout << sArr[x] << '\n';
	}
}//g++ -o a -std=c++11 *.cpp