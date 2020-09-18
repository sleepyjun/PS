// https://www.acmicpc.net/problem/5639
#include <iostream>
#include <algorithm>

using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;

int preOrder[10001];
int inOrder[10001];
void printPostOrder(int preFirst, int preLast,
				   int inFirst, int inLast)
// range will be first ~ last-1
{
	int size = preLast - preFirst;
	if(size == 0) return;
	
	const int root = preOrder[preFirst++];
	int lSubSize = -1;
	for(int i = inFirst; i < inLast; ++i)
	{
		if(root == inOrder[i])
		{
			lSubSize = i-inFirst;
			break;
		}
	}
	if(lSubSize == -1) return;
	int rSubSize = size-lSubSize-1;
	
	printPostOrder(preFirst, preFirst+lSubSize,
				  inFirst, inFirst+lSubSize);
	preFirst+=lSubSize;
	inFirst+=(1+lSubSize);
	printPostOrder(preFirst, preFirst+rSubSize,
				  inFirst,inFirst+rSubSize);
	cout << root << ' ';
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n=0;
	while(!cin.eof())
		cin >> preOrder[n++];
	n--;
	
	std::copy(preOrder, preOrder+n, inOrder);
	std::sort(inOrder, inOrder+n);
	printPostOrder(0,n,0,n);
	cout << '\n';
}