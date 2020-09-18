#include <iostream>
#include <algorithm>
#include <vector>
typedef unsigned long long ull;

int src[100001];

//[left,right]
int func(int left, int right)
{
	if(left == right) return src[left];
	int mid = (left+right)/2;
	int lo = mid, hi = mid+1;
	int res = 
		std::max(func(left,lo), func(hi, right));
	
	int height = std::min(src[lo], src[hi]);
	res = std::max(res, height*2);
	while(lo > left || hi < right)
	{
		if(hi < right && (lo == left || src[hi+1] > src[lo-1]))
		{
			hi++;
			height = std::min(height, src[hi]);
		}
		else
		{
			lo--;
			height = std::min(height, src[lo]);
		}
		res = std::max(res, height*(hi-lo+1));
	}
	
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int n; std::cin >> n;
	for(int i = 0; i < n; ++i)
		std::cin >> src[i];
	
	std::cout << func(0,n-1) << '\n';
}