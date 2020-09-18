#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cin; using std::cout;

int arr[101];
std::vector<int> divs;

void calc(int n)
{
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0) divs.push_back(i);
	
	int cnt = divs.size();
	for(int i = 0; i < cnt; ++i)
	{
		int m = divs[i];
		if(n/m != m) divs.push_back(n/m);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	
	std::sort(arr, arr+n);
	int min = arr[1] - arr[0];
	for(int i = 2; i < n; ++i)
		min = std::min(min, arr[i] - arr[i-1]); 
	
	calc(min);
	std::sort(divs.begin(), divs.end());
	
	for(int i = 1; i < divs.size(); ++i)
	{
		int M = divs[i];
		bool flag = true;
		for(int j = 1; flag && j < n; ++j)
		{
			if(arr[0] % M != arr[j] % M)
				flag = false;
		}
		if(flag)
			cout << M << ' ';
	}
	cout << '\n';
}