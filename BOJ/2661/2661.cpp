#include <iostream>
#include <algorithm>
#include <cstdlib>
using std::cin; using std::cout;

int res[81];
int n;

bool isPossible(int len)
{
	for(int i = 1; i <= len/2; ++i)
	{
		for(int j = 1; j <= len-i; ++j)
		{
			int cnt = 0;
			for(int k = j; k < j + i && k <= len-i; ++k)
				if(res[k] == res[k+i]) cnt++;
			if(cnt == i) return false;
		}
	}
	return true;
}
void backtracking(int idx)
{
	if(idx == n+1)
	{
		for(int i = 1; i <= n; ++i)
			cout << res[i];
		cout << '\n';
		exit(0);
	}
	for(int next = 1; next <= 3; ++next)
	{
		res[idx] = next;
		if(isPossible(idx) == true)
			backtracking(idx+1);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	res[1] = 1;
	backtracking(2);
}