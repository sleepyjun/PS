// https://www.acmicpc.net/problem/2295
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[1001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	std::sort(arr, arr+n);

	std::vector<int> sum;
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j)
			sum.push_back(arr[i]+arr[j]);
	std::sort(sum.begin(), sum.end());
	
	for(int i = n-1; i >= 0; --i)
	{
		for(int j = i-1; j >= 0; --j)
		{
			if(std::binary_search(sum.begin(), sum.end(), arr[i]-arr[j]))
			{
				cout << arr[i] << '\n';
				return 0;
			}
		}
	}
}//g++ -o a -std=c++11 *.cpp