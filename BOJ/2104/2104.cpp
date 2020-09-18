#include <iostream>
#include <algorithm>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

ull src[100001];

//[s,e]
ull solve(int s, int e)
{
	if(s==e) return src[s]*src[s];
	
	int mid = (s+e)/2;
	ull res = std::max(solve(s,mid), solve(mid+1,e));
	
	int left = mid;
	int right = mid+1;
	ull subSum = src[left] + src[right];
	ull min = std::min(src[left], src[right]);
	res = std::max(res, min*subSum);

	while(s < left || right < e)
	{
		if(right < e && (left == s || src[right+1] > src[left-1]))
		{
			right++;
			subSum += src[right];
			min = std::min(min, src[right]);
		}
		else
		{
			left--;
			subSum += src[left];
			min = std::min(min, src[left]);
		}
		
		res = std::max(res, min*subSum);
	}
	
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> src[i];
	
	cout << solve(0, n-1) << '\n';
}