#include <iostream>
#include <vector>

const unsigned long long int MODULE = 1000000007;

int main(int argc, char *argv[])
{
	long long int n, a, b, k;
	std::vector<unsigned long long int> way;
	std::cin >> n >> a >> b >> k;

	if (a > b) {
		a = n - a + 1;
		b = n - b + 1;
	}

	way.resize(b);
	way[a] = 1;

	for (long long int i = 0; i < k; i++) {
		long long int s = b / 2;
		std::vector<unsigned long long int> tmp;
		tmp.resize(b);

		for (long long int j = 1; j <= s; j++) {
			tmp[1] += way[j];
		}

		for (long long int j = 2; j < b; j++) {
			tmp[j] = tmp[j - 1];
			if ((b - j) % 2 == 1) {
				tmp[j] += way[++s];
			}
		}

		for (long long int j = 1; j < b; j++) {
			tmp[j] -= way[j];
			way[j] = tmp[j] % MODULE;

			//std::cout << way[j] << " ";
		}
		//std::cout << std::endl;

	}

	long long int total = 0;
	for (long long int j = 1; j < b; j++) {
		total = (total + way[j]) % MODULE;
	}

	std::cout << total << std::endl;


	return 0;
}