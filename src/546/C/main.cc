#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

typedef long long int ll;

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	ll n, k;

	std::vector< std::list<ll> > cards(2);

	std::cin >> n;
	
	for (ll i = 0; i < 2; i++) {
		std::cin >> k;
		for (ll j = 0; j < k; j++) {
			ll card;
			std::cin >> card;
			cards[i].push_back(card);
		}
	}

	for (ll i = 0; i < 100000; i++) {
		if (cards[0].empty()) {
			std::cout << i << " " << 2;
			return 0;
		}

		if (cards[1].empty() ) {
			std::cout << i << " " << 1;
			return 0;
		}

		ll c0 = cards[0].front();
		ll c1 = cards[1].front();

		cards[0].pop_front();
		cards[1].pop_front();

		if (c0 < c1) {
			cards[1].push_back(c0);
			cards[1].push_back(c1);
		}
		else {
			cards[0].push_back(c1);
			cards[0].push_back(c0);
		}
	}
	
	std::cout << "-1" << std::endl;
	return 0;
}