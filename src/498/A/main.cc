#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>

typedef long long int ll;
typedef long double ld;


int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	std::pair<ll, ll> home, university;
	std::cin >> home.first >> home.second;
	std::cin >> university.first >> university.second;

	ll n, total = 0;
	std::cin >> n;
	while (n--) {
		ld a, b, c;
		std::cin >> a >> b >> c;
		total += ((a*home.first + b*home.second + c) * (a*university.first + b*university.second + c) < 0 ? 1 : 0);
	}
	std::cout << total << std::endl;



	return 0;
}