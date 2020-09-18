#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1001][101];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> arr[i][j];
	for(int i = 0; i < n; ++i)
	{
		for(int j = i+1; j < n; ++j)
		{
			bool f1=false, f2=false;
			for(int k = 0; k < m; ++k)
			{
				if(arr[i][k] == 1 && arr[j][k] == 0)
					f1 = true;
				if(arr[i][k] == 0 && arr[j][k] == 1)
					f2 = true;
				if(f1 && f2)
				{
					cout << "NO" << '\n';
					return 0;
				}
			}
		}
	}
	cout << "YES" << '\n';
	return 0;
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;