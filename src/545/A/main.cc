#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long int ll;

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	ll n;
	std::vector<ll> cars;
	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		bool good = true;
		for (ll j = 0; j < n; j++) {
			ll r;
			std::cin >> r;
			if (r == 3 || r == 1) {
				good = false;
			}
		}
		if (good) {
			cars.push_back(i);
		}
	}

	std::cout << cars.size() << std::endl;
	for (ll i = 0; i < cars.size(); i++) {
		std::cout << cars[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}