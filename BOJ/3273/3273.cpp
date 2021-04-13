// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[100000];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// std::fill(arr,arr+100000,INF);
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	int sum; cin >> sum;
	std::sort(arr, arr+n);

	int cnt = 0;
	int l=0,r=n-1;
	while(l<r)
	{
		if(l==r) break;
		int tSum = arr[l]+arr[r];
		if(sum == tSum) {cnt++; l++;}
		else if(sum < tSum)r--;
		else if(sum > tSum)l++;
	}
	cout << cnt << '\n';
}//g++ -o a -std=c++11 *.cpp