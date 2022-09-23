#include <vector>

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