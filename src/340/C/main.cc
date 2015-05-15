#include <iostream>

#include <algorithm>
#include <vector>
#include <map>
#include <set>

long long int greatest_common_divisor(long long int a, long long int b)
{
	while (b != 0) {
		long long int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	long long int n;
	std::cin >> n;

	std::vector<long long int> a(n + 1);
	for (long long int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());

	long long int numerator = 0;
	
	for (long long int i = 1; i <= n; i++) {
		// 0->1 0->2 0->3 ... n->n
		numerator += (a[i] - a[i - 1]) * (n - i + 1);

		// 1->2 1->3 ... 1->n
		// 2->1 3->1 ... n->1
		numerator += (a[i] - a[i - 1]) * (i - 1) * (n - i + 1) * 2;

	}

	long long int gcd = greatest_common_divisor(numerator, n);
	std::cout << numerator / gcd << " " << n / gcd << std::endl;

	return 0;
}