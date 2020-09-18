#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int l,c; 
std::vector<char> v, res;
void func(int prev, int cnt, int mo, int za)
{	
	if(cnt == l && mo >= 1 && za >= 2)
	{
		for(int i = 0; i < cnt; ++i)
			cout << res[i];
		cout << '\n';
		return;
	}
	if(prev == c-1) return;
	
	for(int i = prev+1; i < c; ++i)
	{
		res.push_back(v[i]);
		if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' 
		   || v[i] == 'o' || v[i] == 'u')
			mo++;
		else
			za++;
		func(i, cnt+1, mo, za);
		if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' 
		   || v[i] == 'o' || v[i] == 'u')
			mo--;
		else
			za--;
		res.pop_back();
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> l >> c;
	
	for(int i = 0; i < c; ++i) 
	{
		char ch; cin >> ch;
		v.push_back(ch);
	}
	std::sort(v.begin(), v.end());

	func(-1,0,0,0);
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;