#include <iostream>
#include <string>

const unsigned long int MAX = 1000000;

unsigned long int left[MAX];
unsigned long int right[MAX];

int main(int argc, char *argv[])
{
	unsigned long int a, b, modb;
	std::string public_key;

	std::cin >> public_key;
	std::cin >> a >> b;

	left[0] = (public_key[0] - '0') % a;
	for (unsigned long int i = 1; i < public_key.length() - 1; i++) {
		left[i] = (left[i - 1] * 10 + public_key[i] - '0') % a;
	}

	modb = 1 % b;
	right[0] = ((public_key[public_key.length() - 1] - '0') * modb ) % b;
	for (unsigned long int i = 1; i < public_key.length() - 1; i++) {
		modb = (modb * 10) % b;
		right[i] = ((public_key[public_key.length() - i - 1] - '0') * modb + right[i - 1]) % b;
	}

	for (unsigned long int i = 0; i < public_key.length() - 1; i++) {
		if (public_key[i + 1] != '0' && left[i] == 0 && right[public_key.length() - i - 2] == 0) {
			std::cout << "YES" << std::endl;
			std::cout << public_key.substr(0, i+1) << std::endl;
			std::cout << public_key.substr(i+1, public_key.length()) << std::endl;
			return 0;
		}
	}
	std::cout << "NO" << std::endl;
	return 0;
}