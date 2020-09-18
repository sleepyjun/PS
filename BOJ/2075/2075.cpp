// https://www.acmicpc.net/problem/2075
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[1500*1500];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n*n; ++i)
		cin >> arr[i];
	std::sort(arr, arr+(n*n)+1, std::greater<int>());
	cout << arr[n-1] << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;