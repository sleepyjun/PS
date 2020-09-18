//https://www.acmicpc.net/problem/2250
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;
struct Tree {
	int root,left,right;
	Tree() : root(-1), left(-1), right(-1)
	{}
};

std::vector<Tree> tree;
bool columnCoord[10001][10001] = {false,};
int order = 1;
int maxHeight = -INF;
int findRoot()
{
	int rootIdx = 1;
	
	while(tree[rootIdx].root != -1)
		rootIdx = tree[rootIdx].root;
	
	return rootIdx;
}

void inOrder(int idx, int height)
{
	if(idx == -1) 
	{
		maxHeight = std::max(maxHeight, height);
		return;
	}
	inOrder(tree[idx].left, height+1);
	columnCoord[height][order++] = true;
	inOrder(tree[idx].right, height+1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	tree.resize(n+1);
	for(int i = 0; i < n; ++i)
	{
		int idx,l,r;
		cin >> idx >> l >> r;
		
		tree[idx].left = l;
		tree[idx].right = r;
		tree[l].root = idx;
		tree[r].root = idx;
	}
	
	int root = findRoot();
	inOrder(root, 1);
	pii res(0,1);
	for(int y = 1; y <= maxHeight; ++y)
	{
		int min = -1,max = -1;
		for(int x = 1; x <= n; ++x)
		{
			if(columnCoord[y][x] == true)
			{
				min = x;
				break;
			}
		}
		for(int x = n; x >= 1; --x)
		{
			if(columnCoord[y][x] == true)
			{
				max = x;
				break;
			}
		}
		if(res.first < max-min)
		{
			res.first = max-min;
			res.second = y;
		}
	}
	
	cout << res.second << ' ' << res.first+1 << '\n';
}