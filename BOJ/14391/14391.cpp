// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool visited[4][4];
int arr[4][4];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	int cnt = n*m;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			char ch; cin >> ch;
			arr[i][j] = ch-'0';
		}
	}

	int ans = 0;
	for(int bit = 0; bit < (1 << cnt); ++bit)
	{
		int temp = 0;
		std::fill(&visited[0][0], &visited[3][4], false);

		for(int i = 0; i < n; ++i) // column
		{
			for(int j = 0; j < m; ++j) // row
			{
				if(visited[i][j] == true) continue;
				int idx = i*m+j;
				int ret = (1 << idx) & bit;

				int sum = 0;
				if(ret != 0) // colum
				{
					for(int k = i; k < n; ++k)
					{
						int check = k*m+j;
						if(visited[k][j] == true) break;
						if(0 == ((1 << check) & bit)) break;

						sum *= 10;
						sum += arr[k][j];
						visited[k][j] = true;
					}
				}
				else // row
				{
					for(int k = j; k < m; ++k)
					{
						int check = i*m+k;
						if(visited[i][k] == true) break;
						if(0 != ((1 << check) & bit)) break;

						sum *= 10;
						sum += arr[i][k];
						visited[i][k] = true;
					}
				}

				temp += sum;
			}
		}

		ans = std::max(ans, temp);
	}

	cout << ans << '\n';
}//g++ -o a -std=c++17 *.cpp