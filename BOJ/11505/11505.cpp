// https://www.acmicpc.net/problem/11505
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
const ull MOD = 1000000007;
ull arr[MAX];
struct SegTree {
	int leaf,size;
	SegTree(int n):size(n)
	{
		leaf = 1;
		while(leaf<size) leaf*=2;
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = ((arr[i*2])*(arr[i*2+1]))%MOD;
	}
	void update(int i, int v)
	{
		i += leaf;
		arr[i] = v;
		while(i>1)
		{
			i/=2;
			arr[i] = ((arr[i*2])*(arr[i*2+1]))%MOD;
		}
	}
	ull query(int s, int e) { return query(s,e,1,0,leaf); }
	ull query(int s, int e, int idx, int ns, int ne)
	{
		if(ne <= s || e <= ns) return 1;
		if(s <= ns && ne <= e) return arr[idx];
		int mid = (ns+ne)/2;
		return ((query(s,e,idx*2,ns,mid)) * 
				(query(s,e,idx*2+1,mid,ne)))% MOD;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(arr,arr+MAX,1);
	int n,m,k; cin>>n>>m>>k;
	int t=m+k;
	SegTree s(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i+s.leaf];
	}
	s.init();
	// for(int i = 0; i < s.leaf; ++i)
	// 	cout << arr[i] << ' ';
	// cout << '\n';
	while(t--)
	{
		ull q,a,b; cin>>q>>a>>b;
		if(q == 1)
			s.update(a-1,b);
		else
			cout << s.query(a-1,b) << '\n';
	}
	
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;