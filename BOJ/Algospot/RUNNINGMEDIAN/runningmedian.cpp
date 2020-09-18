#include<cstdio>
#include<queue>
using namespace std;
int runningMedian(int N, int a, int b);
int main(){
    int testCase;
    scanf("%d", &testCase);
 
    while(testCase--){
        int N = 0, a = 0, b = 0;
        scanf("%d %d %d", &N, &a, &b);
 
        printf("%d\n", runningMedian(N, a, b));
    }
 
    return 0;
}
int runningMedian(int N, int a, int b){
    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int, vector<int>, less<int>> left;
 
    long long currNum = 1983;
    int median = 1983;
    int result = 1983;
 
    while(--N){
        currNum = (currNum * a + b) % 20090711;
        if(currNum > median) right.push(currNum);
        else left.push(currNum);
 
        int diff = left.size() - right.size();
 
        if(diff > 0){
            right.push(median);
            median = left.top();
            left.pop();
        }
        else if(diff < -1){
            left.push(median);
            median = right.top();
            right.pop();
        }
        
        result = (result + median) % 20090711;
    }
 
    return result;
}
/*
#include <iostream>
#include <algorithm>
#include <limits>
#include <set>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int getMedian(const std::multiset<int>& data)
{
	const size_t n = data.size();
	int median = 0;
	
	auto iter = data.cbegin();
	std::advance(iter, n/2);
	
	if(n%2 == 0)
		iter--;
	
	median = *iter;
	
	return median;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n,a,b; cin >> n >> a >> b;
		ull sum = 1983;
		std::multiset<int> set;
		set.insert(1983);
		
		auto prev = set.begin();


		for(int i = 1; i < n; ++i)
		{
			set.insert( ( ( (*prev) * (ull)a) + b) % 20090711);
			sum = (sum + getMedian(set)) % 20090711;
			prev++;
		}
		
		cout << sum << '\n';
	}
}
*/