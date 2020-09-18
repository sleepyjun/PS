#include <iostream>
#include <algorithm>

using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;

int inOrder[100001];
int postOrder[100001];

void printPreOrder(int inFirstIdx, int inLastIdx,
				   int postFirstIdx, int postLastIdx)
// range is first to last-1
{
	const int size = inLastIdx - inFirstIdx;
	if(size == 0) return;
	
	const int root = postOrder[postLastIdx-1];
	int leftSubtreeSize = -1;
	int rightSubtreeSize = -1;
	for(int i = inFirstIdx; i < inLastIdx; ++i)
		if(root == inOrder[i])
		{
			leftSubtreeSize = i;
			break;
		}
	if(leftSubtreeSize == -1) return;
	leftSubtreeSize -= inFirstIdx;
	rightSubtreeSize = size-1-leftSubtreeSize;
	
	cout << root << ' ';
	printPreOrder(inFirstIdx, inFirstIdx+leftSubtreeSize,
				 postFirstIdx, postFirstIdx+leftSubtreeSize);
	printPreOrder(inFirstIdx+leftSubtreeSize+1, inFirstIdx+leftSubtreeSize+1+rightSubtreeSize,
				 postFirstIdx+leftSubtreeSize, postFirstIdx+leftSubtreeSize+rightSubtreeSize);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> inOrder[i];
	for(int i = 0; i < n; ++i)
		cin >> postOrder[i];
	
	printPreOrder(0,n,0,n);
	// range is 0 to n-1
	cout << '\n';
}