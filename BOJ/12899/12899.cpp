// https://www.acmicpc.net/problem/12899
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 4194304;
int arr[MAX];

struct SegTree {
	int leaf, size;
	SegTree(): leaf(0), size(0) {}
	SegTree(int n): size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void update(int i, int v)
	{
		i += leaf;
		arr[i] += v;
		for(i/=2; i>0; i/=2) arr[i] = arr[i*2] + arr[i*2+1];
	}
	int query(int k)
	{
		int pos = 1;
		while(pos < leaf)
		{
			if(k < arr[pos*2]) pos *= 2;
			else k -= arr[pos*2], pos = pos*2+1;
		}
		return pos-leaf;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	SegTree s(2000000);
	for(int i = 0; i < n; ++i)
	{
		int t,x; cin >> t >> x;
		if(t == 1)
		{
			s.update(x, 1);
		}
		else if(t == 2)
		{
			int y = s.query(x-1);
			s.update(y, -1);
			cout << y << '\n';
		}
	}
}//g++ -o a -std=c++17 *.cpp