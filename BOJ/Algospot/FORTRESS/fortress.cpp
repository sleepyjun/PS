#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using std::cin; using std::cout;
typedef std::tuple<int,int,int> xyr;
std::vector<xyr> v;
int n;
int longest;
struct TreeNode {
	std::vector<TreeNode*> children;
};

int square(int x)
{
	return x*x;
}
int squareDist(int a, int b)
{
	return square(std::get<0>(v[a])-std::get<0>(v[b])) +
		square(std::get<1>(v[a])-std::get<1>(v[b]));
}
bool encloses(int big, int small)
{
	int bigRadius = std::get<2>(v[big]);
	int smallRadius = std::get<2>(v[small]);
	return bigRadius > smallRadius &&
		squareDist(big, small) < square(bigRadius - smallRadius);
}
int isDirectChild(int parent, int child)
{
	if(false == encloses(parent, child))
	{
		return false;
	}
	
	for(int i = 0; i < n; ++i)
	{
		if(i != parent && i != child &&
			true == encloses(parent,i) && true == encloses(i, child))
		{
			return false;
		}
	}
	
	return true;
}
TreeNode* getTreeRoot(int root)
{
	TreeNode* ret = new TreeNode();
	
	for(int i = 0; i < n; ++i)
	{
		if(true == isDirectChild(root,i))
			ret->children.push_back(getTreeRoot(i));
	}
	
	return ret;
}

int height(TreeNode* root)
{
	std::vector<int> heights;
	for(int i = 0; i < root->children.size(); ++i)
		heights.push_back(height(root->children[i]));
	if(heights.empty()) return 0;
	sort(heights.begin(), heights.end());
	
	if(heights.size() >= 2)
		longest = std::max(longest, 2 + heights[heights.size()-2] +
						  heights[heights.size()-1]);
	
	return heights.back()+1;
}
int solve(TreeNode* root)
{
	longest = 0;
	int h = height(root);
	return std::max(longest, h);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		v.clear();
		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			int x,y,r;
			cin >> x >> y >> r;
			v.push_back(xyr(x,y,r));
		}
		TreeNode *root = getTreeRoot(0);
		
		cout << solve(root) << '\n';
	}
}
	