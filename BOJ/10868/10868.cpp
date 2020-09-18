// https://www.acmicpc.net/problem/10868
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 262144;
int arr[MAX];
struct SegTree {
	int size, leaf;
	SegTree(int n):size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = std::min(arr[i*2], arr[i*2+1]);
	}
	int query(int s, int e) { return query(s,e,1,0,leaf); }
	int query(int s, int e, int idx, int ns, int ne)
	{
		if(ne <= s || e <= ns) return INF;
		if(s <= ns && ne <= e) return arr[idx];
		int mid = (ns+ne)/2;
		return std::min(query(s,e,idx*2,ns,mid),
					   query(s,e,idx*2+1,mid,ne));
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(arr,arr+MAX,INF);
	int n,m; cin >> n >> m;
	SegTree s(n);
	for(int i = 0; i < n; ++i)
		cin >> arr[i+s.leaf];
	s.init();
	while(m--)
	{
		int a,b; cin >> a >> b;
		cout << s.query(a-1,b) << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;