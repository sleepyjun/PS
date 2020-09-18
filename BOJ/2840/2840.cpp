#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

bool visited[25] = {false,};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	int flag = false;
	std::vector<char> plate(n, '?');
	int current = 0;
	while(k--)
	{
		
		int cnt;
		char ch;
		cin >> cnt >> ch;
		
		current = (current + cnt) % n;
		
		if(plate[current] == ch) continue;
		
		if(visited[current] == true)
		{
			flag = true;
			break;
		}
		else if(plate.end() != std::find(plate.begin(), plate.end(), ch))
		{
			flag = true;
			break;
		}
		visited[current] = true;
		plate[current] = ch;
	}
	if(flag == true)
		cout << '!';
	else
	{
		for(int i = 0; i < n; ++i)
		{
			cout << plate[current--];
			if(current < 0)
				current = n-1;
		}
	}
	cout << '\n';
}
/*
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

bool visited[25] = {false,};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	int flag = false;
	std::vector<char> plate(n, '?');
	int current = 0;
	while(k--)
	{
		
		int cnt;
		char ch;
		cin >> cnt >> ch;
		if(plate.end() != std::find(plate.begin(), plate.end(), ch))
		{
			flag = true;
			break;
		}
		
		cnt %= n;
		if(current - cnt < 0)
			current = (current - cnt) + n;
		else
			current -= cnt;
		
		if(visited[current] == true)
		{
			// plate[current] = '?';
			flag = true;
			break;
		}
		visited[current] = true;
		plate[current] = ch;
	}
	if(flag == true)
		cout << '!';
	else
	{
		for(int i = 0; i < n; ++i)
		{
			cout << plate[(i+current)%n];
		}
	}
	cout << '\n';
}
*/