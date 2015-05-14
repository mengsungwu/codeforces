#include <iostream>
#include <algorithm>
#include <vector>


int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	long long int n, m, total = 0;
	std::cin >> n >> m;
	std::vector< std::vector<long long int> > a(n + 2, std::vector<long long int>(m + 2));

	/* +1/+1 */
	std::vector< std::vector<long long int> > dp1(n + 2, std::vector<long long int>(m + 2));

	/* -1/-1 */
	std::vector< std::vector<long long int> > dp2(n + 2, std::vector<long long int>(m + 2));

	/* -1/+1 */
	std::vector< std::vector<long long int> > dp3(n + 2, std::vector<long long int>(m + 2));

	/* +1/-1 */
	std::vector< std::vector<long long int> > dp4(n + 2, std::vector<long long int>(m + 2));

	for (long long int i = 1; i <= n; i++) {
		for (long long int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}

	for (long long int i = 1; i <= n; i++) {
		for (long long int j = 1; j <= m; j++) {
			dp1[i][j] = a[i][j] + std::max(dp1[i - 1][j], dp1[i][j - 1]);
		}
	}

	for (long long int i = n; i >= 1; i--) {
		for (long long int j = m; j >= 1; j--) {
			dp2[i][j] = a[i][j] + std::max(dp2[i + 1][j], dp2[i][j + 1]);
		}
	}

	for (long long int i = n; i >= 1; i--) {
		for (long long int j = 1; j <= m; j++) {
			dp3[i][j] = a[i][j] + std::max(dp3[i + 1][j], dp3[i][j - 1]);
		}
	}

	for (long long int i = 1; i <= n; i++) {
		for (long long int j = m; j >= 1; j--) {
			dp4[i][j] = a[i][j] + std::max(dp4[i - 1][j], dp4[i][j + 1]);
		}
	}

	for (long long int i = 2; i < n; i++) {
		for (long long int j = 2; j < m; j++) {
			total = std::max(total, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]);
			total = std::max(total, dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]);
		}
	}
	std::cout << total << std::endl;

	return 0;
}