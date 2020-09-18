// https://www.acmicpc.net/problem/2357
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
int maxArr[MAX];
struct maxSeg {
	int size, leaf;
	maxSeg(int n):size(n)
	{
		leaf = 1;
		while(leaf < size) leaf*=2;
		std::fill(maxArr, maxArr+MAX, -1);
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			maxArr[i] = std::max(maxArr[i*2], maxArr[i*2+1]);
	}
	int query(int l, int r)
	// [l,r]
	{
		int res = -1;
		l+=leaf; r+=leaf;
		while(l<=r)
		{
			if(l%2==1) res = std::max(res, maxArr[l++]);
			if(r%2==0) res = std::max(res, maxArr[r--]);
			l/=2; r/=2;
		}
		return res;
	}
};
int minArr[MAX];
struct minSeg {
	int size, leaf;
	minSeg(int n):size(n)
	{
		leaf = 1;
		while(leaf < size) leaf*=2;
		std::fill(minArr, minArr+MAX, INF);
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			minArr[i] = std::min(minArr[i*2], minArr[i*2+1]);
	}
	int query(int l, int r)
	// [l,r]
	{
		int res = INF;
		l+=leaf; r+=leaf;
		while(l<=r)
		{
			if(l%2==1) res = std::min(res, minArr[l++]);
			if(r%2==0) res = std::min(res, minArr[r--]);
			l/=2; r/=2;
		}
		return res;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	maxSeg max(n);
	minSeg min(n);
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		maxArr[i+max.leaf] = x;
		minArr[i+min.leaf] = x;
	}
	max.init(); min.init();
	while(m--)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		cout << min.query(a,b) << ' ' << max.query(a,b) << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;