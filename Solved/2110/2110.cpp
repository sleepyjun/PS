#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

std::vector<int> v;
int n, c;

bool judge(int len)
{
	int cnt = 1;
	int idx = 0;
	for(int i = 1; i < n; ++i)
	{
		if((v[i]-v[idx]) >= len)
		{
			idx = i;
			cnt++;
		}
	}
	return (cnt >= c);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	v.resize(n);
	
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	
	for(int i = 1; i < n; ++i)
		v[i] -= (v[0]-1);
	
	v[0] = 1;
	int left = v[0];
	int right = v[n-1];
	while(left <= right)
	{
		int len = (left+right)/2;
		
		// if (right - left == 1)
		// {
		// 	if (judge(right)) { break; }
		// 	else { right=left; break; }
		// }
		if(judge(len)) //cnt >= c
		{
			left = len+1;
		}
		else //cnt < c
		{
			right = len-1;
		}
	}
	cout << right << '\n';
}