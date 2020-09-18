// https://www.acmicpc.net/problem/1365
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
int arr[100001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<int> v(1,-1);
	for(int i = 0; i < n; ++i) cin >> arr[i];
	for(int i = 0; i < n; ++i)
	{
		if(v.back() < arr[i]) v.push_back(arr[i]);
		else
		{
			auto it = std::lower_bound(v.begin(), v.end(), arr[i]);
			*it = arr[i];
		}
	}
	
	cout << n - (v.size() - 1) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;