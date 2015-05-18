#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

typedef long long int ll;

int main(int argc, char *argv) {

	std::ios_base::sync_with_stdio(false);

	ll n, d, a, b;
	std::vector<std::pair<ll, ll> > customers;
	std::vector<ll> results;
	std::cin >> n >> d >> a >> b;

	for (ll i = 0; i < n; i++) {
		ll x, y;
		std::cin >> x >> y;
		customers.push_back(std::make_pair(x*a + y *b, i+1));
	}

	std::sort(customers.begin(), customers.end());

	for (ll i = 0; i < n; i++) {
		if (customers[i].first <= d) {
			results.push_back(customers[i].second);
			d -= customers[i].first;
		}
	}

	std::cout << results.size() << std::endl;
	for (ll i = 0; i < results.size(); i++) {
		std::cout << results[i] << std::endl;
	}


	return 0;
}