#include<iostream>
#include<algorithm>
using namespace std;

int arr[5000001];
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;
	for(int i = 1; i <= N; ++i)
		cin >> arr[i];
	sort(arr+1,arr+N+1);
	
	cout << arr[K];
	return 0;
}