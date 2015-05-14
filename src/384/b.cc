#include <iostream>

int main() 
{
	std::ios_base::sync_with_stdio(false);

	long long int n, m, k;
	std::cin >> n >> m >> k;

	std::cout << (m * (m - 1)) / 2 << std::endl;
	for (long long int i = 1; i < m; i++) {
		for (long long int j = i + 1; j <= m; j++) {
			if (k == 0) {
				std::cout << i << " " << j << std::endl;
			}
			else {
				std::cout << j << " " << i << std::endl;
			}
		}
	}

	return 0;
}