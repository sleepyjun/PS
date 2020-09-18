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
	int size, leaf;
	SegTree(int n):size(n)
	{
		leaf = 1;
		while(leaf < size) leaf*=2;
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = arr[i*2]+arr[i*2+1];
	}
	void update(int i, int v)
	{
		i += leaf;
		arr[i] = v;
		for(i/=2; i>=1; i/=2)
			arr[i] = arr[i*2]+arr[i*2+1];
	}
	long long query(int l, int r)
	{
		long long ret = 0;
		l+=leaf; r+=leaf;
		while(l <= r)
		{
			if(l%2 == 1) ret += arr[l++];
			if(r%2 == 0) ret += arr[r--];
			l/=2; r/=2;
		}
		return ret;
	}
	// long long query(int l, int r)
	// {
	// 	long long ans = 0;
	// 	for(l+=leaf, r+=leaf; l < r; l>>=1,r>>=1)
	// 	{
	// 		if(l&1) ans+=arr[l++];
	// 		if(r&1) ans+=arr[--r];
	// 	}
	// 	return ans;
	// }
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
	for(int i = 0; i < m+k; ++i)
	{
		long long q,a,b; cin >> q >> a >> b;
		if(q==1) s.update(a-1,b);
		else cout << s.query(a-1,b-1) << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;