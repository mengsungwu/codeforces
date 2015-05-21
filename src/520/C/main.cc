#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>

typedef long long int ll;

ll symbol_to_int(char c)
{
	switch (c) {
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'T':
		return 3;
	default:
		return -1;
	}
}

ll power(ll base, ll n)
{
	ll result = 1;
	for (ll i = 0; i < n; i++) {
		result = (result * base) % 1000000007;
	}
	return result;
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	ll n;
	std::string dna;
	std::vector<ll> count(4);
	
	std::cin >> n >> dna;

	for (ll i = 0; i < dna.size(); i++) {
		count[symbol_to_int(dna[i])]++;
	}

	std::sort(count.begin(), count.end());

	if (count[3] > count[2]) {
		std::cout << "1" << std::endl;
	} else if (count[2] > count[1]) {
		// count[3] == count[2] > count[1]
		// 2^n
		std::cout << power(2, n) << std::endl;
	} else if (count[1] > count[0]) {
		// count[3] == count[2] == count[1] > count[0]
		// 3^n
		std::cout << power(3, n) << std::endl;
	} else {
		// count[3] == count[2] == count[1] == count[0]
		// 4^n
		std::cout << power(4, n) << std::endl;
	}


	return 0;
}