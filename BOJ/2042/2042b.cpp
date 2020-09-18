// https://www.acmicpc.net/problem/2042
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int MAX = 2097152;
long long arr[MAX];
struct SegTree {
	int leaf, size;
	SegTree(int n) : size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
		std::fill(arr, arr+MAX, 0);
	}
	
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = arr[i*2]+arr[i*2+1];
	}
	
	void add(int i, long long v)
	{
		i += leaf;
		v -= arr[i];
		while(i > 0)
		{
			arr[i] += v;
			i/=2;
		}
	}
	// void update(int i, int v)
	// {
	// 	i += leaf;
	// 	arr[i] = v;
	// 	while(i > 1)
	// 	{
	// 		i /= 2;
	// 		arr[i] = arr[i*2] + arr[i*2+1];
	// 	}
	// }
	
	long long sum(int s, int e) { return sum(s,e,1,0,leaf); }
	long long sum(int s, int e, int idx, int ns, int ne)
	{
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[idx];
		int mid = (ns+ne)/2;
		return sum(s,e,idx*2,ns,mid) + sum(s,e,idx*2+1,mid,ne);
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m,k; cin >> n >> m >> k;
	SegTree s(n);
	for(int i = 0; i < n; ++i)
		cin >> arr[s.leaf+i];
	s.init();
	int t = m+k;
	while(t--)
	{
		long long q,a,b; cin >> q >> a >> b;
		if(q == 1)
		{
			s.add(a-1,b);
		}
		else if(q == 2)
		{
			cout << s.sum(a-1,b) << '\n';
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;