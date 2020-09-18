// https://www.acmicpc.net/problem/1275
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 524288;
long long arr[MAX];
struct SegTree {
	int size,leaf;
	SegTree(int n):size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
	void update(int i, int v)
	{
		i += leaf;
		arr[i] = v;
		for(i/=2; i>0; i/=2)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
	long long query(int l, int r)
	{
		l+=leaf; r+=leaf;
		long long res = 0;
		while(l<=r)
		{
			if(l%2 == 1) res += arr[l++];
			if(r%2 == 0) res += arr[r--];
			l/=2; r/=2;
		}
		return res;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,t; cin >> n >> t;
	SegTree s(n);
	for(int i = 0; i < n; ++i)
		cin >> arr[i+s.leaf];
	s.init();
	while(t--)
	{
		int x,y,a,b; cin >> x >> y >> a >> b;
		if(x > y) std::swap(x,y);
		cout << s.query(x-1,y-1) << '\n';
		s.update(a-1,b);
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;