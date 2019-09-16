#include <iostream>
#include <algorithm>
#include <vector>
typedef unsigned long long ull;
std::vector<int> h;

ull func(int left, int right)
{
	if(left == right) return (ull)h[left];
	int mid = (left+right)/2;
	int lo = mid, hi = mid+1;
	ull res = 
		std::max(func(left,lo), func(hi, right));
	
	int height = std::min(h[lo], h[hi]);
	res = std::max(res, (ull)height*2);
	while(lo > left || hi < right)
	{
		if(hi < right && (lo == 0 || h[hi+1] > h[lo-1]))
		{
			hi++;
			height = std::min(height, h[hi]);
		}
		else
		{
			lo--;
			height = std::min(height, h[lo]);
		}
		res = std::max(res, (ull)height*(hi-lo+1));
	}
	
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int n; 
	while(1)
	{
		std::cin >> n;
		if(!n) break;
		h.clear(); h.resize(n);
		for(int i = 0; i < n; ++i)
		{
			std::cin >> h[i];
		}

		std::cout << func(0, n-1) << '\n';
	}
}