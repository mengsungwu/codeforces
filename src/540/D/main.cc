#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>

typedef long long int ll;

std::vector< std::vector< std::vector< double > > > prob(101, std::vector< std::vector<double> >(101, std::vector<double>(101)));

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	ll r, s, p;
	std::cin >> r >> s >> p;
	prob[r][s][p] = 1.0;

	for (ll n = r + s + p; n > 0; n--) {
		for (ll i = 0; i <= r && i <= n; i++) {
			for (ll j = 0; j <= n - i && j <= s; j++) {
				ll k = n - i - j;
				ll total = i*j + i*k + j*k;
				if (total == 0 || k > p) {
					continue;
				}

				//std::cout << prob[i][j][k] << " = ";

				if (i != 0) {
					prob[i - 1][j][k] += i*k*prob[i][j][k] / total;
					//std::cout << prob[i - 1][j][k] << " ";
				}

				if (j != 0) {
					prob[i][j - 1][k] += i*j*prob[i][j][k] / total;
					//std::cout << prob[i][j - 1][k] << " ";
				}

				if (k != 0) {
					prob[i][j][k - 1] += j*k*prob[i][j][k] / total;
					//std::cout << prob[i][j][k - 1] << " ";
				}
				//std::cout << std::endl;
			}
		}
	}

	double surviving = 0;
	for (ll i = 1; i <= r; i++) {
		surviving += prob[i][0][0];
	}

	std::cout << std::setprecision(9) << surviving;

	surviving = 0;
	for (ll i = 1; i <= s; i++) {
		surviving += prob[0][i][0];
	}
	std::cout << std::setprecision(9) << " " << surviving;

	surviving = 0;
	for (ll i = 1; i <= p; i++) {
		surviving += prob[0][0][i];
	}
	std::cout << std::setprecision(9) << " " << surviving << std::endl;

	return 0;
}