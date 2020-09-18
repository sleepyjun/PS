#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = 987654321;

int arrayTree[4194304] = {0,};
ull limit;

ull dfs(int idx)
{
	if(limit <= idx) return 0;
	
	ull leftSum = dfs(idx*2);
	ull rightSum = dfs(idx*2+1);
	

	if(leftSum > rightSum)
	{
		arrayTree[idx*2+1] = leftSum - (rightSum - arrayTree[idx*2+1]);
		
		return arrayTree[idx] + leftSum;
	}
	else
	{
		arrayTree[idx*2] = rightSum - (leftSum - arrayTree[idx*2]);
		
		return arrayTree[idx] + rightSum;
	}
	

}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int height; cin >> height;
	limit = pow(2,height+1);

	for(int i = 2; i < limit; ++i)
		cin >> arrayTree[i];
	
	
	dfs(1);	
	ull sum = 0;
	for(int i = 2; i < limit; ++i)
	{
		sum += arrayTree[i];
	}
	cout << sum << '\n';
}