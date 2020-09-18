#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

std::vector<int> v;
int total;

bool judge(int max)
{
	int sum = 0;
	for(int i = 0; i < v.size(); ++i)
		sum += v[i] > max ? max : v[i];
	if(sum <= total) return true;
	else return false;
}

int func(int left, int right)
{
	if(left > right) return right;
	int mid = (left+right)/2;
	
	if(judge(mid) == true)
	//sum <= total
	{
		func(mid+1, right);
	}
	else
	//sum > total
	{
		func(left, mid-1);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	v.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	cin >> total;
	std::sort(v.begin(), v.end());
	
	if(judge(v.back()) == true)
		cout << v.back() << '\n';
	else if(judge(v.front()) == false)
		cout << total / v.size() << '\n';
	else
		cout << func(v.front(), v.back()) << '\n';
}