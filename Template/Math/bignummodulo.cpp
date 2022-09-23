#include <string>

int mod(const std::string &num)
{
	int res = 0;
	for(char n: num)
		res = (res*10 + (int)(n-'0')) % k;
		
	return res;
}