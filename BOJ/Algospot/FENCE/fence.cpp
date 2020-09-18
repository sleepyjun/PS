#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> h;

int func(int left, int right)
{
	if(left == right) return h[left];
	
	int mid = (left + right) / 2;
	int ret = std::max(func(left, mid), func(mid+1, right));
	
	int lo = mid, hi = mid+1;
	int height = std::min(h[lo], h[hi]);
	ret = std::max(ret, height*2);
	while(lo > left || hi < right)
	{
		if(hi < right && (lo == left || h[lo-1] < h[hi+1]))
		{
			++hi;
			height = std::min(height, h[hi]);
		}
		else
		{
			--lo;
			height = std::min(height, h[lo]);
		}
		ret = std::max(ret, height * (hi - lo + 1));
	}
	
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int t; std::cin >> t;
	while(t--)
	{
		int n; std::cin >> n;
		h.clear();
		for(int i = 0 ; i < n; ++i)
		{
			int height; std::cin >> height;
			h.push_back(height);
		}
		std::cout << func(0, h.size()-1) << '\n';
	}
}