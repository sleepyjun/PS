// https://www.acmicpc.net/problem/3653
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 524288;
int idx[100001];
int arr[MAX];
struct SegTree {
	int size,leaf;
	SegTree(int n) : size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
		std::fill(arr,arr+MAX,0);
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = arr[i*2]+arr[i*2+1];
	}
	void update(int x, int v)
	{
		x += leaf;
		arr[x] = v;
		for(x/=2; x>0; x/=2)
			arr[x] = arr[x*2]+arr[x*2+1];
	}
	int query(int l, int r)
	{
		l += leaf; r += leaf;
		int res = 0;
		while(l<=r)
		{
			if(l%2==1) res += arr[l++];
			if(r%2==0) res += arr[r--];
			l/=2; r/=2;
		}
		return res;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n,m; cin >> n >> m;
		std::fill(idx,idx+n+1,0);
		int up = n;
		SegTree s(n+m);
		for(int i = 1; i <= n; ++i)
		{
			arr[i-1+s.leaf] = 1;
			idx[i] = n-i;
		}s.init();
		for(int i = 1; i <= m; ++i)
		{
			int x; cin >> x;
			cout << s.query(idx[x]+1,n+m) << ' ';
			s.update(idx[x],0);
			idx[x] = up++;
			s.update(idx[x],1);
		}
		cout << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;