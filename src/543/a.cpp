
#include <iostream>

const int MAX = 500;
unsigned long long int a[MAX];
unsigned long long int sol[MAX + 1][MAX + 1];

int main(int argc, char *argv[])
{
	unsigned long long int n, m, b, mod;
	unsigned long long int solutions;


	std::cin >> n >> m >> b >> mod;

	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}

	sol[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = a[i]; k <= b; k++) {
				sol[j][k] = (sol[j][k] + sol[j - 1][k - a[i]]) % mod;
			}
		}
	}

	solutions = 0;
	for (int i = 0; i <= b; i++) {
		solutions = (solutions + sol[m][i]) % mod;
	}

	std::cout << solutions;

	return 0;
}