// https://www.acmicpc.net/problem/1168
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
	SegTree(): size(0), leaf(0) {}
	SegTree(int n): size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void update(int i, int v)
	{
		i += leaf;
		arr[i] += v;
		for(i/=2; i>0; i/=2)
			arr[i] = arr[i*2]+arr[i*2+1];
	}
	int query(int k)
	{
		int pos = 1;
		while(pos < leaf)
		{
			if(k < arr[pos*2]) pos *= 2;
			else k -= arr[pos*2], pos = pos*2+1;
		}
		return pos - leaf;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	int idx = 1;
	SegTree s(100000);

	cout << '<';
	for(int i = 1; i <= n; ++i) s.update(i,1);
	for(int i = n; i >= 1; --i)
	{
		idx = (idx+k-1)%i;
		idx = idx == 0 ? i : idx;
		int ret = s.query(idx-1);
		s.update(ret, -1);
		cout << ret;
		if(i==1) cout << ">\n";
		else cout <<", ";
	}
}//g++ -o a -std=c++17 *.cpp