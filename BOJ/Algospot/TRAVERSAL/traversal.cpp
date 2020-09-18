#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

std::vector<int> slice(const std::vector<int>& v, int a, int b)
{
	return std::vector<int>(v.begin()+a, v.begin()+b);
}

void solve(const std::vector<int>& preorder,
		  const std::vector<int>& inorder)
{
	const int N = preorder.size();
	if(N == 0) return;
	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root)
		- inorder.begin();
	const int R = N - L - 1;
	
	solve(slice(preorder,1,L+1), slice(inorder,0,L));
	solve(slice(preorder,L+1,N), slice(inorder,L+1,N));
	cout << root << ' ';
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	std::vector<int> preorder, inorder;
	while(t--)
	{
		preorder.clear(); inorder.clear();
		int n; cin >> n;
		for(int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			preorder.push_back(x);
		}
		for(int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			inorder.push_back(x);
		}
		solve(preorder, inorder);
		cout << '\n';
	}
}