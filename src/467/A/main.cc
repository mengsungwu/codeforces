#include <iostream>

#include <algorithm>
#include <vector>
#include <map>
#include <set>


int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	long long int n, count = 0;
	std::cin >> n;
	while (n-- > 0) {
		long long int p, q;
		std::cin >> p >> q;
		if (p + 2 <= q) {
			count++;
		}
	}
	
	std::cout << count;

	return 0;
}