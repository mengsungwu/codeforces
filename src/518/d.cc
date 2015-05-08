#include <iostream>
#include <iomanip>
#include <vector>

int main(int argc, char *argv[])
{
	unsigned long int n, t;
	double p, expectation;
	std::vector< std::vector<double> > prob;

	std::cin >> n >> p >> t;

	prob.resize(t + 1);
	for (std::vector< std::vector<double> >::iterator it = prob.begin(); it != prob.end(); it++) {
		it->resize(n + 1);
	}
	
	prob[0][0] = 1.0;

	for (unsigned long int i = 0; i < t; i++) {
		for (unsigned long int j = 0; j < n; j++) {
			prob[i + 1][j + 1] += p * prob[i][j];
			prob[i + 1][j] += (1 - p) * prob[i][j];
		}
		prob[i + 1][n] += prob[i][n];
	}

	expectation = 0.0;
	for (unsigned long int i = 0; i <= n; i++) {
		expectation += i * prob[t][i];
	}

	std::cout << std::setprecision(9) << expectation;

	return 0;
}
