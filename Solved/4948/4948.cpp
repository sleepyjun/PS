#include <iostream>
#include <math.h>
using namespace std;
inline bool isPrime(int n) {
	if (n == 1) { return false; }
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) { return false; }
		}
	}
	return true;

}
int main() {
	int check = 1, count = 0;

	while (1) {

		cin >> check;
		if (check == 0)
			break;
		for (int i = check + 1; i <= check * 2; i++) {
			if (isPrime(i)) { count++; };
		}
		cout << count << endl;
		count = 0;
	}
}