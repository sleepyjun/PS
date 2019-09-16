#include <iostream>
#include <algorithm>
#include <string>
using std::cin; using std::cout;

const std::string str[3] = {"Soongsil","Korea","Hanyang"};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int arr[3];
	int min = 999;
	int idx;
	int sum=0;
	for(int i = 0; i < 3; ++i)
	{
		cin >> arr[i];
		if(min > arr[i])
		{
			min = arr[i];
			idx = i;
		}
		sum += arr[i];
	}
	if(sum >= 100) cout << "OK" << '\n';
	else cout << str[idx] << '\n';
}