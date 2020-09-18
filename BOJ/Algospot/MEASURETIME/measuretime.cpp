#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

struct FenwickTree {
	std::vector<int> tree;
	FenwickTree(int n) : tree(n+1) {}
	
	int sum(int pos)
	//given pos index is 0 to n-1;
	{
		++pos; //make pos start 1
		int ret = 0;
		while(pos > 0)
		{
			ret += tree[pos];
			pos &= (pos-1);
		}
		return ret;
	}
	
	void add(int pos, int val)
	{
		++pos;
		while(pos < tree.size())
		{
			tree[pos] += val;
			pos += (pos & -pos);
			//last bit
		}
	}
};

long long count(const std::vector<int>& arr)
{
	FenwickTree tree(1000000);
	long long ret = 0;
	for(int num : arr)
	{
		ret += tree.sum(999999) - tree.sum(num);
		tree.add(num, 1);
	}
	
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		std::vector<int> arr(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << count(arr) << '\n';
	}
}