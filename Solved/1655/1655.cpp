#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using std::cin; using std::cout;


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::priority_queue<int, std::vector<int>,
	std::greater<int> > minHeap;
	std::priority_queue<int> maxHeap;
	
	while(n--)
	{
		int x; cin >> x;
		
		if(maxHeap.empty())
			maxHeap.push(x);
		else if(maxHeap.size() == minHeap.size())
			maxHeap.push(x);
		else minHeap.push(x);
		
		if((!maxHeap.empty() && !minHeap.empty()) &&
		  	!(maxHeap.top() <= minHeap.top()))
		{
			int a = maxHeap.top();
			int b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b); minHeap.push(a);
		}
		
		cout << maxHeap.top() << '\n';
	}
}