#include <iostream>

int main(int argc, char *argv[])
{

	unsigned long long int n, count;
	std::cin >> n;

	count = 0;
	for (unsigned long long int floor = 0; n >= 2 + floor * 3; floor++) {
		n -= 2 + floor * 3;
		if (n % 3 == 0) {
			count++;
		}
	}

	std::cout << count;
	return 0;
}