#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using std::cin; using std::cout;

bool prime[100001];
bool visited[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	std::fill(prime, prime+100001, true);
	
	for(int i = 2; i <= 100000; ++i)
	{
		if(prime[i] == true)
		{
			for(int j = i*2; j <= 100000; j += i)
				prime[j] = false;
			//primes.push_back(i);
		}
	}
	
	int t; cin >> t;
	while(t--)
	{
		int n, a, b; cin >> n >> a >> b;
		std::queue<int> q;
		std::vector<int> primes;
		
		std::fill(visited, visited+100001, false);
		for(int i = a; i <= b; ++i)
			if(prime[i] == true)
				primes.push_back(i);
		
		if(primes.size() == 0)
		{
			cout << -1 << '\n';
			continue;
		}
		
		int level = 0;
		bool flag = true;
		q.push(n);
		while(!q.empty() && flag)
		{
			int qSize = q.size();
			
			for(int i = 0; i < qSize; ++i)
			{
				int src = q.front(); q.pop();
				
				if(std::binary_search(primes.begin(), primes.end(), src) == true)
				{
					flag = false; break;	
				}
				
				if(visited[src] == false)
				{
					q.push(src/2);
					q.push(src/3);
					if(src < 100000)
						q.push(src+1);
					if(src > 0)
						q.push(src-1);
					
					visited[src] = true;
				}
			}
			level++;
		}
		
		cout << level-1 << '\n';
	}
}