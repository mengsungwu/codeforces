#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>

typedef long long int ll;

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	ll k, w, n;

	std::cin >> k >> w >> n;
	ll borrow = n * (n + 1) / 2 * k - w;
	if (borrow > 0) {
		std::cout << n * (n + 1) / 2 * k - w << std::endl;
	} else {
		std::cout << "0" << std::endl;
	}

	return 0;
}